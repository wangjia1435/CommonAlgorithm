#include "AddCommand.h"
#include <iostream>


AddCommand::AddCommand(Singlton* __pSinglton)
{
	_pSinglton = __pSinglton;
}


AddCommand::~AddCommand()
{

}

void AddCommand::excute()
{
	std::cout << "acount excute add,surplus";
	std::cout << _pSinglton->add(10) << std::endl;
}

void AddCommand::undo()
{
	std::cout << "acount undo add,surplus";
	std::cout << _pSinglton->sub(10) << std::endl;
}