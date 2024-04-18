#!/usr/bin/python
from sqlalchemy.orm import DeclarativeBase
from sqlalchemy import create_engine
engine = create_engine('mysql+mysqldb://root:mostafa@localhost/mostafa')

class base(DeclarativeBase):
    pass

