#pragma once
#ifndef director_h
#define director_h
#include "builder.h"
class director
{
public:
	director();
	virtual ~director();

	void director_action(ConstructBuilder* builder);
};

#endif



