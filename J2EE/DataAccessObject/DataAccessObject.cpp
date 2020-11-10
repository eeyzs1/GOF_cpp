#include<iostream>
#include<vector>
#include<list>
using namespace std;

//Data access object interface - this interface defines the standard operations to be performed on a model object.

//Data access object concrete class - this class implements the above interface.
//This class is responsible for obtaining data from data sources, which can be databases, XML, or other storage mechanisms.

//Model object / value object - simple object that contains get / set methods to store data retrieved by using DAO classes.

class Student {
private:
    string name;
    int rollNo;
public:
    Student(string name, int rollNo) {
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

class StudentDao {
public:
    virtual vector<Student*> getAllStudents()=0;
    virtual Student* getStudent(int rollNo)=0;
    virtual void updateStudent(Student* student)=0;
    virtual void deleteStudent(int index)=0;
};

class StudentDaoImpl:public StudentDao {

private:
    //work as a db
    vector<Student*> students;

public:
    StudentDaoImpl() {
        Student* student1 = new Student("Robert", 0);
        Student* student2 = new Student("John", 1);
        students.push_back(student1);
        students.push_back(student2);
    }
    void deleteStudent(int index) {
        cout << "Student: Roll No " << students[index]->getRollNo()\
            << ", deleted from database" << endl;
        delete students[index];
        students.erase(students.begin()+index);
    }

    vector<Student*> getAllStudents() {
        return students;
    }

    Student* getStudent(int index) {
        return students[index];
    }

    void updateStudent(Student* student) {
        for (auto i : students) {
            if (!i->getName().compare(student->getName())) {
                i->setName(student->getName());
            }
        }
        cout<<"Student: Roll No "<<student->getRollNo()<<", updated in the database"<<endl;
    }
};

int main() {
    StudentDao* studentDao = new StudentDaoImpl();

    //output all students
    for (Student* student : studentDao->getAllStudents()) {
        cout<<"Student: [RollNo : "<< student->getRollNo() << ", Name : " << student->getName() << " ]"<<endl;
    }
    //update student
    Student* student = studentDao->getAllStudents()[0];
    student->setName("Michael");
    studentDao->updateStudent(student);

    //get student to check update
    student=studentDao->getStudent(0);
    cout<<"Student: [RollNo : "<< student->getRollNo() << ", Name : "<< student->getName() + " ]"<<endl;
}