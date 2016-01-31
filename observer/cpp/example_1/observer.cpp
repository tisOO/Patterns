#include <iostream>
#include <vector>

// like an interface in JAVA
class Observer
{
public:
  virtual void update(float temp, float humidity, float pressure) = 0;
};

class Subject
{
public:
  virtual void registerObserver(Observer* o) = 0;
};

class DisplayElement
{
public:
  virtual void display() = 0;
};

class WeatherData: public Subject
{
private:
  std::vector<Observer*> observers;
  float temperature;
  float humidity;
  float pressure;

public:
  WeatherData() {
  }

  virtual void registerObserver(Observer* o) {
    this->observers.push_back(o);
  }

  void removeObserver(Observer* o) {
    // @todo
  }

  void notifyObservers() {
    for (auto observer : this->observers) {
      observer->update(temperature, humidity, pressure);
    }
  }

  void measurementsChanged() {
    this->notifyObservers();
  }

  void setMeasurements(float temperature_, float humidity_, float pressure_) {
    this->temperature = temperature_;
    this->humidity = humidity_;
    this->pressure = pressure_;
    this->measurementsChanged();
  }

  // other methods
};

class CurrentConditionsDisplay: public Observer, public DisplayElement
{
private:
  float temperature;
  float humidity;
  Subject* weatherData;

public:
  CurrentConditionsDisplay(Subject* weatherData_) {
    this->weatherData = weatherData_;
    weatherData->registerObserver(this);
  }

  virtual void update(float temperature_, float humidity_, float pressure_) {
    this->temperature = temperature_;
    this->humidity = humidity_;
    this->display();
  }

  virtual void display() {
    std::cout << "Current condititions: " << this->temperature
              << "C degrees and " << this->humidity << "% humidity"
              << std::endl;
  }
};

int main() {
  WeatherData* weatherData = new WeatherData();
  CurrentConditionsDisplay* currentDisplay =
    new CurrentConditionsDisplay(weatherData);
  weatherData->setMeasurements(80, 65, 30.4f);
  delete currentDisplay;
  delete weatherData;
  return 0;
}
