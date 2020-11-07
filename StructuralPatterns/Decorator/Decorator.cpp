#include<iostream>
#include<string>
using namespace std;

class Component
{
public:
    string description = "Basic Component";
    virtual string getDescription() { return description; }
    virtual double cost() = 0;
};

class ConcreteComponent1 :public Component
{
public:
    ConcreteComponent1() { description = "1st Component"; }
    double cost() { return 6; }
    string getDescrition() { return description; }
};

class ConcreteComponent2 :public Component
{
public:
    ConcreteComponent2() { description = "2nd Component"; }
    double cost() { return 6; }
    string getDescrition() { return description; }
};
class ConcreteComponent3 :public Component
{
public:
    ConcreteComponent3() { description = "3rd Component"; }
    double cost() { return 5; }
    string getDescrition() { return description; }
};

class Decorator :public Component
{
public:
    Component* base;
    string getDescription() { return base->getDescription() + ", Decorator"; }
    Decorator(Component* d) { base = d; }
    double cost() = 0;
};

class Decorator1 :public Decorator
{
public:
    string getDescription() { return base->getDescription() + ", decorator1"; }
    Decorator1(Component* d) :Decorator(d) {}
    double cost() { return base->cost() + 1; }
};
class Decorator2 :public Decorator
{
public:
    string getDescription() { return base->getDescription() + ", decorator2"; }
    Decorator2(Component* d) :Decorator(d) {}
    double cost() { return base->cost() + 2; }
};


int main()
{
    Component* com = new ConcreteComponent1();
    Component* decorator = new Decorator1(com);
    cout << decorator->getDescription() << "  $ : " << decorator->cost() << endl;
    return 0;
}