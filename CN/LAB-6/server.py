import socket            

s = socket.socket()
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR,1)         
host = socket.gethostname() 
port = 2363             
s.bind((host, port))       
s.listen(5)
print "Waiting Client to Join "
c, addr =s.accept();
print "connection Done "
d={}
print "Current Dictionary : ",d
while True  :
	k= c.recv(1024)
	val=k.split()
	if(val[0]=='push'):
		a=int(val[1])
		key=int(val[2])
		if(d.has_key(a)):
			c.send("Key Already Exists")
		else :
			d[a]=key
			c.send(str(key)+" Inserted")
			print "Current Dictionary : ",d
	elif(val[0]=='pull'):
		a=int(val[1])
		if(d.has_key(a)):
			c.send("Key Value at "+str(a)+" is "+str(d[a]))
			
		else :
			c.send("Doesn't Exists")
	elif(val[0]=='del'):
		a=int(val[1])
		if(d.has_key(a)):
			del d[a]
			c.send("Deleted the Key : "+str(a))
			print "Current Dictionary : ",d
		else :
			c.send("Doesn't Exists")
	else :
		c.send("Invalid Keyword")
c.close()
