import socket 

s=socket.socket()
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR,1)         
host=socket.gethostname()
port=2363
s.connect((host,port))
while True :
	
	c=raw_input("enter request : ")
	s.send(c)
	
	l=s.recv(1024)
	print("S : "+l)

s.close
