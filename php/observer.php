<?php
/***
 * Example from "Head first Design Patterns". Pattern "Observe"
 *
 *
 ***/

interface Subject
{
    public function registerObserver(Observer $o);

    public function removeObserver(Observer $o);

    public function notifyObservers();
}

interface Observer
{
    public function update($temp, $himidity, $pressure);
}

interface DisplayElement
{
    public function display();
}

class WeatherData implements Subject
{
    private $observers;
    private $temperature;
    private $humidity;
    private $pressure;

    public function __construct()
    {
        $this->observers = [];
    }

    public function registerObserver(Observer $o)
    {
        $this->observers[] = $o;
    }

    public function removeObserver(Observer $o)
    {
        $i = array_search($o, $this->observers);
        if ($i !== false)
            unset($this->observers[$i]);
    }

    public function notifyObservers()
    {
        foreach ($this->observers as $observe) {
            $observe->update($this->temperature, $this->humidity, $this-> pressure);
        }
    }

    public function measurementsChanged()
    {
        $this->notifyObservers();
    }

    public function setMeasurements($temperature, $humidity, $pressure)
    {
        $this->temperature = $temperature;
        $this->humidity = $humidity;
        $this->pressure = $pressure;
        $this->measurementsChanged();
    }

    // other methods of WeatherData
}


class CurrentConditionDisplay implements Observer, DisplayElement
{
    private $temperature;
    private $humidity;
    private $weatherData;

    public function __construct(Subject $weatherData)
    {
        $this->weatherData = $weatherData;
        $weatherData->registerObserver($this);
    }

    public function update($temperature, $humidity, $pressure)
    {
        $this->temperature = $temperature;
        $this->humidity = $humidity;
        $this->display();
    }

    public function display()
    {
        echo "Current conditions: " . $this->temperature . "F degrees and" . $this->humidity . "% humidity";
    }
}


class WeatherStation
{
    public static function main()
    {
        $weatherData = new WeatherData();
        $currentDisplay = new CurrentConditionDisplay($weatherData);

        $weatherData->setMeasurements(80, 65, 30.4);
        $weatherData->setMeasurements(82, 72, 29.2);
        $weatherData->setMeasurements(78, 90, 29.2);
    }
}

WeatherStation::main();