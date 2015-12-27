#include <iostream>

// like an interface

class FlyBehavior 
{
public:
	virtual void fly() = 0;
};


class FlyWithWings : public FlyBehavior
{
public:
	virtual void fly() {
		std::cout << "I'm flying" << std::endl;
	}
};


class FlyNoWay : public FlyBehavior
{
public:
	virtual void fly() {
		std::cout << "I can't fly" << std::endl;
	}
};

class FlyRocketPowered : public FlyBehavior
{
public:
	virtual void fly() {
		std::cout << "I'm flying with a rocket" << std::endl;
	}
};

////////////////////////////////

class QuackBehavior
{
public:
	virtual void quack() = 0;
};

class Quack : public QuackBehavior
{
public:
	virtual void quack() {
		std::cout << "Quack" << std::endl;
	}
};

class MuteQuack : public QuackBehavior
{
public:
	virtual void quack() {
		std::cout << " Silence" << std::endl;
	}
};

////////////////////////////////
class Duck 
{
protected:
	FlyBehavior *flyBehavior;
	QuackBehavior *quackBehavior;
public:
	Duck() {}
	
	virtual void display() = 0;
	
	void performFly() {
		flyBehavior->fly();
	}

	void performQuack() {
		quackBehavior->quack();
	}

	void swim() {
		std::cout << "All ducks float" << std::endl;
	}

	void setFlyBehavior(FlyBehavior *fb) {
		flyBehavior = fb;
	}

	void setQuackBehavior(QuackBehavior *qb) {
		quackBehavior = qb;
	}
};

class MallardDuck : public Duck
{
public:
	MallardDuck() {
		quackBehavior = new Quack();
		flyBehavior = new FlyWithWings();
	}

	virtual void display() {
		std::cout << "I'm a real Mallard Duck" << std::endl;
	}
};

class ModelDuck : public Duck
{
public:
	ModelDuck() {
		flyBehavior = new FlyNoWay();
		quackBehavior = new Quack();
	}

	virtual void display() {
		std::cout << "I'm model duck" << std::endl;
	}
};

////////////////////////////////

int main() {
	Duck *mallard = new MallardDuck();
	mallard->performQuack();
	mallard->performFly();
	delete mallard;

	Duck *model = new ModelDuck();
	model->performFly();
	model->setFlyBehavior(new FlyRocketPowered());
	model->performFly();
	delete model;
	return 0;
}
