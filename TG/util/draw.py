import networkx as nx
import matplotlib.pyplot as plt
import re
import googlemaps

api_key = ""
client = googlemaps.Client(api_key)

DISTANCE = 100

# Criar um grafo vazio
G = nx.Graph()

agencias = [
  "RUA SANTA CLARA, 245", #
  "AVENIDA RUI BARBOSA, 2376", #
  "RUA RIACHUELO, 57",
  "AVENIDA ANDROMEDA, 1469", #
  "RUA SABARA, 30",
  "RUA EZEQUIEL ALVES GRACIANO, 140",
  "RUA QUINZE DE NOVEMBRO, 259",
  "AVENIDA DOUTOR NELSON D AVILA, 90",
  "RUA LOANDA, 895",
  "RUA GOIANIA, 15", #
]

pessoas_fisicas = [
  "RUA MATIAS PERES, 364",
  "RUA DA ALEGRIA, 39",
  "RUA CAPARAÓ, 370",
  "RUA ITUIUTABA, 50",
  "RUA PIMENTEIRAS, 322",
  "RUA CARVALHO DE ARAÚJO, 106 ",
  "RUA SAMUEL ANTÔNIO RODRIGUES, 197",
]

empresas = [
  "EMBRAER BRG. FARIA LIMA, 2170",
  "AKAER AV. CESARE MONSUETO GIULIO LATTES, 501",
  "DEDÉ CELLAV. ANDRÔMEDA, 654",
]

outros = [
  "UNESP AV. ENGENHEIRO FRANCISO JOSÉ LONGO, 777"
]

G.add_nodes_from(agencias)
G.add_nodes_from(pessoas_fisicas)
G.add_nodes_from(empresas)
G.add_nodes_from(outros)

for agencia in agencias:
  for pessoa in pessoas_fisicas:
    origem = agencia + (', São José dos Campos')
    destino = pessoa + (', São José dos Campos')
    matriz_distancia = client.distance_matrix(origins=origem, destinations=destino)
    distancia = matriz_distancia["rows"][0]["elements"][0]["distance"]["text"]
    match = re.search(r'[0-9.]+', distancia)
    G.add_edge(agencia, pessoa, weight=float(match.group(0)))
    print(f"[{agencia}] -> [{pessoa}] : {distancia} km")

for agencia in agencias:
  for empresa in empresas:
    origem = agencia + (', São José dos Campos')
    destino = empresa + (', São José dos Campos')
    matriz_distancia = client.distance_matrix(origins=origem, destinations=destino)
    distancia = matriz_distancia["rows"][0]["elements"][0]["distance"]["text"]
    match = re.search(r'[0-9.]+', distancia)
    G.add_edge(agencia, empresa, weight=float(match.group(0)))
    print(f"[{agencia}] -> [{empresa}] : {distancia} km")

for agencia in agencias:
  origem = agencia + (', São José dos Campos')
  destino = outros[0] + (', São José dos Campos')
  matriz_distancia = client.distance_matrix(origins=origem, destinations=destino)
  distancia = matriz_distancia["rows"][0]["elements"][0]["distance"]["text"]
  match = re.search(r'[0-9.]+', distancia)
  G.add_edge(agencia, outros[0], weight=float(match.group(0)))
  print(f"[{agencia}] -> [{outros[0]}] : {distancia} km")

color_map = [ *(['skyblue']*10), *(['tab:red']*7), *(['tab:blue']*3), *(['tab:green']*1) ]

options = {
  "font_size": 16,
  "node_size": 3000,
  "linewidths": 3,
  "width": 5,
  "with_labels": True,
  "node_color": color_map,
  "node_size": 1000,
}

pos = nx.spring_layout(G, seed=7)

plt.figure(figsize=(12, 12))
nx.draw(G, pos, **options)
# edges
edge_labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels)

plt.show()