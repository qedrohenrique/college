
def get_enumerated_data():
  V = [
    "GRU", 
    "CNF",
    "GIG",
    "BSB",
    "MAO",
    "REC",
    "CNH",
    "FOR"
  ]

  E = [
    ('GRU', 'CNF'),
    ('GRU', 'GIG'),
    ('GRU', 'BSB'),
    ('GRU', 'MAO'),
    ('GRU', 'FOR'),
    ('GRU', 'REC'),
    ('GIG', 'CNF'),
    ('GIG', 'BSB'),
    ('GIG', 'REC'),
    ('GIG', 'FOR'),
    ('GIG', 'MAO'),
    ('CNF', 'CNH'),
    ('CNF', 'BSB'),
    ('CNH', 'BSB'),
    ('CNH', 'FOR'),
    ('CNH', 'REC'),
    ('BSB', 'MAO'),
    ('BSB', 'FOR'),
    ('BSB', 'REC'),
    ('REC', 'FOR'),
    ('BSB', 'REC'),
  ]

  vertexes = V
  vertexes_as_indexes = {vertex: index for index, vertex in enumerate(vertexes)}

  # Arestas

  edges = []

  for edge in E:
    edges.append((vertexes_as_indexes[edge[0]], vertexes_as_indexes[edge[1]]))

  vertex_indexes = {index: vertex for index, vertex in enumerate(vertexes)}

  return vertex_indexes, edges, V, E


def get_enumerated_sub_data():
  V = [
    "EZE",
    "GIG",
    "BSB",
    "MAO",
    "REC",
    "CNH",
    "FOR"
  ]

  E = [
    ('EZE', 'GIG'),
    ('GIG', 'BSB'),
    ('GIG', 'REC'),
    ('GIG', 'FOR'),
    ('GIG', 'MAO'),
    ('BSB', 'MAO'),
    ('BSB', 'FOR'),
    ('BSB', 'REC'),
    ('REC', 'FOR'),
    ('BSB', 'REC'),
  ]

  vertexes = V
  vertexes_as_indexes = {vertex: index for index, vertex in enumerate(vertexes)}

  # Arestas

  edges = []

  for edge in E:
    edges.append((vertexes_as_indexes[edge[0]], vertexes_as_indexes[edge[1]]))

  vertex_indexes = {index: vertex for index, vertex in enumerate(vertexes)}

  return vertex_indexes, edges, V, E