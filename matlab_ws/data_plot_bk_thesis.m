$ đồ thị position 3D. nhưng chỉ xem mặt phẳng kết quả.
$ 2D pos.
plot(time,px_bf)
hold on
plot(time,py_bf)
grid on
legend('position x','position y')
xlabel('time (microsecond)')
ylabel('position (mm)')

% Vận tốc.
subplot(2,1,1)
plot(time,vel_x_vip)
hold on
plot(time,vx_sp)
legend('velocity x','velocity x setpoint')
xlabel('time(ms)')
ylabel('m/s')
title('velocity x in position hold using px4flow')

subplot(2,1,2)
plot(time,vel_y_vip)
hold on
plot(time,vx_sp)
legend('velocity y','velocity y setpoint')
xlabel('time(ms)')
ylabel('m/s')
title('velocity y in position hold using px4flow')

% rate rpy stabilise and setpoint. dùng subplot.
subplot(3,1,1)
plot(time,rate_rpy0)
hold on
plot(time,rate_rpy_setpoint0)
legend('rate roll','rate roll setpoint')
xlabel('time(ms)')
ylabel('degree/s')
title('rate roll in px4flow hold')

subplot(3,1,2)
plot(time,rate_rpy1)
hold on
plot(time,rate_rpy_setpoint1)
legend('rate pitch','rate pitch setpoint')
xlabel('time(ms)')
ylabel('degree/s')
title('rate pitch in px4flow hold')

subplot(3,1,3)
plot(time,rate_rpy2)
hold on
plot(time,rate_rpy_setpoint2)
legend('rate yaw','rate yaw setpoint')
xlabel('time(ms)')
ylabel('degree/s')
title('rate yaw in px4flow hold')


% rpy dùng subplot
```matlab
subplot(2,1,1)
plot(time,rpy0)
hold on
plot(time,rpy_setpoint0)
legend('roll','roll setpoint')
xlabel('time(ms)')
ylabel('degree')
title('roll in px4flow hold')

subplot(2,1,2)
plot(time,rpy1)
hold on
plot(time,rpy_setpoint1)
legend('pitch','pitch setpoint')
xlabel('time(ms)')
ylabel('degree')
title('pitch in px4flow hold')
```
+ altitude độ cao. ( của hcsr04?? )

