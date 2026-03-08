#include <iostream>
using namespace std;

class Concatenate {
    private:
       string sentence;

    public:
       Concatenate(): sentence("") {};
       Concatenate operator+(const Concatenate &s1);
       void setString(string s);
       string getString();

};

Concatenate Concatenate::operator+(const Concatenate &s1)
{
     Concatenate temp;
     temp.sentence = sentence + s1.sentence; 
     return temp; 
}

void Concatenate::setString(string s) 
{ 
    sentence = s; 
}

int main() 
{ 
    string s1,s2; 
    Concatenate obj1,obj2,obj3; 

    cout << "Enter the first string" << endl; 
    getline(cin,s1); 
    cout << "Enter the second string" << endl; 
    getline(cin,s2);

    cout << "Initial strings: " << endl; 
    cout << "String: " << s1 << endl; 
    cout << "String: " << s2 << endl;

    obj2.setString(s1);

    obj3.setString(s2); 
    obj1 = obj2 + obj3; 
    cout << "After concatenation: " << endl; 
    cout << "String: " << obj1.getString() << endl; 
}