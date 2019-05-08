#pragma once
#include "Subject.h"
class DirectSubject :
	public Subject
{
public:
	DirectSubject();
	virtual ~DirectSubject();
	void action();
};

