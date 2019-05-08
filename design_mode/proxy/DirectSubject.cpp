#include "DirectSubject.h"
#include "iostream"


DirectSubject::DirectSubject()
{
}


DirectSubject::~DirectSubject()
{
}

void DirectSubject::action()
{
	std::cout << "I will appeal" << std::endl;
}