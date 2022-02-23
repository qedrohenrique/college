function [L,U] = LUSemPivo (A)
  [m,n] = size(A);
  if m ~= n, error('Matriz precisa ser quadrada'); end
  s = 0;
  for j = 1:n
    for i = s+1:m-1
        t = A(i+1,j) / A(j,j);
        A(i+1,:) = A(i+1,:) - t * A(j,:);
        f(i+1,j) = t;
    endfor
    s = s+1;
  endfor
  
  U = A;
  L = f; L(:,n)=zeros(n,1);
  for i=1:n
      L(i,i)=1;
  endfor