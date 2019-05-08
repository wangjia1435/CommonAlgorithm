#include "FlyweightBlackMan.h"
#include <iostream>



FlyweightBlackMan::FlyweightBlackMan()
{
	std::cout << "create black man" << std::endl;
}


FlyweightBlackMan::~FlyweightBlackMan()
{
}

void FlyweightBlackMan::showColor()
{
	std::cout << "I am black man" << std::endl;
}

void FlyweightBlackMan::showRace()
{
	std::cout << "my race black man"<<std::endl;
}
