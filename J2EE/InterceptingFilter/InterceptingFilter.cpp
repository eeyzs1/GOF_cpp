#include<iostream>
#include<vector>
#include<list>
using namespace std;


//Filter - Filters perform certain tasks before or after the request handler executes the request.
//Filter chain - the filter chain has multiple filters that are executed in the defined order on target.
//Target - the target object is a request handler.
//Filter manager - the filter manager manages filters and filter chains.
//Client - a client is the object that sends a request to a target object.

class Filter {
public:
	virtual void execute(string request)=0;
};

//concrete filters
class AuthenticationFilter :public Filter {
public:
	void execute(string request) {
		cout << "Authenticating request: " << request << endl;
	}
};

class DebugFilter : public Filter {
public:
	void execute(string request) {
		cout << "request log: " << request << endl;
	}
};

class Target {
public:
	void execute(string request) {
		cout<<"Executing request: " << request<<endl;
	}
};

class FilterChain {
private:
	vector<Filter*> filters;
	Target* target;

public:
	void addFilter(Filter* filter) {
		filters.push_back(filter);
	}

	void execute(string request) {
		for (Filter* filter : filters) {
			filter->execute(request);
		}
		target->execute(request);
	}

	void setTarget(Target* target) {
		this->target = target;
	}
};

class FilterManager {
private:
	FilterChain filterChain;

public:
	FilterManager(Target* target) {
		filterChain = FilterChain();
		filterChain.setTarget(target);
	}
	void setFilter(Filter* filter) {
		filterChain.addFilter(filter);
	}

	void filterRequest(string request) {
		filterChain.execute(request);
	}
};

class Client {
private:
	FilterManager* filterManager;

public:
	Client() {};
	void setFilterManager(FilterManager* filterManager) {
		this->filterManager = filterManager;
	}

	void sendRequest(string request) {
		filterManager->filterRequest(request);
	}
};

int main() {
	FilterManager* filterManager = new FilterManager(new Target());
	filterManager->setFilter(new AuthenticationFilter());
	filterManager->setFilter(new DebugFilter());

	Client* client = new Client();
	client->setFilterManager(filterManager);
	client->sendRequest("HOME");
}