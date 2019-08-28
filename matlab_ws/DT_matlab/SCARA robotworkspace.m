close all
clc
thetamin=-pi/2;
thetamax=pi/2;
npoints=1e2;
%dynamic parameter
theta1=linspace(thetamin+pi/2,thetamax+pi/2,npoints);
theta2=linspace(thetamin,thetamax,npoints);

%static constantsl link lengths
a1=1;
a2=1;
%positions
x1=a1*cos(theta1);
y1=a1*sin(theta1);
for m=1:length(theta1),
    for n=1:length(theta2),
        x2(m,n)=a1*cos(theta1(m))+a2*cos(theta1(m)+theta2(n));
        y2(m,n)=a1*sin(theta1(m))+a2*sin(theta1(m)+theta2(n));
    end
end
figure(1);
set(axes,'Fontsize',10);
plot(x2,y2)
