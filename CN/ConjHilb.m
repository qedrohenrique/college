function ConjHilb()
  
  % A matriz A é encontrada a partir do vetor C
  % basta que se gere um vetor x com as entradas -1 e 1
  % para encontrar um vetor b
  
  C = [2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000];
  for i=1:12
    
    A=hilb(C(i));             % Gera uma matriz de Hilbert a partir do indíce na posição "i" no vetor C
    [L,U] = LUSemPivo(A);
    xe = randVectorX(C,i);     % Gera um vetor com entradas 1 e -1 de forma aleatória
    
    b = A * xe;
    d = L\b;            %resolve o sistema
    x = U\d;
    disp('ERRO X');(norm(x-xe))/norm(xe)
    disp('erro a');(norm((A*x)-b))/norm(b)
  endfor