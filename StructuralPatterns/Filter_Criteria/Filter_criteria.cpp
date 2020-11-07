#include<iostream>
#include<memory>
#include<list>
#include<algorithm>

using namespace std;

class Person
{
public:
    Person(string name, string gender, string maritalStatus)
    {
        this->_name = name;
        this->_gender = gender;
        this->_maritalStatus = maritalStatus;
    }
    string getName()
    {
        return _name;
    }
    string getGender()
    {
        return _gender;
    }
    string getMaritalStstus()
    {
        return _maritalStatus;
    }
    friend bool operator==(const Person& a, const Person& b)
    {
        if (a._gender == b._gender && a._name == b._name && a._maritalStatus == b._maritalStatus)
            return true;
        else
            return false;
    }
private:
    string _name;
    string _gender;
    string _maritalStatus;
};

class Criteria
{
public:
    virtual shared_ptr<list<Person>> meetCriteria(shared_ptr<list<Person>> persons) = 0;
    virtual ~Criteria() = default;
};

class CriteriaMale :public Criteria
{
    virtual shared_ptr<list<Person>> meetCriteria(shared_ptr<list<Person>> persons) override
    {
        shared_ptr<list<Person>> malePerson = make_shared<list<Person>>();
        for (auto& person : *persons)
        {
            if (person.getGender() == "male")
            {
                malePerson->push_back(person);
            }
        }
        return malePerson;
    }
};

class CriteriaFemale :public Criteria
{
    virtual shared_ptr<list<Person>> meetCriteria(shared_ptr<list<Person>> persons) override
    {
        shared_ptr<list<Person>> femalePerson = make_shared<list<Person>>();
        for (auto& person : *persons)
        {
            if (person.getGender() == "female")
            {
                femalePerson->push_back(person);
            }
        }
        return femalePerson;
    }
};

class CriteriaSingle :public Criteria
{
    virtual shared_ptr<list<Person>> meetCriteria(shared_ptr<list<Person>> persons) override
    {
        shared_ptr<list<Person>> singlePerson = make_shared<list<Person>>();
        for (auto& person : *persons)
        {
            if (person.getMaritalStstus() == "single")
            {
                singlePerson->push_back(person);
            }
        }
        return singlePerson;
    }
};

class AndCriteria :public Criteria
{
public:
    AndCriteria(shared_ptr<Criteria> criteria, shared_ptr<Criteria> othercriteria)
    {
        this->_criteria = criteria;
        this->_othercriteria = othercriteria;
    }
    virtual shared_ptr<list<Person>> meetCriteria(shared_ptr<list<Person>> persons) override
    {
        shared_ptr<list<Person>> firstCriteria = _criteria->meetCriteria(persons);
        return _othercriteria->meetCriteria(firstCriteria);
    }
private:
    shared_ptr<Criteria> _criteria;
    shared_ptr<Criteria> _othercriteria;
};

class OrCriteria :public Criteria
{
public:
    OrCriteria(shared_ptr<Criteria> criteria, shared_ptr<Criteria> othercriteria)
    {
        this->_criteria = criteria;
        this->_othercriteria = othercriteria;
    }
    virtual shared_ptr<list<Person>> meetCriteria(shared_ptr<list<Person>> persons) override
    {
        shared_ptr<list<Person>> firstCriteriaItems = _criteria->meetCriteria(persons);
        shared_ptr<list<Person>> otherCriteriaItems = _othercriteria->meetCriteria(persons);
        for (auto& person : *otherCriteriaItems)
        {
            if (find(firstCriteriaItems->begin(), firstCriteriaItems->end(), person) == firstCriteriaItems->end())
            {
                firstCriteriaItems->push_back(person);
            }
        }
        return firstCriteriaItems;
    }
private:
    shared_ptr<Criteria> _criteria;
    shared_ptr<Criteria> _othercriteria;
};

void printPersons(shared_ptr<list<Person>> persons)
{
    for (auto& person : *persons)
    {
        cout << "Person:[Name:" << person.getName();
        cout << ",Gender:" << person.getGender();
        cout << ",Marital Status:" << person.getMaritalStstus() << "]" << endl;
    }
}

int main()
{
    shared_ptr<list<Person>> persons = make_shared<list<Person>>();

    persons->emplace_back("Robert", "male", "single");
    persons->emplace_back("John", "male", "married");
    persons->emplace_back("Laura", "female", "married");
    persons->emplace_back("Diana", "female", "single");
    persons->emplace_back("Mike", "male", "single");
    persons->emplace_back("Bobby", "male", "single");

    shared_ptr<Criteria> male = make_shared<CriteriaMale>();
    shared_ptr<Criteria> female = make_shared<CriteriaFemale>();
    shared_ptr<Criteria> single = make_shared<CriteriaSingle>();
    shared_ptr<Criteria> singleMale = make_shared<AndCriteria>(single, male);
    shared_ptr<Criteria> singleOrFemale = make_shared<OrCriteria>(single, female);
    shared_ptr<Criteria> singleAndFemale = make_shared<AndCriteria>(single, male);

    cout << "Male:" << endl;
    printPersons(male->meetCriteria(persons));

    cout << "\nFemale:" << endl;
    printPersons(female->meetCriteria(persons));

    cout << "\nSingle Male:" << endl;
    printPersons(singleMale->meetCriteria(persons));

    cout << "\nSingle Or Female:" << endl;
    printPersons(singleOrFemale->meetCriteria(persons));

    cout << "\nSingle And Female:" << endl;
    printPersons(singleAndFemale->meetCriteria(persons));

}