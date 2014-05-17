import serial
import time

port = serial.Serial("/dev/ttyACM0", baudrate=38400)

flag = True
port.write("RC 1\r")
port.write("RC 2\r")
port.write("RC 3\r")
i = 0
o = "RO "
c = "RC "
tmp = o+str(i)+'\r'
print tmp
while True:
	i = 0
	while i <= 3:
		if flag==True:
			tmp = o+str(i)+'\r'
		else:
			tmp = c+str(i)+'\r'
		port.write(tmp)
		time.sleep(0.5)
		i+=1
			
	
	flag = ~flag

    
    
