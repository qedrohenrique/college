function x = randVectorX(C,i)
  x = randi([0,1],C(i),1);
  for j=1:C(i)
    if x(j,:)==0
      x(j,:)=-1;
    endif
  endfor