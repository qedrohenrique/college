from math import gcd
import matplotlib.pyplot as plt
from matplotlib.ticker import MaxNLocator

def linear_congruential(a, b, m, initialValue, iterations):
  if a >= m or a <= 0:
    print("Parâmetro 'a' inválido.")
    return
  
  if a >= m or b < 0:
    print("Parâmetro 'b' inválido.")
    return

  if m <= 0:
    print("Parâmetro 'm' inválido.")
    return
    
  if gcd(b, m) != 1:
    print("Maior divisor comum entre 'm' e 'b' deve ser 1.")
    return

  sequence = [initialValue]
  x = initialValue
  for i in range(iterations):
    y = ((a * x) + b) % m
    sequence.append(y)
    x = y

  return sequence

def divisors(start, end):
    divisors = {i: [0, []] for i in range(start, end + 1)}

    for num in range(start, end + 1):
        divisor = num
        multiplier_index = 1
        while divisor <= end:
          value = divisors[divisor]
          value[0] += 1
          value[1].append(num)
          multiplier_index += 1
          divisor = num * multiplier_index
    
    return divisors

def plot_divisors(start, end):
    result = divisors(start, end)
    
    numbers = list(result.keys())
    divisors_and_count = list(result.values())
    divisors_count = list(count for count, divisors in divisors_and_count)
    
    plt.figure(figsize=(10, 5))
    plt.gca().yaxis.set_major_locator(MaxNLocator(integer=True))
    plt.plot(numbers, divisors_count, )
    plt.xlabel('Número')
    plt.ylabel('Quantidade de Divisores')
    plt.title('Quantidade de Divisores por Número')
    plt.xticks([]) 
    plt.grid(True, which='both', axis='y')
    plt.show()
