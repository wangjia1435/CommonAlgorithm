#pragma once
#include <string>
class Cake
{
public:
	Cake();
	virtual ~Cake();
	virtual void showCake() = 0;
	std::string name;
};


class NormalCake
{
public:
	NormalCake();
	virtual ~NormalCake();
	void showCake();
	std::string name;
};
