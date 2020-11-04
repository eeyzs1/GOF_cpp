#include<iostream>
//just simulate the dynamic proxy, not so rigorous
using namespace std;

class Subject {
public:
	Subject() {};
	virtual void Request() = 0;
	~Subject() {};
};


class RealSubject :public Subject
{
public:
	RealSubject(string tag) :Subject() {
		this->specificTag = tag;
	};
	virtual void Request() {
		cout << "Request solved as "<<specificTag << endl;
	}
private:
	string specificTag;
};

class Proxy :public Subject
{
public:
	Proxy() = default;
	Proxy(Subject* subject) :Subject() {
		this->subject = subject;
	};
	virtual void Request() {
		cout << "Specific Proxy solving the request" << endl;
		subject->Request();
	}
	~Proxy() {};
private:
	Subject* subject;
};

class InvocationHandler {
public:
	InvocationHandler() {};
	virtual Proxy* Invoke(string method) = 0;
	~InvocationHandler() {};
};


class DynamicProxy :public InvocationHandler
{
public:
	DynamicProxy() { proxy = nullptr; };
	DynamicProxy(Proxy* proxy) :InvocationHandler() {
		this->proxy = proxy;
	};
	virtual Proxy* Invoke(string method) {
		cout << "DynamicProxy solving the request" << endl;

		if (method == "sub1") {
			cout << "method 1 did sth to generate proxy1" << endl;
			return new Proxy(new RealSubject("sub1"));
		}
		else if (method == "sub2") {
			cout << "method 2 did sth to generate proxy2" << endl;
			return new Proxy(new RealSubject("sub1"));
		}
		else {
			cout << "other method did sth to generate proxy3" << endl;
			return new Proxy(new RealSubject("sub1"));
		}
	}
	~DynamicProxy() {};
private:
	Proxy* proxy;
};

int main() {

	DynamicProxy* dynamicProxy = new DynamicProxy();
	Proxy* proxy1 = dynamicProxy->Invoke("sub1");
	proxy1->Request();
	Proxy* proxy2 = dynamicProxy->Invoke("sub2");
	proxy2->Request();
	return 0;
}

