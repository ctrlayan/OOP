#include <iostream>
#include <fstream>
using namespace std;

class Student
{
private:
    string name;
    string DOB;
    string placeOfBirth;
    int age;
    float CGPA;
public: 
    Student() : name("N/A"), DOB("1/1/2000"), placeOfBirth("city"), age(17), CGPA(1.0){};
    void setData(string n, string date, string place, int a, int cgpa);
    void writeToFile(Student& obj);
};

void Student::setData(string n, string date, string place, int a, int cgpa)
{
    name = n;
    DOB = date;
    placeOfBirth = place;
    age = a;
    CGPA = cgpa;
}

void Student::writeToFile(Student& obj)
{
    ofstream outTemp;

    cout << "\nWriting to file !!\n" << endl;
    outTemp.open("C:\\Users\\Lenovo\\Desktop\\OOP\\Lab11\\data4.txt", ios::app);
    outTemp << "Name: " << name << endl;
    outTemp << "Date Of Birth: " << DOB << endl;
    outTemp << "Place Of Birth: " << placeOfBirth << endl; 
    outTemp << "Age: " << age << endl;
    outTemp << "CGPA: " << CGPA << endl; 
    outTemp.close();

}

int main()
{
    int arrSize = 2;
    string name, dob, pob;
    int age;
    float cgpa;

    Student students[arrSize];

    for(int i = 0; i < arrSize; i++)
    {
    cout << "Enter Name: ";
    getline(cin,name);
    
    cout << "\nEnter Date Of Birth: ";
    getline(cin,dob);

    cout << "\nEnter Place Of Birth: ";
    getline(cin,pob);

    cout << "\nEnter Age: ";
    cin >> age;

    cout << "\nEnter CGPA: ";
    cin >> cgpa;
    cin.ignore();

    students[i].setData(name,dob,pob,age,cgpa);
    students[i].writeToFile(students[i]);
    }
}