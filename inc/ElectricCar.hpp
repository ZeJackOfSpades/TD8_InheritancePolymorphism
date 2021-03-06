#ifndef ELECTRICCAR_HPP
#define ELECTRICCAR_HPP


#include "../inc/Car.hpp"

class ElectricCar : public Car{
	protected:
		bool breaker;

	public:
		ElectricCar();
		ElectricCar(const ElectricCar& ve);

		void start();
		std::string display();

		bool getBreaker()				{return this->breaker;};
		void setBreaker(bool breaker)	{this->breaker = breaker;};


		~ElectricCar();
	
};

#endif