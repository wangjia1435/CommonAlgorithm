#include "FlyweightFactory.h"
#include <string.h>
#include "FlyweightBlackMan.h"
#include "FlyweightYellowMan.h"

FlyweightFactory::FlyweightFactory()
{
}


FlyweightFactory::~FlyweightFactory()
{
}


Flyweight* FlyweightFactory::getMan(std::string m_str)
{
	map<string, Flyweight*>::iterator it = pool.find(m_str);
	if (it == pool.end())
	{
		if (m_str == "yellow" or m_str == "YELLOW")
		{
			pool[m_str]= new FlyweightYellowMan();
		}
		else if (m_str == "black" or m_str == "BLACK")
		{
			pool[m_str] = new FlyweightBlackMan();
		}
		else
		{
			return NULL;
		}
	}
	return pool[m_str];
}
