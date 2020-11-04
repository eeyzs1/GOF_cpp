#include<iostream>

using namespace std;

class Subject {
public:
	Subject() {};
	virtual void Request() = 0;
	~Subject() {};
};


class RealSubject:public Subject
{
	virtual void Request() {
		cout << "Request solved" << endl;
	}
};

class Proxy :public Subject
{
public:
	Proxy()=default;
	Proxy(Subject* subject):Subject() {
		this->subject = subject;
	};
	virtual void Request() {
		cout << "Proxy solving the request" << endl;
		subject->Request();
	}
	~Proxy() {};
private:
	Subject* subject;
};

int main() {
	RealSubject* realSubject = new RealSubject();
	Proxy* proxy = new Proxy(realSubject);
	proxy->Request();

	return 0;
}

