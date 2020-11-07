#pragma once

class AbstractionImplement
{
public:
    AbstractionImplement();
    virtual ~AbstractionImplement();

    virtual void operation() = 0;
};


class ConcreteAbstractionImplement1 :public AbstractionImplement
{
public:
    ConcreteAbstractionImplement1();
    ~ConcreteAbstractionImplement1();

    void operation();
};

class ConcreteAbstractionImplement2 :public AbstractionImplement
{
public:
    ConcreteAbstractionImplement2();
    ~ConcreteAbstractionImplement2();

    void operation();
};


