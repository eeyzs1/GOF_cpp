#include <iostream>
#include <vector>
using namespace std;

class Command {
public:
	Command() {};
	~Command() {};
	virtual void execute() = 0;
};

class Receiver {
public:
	Receiver() {};
	~Receiver() {};
	virtual void action() = 0;
};

class Receiver1:public Receiver {
public:
	Receiver1() {};
	~Receiver1() {};
	virtual void action() {
		cout << "This is the action from receiver 1" << endl;
	};
};

class Receiver2:public Receiver {
public:
	Receiver2() {};
	~Receiver2() {};
	virtual void action() {
		cout << "This is the action from receiver 2" << endl;
	};
};

class CompositeReceiver :public Receiver {
public:
	CompositeReceiver() {};
	CompositeReceiver(Receiver* rec) {
		rec_vec.push_back(rec);
	};
	~CompositeReceiver() {};
	void setReceiver(Receiver* rec) {
		rec_vec.push_back(rec);
	}
	virtual void action() {
		cout << "This is the action from Composite receiver" << endl;
		for (auto i: rec_vec) {
			i->action();
		}
	};

private:
	vector<Receiver*> rec_vec;
};

class ConcreteCommand1 :public Command {
public:
	ConcreteCommand1() :Command() {};
	ConcreteCommand1(Receiver* receiver) {
		this->receiver = receiver;
	}
	~ConcreteCommand1() {};
	void execute() {
		cout << "This is comcrete command 1" << endl;
		receiver->action();
	};
private:
	Receiver* receiver;
};

class ConcreteCommand2 :public Command {
public:
	ConcreteCommand2() :Command() {};
	ConcreteCommand2(Receiver* receiver) {
		this->receiver = receiver;
	}
	~ConcreteCommand2() {};
	void execute() {
		cout << "This is comcrete command 2" << endl;
		receiver->action();
	};
private:
	Receiver* receiver;
};

class Invoker {
public:
	Invoker(Command* command) {
		this->command = command;
	}
	~Invoker() {};
	void setCommand(Command* command) {
		this->command = command;
	}
	void call() {
		command->execute();
	} 
private:
	Command* command;
};

class CompositeInvoker {
public:
	CompositeInvoker() {};
	CompositeInvoker(Command* command) {
		this->command_vec.push_back(command);
	}
	~CompositeInvoker() {};
	void addCommand(Command* command) {
		this->command_vec.push_back(command);
	}
	void call() {
		for(auto i:command_vec)
			i->execute();
	}
private:
	vector<Command*> command_vec;
};


int main() {
	Invoker* invoker = new Invoker(new ConcreteCommand1(new Receiver1()));
	invoker->call();

	cout<<"show the composite invoker now"<<endl;
	CompositeInvoker* com = new CompositeInvoker(new ConcreteCommand2(new Receiver1()));
	com->addCommand(new ConcreteCommand1(new Receiver1()));
	com->addCommand(new ConcreteCommand1(new Receiver2()));
	com->addCommand(new ConcreteCommand2(new Receiver2()));
	com->call();
}