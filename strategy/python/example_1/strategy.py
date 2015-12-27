# -*- coding: utf-8 -*-

#############################################

class Duck:
	_fly_behavior = None;
	_quack_behavior = None;

	def __init__(self):
		pass

	def display(self):
		pass

	def perform_fly(self):
		self._fly_behavior.fly()

	def perform_quack(self):
		self._quack_behavior.quack()

	def swim():
		print("All ducks float")

	@property
	def fly_behavior(self):
	    return self._fly_behavior
	@fly_behavior.setter
	def fly_behavior(self, value):
	    self._fly_behavior = value
	

#############################################

class FlyBehavior:

	def fly(self):
		pass


class FlyWithWings(FlyBehavior):
	
	def fly(self):
		print("I'm flying!")


class FlyNoWay(FlyBehavior):

	def fly(self):
		print("I can't fly")


class FlyRocketPowered(FlyBehavior):

	def fly(self):
		print("I'm flying with rocket")


#############################################

class QuackBehavior:

	def quack(self):
		pass


class Quack(QuackBehavior):

	def quack(self):
		print("Quack")


class MuteQuack(QuackBehavior):

	def quack(self):
		print("Silence")


class Squeak(QuackBehavior):

	def quack(self):
		print("Squeak")


#############################################


class MallardDuck(Duck):

	def __init__(self):
		self._quack_behavior = Quack()
		self._fly_behavior = FlyWithWings()


class ModelDuck(Duck):

	def __init__(self):
		self._fly_behavior = FlyNoWay()
		self._quack_behavior = Quack()

	def display(self):
		print("I'm a model duck")


#############################################

if __name__ == "__main__":
	mallard = MallardDuck()
	mallard.perform_quack()
	mallard.perform_fly()

	model = ModelDuck()
	model.perform_fly()
	model.fly_behavior = FlyRocketPowered()
	model.perform_fly()
