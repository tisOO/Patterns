<?php
/***
 * Example from "Head first Design Patterns". Pattern "Strategy"
 *
 *
 ***/
abstract class Duck
{
    public $flyBehavior;
    public $quackBehavior;

    public function __construct()
    {
    }

    abstract public function display();

    public function performFly()
    {
        $this->flyBehavior->fly();
    }

    public function performQuack()
    {
        $this->quackBehavior->quack();
    }

    public function swim()
    {
        echo "All ducks float, even decoys<br />";
    }
}

class MallardDuck extends Duck
{

    public function __construct()
    {
        $this->quackBehavior = new Quacker();
        $this->flyBehavior = new FlyWithWings();
    }

    public function display()
    {
        echo "I'm real Mallard duck<br />";
    }
}

interface FlyBehavior
{
    public function fly();
}

class FlyWithWings implements FlyBehavior
{
    public function fly()
    {
        echo "I'm flying!!<br />";
    }
}

class FlyNoWay implements FlyBehavior
{
    public function fly()
    {
        echo "I can't fly<br />";
    }
}

interface QuackBehavior
{
    public function quack();
}

class Quacker implements QuackBehavior
{
    public function quack()
    {
        echo "Quack<br />";
    }
}

class MuteQuack implements QuackBehavior
{
    public function quack()
    {
        echo "<< Silence >>";
    }
}

class Squeak implements QuackBehavior
{
    public function quack()
    {
        echo "Squeak <br />";
    }
}

$mallard = new MallardDuck();

$mallard->performQuack();
$mallard->performFly();
$mallard->display();

