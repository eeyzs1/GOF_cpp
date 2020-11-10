#include<iostream>
#include<vector>
#include<list>
using namespace std;

//front controller - a single handler that processes all types of requests from an application, 
//which can be a web - based application or a desktop based application.
//dispatcher - the front - end controller may use a scheduler object to schedule requests to a specific handler.
//view - a view is an object created for a request.

class Homeview {
public:
    void show() {
        cout << "displaying home page" << endl;
    }
};

class Studentview {
public:
    void show() {
        cout << "displaying student page" << endl;
    }
};

class Dispatcher {
private:
    Studentview* studentview;
    Homeview* homeview;
public:
    Dispatcher() {
        studentview = new Studentview();
        homeview = new Homeview();
    }

    void dispatch(string request) {
        if (!request.compare("student")) {
            studentview->show();
        }
        else {
            homeview->show();
        }
    }
};

class Frontcontroller {

private:
    Dispatcher* dispatcher;

    bool isauthenticuser() {
        cout<<"user is authenticated successfully."<<endl;
        return true;
    }

    void trackrequest(string request) {
        cout<<"page requested: " << request<<endl;
    }

public:
    Frontcontroller() {
        dispatcher = new Dispatcher();
    }

    void dispatchrequest(string request) {
        trackrequest(request);
        if (isauthenticuser()) {
            dispatcher->dispatch(request);
        }
    }
};

int main() {
    Frontcontroller* frontcontroller = new Frontcontroller();
    frontcontroller->dispatchrequest("home");
    frontcontroller->dispatchrequest("student");
}