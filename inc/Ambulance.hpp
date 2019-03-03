#ifndef AMBULANCE_HPP
#define AMBULANCE_HPP

#include "../inc/PriorityCar.hpp"

class Ambulance : public PriorityCar
{
public:
	Ambulance(int power, int code);
	Ambulance(Car v, int code);

	std::string display();

	~Ambulance();
	
};