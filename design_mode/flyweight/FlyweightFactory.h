#pragma once
#include "flyweight.h"
#include <map>
#include <string>
using namespace std;
class FlyweightFactory
{
public:
	FlyweightFactory();
	virtual ~FlyweightFactory();
	Flyweight* getMan(std::string m_str);

private:
	map<string, Flyweight*> pool;
};

