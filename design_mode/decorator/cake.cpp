#include "cake.h"
#include <iostream>



Cake::Cake()
{
	name = "Cake";
}


Cake::~Cake()
{
}

NormalCake::NormalCake()
{
	this->name= "NormalCake ";
}

NormalCake::~NormalCake()
{

}

void NormalCake::showCake()
{
	std::cout << "NormalCake  "+name << std::endl;
}