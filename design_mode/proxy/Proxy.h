#pragma once
#include "Subject.h"
#include "DirectSubject.h"
class Proxy :
	public Subject
{
public:
	Proxy(DirectSubject* _dirSubj);
	virtual ~Proxy();
	void action();

private:
	DirectSubject* s_dirSubj;
};

