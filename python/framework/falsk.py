#!/usr/bin/python3
from flask import Flask
app = Flask(__name__)
@app.route('/')
def hello_world():
    return "<p>no hello! messi is the goat<>"
