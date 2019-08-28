%plot(ScopeData.time,ScopeData.signals(2).values)
title('Compare Output Response');
xlabel('time (second)');
ylabel('output (cm)');
plot(ScopeData.time,ScopeData.signals(1).values(:,1),'b')
grid on
hold on
plot(ScopeData.time,ScopeData.signals(1).values(:,2),'r')
plot(xtam,ytam,'g')
legend('set point','y2 output','y2 output old')
xtam=ScopeData.time;
ytam=ScopeData.signals(1).values(:,2);