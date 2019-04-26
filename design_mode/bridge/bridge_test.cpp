#include "abstraction.h"
#include "implementor.h"
#include "bridge_test.h"

/*
场景：假设要对圆形、方型上色，色彩有红色，蓝色。那么有组合圆红，圆绿，方红，方绿。
      当然不能简单的搞圆红，圆绿，方红，方绿四个类出来。如果再加一个紫色，这样代码扩展就
	  很差了。考虑将实现与抽象分开
说明：考虑将实现与抽象分开，类进行组合关联，来设计
类说明：
	implementorA,implementorB 实现类A，B（类似与绿、红色）
	implementor               实现基类(颜色）
	abstractionA，abstractionB 抽象类A，B（类似与形状 圆、方）
	abstraction                抽象基类（形状）
	其中抽象类关联了实现类来实现桥接，组合
*/

void bridge_test(void)
{
	implementor* red = new implementorA();
	implementor* blue = new implementorB();

	abstraction* cycle_red = new abstractionA(red);
	abstraction* cycle_blue = new abstractionA(blue);

	abstraction* square_red = new abstractionB(red);
	abstraction* square_blue = new abstractionB(blue);

	cycle_red->execute();
	cycle_blue->execute();
	square_red->execute();
	square_blue->execute();
}