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
    com1 = comment(comment = "yes sir", user_id = 1)
    com2 = comment(comment = "ok sir", user_id = 3)
    com3 = comment(comment = "no sir", user_id = 2)
    session.add(com1)
    session.add(com2)
    session.add(com3)
    session.commit()
