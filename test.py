#!/usr/bin/python3
import MySQLdb
try:
    connection = MySQLdb.connect("localhost", "root", "mostafa", "mostafa")
    print("connected")
except:
    print("can't connect to database")

curse = connection.cursor()
curse.execute("insert into contact_info (name, call_number) values ('ibrahim', '01154199652');")
curse.execute("select * from contact_info")

arr = curse.fetchall()
connection.close()
print(arr)
