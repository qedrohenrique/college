function taylor(x, n)
  
  aux = 0;
  
  for i=0:n
    aux = aux + (exp(0)/factorial(i))*x^i;
    i = i + 1;
  endfor
  R = aux
  erro = abs((exp(2) - aux)/exp(2)) * 100