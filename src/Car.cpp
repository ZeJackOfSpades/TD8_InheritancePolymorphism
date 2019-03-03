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