function s = NewtonGaussJacobi (x)
  tic;
  n = length(x); 
  
  for i = 1 : n -1
     b(i,1) = exp(x(1)-1) + 5*x(i)^2 + 7*x(i) - (x(i+1)^2) - 12;
  endfor
  
  b(n,1) = ((x(i)^2)*exp(x(1)-1)) + 5*x(n)^2 + 7*x(n) - 13;
  
  A = JacobiMatrix(x);
  
  chute_inicial = zeros(n,1);
  GaussJacobi(A,b, chute_inicial, 1000, 10e-100)
  toc