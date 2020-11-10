#include <iostream>
using namespace std;

//Context:Ask for leave
//Abstract Handler
class Handler
{
public:
    Handler() { m_pNextHandler = NULL; }
    virtual ~Handler() {}

    //set next handler
    void SetNextHandler(Handler* successor) { m_pNextHandler = successor; }
    //handle request
    virtual void HandleRequest(int days) = 0;
protected:
    Handler* m_pNextHandler;  //next handler
};


//cocrete handler director
class Director :public Handler
{
public:
    //handle request
    virtual void HandleRequest(int days)
    {
        if (days <= 1)
        {
            cout << "I am the director, can handle 1 day absence. Agree!" << endl;
        }
        else//cant handle then goto next handler
        {
            m_pNextHandler->HandleRequest(days);
        }
    }
};

//cocrete handler manager
class Manager :public Handler
{
public:
    //handle request
    virtual void HandleRequest(int days)
    {
        if (days <= 3)
        {
            cout << "I am the manager, can handle 3 day absence. Agree!" << endl;
        }
        else
        {
            m_pNextHandler->HandleRequest(days);
        }
    }
};

//cocrete handler Boss
class Boss :public Handler
{
public:
    //handle request
    virtual void HandleRequest(int days)
    {
        if (days <= 7)
        {
            cout << "I am the manager, can handle 7 day absence. Agree!" << endl;
        }
        else
        {
            cout << "Your leave is too long. Don't agree!" << endl;
        }
    }
};

//client
int main()
{
    Handler* director = new Director;
    Handler* manager = new Manager;
    Handler* boss = new Boss;

    //setup chain of responsibility
    director->SetNextHandler(manager);
    manager->SetNextHandler(boss);

    director->HandleRequest(1);
    director->HandleRequest(2);
    director->HandleRequest(5);
    director->HandleRequest(8);
    return 0;
}