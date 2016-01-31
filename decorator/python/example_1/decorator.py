# -*- coding: utf-8 -*-

class Beverage:
    def __init__(self):
        self._description = "Unknown beverage"

    def get_description(self):
        return self._description

    def cost(self):
        pass


class CondimentDecorator(Beverage):

    def get_description(self):
        return None


# Beverages

class Espresso(Beverage):

    def __init__(self):
        self._description = "Espresso"

    def cost(self):
        return 1.99


class HouseBlend(Beverage):

    def __init__(self):
        self._description = "House Blend Coffee"

    def cost(self):
        return .89

class DarkRoast(Beverage):

    def __init__(self):
        self._description = "Dark Roast Coffee"

    def cost(self):
        return 1.99


class Decaf(Beverage):

    def __init__(self):
        self._description = "Decaf Coffee"

    def cost(self):
        return .89

# decorators
class Mocha(CondimentDecorator):

    def __init__(self, beverage_):
        self._beverage = beverage_
        self._description = "Mocha"

    def get_description(self):
        return self._beverage.get_description() + ", " + self._description

    def cost(self):
        return .20 + self._beverage.cost()

class Soy(CondimentDecorator):

    def __init__(self, beverage_):
        self._beverage = beverage_
        self._description = "Soy"

    def get_description(self):
        return self._beverage.get_description() + ", " + self._description

    def cost(self):
        return .35 + self._beverage.cost()


class Whip(CondimentDecorator):

    def __init__(self, beverage_):
        self._beverage = beverage_
        self._description = "Whip"

    def get_description(self):
        return self._beverage.get_description() + ", " + self._description

    def cost(self):
        return .45 + self._beverage.cost()


def main():
    beverage = Espresso()
    print(beverage.get_description() +" $" + str(beverage.cost()))

    beverage2 = DarkRoast()
    beverage2 = Mocha(beverage2)
    beverage2 = Mocha(beverage2)
    beverage2 = Whip(beverage2)
    print(beverage2.get_description() +" $" + str(beverage2.cost()))

    beverage3 = HouseBlend()
    beverage3 = Soy(beverage3)
    beverage3 = Mocha(beverage3)
    beverage3 = Whip(beverage3)
    print(beverage3.get_description() +" $" + str(beverage3.cost()))


if __name__ == "__main__":
    main()
