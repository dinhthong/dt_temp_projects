from Tkinter import *       
import RPi.GPIO as GPIO
import time

pin = 18
GPIO.setmode(GPIO.BCM)
GPIO.setup(pin, GPIO.OUT)

pwm = GPIO.PWM(pin, 500)
pwm.start(0)

class App:
        
    def __init__(self, master):
        frame = Frame(master)
        frame.pack()
        
        Label(frame, text='Do Sang').grid(row=0, column=0)
        
        scaleRed = Scale(frame, length=500, from_=0, to=100, orient=HORIZONTAL, command=self.tanggiam)
        scaleRed.grid(row=0, column=1)
    
    def tanggiam(self,duty):
        pwm.ChangeDutyCycle(duty)

root = Tk()
root.wm_title('RasPi.vn-Dieu Khien Do Sang LED')
app = App(root)
root.geometry("600x100+0+0")
try:
    root.mainloop()
finally:  
    GPIO.cleanup()
