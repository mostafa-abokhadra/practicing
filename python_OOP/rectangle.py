#!/usr/bin/python3
"""rectangle module"""
from models.base import Base
"""super class import"""


class Rectangle(Base):
    """rectangle class inherits from base
    """
    attrs = ["id", "width", "height", "x", "y"]
    def __init__(self, width, height, x=0, y=0, id=None):
        self.width = width
        self.height = height
        self.x = x
        self.y = y
        super().__init__(id)

    @property
    def width(self):
        """
        Returns:
            width
        """
        return self.__width

    @width.setter
    def width(self, width):
        """setting width

        args:
            width: width value
        """
        if type(width) is not int:
            raise TypeError("width must be an integer")
        if width <= 0:
            raise ValueError("width must be > 0")
        self.__width = width

    @property
    def height(self):
        """
        Returns:
            height
        """
        return self.__height

    @height.setter
    def height(self, height):
        """setting height

        args:
            height: height
        """
        if type(height) is not int:
            raise TypeError("height must be an integer")
        if height <= 0:
            raise ValueError("height must be > 0")
        self.__height = height

    @property
    def x(self):
        """
        Returns:
            x value
        """
        return self.__x

    @x.setter
    def x(self, x):
        """setting x
        
        args:
            x: x value
        """
        if type(x) is not int:
            raise TypeError("x must be an integer")
        if x < 0:
            raise ValueError("x must be >= 0")
        self.__x = x

    @property
    def y(self):
        """
        Returns:
            y value
        """
        return self.__y

    @y.setter
    def y(self, y):
        """setting y

        args:
            y: y value
        """
        if type(y) is not int:
            raise TypeError("y must be an integer")
        if y < 0:
            raise ValueError("y must be >= 0")
        self.__y = y

    def area(self):
        """
        Returns:
            rec area
        """
        return self.width * self.height

    def display(self):
        """printing rec as #
        """
        for i in range(self.y):
            print()
        for i in range(self.height):
            for l in range(self.x):
                print(' ', end="")
            for j in range(self.width):
                print("#", end="")
            print()

    def update(self, *args, **kwargs):
        """updating attrs values

        args:
            args: list of values
            kwargs: key worded attrs
        """
        if args:
            for i in range(len(args)):
                setattr(self, __class__.attrs[i], args[i])
        else:
            for key in kwargs:
                setattr(self, key, kwargs[key])

    def __str__(self):
        """
        Returns:
            rectangle
        """
        return "[Rectangle] ({}) {}/{} - {}/{}".format(
                self.id, self.x, self.y, self.width, self.height)

    def to_dictionary(self):
        """convert to dictionary
        """
        dictionary = {}
        for attr in self.attrs:
            dictionary[attr] = getattr(self, attr)
        return dictionary
