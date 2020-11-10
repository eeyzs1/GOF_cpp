#include<iostream>
#include<vector>
#include<list>
using namespace std;


class Memento {
private:
    string state;
public:
    Memento(string state)
    {
        this->state = state;
    }
    void setState(string state)
    {
        this->state = state;
    }
    string getState()
    {
        return state;
    }
};

class Originator {
private:
    string state;
public :
    void setState(string state)
    {
        this->state = state;
    }
    string getState()
    {
        return state;
    }
    Memento* createMemento()
    {
        return new Memento(state);
    }
    void restoreMemento(Memento* m)
    {
        this->setState(m->getState());
    }
};

class Caretaker {
private:
    Memento* memento;
public:
    void setMemento(Memento* m)
    {
        memento = m;
    }
    Memento* getMemento()
    {
        return memento;
    }
};

int main() {
    Originator* org = new Originator();
    Caretaker* cr = new Caretaker();
    org->setState("S0");
    cout<<"initial state" + org->getState()<<endl;
    cr->setMemento(org->createMemento()); //save state     
    org->setState("S1");
    cout << "new state" + org->getState() << endl;
    org->restoreMemento(cr->getMemento()); //restore state
    cout << "restore state" + org->getState() << endl;
}
