import socket 

s=socket.socket()
host=socket.gethostname()
port=2361
s.connect((host,port))
while True :
	#print "Request : "
	c=raw_input("C : ")
	s.send(c)
	#print ("Reply form Server: ", s.recv(1024))
	l=s.recv(1024)
	print "S : "+l
s.close
