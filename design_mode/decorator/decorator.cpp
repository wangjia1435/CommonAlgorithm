#include "decorator.h"
#include <iostream>


Decorator::Decorator()
{
}


Decorator::~Decorator()
{
}

DecoratorA::DecoratorA(Cake* pCake)
{
	this->m_pCake = pCake;
}

DecoratorA::~DecoratorA()
{
}

void DecoratorA::ShowCake()
{
	this->m_pCake->name = "DecoratorA  " + this->m_pCake->name;
	std::cout << this->m_pCake->name << std::endl;
}
