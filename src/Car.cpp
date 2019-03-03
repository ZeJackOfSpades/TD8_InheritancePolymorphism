#include "../inc/Car.hpp"
/* RAPPEL ATTRIUTES

	int power;
	std::string color;
	int speed;
	bool isStarted;

*/
Car::Car(){}

Car::Car(const Car &v){
	this->power 	=	v.power;
	this->color 	= 	v.color;
	this->speed 	= 	v.speed;
	this->isStarted =	v.isStarted;
}
void Car::start(void){
	setIsStarted(true);
}

void Car::accelerate (int v){}

std::string Car::display(){
	return std::to_string(getPower()) + "\n" + getColor() + "\n" +std::to_string(getSpeed()) + std::to_string(getIsStarted());
}


