<?php

abstract class Beverage
{
    /* @var string */
    protected $description = "Unknown Beverage";

    /* @return string */
    public function getDescription() {
        return $this->description;
    }

    /* @var double */
    public abstract function cost();
}


abstract class CondimentDecorator extends Beverage
{
    /* @return string */
    //public abstract function getDescription();
}


class Espresso extends Beverage
{
    public function __construct() {
        $this->description = "Espresso";
    }

    /* @return double */
    public function cost() {
        return 1.99;
    }
}

class DarkRoast extends Beverage
{
    public function __construct() {
        $this->description = "DarkRoast";
    }

    /* @return double */
    public function cost() {
        return 2.99;
    }
}


class HouseBlend extends Beverage
{
    public function __construct() {
        $this->description = "House Blend Coffee";
    }

    /* @return double */
    public function cost() {
        return .89;
    }
}

class Mocha extends CondimentDecorator
{
    /* @var Beverage */
    private $beverage;

    /* @var Beverage */
    public function __construct($beverage) {
        $this->beverage = $beverage;
    }

    public function getDescription() {
        return $this->beverage->getDescription() . ", Mocha";
    }

    public function cost() {
        return .20 + $this->beverage->cost();
    }
}

class Soy extends CondimentDecorator
{
    /* @var Beverage */
    private $beverage;

    /* @var Beverage */
    public function __construct($beverage) {
        $this->beverage = $beverage;
    }

    public function getDescription() {
        return $this->beverage->getDescription() . ", Soy";
    }

    public function cost() {
        return .29 + $this->beverage->cost();
    }
}

class Whip extends CondimentDecorator
{
    /* @var Beverage */
    private $beverage;

    /* @var Beverage */
    public function __construct($beverage) {
        $this->beverage = $beverage;
    }

    public function getDescription() {
        return $this->beverage->getDescription() . ", Whip";
    }

    public function cost() {
        return .20 + $this->beverage->cost();
    }
}

class StarbuzzCofee
{
    /* @return void */
    public static function main() {
        $beverage = new Espresso();
        echo $beverage->getDescription() . " $" . $beverage->cost() . "<br>";

        $beverage2 = new DarkRoast();
        $beverage2 = new Mocha($beverage2);
        $beverage2 = new Mocha($beverage2);
        $beverage2 = new Whip($beverage2);
        echo $beverage2->getDescription() . " $" . $beverage2->cost() . "<br>";

        $beverage3 = new Whip(new Mocha(new Soy(new HouseBlend())));
        echo $beverage3->getDescription() . " $" . $beverage3->cost() . "<br>";
    }
}

StarbuzzCofee::main();