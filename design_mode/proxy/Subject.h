#pragma once
class Subject
{
public:
	Subject();
	virtual ~Subject();
	virtual void action()=0;
};

