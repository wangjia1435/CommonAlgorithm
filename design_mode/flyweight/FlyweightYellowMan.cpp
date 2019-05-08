#include "FlyweightYellowMan.h"
#include <iostream>



FlyweightYellowMan::FlyweightYellowMan()
{
	std::cout << "create yellow man" << std::endl;
}


FlyweightYellowMan::~FlyweightYellowMan()
{
}


void FlyweightYellowMan::showColor()
{
	std::cout << "I am yellow man"<<std::endl;
}

void FlyweightYellowMan::showRace()
{
	std::cout << "my race yellow man"<<std::endl;
}