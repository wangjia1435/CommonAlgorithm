
/*
说明：根据“单一职责”原则，在软件中将一个系统划分位若干个子系统有利于降低整个
      系统复杂性，使子系统间通信的相互依赖关系达到最小，引入一个外观对象，为子
	  系统提供简单而单一的入口。
      迪米特法则体现：通过引入一个新的外观类降低原有系统复杂度，降低客户类与子系统类
	  的耦合度。

类：
     facade 外观类
	 subsystem 子系统类
*/
#include "facade.h"

void facade_test()
{
	facade* s_facade = new facade();
	s_facade->facadeAction();
}