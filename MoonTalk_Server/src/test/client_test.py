#!/usr/bin/python3

import socket

if __name__ == "__main__":
    count = 0
    cli = []
    while(count < 200):
        cli.append(socket.socket())
        cli[count].connect(("192.168.31.128", 8000))
        count = count + 1