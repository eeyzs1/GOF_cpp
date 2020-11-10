#include<iostream>
#include<list>
using namespace std;

class Element;

class Visitor
{
public:
    virtual void visitA(Element* x) = 0;
    virtual void visitB(Element* x) = 0;
};

class Element
{
public:
    virtual void accept(Visitor* x) = 0;
    virtual void operation() = 0;
};

class ConcreteVisitor1 :public Visitor {
public:
    virtual void visitA(Element* x) {
        cout << "visitor 1 visit the element in appraoch A" << endl;
        x->operation();
    };
    virtual void visitB(Element* x) {
        cout << "visitor 1 visit the element in appraoch B" << endl;
        x->operation();
    };
};

class ConcreteVisitor2 :public Visitor {
public:
    virtual void visitA(Element* x) {
        cout << "visitor 2 visit the element in appraoch A" << endl;
        x->operation();
    };
    virtual void visitB(Element* x) {
        cout << "visitor 2 visit the element in appraoch B" << endl;
        x->operation();
    };
};

class ConcreteElementA :public Element {
public:
    virtual void accept(Visitor* x) { 
        cout << "Element A accepted visitor" << endl;
        x->visitA(this); 
    };
    virtual void operation() {
        cout << "operation to element A" << endl;
    };
};

class ConcreteElementB :public Element {
public:
    virtual void accept(Visitor* x) { 
        cout << "Element B accepted visitor" << endl;
        x->visitB(this); 
    };
    virtual void operation() {
        cout << "operation to element B" << endl;
    };
};

class objectStructure {
public:
    void accept(Visitor* visitor)
    {
        for (auto i:ele_ls)
        {
           i->accept(visitor);
        }
    }
    void add(Element* element)
    {
        ele_ls.push_back(element);
    }

private:
    list<Element*> ele_ls;
};

int main() {
    objectStructure* os = new objectStructure();
    os->add(new ConcreteElementA());
    os->add(new ConcreteElementB());
    Visitor* visitor = new ConcreteVisitor1();
    os->accept(visitor);
    cout << "try new visitor now" << endl;
    Visitor* visitor2= new ConcreteVisitor2();
    os->accept(visitor2);
}

