#include<iostream>
#include<vector>
#include<list>
using namespace std;

//The client: presentation layer code can be JSP, servlet, or UI java code.
//Business delegate - an entry class for client entities that provides access to business service methods.
//Lookup service - the lookup service object is responsible for obtaining the relevant business 
//implementationand providing the business object access to the business representative object.
//Business Service - business service interface.The entity class of the business service is implemented, 
//and the actual business implementation logic is provided.

class BusinessService {
public:
	virtual void doProcessing()=0;
};

class EJBService: public BusinessService {
public:
	void doProcessing() {
		cout<<"Processing task by invoking EJB Service"<<endl;
	}
};

class JMSService: public BusinessService {
public:
	void doProcessing() {
		cout<<"Processing task by invoking JMS Service"<<endl;
	}
};

class BusinessLookUp {
public:
	BusinessService* getBusinessService(string serviceType) {
		if (!serviceType.compare("EJB")) {
			return new EJBService();
		}
		else {
			return new JMSService();
		}
	}
};

class BusinessDelegate {
private:
	BusinessLookUp* lookupService = new BusinessLookUp();
	BusinessService* businessService;
	string serviceType;

public:
	void setServiceType(string serviceType) {
		this->serviceType = serviceType;
	}

	void doTask() {
		businessService = lookupService->getBusinessService(serviceType);
		businessService->doProcessing();
	}
};

class Client {
private:
	BusinessDelegate* businessService;

public:
	Client(BusinessDelegate* businessService) {
		this->businessService = businessService;
	}

	void doTask() {
		businessService->doTask();
	}
};

int main() {
	BusinessDelegate* businessDelegate = new BusinessDelegate();
	businessDelegate->setServiceType("EJB");

	Client* client = new Client(businessDelegate);
	client->doTask();

	businessDelegate->setServiceType("JMS");
	client->doTask();
}
