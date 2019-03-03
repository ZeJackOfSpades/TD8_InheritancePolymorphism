#ifndef PRIORITYCAR_HPP
#define PRIORITYCAR_HPP

#include <exception>

#include "../inc/Car.hpp"

class PriorityCar : public Car
{
private:
	bool beacon;
	int code;
public:
	PriorityCar(bool beacon, int code);
	void startWithCode(int code);
	

	int getCode(){return this->code;};
	bool getBeacon(){return this->beacon;};
	void setCode(int code){this->code = code;};
	void setBeacon(bool beacon){this->beacon = beacon;};

	~PriorityCar();
	
};

#endif