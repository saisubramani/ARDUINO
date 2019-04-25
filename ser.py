import serial
import time

ArduinoSerial = serial.Serial('/dev/ttyUSB0',9600)
#time.sleep(2)

#print(ArduinoSerial.readline())
#print("enter data:")
data = 	input("Enter the DATA:")
print(type(data))

try:
	ArduinoSerial.write(data.encode())
	print("data sent..")
	x = (ArduinoSerial.readline()).decode()
	print ("recieved",x)
except Exception as e:
	print(e)


