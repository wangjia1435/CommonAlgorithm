#pragma once
#include "cake.h"
#include <iostream>

class Decorator :
	public Cake
{
public:
	Decorator();
	virtual ~Decorator();
	void showCake() { std::cout << name.c_str() << std::endl; };
	protected: Cake * m_pCake;
};

class DecoratorA :
	public Decorator
{
public:
	DecoratorA(Cake* pCake);
	virtual ~DecoratorA();
	void ShowCake();

protected: Cake* m_pCake;
};

//class DecoratorB :
//	public Decorator
//{
//public:
//	DecoratorB(Cake* pCake);
//	virtual ~DecoratorB();
//	void ShowCake();
//
//protected: Cake* m_pCake;
//};

