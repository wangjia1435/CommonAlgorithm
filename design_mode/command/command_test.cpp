/*
������ģʽ
Ŀ�ģ���Ϊ����������Ϊִ���߽�������ϣ����Ͽ���ԭ��
֧�ֹ��ܣ�����������Ŷӣ���֧�ֳ�������

���ܣ���һ�������װ�ɶ��󣬿��Ը��ݲ�ͬ������ִ�в�ͬ����������������Ŷӻ��¼������־����֧�ֳ�������
����������꣬�˿��µ���command��������Ա��¼��invoker������ʦ���յ��ݳ��ˣ�reciever��
�ࣺ
invoker�ࣺҪ�������ִ�и����󣨾���command���е�ִ�к������������ڿ��ⳡ���еķ���Աwaiter
command�ࣺ����ִ�в����Ľӿ�
concreteCommand���������߶������һ�����������ý�������Ӧ����
reciever��֪�����ʵʩִ�н����������ز���
*/
#include "AddCommand.h"
#include "Singlton.h"
#include "Invoker.h"
void command_test()
{
	Singlton* pReciver = new Singlton();/*ִ���߽�ɫ ��ʦ*/

	AddCommand* pAddCmd = new AddCommand(pReciver->getInstance());

	Invoker* pInvoker = new Invoker();/* Waiter��ɫ*/

	pInvoker->push(pAddCmd);
	pInvoker->excute();
	pInvoker->push(pAddCmd);
	pInvoker->excute();
	pInvoker->undo();

}