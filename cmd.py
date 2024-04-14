#!/usr/bin/python3

import os
import cmd

class cmd(cmd.Cmd):
    def do_greet(self, line):
        args = line.split()
        if len(args) == 0:
            print("hello")
        else:
            print(f"hello {args[0]}")
    
    def do_EOF():
        return True

    

interpreter = cmd()
interpreter.cmdloop()
