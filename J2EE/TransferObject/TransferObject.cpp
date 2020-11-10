#include<iostream>
#include<vector>
#include<list>
using namespace std;


//Business Object: A business service that populates data for a transfer object
//Transfer Object: only methods to set / get properties.
//Client: Clients can send requests or send transport objects to business objects

//transfer object
class StudentVO {
private:
    string name;
    int rollNo;
public:
    StudentVO(string name, int rollNo) {
        this->name = name;
        this->rollNo = rollNo;
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    int getRollNo() {
        return rollNo;
    }

    void setRollNo(int rollNo) {
        this->rollNo = rollNo;
    }
};

class StudentBO {
private:
    //use vector as db
    vector<StudentVO*> students;

public:
    StudentBO() {
        students = vector<StudentVO*>();
        StudentVO* student1 = new StudentVO("Robert", 0);
        StudentVO* student2 = new StudentVO("John", 1);
        students.push_back(student1);
        students.push_back(student2);
    }
    void deleteStudent(int index) {
        cout<<"Student: Roll No " << students[index]->getRollNo() << ", deleted from database"<<endl;
        students.erase(students.begin() + index);
    }

    //retrieve all records of students from db
    vector<StudentVO*> getAllStudents() {
        return students;
    }

    StudentVO* getStudent(int rollNo) {
        return students[rollNo];
    }

    void updateStudent(StudentVO student) {
        students[student.getRollNo()]->setName(student.getName());
        cout<<"Student: Roll No "<< student.getRollNo() << ", updated in the database"<<endl;
    }
};

int main() {
    StudentBO* studentBusinessObject = new StudentBO();
    //output all studnts
    for (StudentVO* student : studentBusinessObject->getAllStudents()) {
        cout<<"Student: [RollNo : "<<student->getRollNo() << ", Name : " << student->getName() << " ]"<<endl;
    }
    //update student
    StudentVO* student = studentBusinessObject->getAllStudents()[0];
    student->setName("Michael");
    studentBusinessObject->updateStudent(*student);
    //retrieve student
    studentBusinessObject->getStudent(0);
    cout<<"Student: [RollNo : "<<student->getRollNo() << ", Name : " << student->getName() << " ]"<<endl;
}
