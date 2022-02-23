import numpy as np
# Função que sera usada:
# f(x) = 1 + 2x - x^2

# Parâmertros
print("Digite w: ")
w = float(input())
print("Digite c1: ")
c1 = float(input())
print("Digite c2: ")
c2 = float(input())
print("Digite r1: ")
r1 = float(input())
print("Digite r2: ")
r2 = float(input())
print("Digite n: ")
n = int(input())
print("Digite itr: ")
itr = int(input())

X = np.random.uniform(low=0.0, high=10.0, size=(n,))
V = np.random.uniform(low=0.0, high=10.0, size=(n,))
F = 5*[0]

# Inicialização posições

Xi = 5*[0]
Vi = 5*[0]
Fi = 5*[0]

for i in range(len(X)):
  Xi[i] = round(10*(X[i] - 0.5), 4)
  Vi[i] = round(V[i] - 0.5, 4)
  
# Primeira iteração

X = Xi
V = Vi
for i in range(len(F)):
  F[i] = round((1 + (2*X[i]) - (X[i]**2)), 4)
  
Pbest = X
GbestFit = max(F)
Gbest = X[F.index(GbestFit)]

# Segunda iteração em diante

for i in range(1, itr):
  
  for j in range(len(Xi)):
    Vi[j] = round((w*V[j]) + (c1*r1*(Pbest[j]-X[j])) + (c2*r2*(Gbest - X[j])), 4)
    Xi[j] = round(X[j] + Vi[j], 4)
  
  for j in range(len(Fi)):
    Fi[j] = round((1 + (2*Xi[j]) - (Xi[j]**2)), 4) 
    
  for j in range(len(Pbest)):
    if F[j] < Fi[j]:
      Pbest[j] = Xi[j]
    if GbestFit < Fi[j]:
      GbestFit = Fi[j]
      Gbest = Xi[j]
  
  X = Xi
  V = Vi

print("V: ", end='')
print(V)
print("X: ", end='')
print(X)
print("F: ", end='')
print(F)
print("Pbest: ", end='')
print(Pbest)
print("Gbest: ", end='')
print(Gbest)
print("GbestFitness: ", end='')
print(GbestFit)
   