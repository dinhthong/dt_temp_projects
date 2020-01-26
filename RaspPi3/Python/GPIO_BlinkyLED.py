import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
#25 la descriptive number, ko phai so thu tu
GPIO.setup(25,GPIO.OUT)
while True:
    GPIO.output(25,GPIO.HIGH)
    time.sleep(1)
    GPIO.output(25,GPIO.LOW)
    time.sleep(1)
