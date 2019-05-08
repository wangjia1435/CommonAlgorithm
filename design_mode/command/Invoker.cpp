#include "Invoker.h"



Invoker::Invoker()
{

}

Invoker::~Invoker()
{
}


void Invoker::push(Command* __pCommand)
{
	_pCommand = __pCommand;
	if (_pCommand != NULL)
	{
		_listCommand.push(_pCommand);
	}
}

void Invoker::excute()
{
	Command* __Command;
	if (_pCommand != NULL)
	{
		__Command=_listCommand.front();
		if (!__Command) { fprintf(stderr, "queue front return null\n"); }
		__Command->excute();
		_lastCommand = __Command;
		_listCommand.pop();
	}
}

void Invoker::undo()
{
	if (_lastCommand!= NULL)
	{
		_lastCommand->undo();
		_lastCommand = NULL;
	}
}