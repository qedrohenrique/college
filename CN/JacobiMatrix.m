function J = JacobiMatrix (x)
  
  n = length(x);
  J = zeros(n,n);
  
  J(1,1) = exp(x(1)-1) + (10*x(1)) + 7;
  J(1,2) = - (2*x(2));
  
  for i = 2 : n - 1
    J(i,1) = exp(x(1)-1);
    J(i,i) = 10*x(i) + 7;
    J(i,i+1) = - (2*x(i+1));
  endfor
  
  J(n,1) = ((x(1)^2)*exp(x(1)-1)) + (2*x(1)*exp(x(1)-1));
  J(n,n) = 10*x(n) + 7;
