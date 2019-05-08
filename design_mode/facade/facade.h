#pragma once
#include "subsystemA.h"
#include "subsystemB.h"
class facade
{
public:
	facade();
	virtual ~facade();
	void facadeAction();
private:
	subsystemA* m_aSys;
	subsystemB* m_bSys;
};

