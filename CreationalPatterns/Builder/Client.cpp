#include "Director.h"



int main()
{
	AbstractBuilder* builder = new Builder();
	Director* director = new Director(builder);

	director->construct();

	Product* product = builder->getProduct();
	product->show();
	return 0;
}