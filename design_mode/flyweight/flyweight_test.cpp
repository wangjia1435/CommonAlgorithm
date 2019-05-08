
/*
ģʽ����Ԫģʽ��flyweight��
Ŀ�ģ����ڴ����ظ����󲻽��д�������ʡ�ռ�
˵�������ù�������Ч֧�ִ���ϸ���ȶ���ĸ��á�
�ࣺ
	flyweight��������Ԫ�ࣩ���ڳ�����Ԫ���������˾�����Ԫ�๫���ķ�������������������ṩ
	    ������ڲ����ݣ�Ҳ����ͨ�����������ⲿ����
	ConcreteFlyweight��������Ԫ�ࣩ��ʵ�ֳ�����Ԫ�࣬�ھ�������Ϊ�ڲ�״̬�ṩ�˴洢�ռ䣬
	    ���Խ�ϵ���ģʽ��ƾ�����Ԫ�࣬Ϊÿ��������Ԫ���ṩΨһ��Ԫ����
	UnsharedConcreteFlyweight�����ܱ�������������Ϊ�ǹ�����
	FlyweightFactory����Ԫ�����ࣩ��������������Ԫ���󣬽��������͵ľ�����Ԫ����洢��һ��
	    ��Ԫ���У���Ԫ�����Ϊ�洢����ֵ�ԡ����ϡ���Ϲ���ģʽ������ơ�
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