#ifndef adpter_h 
#define adpter_h

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

#include "target.h"
#include "adptee.h"
class adpter :public target
{
public:
	adpter(adptee* _adptee);
	virtual ~adpter();

	void interface_request(void);

private:
	adptee* m_adptee;

};
#endif

