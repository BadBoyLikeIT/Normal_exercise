#2018/1/23 class
class Student(object):
	def __init__(self,name):
		self.name = name
		#self.score = score

	def print_score(self):
		print('%s: %s'%(self.name,self.score))
	def get_score(self):
		return self._score

	def set_score(self,value):
		if not isinstance(value,int):
			raise ValueError('score must be an integer!')
		if value < 0 or value >100:
			raise ValueError('score must between 0 to 100!')
		self._score = value

from enum import Enum,unique

@unique
class Weekday(Enum):
		Sun = 0
		Mon = 1
		Tue = 2
		Wed = 3
		Thu = 4
		Fri = 5
		Sat = 6

class Animal(object):
	def run(self):
		print('Animal is running....')
class Dog(Animal):
	def run(self):
		print('Dog is running...')
	def eat(self):
		print('Eating meat...')
class Cat(Animal):
	pass
