function y=test_NN(x,v,w)%Define hidden layer activation function:
syms f
%Define hidden layer activation function:
y_h=(1-exp(-2*f))/(1+exp(-2*f));
%Define output layer activation function:
y_out=1/(1+exp(-f));
neth=v'*x;
z=[-1;double(subs(y_h,f,neth))];
neto=w'*z;
y=double(subs(y_out,f,neto));
end