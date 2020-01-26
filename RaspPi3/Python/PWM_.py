import RPi.GPIO as GPIO
from time import sleep

pin = 18
GPIO.setmode(GPIO.BCM)
GPIO.setup(pin, GPIO.OUT)

pwm = GPIO.PWM(pin, 500) #khai bao pwm, pin = 18, tan so 500Hz
pwm.start(0) #bat dau voi duty cycle = 0

try:
	for duty_cycle in range(100):
		pwm.ChangeDutyCycle(duty_cycle) #thay doi duty cycle tu 0 den 100
		sleep(0.1)
		
finally:
	GPIO.cleanup()
