% In numerical analysis, Newton's method (also known as the Newton–Raphson method), named after Isaac Newton and Joseph Raphson, 
% is a method for finding successively better approximations to the roots (or zeroes) of a real-valued function.
% created 6/11/2017

syms x;
%y=x^3-12*x^2+39*x-28;
y=x^5+10*x^3-0.5*x-4;
%start point
x_solved=2;
%define axes range
a=-3;b=2;

while(1)
clf;
xm=a:0.01:b;
%ym=xm.^3-12*xm.^2+39*xm-28;
ym=xm.^5+10*xm.^3-0.5*xm-4;
%48*xm.*(xm+1).^60-(xm+1).^60+1
plot(xm,ym,'b');

%ax=[a b subs(y,a) subs(y,b)]
axis([a b -600 120]);
grid on 
hold on
y_tt=subs(diff(y,x),x_solved)*(xm-x_solved)+subs(y,x_solved);
plot(xm,y_tt,'r')
x_solved=x_solved-subs(y,x_solved)/subs(diff(y,x),x_solved);
x_solved=double(x_solved);
if (subs(y,x_solved)<10^-7)
    xlabel(strcat('done x=',num2str(x_solved)));
    plot(x_solved,subs(y,x_solved),'gx')
    break;
end
title('<Paused> Press a key to continue');
pause
end
