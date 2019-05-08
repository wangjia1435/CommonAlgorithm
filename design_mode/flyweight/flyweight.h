#pragma once
#include <string>
class Flyweight
{
public:
	Flyweight();
	virtual ~Flyweight();

	virtual void showColor()=0;
	virtual void showRace()=0;

};

