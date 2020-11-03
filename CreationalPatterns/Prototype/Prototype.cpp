#include <iostream>
#include <string>
using namespace std;

class Prototype
{
private:
    string str;
public:
    Prototype(string s)
    {
        str = s;
    }
    Prototype()
    {
        str = "";
    }
    void show()
    {
        cout << str << endl;
    }
    void setStr(string str) {
        this->str = str;
    }
    virtual Prototype* clone() = 0;
};

class ConcretePrototype1 :public Prototype
{
public:
    ConcretePrototype1(string s) :Prototype(s)
    {}
    ConcretePrototype1() {}
    virtual Prototype* clone()
    {
        cout << "1 called" << endl;
        ConcretePrototype1* p = new ConcretePrototype1();
        *p = *this;
        return p;
    }
};


class ConcretePrototype2 :public Prototype
{
public:
    ConcretePrototype2(string s) :Prototype(s)
    {}
    ConcretePrototype2() {}
    virtual Prototype* clone()
    {
        cout << "2 called" << endl;
        ConcretePrototype2* p  = new ConcretePrototype2();
        *p = *this;
        return p;
    }
};

int main()
{
    ConcretePrototype1* test = new ConcretePrototype1("ptt1");
    ConcretePrototype2* test2 = (ConcretePrototype2*)test->clone();
    ConcretePrototype2* test5 = (ConcretePrototype2*)test2->clone();//notice:still use ConcretePrototype1's method
    ConcretePrototype2* test3 = new ConcretePrototype2("ptt2");
    ConcretePrototype2* test4 = (ConcretePrototype2*)test3->clone();
    test3->setStr("hello,changed now");
    test->show();
    test2->show();
    test3->show();
    test4->show();
    return 0;
}