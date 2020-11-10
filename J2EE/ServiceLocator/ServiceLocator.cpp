#include<iostream>
#include<vector>
#include<list>
using namespace std;

//Service: The service that actually processes the request.
//Context: initial Context - contains the reference to the needed service
//Service Locator:Service locator is a single point of contact of services through 
//Naming and Directory Interface lookup and caching services
//Cache: Cache references to services so that they can be reused
//Client: A client is an object that calls a service through a servicelocator

class Service {
public:
	virtual string getName() = 0;
	virtual void execute() = 0;
};

class Service1 :public Service {
public:
	void execute() {
		cout << "Executing Service1" << endl;
	}

	string getName() {
		return "SERVICE1";
	}
};

class Service2 :public Service {
public:
	void execute() {
		cout << "Executing Service2" << endl;
	}

	string getName() {
		return "SERVICE2";
	}
};

class InitialContext {
public:
	Service* lookup(string ndiName) {
		if (!ndiName.compare("SERVICE1")) {
			cout << "Looking up and creating a new Service1 object" << endl;
			return new Service1();
		}
		else if (!ndiName.compare("SERVICE2")) {
			cout << "Looking up and creating a new Service2 object" << endl;
			return new Service2();
		}
		return nullptr;
	}
};

class Cache {

private:
	vector<Service*> services;

public:
	Cache() {
		services = vector<Service*>();
	}

	Service* getService(string serviceName) {
		for (Service* service : services) {
			if (!service->getName().compare(serviceName)) {
				cout<<"Returning cached  " << serviceName << " object"<<endl;
				return service;
			}
		}
		return nullptr;
	}

	void addService(Service* newService) {
		bool exists = false;
		for (Service* service : services) {
			if (!service->getName().compare(newService->getName())) {
				exists = true;
			}
		}
		if (!exists) {
			services.push_back(newService);
		}
	}
};

class ServiceLocator {

public:
	static Cache cache;
	static Service* getService(string ndiName) {

		Service* service = cache.getService(ndiName);

		if (service != nullptr) {
			return service;
		}

		InitialContext* context = new InitialContext();
		service = context->lookup(ndiName);
		cache.addService(service);
		return service;
	}
};

Cache ServiceLocator::cache = Cache();

int main() {
	Service* service = ServiceLocator::getService("SERVICE1");
	service->execute();
	service = ServiceLocator::getService("SERVICE2");
	service->execute();
	service = ServiceLocator::getService("SERVICE1");
	service->execute();
	service = ServiceLocator::getService("SERVICE2");
	service->execute();
}
