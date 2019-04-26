#include "cake.h"
#include "decorator.h"


/* 
作用：动态的给对象添加职能，而不改变对象，符合开闭原则
类说明：
componet：需要添加职能对象的抽象基类
concreteComponent：需要添加职能的对象，即被装饰者
decorator：装饰器，抽象类
concreteDecorator：具体附有职能的装饰器

说明：componet作为 ，抽象对象。装饰器和具体被抽象的对象都继承该类，
      装饰器维护着一个被装饰对象的引用，从而达到为该对象添加职能的目的。
*/
void decorator_test(void)
{
	NormalCake* pCake = new NormalCake();
	DecoratorA* pDecoratorCake = new DecoratorA((Cake *)pCake);
	pDecoratorCake->ShowCake();
}