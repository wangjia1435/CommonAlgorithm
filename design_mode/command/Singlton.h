#include <cstddef>
#pragma once
/*����ģʽ-�ڴ�comandģʽ�а���reciver��ɫ */
class Singlton
{
public:
	Singlton();
	~Singlton();

	static Singlton* getInstance();
	int add(int a);
	int sub(int b);
private:
	static Singlton* pInstance;

	static unsigned int total;


};

