#include "adptee.h"
#include "adpter.h"
#include "target.h"
using namespace std;

/*
�������Դ����������ƺͱ��뼼�ɳ�Ϊ������ģʽ�������еĽӿ�ת��Ϊ�ͻ������Ľӿ�
��װ�ࣨ����������adpter
�����ߣ���������ࣩ��adptee
�ֳ�Ϊ��װ��wrapper

��ɫ��
target Ŀ����
adpter ��������
adptee ��������
client �ͻ���
*/

void adpter_test(void)
{
	adptee* m_adptee = new adptee();
	target* m_target = new adpter(m_adptee);
	target* m_ori_target = new target();
	m_target->interface_request();
	m_ori_target->interface_request();
}