#include "adpter.h"
#include <iostream>
using namespace std;



adpter::adpter(adptee* _adptee)
{
	m_adptee = _adptee;
}


adpter::~adpter()
{
}

void adpter::interface_request(void)
{
	std::cout<<"excute adptee interface"<<std::endl;
	m_adptee->adptee_request();
}