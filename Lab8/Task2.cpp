#include <iostream>
#include <string>

using namespace std;

// Base class
class Person {
protected:
    string studentName;
    string studentRoll;
    string studentAddress;

public:
    void setDetails(string n, string r, string a) {
        studentName = n;
        studentRoll = r;
        studentAddress = a;
    }
};

// Derived class
class Result : public Person {
private:
    float subject1, subject2, subject3;
    float sum;
    float avg;

public:
    void setMarks(float s1, float s2, float s3) {
        subject1 = s1;
        subject2 = s2;
        subject3 = s3;
        sum = subject1 + subject2 + subject3;
        avg = sum / 3.0;
    }

    string fetchName() { return studentName; }
    string fetchRoll() { return studentRoll; }
    string fetchAddress() { return studentAddress; }

    float fetchS1() { return subject1; }
    float fetchS2() { return subject2; }
    float fetchS3() { return subject3; }
    float fetchTotal() { return sum; }
    float fetchAverage() { return avg; }
};

int main() {
    Result stdObj;

    string n, r, addr;
    float s1, s2, s3;

    // Input details
    cout << "Enter name: ";
    getline(cin, n);

    cout << "Enter roll number: ";
    getline(cin, r);

    cout << "Enter address: ";
    getline(cin, addr);

    stdObj.setDetails(n, r, addr);

    // Input marks
    cout << "Enter marks for 3 subjects:" << endl;
    cout << "Subject 1: ";
    cin >> s1;
    cout << "Subject 2: ";
    cin >> s2;
    cout << "Subject 3: ";
    cin >> s3;

    stdObj.setMarks(s1, s2, s3);

    // Output
    cout << "\nStudent Detail" << endl;
    cout << "Name: " << stdObj.fetchName() << endl;
    cout << "Roll No: " << stdObj.fetchRoll() << endl;
    cout << "Address: " << stdObj.fetchAddress() << endl;

    cout << "\nMarks" << endl;
    cout << "Subject 1: " << stdObj.fetchS1() << endl;
    cout << "Subject 2: " << stdObj.fetchS2() << endl;
    cout << "Subject 3: " << stdObj.fetchS3() << endl;
    cout << "Total Marks: " << stdObj.fetchTotal() << endl;
    cout << "Average Marks: " << stdObj.fetchAverage() << endl;

    return 0;
}