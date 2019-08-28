fibo(1,1).
fibo(2,1).
fibo(N,F):-N>2,N1 is N-1,N2 is N-2,fibo(N1,F1),fibo(N2,F2),F is F1+F2.
