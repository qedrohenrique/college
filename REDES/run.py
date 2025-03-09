import subprocess
import argparse
import os

parser = argparse.ArgumentParser(description="Run NS3 simulations.")
parser.add_argument("--ns3_path", type=str, help="Path to the ns3 executable")
args = parser.parse_args()

ns3_path = args.ns3_path if args.ns3_path else './ns3'

if (not args.ns3_path):
    print("[!] No ns3 path given. Using './ns3' as path.")
    print("[!] You can run this file with --ns3_path flag.")

if not os.path.isfile(ns3_path) or not os.access(ns3_path, os.X_OK):
    print(f"[!] Error: The specified ns3 executable at '{
          ns3_path}' does not exist or is not executable.")
    exit(1)

print("[!] You can set number of hosts and enable mobility in the scripts.")

try:
    for num_nodes in [1, 2, 4, 8, 16, 32]:
        print(
            f"[+] Running simulations with {num_nodes} nodes and WITHOUT mobility.")

        command_tcp = [ns3_path, 'run', 'tcp.py', '--', '--num_station_nodes',
                       str(num_nodes), '--enable_mobility', str(False)]
        print("[+] Running tcp.py...")
        result_tcp = subprocess.run(
            command_tcp, check=True, text=True, capture_output=True)
        print("[!] Output tcp.py:")
        print(result_tcp.stdout)

        command_udp = [ns3_path, 'run', 'udp.py', '--', '--num_station_nodes',
                       str(num_nodes), '--enable_mobility', str(False)]
        print("[+] Running udp.py...")
        result_udp = subprocess.run(
            command_udp, check=True, text=True, capture_output=True)
        print("[!] Output udp.py:")
        print(result_udp.stdout)

        command_tcp_and_udp = [ns3_path, 'run', 'tcp_and_udp.py', '--',
                               '--num_station_nodes', str(num_nodes), '--enable_mobility', str(False)]
        print("[+] Running tcp_and_udp.py...")
        result_tcp_and_udp = subprocess.run(
            command_tcp_and_udp, check=True, text=True, capture_output=True)
        print("[!] Output tcp_and_udp.py:")
        print(result_tcp_and_udp.stdout)

        print(
            f"[+] Running simulations with {num_nodes} nodes and WITH mobility.")

        command_tcp = [ns3_path, 'run', 'tcp.py', '--', '--num_station_nodes',
                       str(num_nodes), '--enable_mobility', str(True)]
        print("[+] Running tcp.py...")
        result_tcp = subprocess.run(
            command_tcp, check=True, text=True, capture_output=True)
        print("[!] Output tcp.py:")
        print(result_tcp.stdout)

        command_udp = [ns3_path, 'run', 'udp.py', '--', '--num_station_nodes',
                       str(num_nodes), '--enable_mobility', str(True)]
        print("[+] Running udp.py...")
        result_udp = subprocess.run(
            command_udp, check=True, text=True, capture_output=True)
        print("[!] Output udp.py:")
        print(result_udp.stdout)

        command_tcp_and_udp = [ns3_path, 'run', 'tcp_and_udp.py', '--',
                               '--num_station_nodes', str(num_nodes), '--enable_mobility', str(True)]
        print("[+] Running tcp_and_udp.py...")
        result_tcp_and_udp = subprocess.run(
            command_tcp_and_udp, check=True, text=True, capture_output=True)
        print("[!] Output tcp_and_udp.py:")
        print(result_tcp_and_udp.stdout)


except subprocess.CalledProcessError as e:
    print(f"[!] Error: {e.stderr}")
