#pragma once
#include "flyweight.h"
class FlyweightBlackMan :
	public Flyweight
{
public:
	FlyweightBlackMan();
	virtual ~FlyweightBlackMan();
	void showColor();
	void showRace();
};

