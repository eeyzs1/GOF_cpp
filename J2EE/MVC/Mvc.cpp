#include <iostream>
#include <string>
#include<vector>
#include<list>
using namespace std;


//Model: the object to store and retrieve data, can have the logic to update controller
//View: visulization of data
//Controller:control model and view, control data flow to model object and update view when data changed/seperate view and model

//model
class Student {
private:
    string rollNo;
    string name;
public:
    string getRollNo() {
        return rollNo;
    }
    void setRollNo(string rollNo) {
        this->rollNo = rollNo;
    }
    string getName() {
        return name;
    }
    void setName(string name) {
        this->name = name;
    }
};

class StudentView {
public:
    void printStudentDetails(string studentName, string studentRollNo) {
        cout<<"Student: "<<endl;
        cout << "Name: " + studentName << endl;
        cout<<"Roll No: " + studentRollNo<<endl;
    }
};

class StudentController {
private:
    Student model;
    StudentView view;

public:
    StudentController(Student model, StudentView view) {
        this->model = model;
        this->view = view;
    }

    void setStudentName(string name) {
        model.setName(name);
    }

    string getStudentName() {
        return model.getName();
    }

    void setStudentRollNo(string rollNo) {
        model.setRollNo(rollNo);
    }

    string getStudentRollNo() {
        return model.getRollNo();
    }

    void updateView() {
        view.printStudentDetails(model.getName(), model.getRollNo());
    }
};

static Student retrieveStudentFromDatabase() {
    Student student = Student();
    student.setName("Robert");
    student.setRollNo("10");
    return student;
}

int main() {

    Student model = retrieveStudentFromDatabase();

    StudentView view = StudentView();

    StudentController controller = StudentController(model, view);

    controller.updateView();
    controller.setStudentName("John");
    controller.updateView();
}
