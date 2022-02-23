function x = SistemaComLU(A,b)
  [L,U] = lu(A);
  d = L\b;
  x = U\d;