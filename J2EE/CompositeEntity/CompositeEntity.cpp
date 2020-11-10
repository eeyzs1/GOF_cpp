#include<iostream>
#include<vector>
#include<list>
using namespace std;

//Composite entity - this is the main entity bean.It can be coarse - grained, 
//or it can contain a coarse - grained object for a lifetime.

//Coarse grained object - this object contains dependent objects.
//It has its own lifecycle and can manage the lifecycle of dependent objects.

//Dependent object - a dependent object is an object that depends on coarse - grained objects for a continuous life cycle.
//Strategies - policies represent how composite entities are implemented.

class DependentObject1 {

private:
    string data;

public:
    void setData(string data) {
        this->data = data;
    }

    string getData() {
        return data;
    }
};

class DependentObject2 {

private:
    string data;

public:
    void setData(string data) {
        this->data = data;
    }

    string getData() {
        return data;
    }
};

class CoarseGrainedObject {
private:
    DependentObject1* do1 = new DependentObject1();
    DependentObject2* do2 = new DependentObject2();

public:
    void setData(string data1, string data2) {
        do1->setData(data1);
        do2->setData(data2);
    }

    string* getData() {
        static string strary[2];
        strary[0] = do1->getData();
        strary[1] = do2->getData();
        return strary;
    }
};

class CompositeEntity {
private:
    CoarseGrainedObject* cgo = new CoarseGrainedObject();

public:
    void setData(string data1, string data2) {
        cgo->setData(data1, data2);
    }

    string* getData() {
        return cgo->getData();
    }
};

class Client {
private:
    CompositeEntity* compositeEntity = new CompositeEntity();

public:
    void printData() {
        string* strary = compositeEntity->getData();
        for (int i = 0; i < 2; i++) {
            cout<<"Data: " <<strary[i]<<endl;
        }
    }

    void setData(string data1, string data2) {
        compositeEntity->setData(data1, data2);
    }
};

int main() {
    Client* client = new Client();
    client->setData("Test", "Data");
    client->printData();
    client->setData("Second Test", "Data1");
    client->printData();
}