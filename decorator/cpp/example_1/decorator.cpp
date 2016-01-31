#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Beverage
{
protected:
  string description = "Unknown Beverage";
public:

  virtual string getDescription() {
    return this->description;
  }

  virtual double cost() = 0;
};

class CondimentDecorator: public Beverage
{
protected:
  Beverage* beverage;

public:
  virtual string getDescription() = 0;

  ~CondimentDecorator() {
    delete beverage;
  }
};

// Beverages

class Espresso: public Beverage
{
public:
  Espresso() {
    this->description = "Espresso";
  }

  virtual double cost() {
    return 1.99;
  }
};

class HouseBlend: public Beverage
{
public:
  HouseBlend() {
    this->description = "House Blend Coffee";
  }

  virtual double cost() {
    return .89;
  }
};


class DarkRoast: public Beverage
{
public:
  DarkRoast() {
    this->description = "Dark Roast Coffee";
  }

  virtual double cost() {
    return .99;
  }
};

class Decaf: public Beverage
{
public:
  Decaf() {
    this->description = "Decaf Coffee";
  }

  virtual double cost() {
    return .77;
  }
};


// decorators

class Mocha: public CondimentDecorator
{

public:
  Mocha(Beverage* beverage_) {
    this->beverage = beverage_;
  }

  virtual string getDescription() {
    return this->beverage->getDescription() + ", Mocha";
  }

  virtual double cost() {
    return .20 + this->beverage->cost();
  }
};

class Soy: public CondimentDecorator
{

public:
  Soy(Beverage* beverage_) {
    this->beverage = beverage_;
  }

  virtual string getDescription() {
    return this->beverage->getDescription() + ", Soy";
  }

  virtual double cost() {
    return .31 + this->beverage->cost();
  }
};

class Whip: public CondimentDecorator
{

public:
  Whip(Beverage* beverage_) {
    this->beverage = beverage_;
  }

  virtual string getDescription() {
    return this->beverage->getDescription() + ", Whip";
  }

  virtual double cost() {
    return .25 + this->beverage->cost();
  }
};

int main() {
  Beverage* beverage = new Espresso();
  cout << beverage->getDescription() << "$ " << beverage->cost() << endl;
  delete beverage;

  Beverage* beverage2 = new DarkRoast();
  beverage2 = new Mocha(beverage2);
  beverage2 = new Mocha(beverage2);
  beverage2 = new Whip(beverage2);
  cout << beverage2->getDescription() << "$ " << beverage2->cost() << endl;
  delete beverage2;

  Beverage* beverage3 = new DarkRoast();
  beverage3 = new Soy(beverage3);
  beverage3 = new Mocha(beverage3);
  beverage3 = new Whip(beverage3);
  cout << beverage3->getDescription() << "$ " << beverage3->cost() << endl;
  delete beverage3;

  return 0;
}
