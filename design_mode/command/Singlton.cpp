#include "Singlton.h"

Singlton* Singlton::pInstance=nullptr;
unsigned int Singlton::total = 0;
Singlton::Singlton()
{
}


Singlton::~Singlton()
{
}

 Singlton* Singlton::getInstance()
{
	if(pInstance == nullptr)
	{
		pInstance = new Singlton();
	}
	return pInstance;
}

 int Singlton:: add(int a) 
 {
	 total = total + a;
	 return(total);
 }
 int Singlton::sub(int b)  
 {
	 total = total - b;
	 return(total);
 }
