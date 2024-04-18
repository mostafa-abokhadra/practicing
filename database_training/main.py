#!/usr/bin/python3
from models.user import user
from models.comment import comment
from models.base import engine, base
from sqlalchemy.orm import sessionmaker
from uuid import uuid4
base.metadata.create_all(bind=engine)
Session = sessionmaker(bind=engine)
session = Session()

with engine.connect() as connection:
    user1 = user(
            id = 1,
            name = "mostafa",
            email='yes@gmail.com',
            passwd = 'mostafaf'
            )
    com = comment()
    com.comment = "this is my first comment2"
    com.user_id = 4
    session.add(com)
    session.commit()
