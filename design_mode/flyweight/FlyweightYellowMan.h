#pragma once
#include "flyweight.h"
class FlyweightYellowMan :
	public Flyweight
{
public:
	FlyweightYellowMan();
	virtual ~FlyweightYellowMan();
	void showColor();
	void showRace();
};

