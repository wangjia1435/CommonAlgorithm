
/*
模式：享元模式（flyweight）
目的：对于大量重复对象不进行创建，节省空间
说明：运用共享技术有效支持大量细粒度对象的复用。
类：
	flyweight（抽象享元类）：在抽象享元类中声明了具体享元类公共的方法，方法可以向外界提供
	    对象的内部数据，也可以通过方法设置外部数据
	ConcreteFlyweight（具体享元类）：实现抽象享元类，在具体类中为内部状态提供了存储空间，
	    可以结合单例模式设计具体享元类，为每个具体享元类提供唯一享元对象
	UnsharedConcreteFlyweight：不能被共享的子类设计为非共享类
	FlyweightFactory（享元工厂类）：创建并管理享元对象，将各种类型的具体享元对象存储在一个
	    享元池中，享元池设计为存储“键值对”集合。结合工厂模式进行设计。
*/
#include "FlyweightFactory.h"
void flyweight_test()
{
	FlyweightFactory* manFactory = new FlyweightFactory();
	Flyweight* yellowMan= manFactory->getMan("yellow");
	yellowMan->showColor();
	yellowMan->showRace();
	Flyweight* blackMan = manFactory->getMan("black");
	blackMan->showColor();
	blackMan->showRace();
	Flyweight* yellowMan1 = manFactory->getMan("yellow");
	yellowMan1->showColor();
	yellowMan1->showRace();
}