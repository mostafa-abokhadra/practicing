#!/usr/bin/python3
"""square module"""
from models.rectangle import Rectangle
"""importing superclass"""


class Square(Rectangle):
    """sqaur class that inherits from rectangle"""
    def __init__(self, size, x=0, y=0, id=None):
        """initializing attrs

        args:
            size: size of square
            x: horizontal line
            y: vertical line
            id: id
        """
        super().__init__(size, size, x, y, id)
        self.width = size
        self.height = size

    def __str__(self):
        """getting square

        Returns:
            string
        """
        return "[Square] ({}) {}/{} - {}".format(
                self.id, self.x, self.y, self.size)

    @property
    def size(self):
        """
        Returns:
            size
        """
        return self.width

    @size.setter
    def size(self, size):
        """setting size

        args:
            size: size
        """
        self.width = size
        self.height = size

    def update(self, *args, **kwargs):
        """assigns attrs

        args:
            args: list of args
            kwargs: list of keyworded args
        """
        attrs = ["id", "size", "x", "y"]
        if args:
            for i in range(len(args)):
                if i == 1:
                    setattr(self, 'width', args[i])
                    setattr(self, 'height', args[i])
                else:
                    setattr(self, __class__.attrs[i], args[i])
        else:
            for key in kwargs:
                setattr(self, key, kwargs[key])

    def to_dictionary(self):
        """Returns a dictionary"""
        attrs = ['id', 'size', 'x', 'y']
        dicty = {}
        for key in attrs:
            if key == 'size':
                dicty[key] = getattr(self, 'width')
            else:
                dicty[key] = getattr(self, key)
        return dicty
