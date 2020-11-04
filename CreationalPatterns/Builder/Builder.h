#pragma once
#ifndef _BUILDER_H_
#define _BUILDER_H_

#include <stdio.h>

class Product {
public:
	Product();
	~Product();

	void setPartA(int param);
	void setPartB(int param);
	void setPartC(int param);

	void show();

private:
	int partA;
	int partB;
	int partC;

};


class AbstractBuilder {
public:
	AbstractBuilder();
	virtual ~AbstractBuilder();

	virtual void createProduct() = 0;
	virtual void buildPartA(int param) = 0;
	virtual void buildPartB(int param) = 0;
	virtual void buildPartC(int param) = 0;

	virtual Product* getProduct() = 0;
};


class Builder : public AbstractBuilder {
public:
	Builder();
	~Builder();

	void createProduct();
	void buildPartA(int param);
	void buildPartB(int param);
	void buildPartC(int param);

	Product* getProduct();

private:
	Product* curProduct;

};

#endif
