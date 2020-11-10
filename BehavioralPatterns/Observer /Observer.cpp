#include<iostream>
#include<list>
using namespace std;

class Observer {
public:
	virtual void response() = 0;
};

class ConcreteObserver1 :public Observer {
public:
	virtual void response() {
		cout<<"observer 1 response to the notification"<<endl;
	};
};

class ConcreteObserver2 :public Observer {
public:
	virtual void response() {
		cout << "observer 2 response to the notification" << endl;
	};
};

class Subject {
public:
	Subject() {};
	~Subject() {};
	void add(Observer* ob) { obs.push_back(ob); }
	virtual void notify() = 0;
	list<Observer*> getObs() { return this->obs; }
private:
	list<Observer*> obs;
};

class ConcreteSubject :public Subject {
public:
	ConcreteSubject() {};
	~ConcreteSubject() {};
	virtual void notify() {
		for (auto i : getObs()) {
			i->response();
	}
	};
};

int main() {
	ConcreteSubject* cs = new ConcreteSubject();
	cs->add(new ConcreteObserver1());
	cs->add(new ConcreteObserver2());
	cs->notify();
}
