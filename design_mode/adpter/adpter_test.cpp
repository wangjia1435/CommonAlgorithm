#include "adptee.h"
#include "adpter.h"
#include "target.h"
using namespace std;

/*
类似与电源适配器的设计和编码技巧称为适配器模式，将现有的接口转化为客户期望的接口
包装类（适配器）：adpter
适配者（被适配的类）：adptee
又称为包装器wrapper

角色：
target 目标类
adpter 适配器类
adptee 适配者类
client 客户类
*/

void adpter_test(void)
{
	adptee* m_adptee = new adptee();
	target* m_target = new adpter(m_adptee);
	target* m_ori_target = new target();
	m_target->interface_request();
	m_ori_target->interface_request();
}