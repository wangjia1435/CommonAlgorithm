#include "abstraction.h"
#include "implementor.h"
#include <iostream>


abstraction::abstraction()
{
}


abstraction::~abstraction()
{
}

abstractionA::abstractionA(implementor* imp)
{
	this->_imp = imp;
}


abstractionA::~abstractionA()
{
}

void abstractionA::execute()
{
	std::cout << "abstractionA execute" << std::endl;
	_imp->execute();
}

abstractionB::abstractionB(implementor* imp)
{
	this->_imp = imp;
}


abstractionB::~abstractionB()
{
}

void abstractionB::execute(void)
{
	std::cout << "abstractionB execute" << std::endl;
	this->_imp->execute();
}