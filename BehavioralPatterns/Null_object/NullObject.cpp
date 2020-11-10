#include<iostream>
#include<vector>
#include<list>
using namespace std;

class AbstractCustomer {
protected:
    string name;
public:
    virtual bool isNil() = 0;
    virtual string getName() = 0;
};

class RealCustomer:public AbstractCustomer {
public:
    RealCustomer(string x) {
        this->name = x;
    };
    virtual bool isNil() {
        return false;
    };
    virtual string getName() {
        return "Real customer";
    };
};

class NullCustomer:public AbstractCustomer {
public:
    NullCustomer() {};
    virtual bool isNil() {
        return true;
    };
    virtual string getName() {
        return "Not Available in Customer Database";
    };
};


class CustomerFactory {
private:
    string names[3] = { "Rob", "Joe", "Julie" };

public:
    AbstractCustomer* getCustomer(string name) {
        for (int i = 0; i < 3; i++) {
            if (!names[i].compare(name)) {
                return new RealCustomer(name);
            }
        }
        return new NullCustomer();
    }
};

int main() {
    CustomerFactory cs =CustomerFactory();
    AbstractCustomer* customer1 = cs.getCustomer("Rob");
    AbstractCustomer* customer2 = cs.getCustomer("Bob");
    AbstractCustomer* customer3 = cs.getCustomer("Julie");
    AbstractCustomer* customer4 = cs.getCustomer("Laura");

    cout<<"Customers"<<endl;
    cout << customer1->getName() << endl;
    cout << customer2->getName() << endl;
    cout << customer3->getName() << endl;
    cout << customer4->getName() << endl;
}
