#include <vector>
#include<iostream>
using namespace std;

/*
Component abstract base class.
*/
class Component
{
public:
    //pure virtual function to provide only interface, do nth
    virtual void Operation() = 0;

    // virtual functions to provide interface, have implemetations, do nth
    virtual void Add(Component*) { cout << "Component::Add" << endl; };
    virtual void Remove(int) { cout << "Component::Remove" << endl; };
    virtual Component* GetChild(int index) { cout << "Component::GetChild" << endl; return NULL; };
    virtual ~Component() { cout << "Component::Destructor" << endl; };
protected:
    Component() { cout << "Component::Constuctor" << endl; };
};

//Leaf node:doesnt contains son component, so no Add, Remove GetChaild functions
class Leaf :public Component
{
public:
    //only have to implement Operation()
    virtual void Operation() { cout << "Leaf::Operation" << endl; };
    Leaf() { cout << "Leaf::Consturctor" << endl; };
    ~Leaf() {};
};

//Composite��contains son class
class Composite :public Component
{
public:
    Composite() { cout << "Composite::Consturctor" << endl; };
    ~Composite() {};
    //implement all interfaces
    void Operation() {
        cout << "Composite::Operation" << endl;
        vector<Component*>::iterator iter = this->m_ComVec.begin();
        for (; iter != this->m_ComVec.end(); iter++)
        {
            (*iter)->Operation();
        }
    };
    void Add(Component* com) { this->m_ComVec.push_back(com); };
    void Remove(int index) { 
        if (index < 0 || index > this->m_ComVec.size()-1) return;
        this->m_ComVec.erase(m_ComVec.begin()+index);
    };
    Component* GetChild(int index) {
        if (index < 0 || index > this->m_ComVec.size()-1) return NULL;
            return this->m_ComVec[index];
    };
private:
    //use vector to contain son components here.
    vector<Component*> m_ComVec;
};


int main()
{
    /*
     no matter Leaf or Composite objects: pRoot、pCom implemented Operation interface, so can call Operation() directly
      =>users/clients can use single or composite objects in the same behavors=>consistency
    */
    Composite* pRoot = new Composite();

    //add leaf to composite pRoot
    pRoot->Add(new Leaf());

    Leaf* pLeaf1 = new Leaf();
    Leaf* pLeaf2 = new Leaf();

    cout << "show the meaningless function call from leaves" << endl;
    pLeaf1->Add(pLeaf2);
    pLeaf1->Remove(2);
    pLeaf1->Operation();

    //composite object can do all functions(Add、Remove、GetChild、Operation)。
    Composite* pCom = new Composite();
    
    cout << "add leaves to pCom" << endl;
    pCom->Add(pLeaf1);
    pCom->Add(pLeaf2);
    cout << "pCom call operation" << endl;
    pCom->Operation();

    cout << "pCom remove one child then call operation" << endl;
    pCom->Remove(1);
    pCom->Operation();

    //add pCom to pRoot
    pRoot->Add(pCom);

    //pRoot do operation
    cout << "pRoot call operation" << endl;
    pRoot->Operation();

    cout << "get the child from pCom then call operation" << endl;
    Component* cp = pCom->GetChild(0);
    cp->Operation();



    return 0;
}