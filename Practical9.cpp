// Define a class Person having name as a data member. Inherit two classes Student and
// Employee from Person. Student has additional attributes as course, marks and year and
// Employee has department and salary. Write display() method in all the three classes to
// display the corresponding attributes. Provide the necessary methods to show runtime
// polymorphism.


#include <iostream>

using namespace std;

// Base class Person
class Person {
protected:
    char name[50];
public:
    Person(const char* _name) {
        int i = 0;
        while (_name[i] != '\0') {
            name[i] = _name[i];
            i++;
        }
        name[i] = '\0';
    }

    virtual void display() const {
        cout << "Name: " << name << endl;
    }
};

// Derived class Student
class Student : public Person {
private:
    char course[50];
    float marks;
    int year;
public:
    Student(const char* _name, const char* _course, float _marks, int _year)
        : Person(_name) {
        int i = 0;
        while (_course[i] != '\0') {
            course[i] = _course[i];
            i++;
        }
        course[i] = '\0';
        marks = _marks;
        year = _year;
    }

    void display() const override {
        cout << "Student Details:" << endl;
        Person::display();
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
        cout << "Year: " << year << endl;
    }
};

// Derived class Employee
class Employee : public Person {
private:
    char department[50];
    float salary;
public:
    Employee(const char* _name, const char* _department, float _salary)
        : Person(_name) {
        int i = 0;
        while (_department[i] != '\0') {
            department[i] = _department[i];
            i++;
        }
        department[i] = '\0';
        salary = _salary;
    }

    void display() const override {
        cout << "Employee Details:" << endl;
        Person::display();
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    // Creating objects of derived classes
    Person* personPtr;
    Student student("Deepali", "Computer Science", 85.5, 2023);
    Employee employee("Pranay", "Human Resources", 50000);

    // Using runtime polymorphism
    personPtr = &student;
    personPtr->display();

    personPtr = &employee;
    personPtr->display();

    return 0;
}
