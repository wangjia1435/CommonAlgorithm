#pragma once
#include "Command.h"
#include <queue>
#include <string>
class Invoker
{
public:
	Invoker();
	~Invoker();
	void push(Command* __pCommand);
	void excute();
	void undo();
private:
	std::queue<Command*> _listCommand;
	Command* _pCommand;
	Command* _lastCommand;
};

