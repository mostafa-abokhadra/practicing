#!/usr/bin/python3
from sqlalchemy import Column, Integer, String, ForeignKey
from models.base import base
from sqlalchemy.orm import relationship, backref

class user(base):
    __tablename__ = 'users'
    id = Column(Integer, nullable=False, autoincrement=True,primary_key=True, unique=True)
    name = Column(String(50), nullable=False)
    email = Column(String(100), nullable=False, unique=True)
    passwd = Column(String(20), nullable=False)
    comment = relationship('comment', back_populates='user')
