#include "cake.h"
#include "decorator.h"


/* 
���ã���̬�ĸ��������ְ�ܣ������ı���󣬷��Ͽ���ԭ��
��˵����
componet����Ҫ���ְ�ܶ���ĳ������
concreteComponent����Ҫ���ְ�ܵĶ��󣬼���װ����
decorator��װ������������
concreteDecorator�����帽��ְ�ܵ�װ����

˵����componet��Ϊ ���������װ�����;��屻����Ķ��󶼼̳и��࣬
      װ����ά����һ����װ�ζ�������ã��Ӷ��ﵽΪ�ö������ְ�ܵ�Ŀ�ġ�
*/
void decorator_test(void)
{
	NormalCake* pCake = new NormalCake();
	DecoratorA* pDecoratorCake = new DecoratorA((Cake *)pCake);
	pDecoratorCake->ShowCake();
}