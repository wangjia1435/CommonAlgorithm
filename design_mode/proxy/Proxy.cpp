#include "Proxy.h"
#include "iostream"


Proxy::Proxy(DirectSubject* _dirSubj)
{
	s_dirSubj = _dirSubj;
}


Proxy::~Proxy()
{
}

void Proxy::action()
{
	std::cout << "I am proxy.I was authorized deal the appeal" << std::endl;
	s_dirSubj->action();
}