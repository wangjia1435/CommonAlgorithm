#include "facade.h"



facade::facade()
{
	m_aSys = new subsystemA();
	m_bSys = new subsystemB();
}


facade::~facade()
{
	delete  m_aSys;
	delete  m_bSys;
}

void facade::facadeAction()
{
	m_aSys->subsystemAaction();
	m_bSys->subsystemBaction();
}