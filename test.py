#!/usr/bin/python3

file = open("messi.txt", mode="a", encoding="utf-8")
for i in range(10):
    file.write(str(i))
file.close()
