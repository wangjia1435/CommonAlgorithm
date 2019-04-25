#ifndef _implementor_h_
#define _implementor_h_
class implementor
{
public:
	implementor();
	~implementor();
	virtual void execute() = 0;
};


class implementorA:public implementor
{
public:
	implementorA();
	virtual ~implementorA();
	void execute();
};


class implementorB:public implementor
{
public:
	implementorB();
	virtual ~implementorB();
	void execute();
};
#endif


