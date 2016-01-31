# -*- coding: utf-8 -*-

class Subject:

	def register_observer(observer):
		pass

	def remove_observer(observer):
		pass

	def notify_observers():
		pass


class Observer:

	def update(temp, humidity, pressure):
		pass


class DisplayElement:

	def display():
		pass


class WeatherData(Subject):

	_observers = []
	_temperature = 0.0
	_humidity = 0.0
	_pressure = 0.0

	def __init__(self):
		self._observers = []

	def register_observer(self, observer):
		self._observers.append(observer)

	def remove_observer(self, observer):
		try:
			i = self._observers.remove(observer)
		except ValueError:
			pass
	
	def notify_observers(self):
		for observer in self._observers:
			observer.update(self._temperature, self._humidity, self._pressure)

	def measurements_changed(self):
		self.notify_observers()

	def set_mesasurements(self, temperature, humidity, pressure):
		self._temperature = temperature
		self._humidity = humidity
		self._pressure = pressure
		self.measurements_changed()


class CurrentConditionsDisplay(Observer, DisplayElement):

	_temperature = 0.0
	_humidity = 0.0
	_weather_data = None

	def __init__(self, weather_data):
		self._weather_data = weather_data
		weather_data.register_observer(self)

	def update(self, temperature, humidity, pressure):
		self._temperature = temperature
		self._humidity = humidity
		self.display()

	def display(self):
		print("Current conditions: %s F degrees and %s humidity" % (self._temperature, self._humidity))

if __name__ == "__main__":
	weather_data = WeatherData()
	current_display = CurrentConditionsDisplay(weather_data)
	weather_data.set_mesasurements(80, 65, 30.4)
	weather_data.set_mesasurements(72, 25, 31.4)
	weather_data.set_mesasurements(31, 65, 32.4)
