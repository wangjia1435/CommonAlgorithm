/*
命令者模式
目的：行为请求者与行为执行者进行松耦合，符合开闭原则。
支持功能：对请求进行排队，可支持撤销功能

功能：将一个请求封装成对象，可以根据不同的请求执行不同动作，对请求进行排队或记录请求日志，可支持撤销动作
场景：烤肉店，顾客下单（command），服务员记录（invoker），厨师接收单据炒菜（reciever）
类：
invoker类：要求该命令执行该请求（具体command类中的执行函数），类似于烤肉场景中的服务员waiter
command类：声明执行操作的接口
concreteCommand：将接收者对象绑定于一个动作，调用接收者相应动作
reciever：知道如何实施执行接收命令的相关操作
*/
#include "AddCommand.h"
#include "Singlton.h"
#include "Invoker.h"
void command_test()
{
	Singlton* pReciver = new Singlton();/*执行者角色 厨师*/

	AddCommand* pAddCmd = new AddCommand(pReciver->getInstance());

	Invoker* pInvoker = new Invoker();/* Waiter角色*/

	pInvoker->push(pAddCmd);
	pInvoker->excute();
	pInvoker->push(pAddCmd);
	pInvoker->excute();
	pInvoker->undo();

}