import xml.etree.ElementTree as ET
import csv
import re
# import tabulate


def parse_ipv4_flow_classifier(xml_file):
    tree = ET.parse(xml_file)
    root = tree.getroot()

    flow_list = []

    for classifier in root.findall(".//Ipv4FlowClassifier"):
        for flow in classifier.findall("Flow"):
            flow_id = flow.get("flowId", "N/A")
            source_address = flow.get("sourceAddress", "N/A")
            destination_address = flow.get("destinationAddress", "N/A")

            flow_data = {
                "flowId": flow_id,
                "sourceAddress": source_address,
                "destinationAddress": destination_address
            }

            flow_list.append(flow_data)

    return flow_list


def find_flows_in_stats(xml_file, valid_flows):
    def is_address_wanted(flow):
        return not flow["sourceAddress"].endswith(".1")

    def is_wired_flow(flow):
        ip = flow.get("sourceAddress", "N/A")
        ipv4_pattern = r"^10\.(\d+)\.(\d+)\.(\d+)$"

        match = re.match(ipv4_pattern, ip)

        if match:
            y = int(match.group(2))

        if y == 6:
            return True

        return False

    def is_wireless_flow(flow):
        ip = flow.get("sourceAddress", "N/A")
        ipv4_pattern = r"^10\.(\d+)\.(\d+)\.(\d+)$"

        match = re.match(ipv4_pattern, ip)

        if match:
            x = int(match.group(1))
            y = int(match.group(2))

        if y == 0 and x == 0:
            return True

        return False

    def get_node_type(flow):
        if is_wired_flow(flow):
            return "wired"
        elif is_wireless_flow(flow):
            return "wireless"
        else:
            return "unknown"

    def get_flow_by_id(flow_list, flow_id):
        for f in flow_list:
            if f["flowId"] == flow_id:
                return f
        return None

    tree = ET.parse(xml_file)
    root = tree.getroot()

    stats_list = []

    for flow_stats in root.findall(".//FlowStats"):
        for flow in flow_stats.findall("Flow"):
            flow_id = flow.get("flowId", "N/A")

            if any(f["flowId"] == flow_id and is_address_wanted(f) for f in valid_flows):
                stats_list.append({
                    "flowId": flow_id,
                    "details": flow.attrib,
                    "nodeType": get_node_type(get_flow_by_id(valid_flows, flow_id))
                })

    return stats_list


def calculate_metrics_from_stats(filtered_flows):
    metrics = []

    for flow in filtered_flows:
        flow_id = flow.get("flowId", "N/A")

        # Vazão

        rx_bytes = int(flow["details"].get("rxBytes", 0))
        time_first_rx_packet = float(flow["details"].get(
            "timeFirstRxPacket", "0").replace("ns", "")) * 1e-9
        time_last_rx_packet = float(flow["details"].get(
            "timeLastRxPacket", "0").replace("ns", "")) * 1e-9

        time_total = time_last_rx_packet - time_first_rx_packet

        if time_total > 0:
            throughput = rx_bytes / time_total
        else:
            throughput = 0

        # Perda de pacotes

        tx_packets = int(flow["details"].get("txPackets", 0))
        rx_packets = int(flow["details"].get("rxPackets", 0))
        lost_packets_percentage = 100 * (tx_packets - rx_packets) / tx_packets

        # Atraso

        delay_sum = float(flow["details"].get(
            "delaySum", "0").replace("ns", "")) * 1e-9
        if rx_packets > 0:
            delay = delay_sum / rx_packets
        else:
            delay = 0

        metrics.append({
            "flowId": flow_id,
            "nodeType": flow["nodeType"],
            "throughput": "%.2f" % round(throughput, 2),
            "packetLoss": "%.2f" % round(lost_packets_percentage, 2),
            "delay": "%.2f" % round(delay, 2)
        })

    return metrics


def export_metrics_to_csv(metrics, filename="metrics.csv"):
    if not metrics:
        print("A lista de métricas está vazia. Nada a exportar.")
        return

    headers = metrics[0].keys()

    try:
        with open(filename, mode="w", newline="", encoding="utf-8") as csvfile:
            writer = csv.DictWriter(csvfile, fieldnames=headers)
            writer.writeheader()

            for metric in metrics:
                writer.writerow(metric)

        print(f"Dados exportados com sucesso para o arquivo: {filename}")
    except Exception as e:
        print(f"Erro ao exportar os dados: {e}")


if __name__ == "__main__":
    app_type = "tcp"
    num_nodes = "32"
    has_mobility = True
    has_mobility_suffix = "_mobility" if has_mobility else ""

    xml_file_path = f"ns3-unifesp/output/{app_type}_{
        num_nodes}{has_mobility_suffix}.xml"

    valid_flows = parse_ipv4_flow_classifier(xml_file_path)

    filtered_stats = find_flows_in_stats(xml_file_path, valid_flows)

    metrics = calculate_metrics_from_stats(filtered_stats)

    export_metrics_to_csv(
        metrics, f"ns3-unifesp/output/{app_type}_{num_nodes}{has_mobility_suffix}_metrics.csv")

    # for m in metrics:
    #     print(f"Flow ID: {m['flowId']}, Throughput: {m['throughput']} bytes/segundo, Perda de pacotes: {m['packetLoss']}%, Atraso: {m['delay']}ns.")

    # header = ["flowId", "throughput (bytes/segundo)", "perda de pacotes (%)", "atraso (ns)"]
    # rows = [x.values() for x in metrics]
    # print(tabulate.tabulate(rows, header, tablefmt="grid"))
