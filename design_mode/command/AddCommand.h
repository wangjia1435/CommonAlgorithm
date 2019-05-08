#pragma once
#include "Command.h"
#include "Singlton.h"
class AddCommand :
	public Command
{
public:
	AddCommand(Singlton* __pSinglton);
	virtual ~AddCommand();
	void excute();
	void undo();

private:
	Singlton* _pSinglton;
};

