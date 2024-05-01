# Exercício 1

def adjacency_from_graph(V, E):
  adjacency_matrix = [[0 for _ in V] for _ in V]

  vertex_indexes = {vertex: index for index, vertex in enumerate(V)}

  for v1, v2 in E:
      if v1 < v2:
        i = vertex_indexes[v1]
        j = vertex_indexes[v2]
      else:
        i = vertex_indexes[v2]
        j = vertex_indexes[v1]
      adjacency_matrix[i][j] = 1

  for i in range(len(V)):
        for j in range(i + 1, len(V)):
            adjacency_matrix[j][i] = adjacency_matrix[i][j]

  return adjacency_matrix

def graph_from_adjacency(matrix):
  V = [i for i in range(len(matrix))]
  E = []

  for i in range(len(matrix)):
      for j in range(i, len(matrix)):
          if matrix[i][j] == 1:
              E.append((V[i], V[j]))

  return V, E

def incidence_from_graph(V, E):
    incidence_matrix = [[0 for _ in range(len(E))] for _ in range(len(V))]

    vertex_indexes = {vertex: index for index, vertex in enumerate(V)}

    for j, (v1, v2) in enumerate(E):
        i1 = vertex_indexes[v1]
        i2 = vertex_indexes[v2]
        incidence_matrix[i1][j] = 1
        incidence_matrix[i2][j] = 1
    
    return incidence_matrix

def graph_from_incidence(matrix):
    V = [i for i in range(len(matrix))]
    E = []
  
    for j in range(len(matrix[0])):
        edge = [i for i in range(len(matrix)) if matrix[i][j] == 1]
        if len(edge) == 2:
            v1, v2 = edge
            E.append((V[v1], V[v2]))

    return V, E

def adjacency_list_from_graph(V, E):
    adjacency_list = {vertex: [] for vertex in V}
    
    for v1, v2 in E:
        adjacency_list[v1].append(v2)
        adjacency_list[v2].append(v1)
    
    return adjacency_list

def graph_from_adjacency_list(adj_list):
    V = list(adj_list.keys())
    E = []

    duplicated_vertexes = set()

    for vertex, edges in adj_list.items():
        for edge in edges:
            if (edge, vertex) not in duplicated_vertexes:
                E.append((vertex, edge))
                duplicated_vertexes.add((vertex, edge))
    
    return V, E

def get_graph_representation(graph):
  # -1 -> padrão G=(V, E)
  # 0 -> lista adjacencia
  # 1 -> matriz adjacencia
  # 2 -> matriz incidencia
  if isinstance(graph, dict):
      return "Lista de Adjacência", 0

  if isinstance(graph, list):
    if(len(graph) != len(graph[0])):
      for column in list(zip(*graph)):
        edges = [i for i in range(len(column)) if column[i] == 1]
        
        if len(edges) != 2:
          return "Não identificado", 3
        
      return "Matriz Incidência", 2
    else:
      for column in graph:
        edges = [i for i in range(len(column)) if column[i] == 1]

        if len(edges) != 2:
            if(is_symmetric(graph, len(graph))):
              return "Matriz Adjacência", 1
            return "Não identificado", 3
        
      return "Matriz Incidência", 2
    
  if len(graph) == 2:
    if isinstance(graph[0], list) and isinstance(graph[1], list):
      return 'Representação Padrão', -1
  
  return "Não identificado", 3
    
def get_other_representations(graph):
  _, type = get_graph_representation(graph)
  
  if type == 0:
    V, E = graph_from_adjacency_list(graph)
    adjacency_matrix = adjacency_from_graph(V, E )
    incidence_matrix = incidence_from_graph(V, E )
    return adjacency_matrix, incidence_matrix
   
  if type == 1:
    V, E  = graph_from_adjacency(graph)
    incidence_matrix = incidence_from_graph(V, E )
    adj_list = adjacency_list_from_graph(V, E )
    return adj_list, incidence_matrix
   
  if type == 2:
    V, E  = graph_from_incidence(graph)
    adjacency_matrix = adjacency_from_graph(V, E )
    adj_list = adjacency_list_from_graph(V, E )
    return adjacency_matrix, adj_list
  
  print("Representação não encontrada")
  return graph

def transpose(mat, tr, N):
    for i in range(N):
        for j in range(N):
            tr[i][j] = mat[j][i]
 
def is_symmetric(mat, N):
    tr = [[0 for j in range(len(mat[0]))] for i in range(len(mat))]
    transpose(mat, tr, N)
    for i in range(N):
        for j in range(N):
            if (mat[i][j] != tr[i][j]):
                return False
    return True

# Exercício 2

def get_graph_vertex_total(graph):
  _, type = get_graph_representation(graph)

  if type == 0:
    V, E = graph_from_adjacency_list(graph)
    return (len(V))
  
  if type == 1:
    V, E = graph_from_adjacency(graph)
    return (len(V))
  
  if type == 2:
    V, E = graph_from_incidence(graph)
    return (len(V))

def get_graph_edges_total(graph):
  _, type = get_graph_representation(graph)

  if type == 0:
    V, E = graph_from_adjacency_list(graph)
    return (len(E))
  
  if type == 1:
    V, E = graph_from_adjacency(graph)
    return (len(E))
  
  if type == 2:
    V, E = graph_from_incidence(graph)
    return (len(E))

def get_adjacent_vertexes(vertex, graph):
  _, type = get_graph_representation(graph)

  if type == 0:
    return(graph[vertex])
  
  if type == 1:
    V, E = graph_from_adjacency(graph)
    adjacency_list = adjacency_list_from_graph(V, E)
    return(adjacency_list[vertex])
  
  if type == 2:
    V, E = graph_from_incidence(graph)
    adjacency_list = adjacency_list_from_graph(V, E)
    return(adjacency_list[vertex])

def is_adjacent_vertex(a, b, graph):
  adjacents = get_adjacent_vertexes(a, graph)

  return b in adjacents

def vertex_degree(v, graph):
  _, type = get_graph_representation(graph)

  if type == 0:
    return (len(graph[v]))
  
  if type == 1:
    V, E = graph_from_adjacency(graph)
    adjacency_list = adjacency_list_from_graph(V, E)
    return(len(adjacency_list[v]))
  
  if type == 2:
    V, E = graph_from_incidence(graph)
    adjacency_list = adjacency_list_from_graph(V, E)
    return(len(adjacency_list[v]))

def all_vertexes_degree(graph):
  _, type = get_graph_representation(graph)

  if type == 0:
    degrees = {}
    for v in graph:
      degrees[v] = vertex_degree(v, graph)
    return (degrees)
  
  if type == 1:
    V, E = graph_from_adjacency(graph)
    adjacency_list = adjacency_list_from_graph(V, E)
    degrees = {}
    for v in adjacency_list:
      degrees[v] = vertex_degree(v, adjacency_list)
    return (degrees)
  
  if type == 2:
    V, E = graph_from_incidence(graph)
    adjacency_list = adjacency_list_from_graph(V, E)
    degrees = {}
    for v in adjacency_list:
      degrees[v] = vertex_degree(v, adjacency_list)
    return (degrees)

def simple_path_adj_list(graph, start, end, path=[]):
    path = path + [start]
    
    if start == end:
        return path
    
    if start not in graph:
        return None
    
    for vertex in graph[start]:
        if vertex not in path:
            extended_path = simple_path_adj_list(graph, vertex, end, path)
            if extended_path: 
                return extended_path

    return None

def simple_path(graph, start, end, path=[]):
  _, type = get_graph_representation(graph)

  if type == 0:
    return simple_path_adj_list(graph, start, end, path=[])
  
  if type == 1:
    V, E = graph_from_adjacency(graph)
    adjacency_list = adjacency_list_from_graph(V, E)
    return simple_path_adj_list(adjacency_list, start, end, path=[])
  
  if type == 2:
    V, E = graph_from_incidence(graph)
    adjacency_list = adjacency_list_from_graph(V, E)
    return simple_path_adj_list(adjacency_list, start, end, path=[])

def dfs_adj_matrix(v, parent, visited, graph, start_vertex, path):
    visited[v] = True
    path.append(v)

    for i in range(len(graph[v])):
        if graph[v][i] == 1: 
            if not visited[i]: 
                if dfs_adj_matrix(i, v, visited, graph, start_vertex, path):
                    return True
            elif i != parent and i == start_vertex:  # Encontrou um ciclo
                path.append(i)
                return True

    path.pop()
    return False

def cycle_adj_matrix(start, graph):
    start_vertex = start
    visited = [False] * len(graph)
    path = []

    if dfs_adj_matrix(start, -1, visited, graph, start_vertex, path):
        return path
    else:
        return None

def cycle(start, graph):
  _, type = get_graph_representation(graph)

  if type == 0:
    V, E = graph_from_adjacency_list(graph)
    adj_matrix = adjacency_from_graph(V, E)
    return cycle_adj_matrix(start, adj_matrix)
  
  if type == 1:
    return cycle_adj_matrix(start, graph)
  
  if type == 2:
    V, E = graph_from_incidence(graph)
    adj_matrix = adjacency_from_graph(V, E)
    return cycle_adj_matrix(start, adj_matrix)
  
def is_subgraph(V, E, Vsub, Esub):
  E_named = []

  for e in E:
    E_named.append((V[e[0]], V[e[1]]))

  for v in Vsub:
    if v not in V:
      return False
    
  for e in Esub:
    if (Vsub[e[0]], Vsub[e[1]]) not in E_named:
      return False
  
  if not (is_valid_graph(Vsub, Esub)):
    return False

  return True

def is_valid_graph(V, E):
  for v1, v2 in E:
    if v1 not in V or v2 not in V:
      return False
      
  return True
      
# Exercício 3 

import vertexes_and_edges
V, E = vertexes_and_edges.get_enumerated_data()

adj_list = adjacency_list_from_graph(V, E)
adj_matrix = adjacency_from_graph(V, E)
inc_matrix = incidence_from_graph(V, E)

adj_list_degrees = all_vertexes_degree(adj_list)
print(adj_list_degrees)
print(all_vertexes_degree(adj_matrix))
print(all_vertexes_degree(inc_matrix))

for v in adj_list_degrees.keys():
  print(V[v], ": ", adj_list_degrees[v])





# adj_matrix = adjacency_from_graph(V, E)

# vertex_degrees = {}
# degrees = []

# for v in V.keys():
#   vertex_degrees[vertex_degree(v, adj_matrix)] = V[v]
#   degrees.append(vertex_degree(v, adj_matrix))

# print(vertex_degrees[max(degrees)], ' - ', max(degrees))
# print(vertex_degrees[min(degrees)], ' - ', min(degrees))