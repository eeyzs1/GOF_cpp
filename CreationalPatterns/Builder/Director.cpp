#include "Director.h"


Director::Director(AbstractBuilder* builder)
{
	curBuilder = builder;
}


Director::~Director()
{

}


void Director::construct()
{
	if (!curBuilder)
		return;

	curBuilder->createProduct();
	curBuilder->buildPartA(1);
	curBuilder->buildPartB(2);
	curBuilder->buildPartC(3);
}