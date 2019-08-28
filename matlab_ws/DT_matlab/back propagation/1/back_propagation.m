clear all;clc;

X=[1 0 -1;-1 1 0];
D=[.8 .7 .2];
hidden_layer=2;
syms f;
%Define hidden layer activation function:
y_h=(1-exp(-2*f))/(1+exp(-2*f));
%Define output layer activation function:
y_out=1/(1+exp(-f));
%parameters initialization
eta=.3;
epsilon=10^-1;
%[thetah_init,thetao_init,v_init,w_init]= my_init_para(X,hidden_layer);
E=epsilon+1;
%v=[thetah_init;v_init];
%w=[thetao_init;w_init];
v=[.5 .7;.3 .6;-.5 .4];
w=[-.2;-.8;-.3];
X_train=[-ones(1,size(X,2));X];
%size definition
K=size(D,2);
deltah=zeros(hidden_layer,1);
v_new=zeros(size(v));
while(E>epsilon)
    E=0;
for k=1:K % step 5
neth=v'*X_train(:,k);
z=[-1;double(subs(y_h,f,neth))];
neto=w'*z;
y=double(subs(y_out,f,neto));
% output layer
deltao=(D(k)-y)*double(subs(diff(y_out,f),f,neto));
w_new=w+eta*deltao*z; % w(k+1)
% hidden layer
for i=1:hidden_layer
deltah(i)=deltao*w(i+1)*double(subs(diff(y_h,f),f,neth(i)));
v_new(:,i)=v(:,i)+eta*deltah(i)*X_train(:,k);
end
v=v_new
w=w_new
E=E+0.5*(D(k)-y)^2
end %end of 1 sample training
end %end of 1 period training
