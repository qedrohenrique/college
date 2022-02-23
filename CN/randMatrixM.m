function M = randMatrixM(C,i)
  M = randi([0,1],C(i),C(i));
  for j=1:C(i)
    for k=1:C(i)
      if M(j,k)==0
      M(j,k)=-1;
    endif
    endfor
  endfor