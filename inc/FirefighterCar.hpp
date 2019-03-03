#ifndef FIREFIGHTERCAR_HPP
#define FIREFIGHTERCAR_HPP 

#include "../inc/PriorityCar.hpp"

class FirefighterCar : public PriorityCar
{
public:
	FirefighterCar(int power, int code);
	FirefighterCar(const Car &v, int code);
	std::string display();

	~FirefighterCar();
	
};



#endif