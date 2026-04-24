#include <iostream>
using namespace std;

class Person {
public:
    virtual void setData(int a, float b, string c = "") = 0;
    virtual void showData() = 0;
};

class Student : public Person {
private:
    int rollNo;
    float gpa;

public:
    void setData(int r, float g, string c = "") override {
        rollNo = r;
        gpa = g;
    }

    void showData() override {
        cout << "Student Roll No: " << rollNo << endl;
        cout << "GPA: " << gpa << endl;
    }
};

class Lecturer : public Person {
private:
    int empID;
    string department;

public:
    void setData(int id, float dummy, string dept) override {
        empID = id;
        department = dept;
    }

    void showData() override {
        cout << "Employee ID: " << empID << endl;
        cout << "Department: " << department << endl;
    }
};

int main() {
    Person* p1 = new Student();
    Person* p2 = new Lecturer();

    int roll;
    float gpa;

    cout << "--- Enter Student Data ---\n";
    cout << "Enter Roll No: ";
    cin >> roll;
    cout << "Enter GPA: ";
    cin >> gpa;
    p1->setData(roll, gpa);

    int empID;
    string dept;

    cout << "\n--- Enter Lecturer Data ---\n";
    cout << "Enter Employee ID: ";
    cin >> empID;
    cout << "Enter Department: ";
    cin >> dept;
    p2->setData(empID, 0, dept);

    cout << "\n--- Student Record ---\n";
    p1->showData();

    cout << "\n--- Lecturer Record ---\n";
    p2->showData();

    return 0;
}