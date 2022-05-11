def chanceWithMutation(idv, target, mutateChance):
  chance = 1
  for i in range(len(idv)):
    if idv[i] == target[i]:
      chance *= (1 - mutateChance)
    else:
      chance *= mutateChance
  return chance

def main():
  
  numTestCases = int(input())
  
  while numTestCases != 0:
    
    # Input handling
    
    numBits = int(input())
    auxInput = input().split(" ")
    cutPos, mutProb = int(auxInput[0]), float(auxInput[1])
    firstIndividual = input()
    secondIndividual = input()
    targetIndividual = input()
    
    # Spliting for crossover
    
    leftFirstIndv = firstIndividual[:cutPos]
    rightFirstIndv = firstIndividual[cutPos:numBits]
    leftSecondIndv = secondIndividual[:cutPos]
    rightSecondIndv = secondIndividual[cutPos:numBits]
    
    # New individuals
    
    firstCrossover = leftFirstIndv + rightSecondIndv
    secondCrossover = leftSecondIndv + rightFirstIndv
    
    # Probability of Union of A with B is P(A) + P(B) - P(AUB) - U here is interssection lol
    # where the event A is the first individual becoming the target individual
    # B is the second individual becoming the target individual
    # and AUB is the event where both become the target individual
    
    # Demorei pra sacar essa, ainda bem que estou fazendo probabilidade e estatística nesse semestre
    
    pA = chanceWithMutation(firstCrossover, targetIndividual, mutProb)
    pB = chanceWithMutation(secondCrossover, targetIndividual, mutProb)
    pAUB = pA * pB
    
    print("%.7f"%(pA + pB - pAUB))
    
    numTestCases -= 1
  
  return None

if __name__ == "__main__":
  main()
