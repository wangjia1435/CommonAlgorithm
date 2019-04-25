#pragma once
#ifndef _abstraction_h_
#define _abstraction_h_

class implementor;
class abstraction
{
public:
	abstraction();
	~abstraction();
	virtual void execute()=0;
};

class abstractionA:public abstraction
{
public:
	abstractionA(implementor* imp);
	virtual ~abstractionA();
	void execute();

private:
	implementor* _imp;
};

class abstractionB :public abstraction
{
public:
	abstractionB(implementor* imp);
	virtual ~abstractionB();
	void execute();

private:
	implementor* _imp;
};
#endif