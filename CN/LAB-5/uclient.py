import socket 

s=socket.socket()
host=socket.gethostname()
port=12345
addr = (host, port)
s.sendto("hello",addr)

