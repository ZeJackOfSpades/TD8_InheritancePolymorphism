#ifndef ELECTRICCAR_HPP
#define ELECTRICCAR_HPP

#include "../inc/Car.hpp"

class ElectricCar : public Car
{
private:
	bool breaker;

public:
	ElectricCar();
	ElectricCar(const ElectricCar &ve);

	void start();
	std::string display();

	~ElectricCar();
	
};

#endif