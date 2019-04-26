#include "abstraction.h"
#include "implementor.h"
#include "bridge_test.h"

/*
����������Ҫ��Բ�Ρ�������ɫ��ɫ���к�ɫ����ɫ����ô�����Բ�죬Բ�̣����죬���̡�
      ��Ȼ���ܼ򵥵ĸ�Բ�죬Բ�̣����죬�����ĸ������������ټ�һ����ɫ������������չ��
	  �ܲ��ˡ����ǽ�ʵ�������ֿ�
˵�������ǽ�ʵ�������ֿ����������Ϲ����������
��˵����
	implementorA,implementorB ʵ����A��B���������̡���ɫ��
	implementor               ʵ�ֻ���(��ɫ��
	abstractionA��abstractionB ������A��B����������״ Բ������
	abstraction                ������ࣨ��״��
	���г����������ʵ������ʵ���Žӣ����
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