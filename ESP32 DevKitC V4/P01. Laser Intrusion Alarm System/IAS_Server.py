import socket

s = socket.socket()

s.bind(('server ip',server port)) #Input IP, PORT
s.listen(0)

while True:
    client, aaddr = s.accept()
    while True:
        content = client.recv(31)

        if len(content) == 0:
            break

        else:
            # default utf-8
            decoded_content = content.decode(encoding='utf-8')
            print(decoded_content)
    client.close()
