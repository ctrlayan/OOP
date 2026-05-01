#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream outdata;
    string data;
    outdata.open("C:\\Users\\Lenovo\\Desktop\\OOP\\Lab11\\data3.txt",ios::app);
    cout <<"Writing the File..."<<endl;
    cout <<"Enter your name and where you are from: ";
    getline(cin,data);
    outdata<<data<<endl;
    outdata.close();

    ifstream indata;
    indata.open("C:\\Users\\Lenovo\\Desktop\\OOP\\Lab11\\data3.txt");
    cout<<"\nReading the File..."<<endl;

    char n;
    int charcount = 0;

    cout<<"\n-----CHARACTERS-----"<<endl;
    while(indata.get(n))
    {
        cout << n << " ";
        charcount++;
    }

    cout <<"Number of Character: " << charcount <<endl;

    indata.close();

    indata.open("C:\\Users\\Lenovo\\Desktop\\OOP\\Lab11\\data3.txt");

    string word;
    int wordcount = 0;

    cout<<"\n-----WORDS-----"<<endl;
    while(indata >>word )
    {
        cout << word << " ";
        wordcount++;
    }

    cout << "Number of Words: " << wordcount <<endl;

    indata.close();

    indata.open("C:\\Users\\Lenovo\\Desktop\\OOP\\Lab11\\data3.txt");

    string line;
    int linecount = 0;

    cout<<"\n-----LINES-----"<<endl;
    while(getline(indata,line))
    {
        cout << line<<endl;
        linecount++;
    }

    cout <<"Number of Lines: "<< linecount <<endl;

    indata.close();
    return 0;

}

