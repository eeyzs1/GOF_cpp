#include<iostream>
#include<vector>
using namespace std;

class object {
public:
	int value;
	object(int x) :value(x) {};
};

class Iterator {
public:
	virtual object first() = 0;
	virtual object next() = 0;
};

class ConcreteIterator : public Iterator {
public:
	ConcreteIterator(vector<object>& object_vector) {
		this->object_vector = object_vector;
		index = -1;
	}

	object first() {
		return object_vector[0];
	}
	object next() {
		if (index > signed(object_vector.size() - 2))index = 0;
		index += 1;
		return object_vector[index];
	}
	bool hasNext() {
		return (index < signed(object_vector.size() - 1));
	}

private:
	vector<object> object_vector;
	int index;
};

class Aggregate {
public:
	virtual void add(object value)=0;
	virtual void remove(int index) = 0;
	virtual ConcreteIterator* getIterator() = 0;
};

class ConcreteAggregate : public Aggregate {
public:
	void add(object value) {
		object_vector.push_back(value);
	}
	void remove(int index) {
		if (index<0 || index>object_vector.size() - 1)return;
		object_vector.erase(object_vector.begin()+index);
	}
	ConcreteIterator* getIterator() {
		return new ConcreteIterator(object_vector);
	}
private:
	vector<object> object_vector;
};

int main() {
	Aggregate* ag = new ConcreteAggregate();
	ag->add(object(1));
	ag->add(object(2));
	ag->add(object(4));
	ag->add(object(9));

	ConcreteIterator* it = ag->getIterator();

	while (it->hasNext()) {
		cout << it->next().value << endl;
	}
}
