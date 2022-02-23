import numpy as np
import copy

def coolPrint(visited):
  for i in range(len(visited)-1):
    if visited[i] == 0:
      print('A' + " → ", end='')
    if visited[i] == 1:
      print('B' + " → ", end='')
    if visited[i] == 2:
      print('C' + " → ", end='')
    if visited[i] == 3:
      print('D' + " → ", end='')
    if visited[i] == 4:
      print('E' + " → ", end='')
    
  if visited[len(visited)-1] == 0:
    print('A')
  if visited[len(visited)-1] == 1:
    print('B')
  if visited[len(visited)-1] == 2:
    print('C')
  if visited[len(visited)-1] == 3:
    print('D')
  if visited[len(visited)-1] == 4:
    print('E')

def inputAdjMatrix(matrix):
  for i in range(5):         
    a =[]
    for j in range(5):     
         a.append(int(input()))
    matrix.append(a)
    
# Parâmetros

startingPoint = int(input())
# A -> 0
# B -> 1
# (...)

alpha = float(input())
beta = float(input())
rho = float(input())
tau = float(input())

# Grafo #

inputMatrix = []
inputAdjMatrix(inputMatrix)

# Matriz feromônios #

ferMatrix = np.zeros((5,5))
for i in range(5):
  for j in range(5):
    if i==j:
      ferMatrix[i][j] = 0
    else:
      ferMatrix[i][j] = tau

# Execucao #

visited = []
visited.append(startingPoint)
currPoint = startingPoint
P = 5*[0]

#Caminho percorrido
matrix = copy.deepcopy(inputMatrix)
for i in range(4):
  for j in range(5):
    if j not in visited and matrix[currPoint][j] != 0:
      P[j]=(alpha*beta*tau*(1/matrix[currPoint][j]))
  
  m = P.index(max(P))
  visited.append(m)
  P = 5*[0]
  matrix[m][currPoint] = 0
  currPoint = m
  
# Atualizando matriz de feromônios

for i in range(5):
  for j in range(5):
    if inputMatrix[i][j] !=0:
      print(f"({i}, {j}): "+ str(inputMatrix[i][j]))
      ferMatrix[i][j] = ((1-rho)*ferMatrix[i][j])+(rho*1/inputMatrix[i][j])
    else:
      ferMatrix[i][j] = 0
print(ferMatrix)
coolPrint(visited)

    