#ifndef adpter_h 
#define adpter_h



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

