#!/usr/bin/python3
import json
import os
import csv


class Base:
    __nb_objects = 0
    def __init__(self, id=None):
        if id:
            self.id = id
        else:
            Base.__nb_objects += 1
            self.id = Base.__nb_objects

    @staticmethod
    def to_json_string(list_dictionaries):
        if not list_dictionaries:
            return "[]"
        else:   
            return json.dumps(list_dictionaries)

    @classmethod
    def save_to_file(cls, list_objs):
        name = cls.__name__ + ".json"
        with open(name, "w", encoding="utf-8") as fily:
            if list_objs:
                listy = [inst.to_dictionary() for inst in list_objs]
                json_str = cls.to_json_string(listy)
                fily.write(json_str)
            else:
                fily.write("[]")

    @staticmethod
    def from_json_string(json_string):
        if json_string:
            return json.loads(json_string)

    @classmethod
    def create(cls, **dictionary):
        if cls.__name__ == 'Rectangle':
            dummy = cls(2, 4)
        if cls.__name__ == 'Square':
            dummy = cls(4)
        dummy.update(**dictionary)
        return dummy

    @classmethod
    def load_from_file(cls):
        listy2 = []
        filename = cls.__name__ + ".json"
        if os.path.exists(filename):
            with open(filename, mode='r', encoding='utf-8') as fily:
                file = fily.read()
            listy = cls.from_json_string(file)
            listy2 = []
            for i in range(len(listy)):
                listy2.append(cls.create(**listy[i]))
        return listy2

    @classmethod
    def to_csv(cls, dictionary):
        csvalue = [dictionary[key] for key in dictionary]
        return csvalue

    @classmethod
    def save_to_file_csv(cls, list_objs):
        filename = cls.__name__ + '.csv'
        with open(filename, mode="w") as file:
            obj = csv.writer(file)
            for inst in list_objs:
                obj.writerow(cls.to_csv(inst.to_dictionary()))

    @classmethod
    def load_from_file_csv(cls):
        filename = cls.__name__ + '.csv'
        with open(filename, mode="r", encoding="utf-8") as file:
            obj = csv.reader(file)
            listy = list(obj)
            dictionary = {}
            final_list = []
            for each_list in listy:
                for i in range(len(each_list)):
                    dictionary[cls.attrs[i]] = int(each_list[i])
                final_list.append(cls.create(**dictionary))
                dictionary.clear()
            return final_list
