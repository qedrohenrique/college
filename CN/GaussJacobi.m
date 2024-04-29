function x = GaussJacobi(A, b, p, maxItr, maxErr)
  
  n = length(b);    % N�mero de vari�veis
  x = p;            % Chute inicial
        
  err = Inf;        % Erro precisa ser o maior poss�vel no come�o
  itr = 0;          % Contador n�mero de itera��es
  
  while itr < maxItr && err > maxErr    % Condi��es de parada
    xOld = x;
    
    sum = A(1,2) * xOld(1);
    x(1) = (1/A(1,1)) * (b(1)-sum);
    
    for i = 2:n-1
      sum = A(i,1) + (A(i,i+1) * xOld(i));
      x(i) = (1/A(i,i))*(b(i)-sum);     % Passo no m�todo de Jacobi
    endfor
    
    sum = A(n,1) * xOld(n);
    x(n) = (1/A(n,n)) * (b(n)-sum);
    
    itr = itr+1;
    err = abs(x-xOld)/abs(x);               % Norma do res�duo
  endwhile