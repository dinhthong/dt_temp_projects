% without theta
% train k-th sample, dont understand why it doesn't work
syms f;
%Define hidden layer activation function:
y_h=(1-exp(-f))/(1+exp(-f));
%Define output layer activation function:
y_out=f;
eta=.4;
thetah=[.6;.3]
thetao=-.4
epsilon=10^-1;
% initial network data
E=epsilon+1;
v1=[thetah(1);2;1];v2=[thetah(2);-1;.5];
v=[v1 v2];
w=[thetao;1;-1];
X=[-.7 .2 1.4;.3 .6 -.9];
X_train=[-ones(1,3);X];
D=[0.8 1.2 1];
K=size(D,2);

while(E>epsilon)
    E=0;
for k=1:K % step 5
   % txt=strcat('Sample thu ',int2str(k));
   % disp(txt);
neth=v'*X_train(:,k);
z=double([-1;subs(y_h,f,neth(1));subs(y_h,f,neth(2))]);
neto=w'*z;
y=double(subs(y_out,f,neto));
%lop ra
deltao=(D(k)-y)*double(subs(diff(y_out,f),f,neto));
w_new=w+eta*deltao*z; % w(k+1)
%lop an
deltah1=deltao*w(1)*double(subs(diff(y_h,f),f,neth(1))); % dealtah1(k+1)
deltah2=deltao*w(2)*double(subs(diff(y_h,f),f,neth(2)));% dealtah2(k+1)
deltah=[deltah1;deltah2];
v_new=v+eta*[deltah1*X_train(:,k),deltah2*X_train(:,k)];
v=v_new;w=w_new;
E=E+0.5*(D(k)-y)^2;
end %end of 1 period training

end