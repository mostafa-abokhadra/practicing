#!/usr/bin/python3
from models.base import base
from sqlalchemy.orm import relationship
from sqlalchemy import String, Column, ForeignKey, Integer
from models.user import user

class comment(base):
    __tablename__ = 'comments'
    comment_id = Column(Integer, primary_key=True, nullable=False, autoincrement=True)
    comment = Column(String(100))
    user_id = Column(Integer, ForeignKey('users.id'), nullable=False)
    user = relationship('user', back_populates='comment')
