#include "../inc/PoliceCar.hpp"

/*			RAPPEL
class PoliceCar : public PriorityCar
{
public:
	PoliceCar(int power, int code);
	PoliceCar(const Car& v, int code);

	std::string display();

	~PoliceCar();
	
}; */

PoliceCar::PoliceCar(int power, int code) : PriorityCar(beacon, code){
	this->power =	power;
	this->code 	=	code;
}
PoliceCar::PoliceCar(const PriorityCar& v, int code) : PriorityCar(v){
	this->code 	=	code;
}
