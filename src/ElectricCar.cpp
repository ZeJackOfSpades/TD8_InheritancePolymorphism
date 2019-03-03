#include "../inc/ElectricCar.hpp"

/* 			RAPPEL 	
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
	
}; */

ElectricCar::ElectricCar(): Car(){}

std::string ElectricCar::display(){
	Car::display();
	return std::to_string(getBreaker());

}

ElectricCar::ElectricCar(const ElectricCar& ve):Car(ve){
	this->breaker	=	ve.breaker;
}

void ElectricCar::start(){
	if(breaker == false){
		Car::start();
	}else{
		std::cout<<"Breaker must be desactivated before start"<<std::endl;
	}
}