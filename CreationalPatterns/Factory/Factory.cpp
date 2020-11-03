
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


class Factory
{
public:
    virtual Product* createSpecificProduct(void) = 0;
};

class ProductAFactory : public Factory
{
public:
    Product* createSpecificProduct(void)
    {
        return (new ProductA());
    }
};

class ProductBFactory : public Factory
{
public:
    Product* createSpecificProduct(void)
    {
        return (new ProductB());
    }
};


int main(int argc, char** argv)
{
    Factory* factory = new ProductAFactory();
    Product* productA = factory->createSpecificProduct();
    factory = new ProductBFactory();
    Product* productB = factory->createSpecificProduct();
    productA->showInfo();
    productB->showInfo();
    delete factory; delete productA; delete productB;

    return 0;
}



