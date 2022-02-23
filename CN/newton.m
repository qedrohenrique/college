function newton(f, N0)
  syms x
  for i=0:3
    aux = f/diff(f,1,x);
    x_axis = -10:1:10;
    plot(x_axis,aux);
  endfor
