#include "adptee.h"
#include "adpter.h"
#include "target.h"
using namespace std;

void adpter_test(void)
{
	adptee* m_adptee = new adptee();
	target* m_target = new adpter(m_adptee);
	target* m_ori_target = new target();
	m_target->interface_request();
	m_ori_target->interface_request();
}