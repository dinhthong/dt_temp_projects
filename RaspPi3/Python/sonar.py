# go to this URL to see the pinouts
#  http://blackconsole.net/2016/06/19/do-khoang-cach-voi-raspberry-pi-dung-cam-bien-sieu-am/
#  Trigger pin directly connects to GPIO18
#  Echo pin - GPIO24 #NOTE the GPIO RPi's level input HIGH is 3V
# import RPi.GPIO as GPIO
import time
import thread
from Tkinter import *
root = Tk()

TRIG_PIN = 18
ECHO_PIN = 24

GPIO.setmode(GPIO.BCM)

GPIO.setup(TRIG_PIN, GPIO.OUT)
GPIO.setup(ECHO_PIN, GPIO.IN)

batdaudo = 0
ketthucdo = 0
thoigiando = 0
khoangcach = 0
hienthi = StringVar()
hienthi.set('0.00')


frame = Frame(root, width=500, height=300)
root.title('RASPI.VN Demo Cam bien sieu am')
frame.grid(row=0, column=0, sticky='NW')
frame.grid_propagate(0)
frame.update()


label = Label(frame, width=500, height=300, textvariable = hienthi)
lbfont = ('times', 20, 'bold')
label.config(font=lbfont)
label.place(x=240,y=150,anchor="center")

#tac vu do khoang cach
def dokhoangcach(ten, chodoi):
	print('bat dau do')
	time.sleep(chodoi)
	#moi giay do 1 lan
	while True:
		#kich hoat cam bien theo muc LOW-HIGH-LOW
		GPIO.output(TRIG_PIN, False)
		#cho 200 ms
		time.sleep(0.2)
		GPIO.output(TRIG_PIN, True)
		#cho 10 micro giay
		time.sleep(0.00001)
		GPIO.output(TRIG_PIN, False)
		
		#chan ECHO duoc keo xuong muc 0 cho toi khi nhan duoc tin hieu phan hoi
    		#ham time() de lay thoi gian hien tai
		batdaudo = time.time()
		while GPIO.input(ECHO_PIN) == 0:
			batdaudo = time.time()
		#co tin hieu phan hoi chan ECHO duoc keo len muc 1, 
		#wait cho den khi nhan duoc het tin hieu phan hoi
		ketthucdo = time.time()
		while GPIO.input(ECHO_PIN) == 1:
			ketthucdo = time.time()
		
		#hoan tat nhan tin hieu phan hoi, tinh khoang thoi gian phan hoi
		thoigiando = ketthucdo - batdaudo

		#van toc sieu am la 344m/s = 34400cm/s
		khoangcach = (thoigiando * 34400)/2
	
		hienthi.set(str(round(khoangcach, 2)) + ' cm')
	
		time.sleep(1)
	

try:
	thread.start_new_thread(dokhoangcach, ('luong 1', 2,))
except:
	print 'loi tao luong'
	sys.exit()

#tac vu hien thi giao dien
root.mainloop()