#include <cstddef>
#pragma once
/*单例模式-在此comand模式中扮演reciver角色 */
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

