N  = 1000;
T  = 0.01;
Tstop = (N-1)*T;
    
% Tao chuoi tin hieu dien ap dau vao ngau nhien uktt = 0:T:T*(N-1);
tt = 0:T:T*(N-1);
u  = zeros(1,N);
 
u(1:90)    = 1;
u(150:200) = 0.9;
u(270:350) = 0.8;
u(400:440) = 1;
u(480:500) = 0.7;
u(700:750) = 1;
u(800:900) = 0.6;
uk = [tt; u]';
% Chay mo phong mo hinh simulink vua tao o Hinh 6
sim('thu_thap_so_lieu.slx');
 
% Ve tin hieu dau vao - dau ra
plot(tt,u','r',tt,yk,'b')
legend('uk','yk')
 
% Nhan dang doi tuong voi he so quen lamda
Theta = rand(4,N);
P = 1e5*eye(4);
lamda = 0.8;
for i=3:N
  PHI = [-yk(i-1) -yk(i-2) u(i-1) u(i-2)]';
  e = yk(i) - PHI'*Theta(:,i-1);
  L = P*PHI / (lamda + PHI'*P*PHI);
  P = 1/lamda *(P - P*PHI*PHI'*P /(lamda + PHI'*P*PHI));  
  Theta(:,i) = Theta(:,i-1) + L*e;
end
 
% Ve do thi cac he so a1, a2, b1, b2 vua nhan dangfigure;
subplot(2,1,1);
plot(tt,Theta(1,:),'r',tt,Theta(2,:),':r');
legend('a_1','a_2')
grid on
subplot(2,1,2);
plot(tt,Theta(3,:),'b',tt,Theta(4,:),':b')
legend('b_1','b_2');
grid on
 
% Hien thi gia tri Theta cuoi cung
Theta(:,N)
 
 
 