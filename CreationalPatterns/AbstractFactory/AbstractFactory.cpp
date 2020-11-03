
#include <iostream>
using namespace std;

class Product
{
public:
    virtual void showInfo(void) = 0;
};

class ProductA : public Product
{
public:
    ProductA()
    {
        cout << "ProductA::ProductA()" << endl;
    }
    virtual void showInfo(void)
    {
        cout << "ProductA::showInfo()" << endl;
    }
    ~ProductA()
    {

    }
};

class ProductB : public Product
{
public:
    ProductB()
    {
        cout << "ProductB::ProductB()" << endl;
    }
    virtual void showInfo(void)
    {
        cout << "ProductB::showInfo()" << endl;
    }
    ~ProductB()
    {

    }
};


class HighProduct
{
public:
    virtual void showInfo(void) = 0;
};

class HighProductA : public HighProduct
{
public:
    HighProductA()
    {
        cout << "HighProductA::HighProductA()" << endl;
    }
    virtual void showInfo(void)
    {
        cout << "HighProductA::showInfo()" << endl;
    }
    ~HighProductA()
    {

    }
};

class HighProductB : public HighProduct
{
public:
    HighProductB()
    {
        cout << "HighProductB::HighProductB()" << endl;
    }
    virtual void showInfo(void)
    {
        cout << "HighProductB::showInfo()" << endl;
    }
    ~HighProductB()
    {

    }
};


class Factory
{
public:
    virtual Product* createSpecificProduct(void) = 0;
    virtual HighProduct* createdSpecificHighProduct(void) = 0;
};

class ProductAFactory : public Factory
{
public:
    Product* createSpecificProduct(void)
    {
        return (new ProductA());
    }

    HighProduct* createdSpecificHighProduct(void)
    {
        return (new HighProductA());
    }
};

class ProductBFactory : public Factory
{
public:
    Product* createSpecificProduct(void)
    {
        return (new ProductB());
    }
    HighProduct* createdSpecificHighProduct(void)
    {
        return (new HighProductB());
    }
};


int main(int argc, char** argv)
{
    Factory* factory = new ProductAFactory();
    Product* productA = factory->createSpecificProduct();
    HighProduct* highProductA = factory->createdSpecificHighProduct();
    productA->showInfo();
    highProductA->showInfo();
    delete factory; delete productA; delete highProductA;

    return 0;
}



