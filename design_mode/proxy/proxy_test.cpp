
/* 
˵����Ϊ���������ṩһ�ִ����Կ��ƶ��������ķ��ʡ�RealSubjext��
	  Proxy���̳�Subject��Proxy�������RealSubject�����ָ�롣

	  ��װ����ģʽ�е����ƣ���������װ�������󶼻�����һ�������������ڴ��������������DirectSubject��
	  �������������Component����

�ࣺ
	Subject��RealSubject��Proxy�Ĺ�ͬ����
	RealSubject:������Ķ���
	Proxy���������
*/
#include "DirectSubject.h"
#include "Proxy.h"
void proxy_test()
{
	DirectSubject* dirSubject = new DirectSubject();
	Proxy* proxy = new Proxy(dirSubject);
	proxy->action();
}