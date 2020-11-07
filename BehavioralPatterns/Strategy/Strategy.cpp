#include<iostream>

using namespace std;


class Strategy {
public:
	Strategy() {};
	~Strategy() {};

	virtual void strategyMethod() = 0;
};


class ConcreteStrategy1 :public Strategy {
public:
	ConcreteStrategy1() :Strategy() {};
	~ConcreteStrategy1() {};

	virtual void strategyMethod() {
		cout << "this is the special strategy 1" << endl;
	};

};


class ConcreteStrategy2 :public Strategy {
public:
	ConcreteStrategy2() :Strategy() {};
	~ConcreteStrategy2() {};

	virtual void strategyMethod() {
		cout << "this is the special strategy 2" << endl;
	};

};


class Context  {
public:
	Context() { this->strategy = nullptr; };
	Context(Strategy* strategy) { this->strategy = strategy; };
	~Context() { 
		this->strategy->~Strategy();
		delete this->strategy; 
	};

	virtual Strategy* getStrategy() {
		return this->strategy;
	};

	virtual void setStrategy(Strategy* strategy) {
		this->strategy=strategy;
	};

	virtual void strategyethod() {
		this->strategy->strategyMethod();
	};

private:
	Strategy* strategy;

};

int main() {
	Context* con = new Context(new ConcreteStrategy1());
	con->strategyethod();

	con->setStrategy(new ConcreteStrategy2());

	con->strategyethod();
}