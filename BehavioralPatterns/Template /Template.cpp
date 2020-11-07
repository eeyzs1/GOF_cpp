#include<iostream>

using namespace std;

class AbstractClass
{
public:
	virtual void AbstractMethod1() = 0;
	virtual void AbstractMethod2() = 0;
	void SpecificMethod() { cout << "hi" << endl; };

	virtual void HookMethod1() { cout << "base::hook 1" << endl; };
	virtual bool HookMethod2() { return false; };
	void TemplateMethod() {
		AbstractMethod1();
		AbstractMethod2();
		HookMethod1();
		if (HookMethod2()) {
			SpecificMethod();
		}
	};


	virtual ~AbstractClass() {}
};

class ConcreteClass1 :public AbstractClass
{
public:
	virtual void AbstractMethod1() { cout << "concreteclass 1::ab method 1" << endl; };
	virtual void AbstractMethod2() { cout << "concreteclass 1::ab method 2" << endl; };
	~ConcreteClass1() {}
	virtual bool HookMethod2() { 
		cout<<"concreteclass 1::hook 2"<<endl;
		return true; 
	};
	virtual void HookMethod1() { cout << "concreteclass 1::hook 1" << endl; };
};

class ConcreteClass2 :public AbstractClass
{
public:
	virtual void AbstractMethod1() { cout << "concreteclass 2::ab 1" << endl; };
	virtual void AbstractMethod2() { cout << "concreteclass 2::ab 2" << endl; };
	~ConcreteClass2() {}
	virtual void HookMethod1() { cout << "concreteclass 2::hook 1" << endl; };
};


int main() {
	AbstractClass* con1 = new ConcreteClass1();
	con1->TemplateMethod();

	cout << "next" << endl;

	AbstractClass* con2 = new ConcreteClass2();
	con2->TemplateMethod();
}

