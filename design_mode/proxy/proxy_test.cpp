
/* 
说明：为其他对象提供一种代理以控制对这个对象的访问。RealSubjext和
	  Proxy都继承Subject，Proxy对象包含RealSubject对象的指针。

	  与装饰器模式有点类似，代理对象和装饰器对象都会引入一个对象，区别在于代理引入的是子类DirectSubject而
	  抽象类引入的是Component基类

类：
	Subject：RealSubject和Proxy的共同基类
	RealSubject:被代理的对象
	Proxy：代理对象
*/
#include "DirectSubject.h"
#include "Proxy.h"
void proxy_test()
{
	DirectSubject* dirSubject = new DirectSubject();
	Proxy* proxy = new Proxy(dirSubject);
	proxy->action();
}