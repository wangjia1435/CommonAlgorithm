#pragma once
class Command
{
public:
	Command();
	virtual ~Command();
	virtual void excute() = 0;
	virtual void undo() = 0;
};

