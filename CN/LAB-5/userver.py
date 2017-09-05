import socket 

s=socket.socket()
host=socket.gethostname()
port=12345
s.bind((host,port))

message, address = s.recvfrom(1024)
print "Request : " +message


