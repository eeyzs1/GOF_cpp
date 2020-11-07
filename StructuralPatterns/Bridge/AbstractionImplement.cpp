#include "AbstractionImplement.h"
#include <iostream>

using namespace std;

AbstractionImplement::AbstractionImplement()
{

}


AbstractionImplement::~AbstractionImplement()
{

}


ConcreteAbstractionImplement1::ConcreteAbstractionImplement1()
{

}


ConcreteAbstractionImplement1::~ConcreteAbstractionImplement1()
{

}


void ConcreteAbstractionImplement1::operation()
{
    cout<< "operation from concreteAbstractionImplement1"<<endl;
}


ConcreteAbstractionImplement2::ConcreteAbstractionImplement2()
{

}


ConcreteAbstractionImplement2::~ConcreteAbstractionImplement2()
{

}


void ConcreteAbstractionImplement2::operation()
{
    cout << "operation from concreteAbstractionImplement2" << endl;
}