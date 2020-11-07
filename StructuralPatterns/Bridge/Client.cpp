#include "Abstraction.h"
#include <iostream>


void func() {
    AbstractionImplement* absImp1 = new ConcreteAbstractionImplement1();
    Abstraction* abs1 = new DefinedAbstraction(absImp1);
    abs1->operation();
    delete abs1;

    AbstractionImplement* absImp2 = new ConcreteAbstractionImplement2();
    Abstraction* abs2 = new DefinedAbstraction(absImp2);
    abs2->operation();
    delete abs2;

    abs1 = new DefinedAbstraction(absImp2);
    abs1->operation();
    delete abs1;
}

int main()
{
    func();

    
    return 0;
}