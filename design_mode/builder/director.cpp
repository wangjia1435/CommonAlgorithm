#include "director.h"
#include "stdio.h"


director::director()
{
}


director::~director()
{
}

/*
ConstructBuilder is a construct class,it also replace as abstract class.
and it will more flexiable.
*/
void director::director_action(ConstructBuilder* builder)
{
	builder->buildPartA();
	builder->buildPartB();
	builder->buildPartC();
	printf("director direct over!");
}
