#ifndef POLICECAR_HPP
#define POLICECAR_HPP

#include "../inc/PriorityCar.hpp"

class PoliceCar : public PriorityCar
{
public:
	PoliceCar(int power, int code);
	PoliceCar(const Car& v, int code);

	std::string display();

	~PoliceCar();
	
};

#endif