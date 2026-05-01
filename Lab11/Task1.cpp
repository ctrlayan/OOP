#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream outdata;
    string name;
    int age;
    outdata.open("C:\\Users\\Lenovo\\Desktop\\OOP\\Lab11\\data.txt",ios::in | ios::out);
    cout <<"Writing the File..."<<endl;
    cout <<"Enter your Name: ";
    getline(cin,name);
    outdata<<name<<endl;
    cout <<"Enter your age: ";
    cin >> age;
    outdata<<age<<endl;

    ifstream indata;
    cout<<"Reading the File..."<<endl;
    indata>>name;
    cout <<"Name: " <<name <<endl;

    indata>>age;
    cout <<"Age: " <<age <<endl;

    outdata.close();

}

