#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream outdata;
    string name;
    outdata.open("C:\\Users\\Lenovo\\Desktop\\OOP\\Lab11\\data2.txt");
    cout <<"Writing the File..."<<endl;
    cout <<"Enter your Name: ";
    getline(cin,name);
    outdata<<name<<endl;
    outdata.close();

    ifstream indata;
    indata.open("C:\\Users\\Lenovo\\Desktop\\OOP\\Lab11\\data2.txt");
    cout<<"Reading the File..."<<endl;

    char n;

    while(indata.get(n))
    {
        cout << n << " ";
    }

    indata.close();
    return 0;

}

