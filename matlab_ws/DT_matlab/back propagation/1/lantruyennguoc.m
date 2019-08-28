%without theta
% train k-th sample
k=1
syms f
%Define hidden layer activation function:
y_h=(1-exp(-f))/(1+exp(-f))
%Define output layer activation function:
y_out=f
eta=.4
v1=[2;1];v2=[-1;.5]
v=[v1 v2]
w=[1;-1]
x=[-.5 .8 1;.4 .2 -.6]
D=[1 0 1]
neth=v'*x(:,k)
z=double([subs(y_h,f,neth(1));subs(y_h,f,neth(2))])
neto=w'*z
y=double(subs(y_out,f,neto))
%lop ra
deltao=(D(k)-y)*double(subs(diff(y_out,f),f,neto))
w_new=w+eta*deltao*z % w(k+1)
%lop an
deltah1=deltao*w(1)*double(subs(diff(y_h,f),f,neth(1))) % dealtah1(k+1)
deltah2=deltao*w(2)*double(subs(diff(y_h,f),f,neth(2)))% dealtah2(k+1)
deltah=[deltah1;deltah2]
v_new=v+eta*[deltah1*x(:,k),deltah2*x(:,k)]