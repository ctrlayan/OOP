#include <iostream>
#include <string>
using namespace std;

//BASE CLASS
class Person {
protected:
    string name;
    int age;

public:
    void setPerson(string n, int a);
    string getName();
    int getAge();
};

void Person::setPerson(string n, int a) {
    name = n;
    age = a;
}

string Person::getName() {
    return name;
}

int Person::getAge() {
    return age;
}

//STUDENT
class Student : public Person {
private:
    string program;

public:
    void setStudent(string n, int a, string p);
    string getProgram();
};

void Student::setStudent(string n, int a, string p) {
    setPerson(n, a);
    program = p;
}

string Student::getProgram() {
    return program;
}

//EMPLOYEE
class Employee : public Person {
protected:
    double salary;

public:
    void setEmployee(string n, int a, double s);
    double getSalary();
};

void Employee::setEmployee(string n, int a, double s) {
    setPerson(n, a);
    salary = s;
}

double Employee::getSalary() {
    return salary;
}

//LECTURER
class Lecturer : public Employee {
private:
    string subject;

public:
    void setLecturer(string n, int a, double s, string sub);
    string getSubject();
};

void Lecturer::setLecturer(string n, int a, double s, string sub) {
    setEmployee(n, a, s);
    subject = sub;
}

string Lecturer::getSubject() {
    return subject;
}

//DIRECTOR
class Director : public Employee {
private:
    string department;

public:
    void setDirector(string n, int a, double s, string d);
    string getDepartment();
};

void Director::setDirector(string n, int a, double s, string d) {
    setEmployee(n, a, s);
    department = d;
}

string Director::getDepartment() {
    return department;
}

//CLERK
class Clerk : public Employee {
private:
    string role;

public:
    void setClerk(string n, int a, double s, string r);
    string getRole();
};

void Clerk::setClerk(string n, int a, double s, string r) {
    setEmployee(n, a, s);
    role = r;
}

string Clerk::getRole() {
    return role;
}

//SORT
void sortStudents(Student arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].getName() > arr[j + 1].getName()) {
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortLecturers(Lecturer arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].getName() > arr[j + 1].getName()) {
                Lecturer temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortDirectors(Director arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].getName() > arr[j + 1].getName()) {
                Director temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortClerks(Clerk arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].getName() > arr[j + 1].getName()) {
                Clerk temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main() {

    int nStudents, nLecturers, nDirectors, nClerks;

    // Input sizes
    cout << "Enter number of students: ";
    cin >> nStudents;

    cout << "Enter number of lecturers: ";
    cin >> nLecturers;

    cout << "Enter number of directors: ";
    cin >> nDirectors;

    cout << "Enter number of clerks: ";
    cin >> nClerks;

    Student students[nStudents];
    Lecturer lecturers[nLecturers];
    Director directors[nDirectors];
    Clerk clerks[nClerks];

    string name, program, subject, department, role;
    int age;
    double salary;

    //Input Students
    for (int i = 0; i < nStudents; i++) {
        cout << "\nEnter Student " << i + 1 << " Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
        cout << "Program: ";
        cin >> program;

        students[i].setStudent(name, age, program);
    }

    //Input Lecturers
    for (int i = 0; i < nLecturers; i++) {
        cout << "\nEnter Lecturer " << i + 1 << " Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
        cout << "Salary: ";
        cin >> salary;
        cout << "Subject: ";
        cin >> subject;

        lecturers[i].setLecturer(name, age, salary, subject);
    }

    //Input Directors
    for (int i = 0; i < nDirectors; i++) {
        cout << "\nEnter Director " << i + 1 << " Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
        cout << "Salary: ";
        cin >> salary;
        cout << "Department: ";
        cin >> department;

        directors[i].setDirector(name, age, salary, department);
    }

    //Input Clerks
    for (int i = 0; i < nClerks; i++) {
        cout << "\nEnter Clerk " << i + 1 << " Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
        cout << "Salary: ";
        cin >> salary;
        cout << "Role: ";
        cin >> role;

        clerks[i].setClerk(name, age, salary, role);
    }

    //SORT
    sortStudents(students, nStudents);
    sortLecturers(lecturers, nLecturers);
    sortDirectors(directors, nDirectors);
    sortClerks(clerks, nClerks);

    //DISPLAY
    cout << "\n===== Students =====\n";
    for (int i = 0; i < nStudents; i++) {
        cout << students[i].getName() << ", "
             << students[i].getAge() << ", "
             << students[i].getProgram() << endl;
    }

    cout << "\n===== Lecturers =====\n";
    for (int i = 0; i < nLecturers; i++) {
        cout << lecturers[i].getName() << ", "
             << lecturers[i].getAge() << ", "
             << lecturers[i].getSalary() << ", "
             << lecturers[i].getSubject() << endl;
    }

    cout << "\n===== Directors =====\n";
    for (int i = 0; i < nDirectors; i++) {
        cout << directors[i].getName() << ", "
             << directors[i].getAge() << ", "
             << directors[i].getSalary() << ", "
             << directors[i].getDepartment() << endl;
    }

    cout << "\n===== Clerks =====\n";
    for (int i = 0; i < nClerks; i++) {
        cout << clerks[i].getName() << ", "
             << clerks[i].getAge() << ", "
             << clerks[i].getSalary() << ", "
             << clerks[i].getRole() << endl;
    }

    return 0;
}