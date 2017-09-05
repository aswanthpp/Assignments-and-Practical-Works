import socket            

s = socket.socket()         
host = socket.gethostname() 
port = 2361              
s.bind((host, port))       
s.listen(5)
print "Waiting Client to Join "
c, addr =s.accept();
print "connection Done "
while True  :
	k= c.recv(1024)
	print "C : " + k 
	#print ("from ", addr ) 
	k=raw_input("S : ")
	#print "S : "+k
	c.send(k)
	#c.send("Got Message: " + k)
c.close()
	 
