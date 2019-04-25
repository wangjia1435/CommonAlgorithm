#include "implementor.h"
#include <iostream>


implementor::implementor()
{
}


implementor::~implementor()
{
}

implementorA::implementorA()
{
}


implementorA::~implementorA()
{
}

void implementorA::execute()
{
	std::cout << "execute implementorA" << std::endl;
}

implementorB::implementorB()
{
}


implementorB::~implementorB()
{
}

void implementorB::execute()
{
	std::cout << "execute implementorB" << std::endl;
}