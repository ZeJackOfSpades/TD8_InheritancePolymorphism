#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>
#include <string>
#include <typeinfo>



class Car
{
protected:
	int power;
	std::string color;
	int speed;
	bool isStarted;
public:
	Car();
	Car(const Car& v);
	void start();
	std::string display();
	void accelerate(int v);

	int getPower()			{return this->power;};
	std::string getColor()	{return this->color;};
	int getSpeed()			{return this->speed;};
	bool getIsStarted()		{return this->isStarted;};

	void setPower(int power)			{this->power = power;};
	void setColor(std::string color)	{this->color = color;};
	void setSpeed(int speed)			{this->speed = speed;};
	void setIsStarted (bool isStarted)	{this->isStarted = isStarted;};

	//~Car();
	
};

#endif