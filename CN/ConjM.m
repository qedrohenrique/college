function x = ConjM()
  C = [2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000];

  for i=1:length(C)
  I = eye(C(i));
  M = randMatrixM(C,i);
  MT = transpose(M);
  xe = randVectorX(C,i);
  A = (MT * M) + I;
  U = chol(A);
  
  b = A*xe;   

  d = U'\b;            %resolve o sistema
  x = U\d   
  endfor