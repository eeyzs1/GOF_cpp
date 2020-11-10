#include <iostream>
#include<vector>
using namespace std;

class State {
public:
	virtual void handle() = 0;
};

class ConcreteState1 :public State {
public:
	virtual void handle() {
		cout << "this is the state 1" << endl;
	};
};

class ConcreteState2 :public State {
public:
	virtual void handle() {
		cout << "this is the state 2" << endl;
	};
};

class Context {
public:
	Context() {};
	Context(State* state) {
		this->state = state;
	};
	~Context() {};
	void handle() {
		state->handle();
	}

private:
	State* state;
};

class ShareContext {
public:
	ShareContext() {};
	ShareContext(State* state) {
		this->shareState = state;
	};
	ShareContext(State* state, vector<State*> state_vec) {
		this->shareState=state;
		this->state_vec = state_vec;
	};
	~ShareContext() {};
	void handle() {
		cout << "solve the shared state" << endl;
		this->shareState->handle();
		cout << "solve the specific states" << endl;
		for(auto state:state_vec)
		state->handle();
	}

	void addState(State* state) {
		state_vec.push_back(state);
	}
	void setShareState(State* state) {
		this->shareState = state;
	}

private:
	vector<State*> state_vec;
	State* shareState;
};


int main() {
	Context* con = new Context(new ConcreteState1());
	cout << "single context handling" << endl;
	con->handle();

	ShareContext* shCon = new ShareContext(new ConcreteState2());
	shCon->addState(new ConcreteState1());
	shCon->addState(new ConcreteState2);
	shCon->addState(new ConcreteState2());
	shCon->handle();
}
