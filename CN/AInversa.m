function X = AInversa (A)
  
  % Encontrando as matrizes L e U de A
  
  [L,U] = LUSemPivo(A);

  % Tamanho da matriz A, usado na função eye para gerar uma matriz identidade
  % de ordem N
  
  [m,n]=size(A);
   
  I = eye(m);
  Y = inv(L) * I;
  X = inv(U) * Y;