#include "Builder.h"

Product::Product()
{
	partA = 0;
	partB = 0;
	partC = 0;
}

Product::~Product()
{

}


void Product::setPartA(int param)
{
	partA = param;
}


void Product::setPartB(int param)
{
	partB = param;
}


void Product::setPartC(int param)
{
	partC = param;
}


void Product::show()
{
	fprintf(stderr, "partA = %d  partB = %d  partC = %d\n", partA, partB, partC);
}


AbstractBuilder::AbstractBuilder()
{

}


AbstractBuilder::~AbstractBuilder()
{

}


Builder::Builder()
	:curProduct(nullptr)
{

}


Builder::~Builder()
{

}


void Builder::createProduct()
{
	fprintf(stderr, "创建一个产品空壳\n");
	curProduct = new Product();
}


void Builder::buildPartA(int param)
{
	fprintf(stderr, "正在构建产品的A部分\n");
	curProduct->setPartA(param);
}


void Builder::buildPartB(int param)
{
	fprintf(stderr, "正在构建产品的B部分\n");
	curProduct->setPartB(param);
}


void Builder::buildPartC(int param)
{
	fprintf(stderr, "正在构建产品的C部分\n");
	curProduct->setPartC(param);
}


Product* Builder::getProduct()
{
	return curProduct;
}