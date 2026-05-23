#include<iostream>
using namespace std;

int main(){

    float a, b, c, d;

    cout << "Enter value of a: ";
    cin >> a;

    cout << "Enter value of b: ";
    cin >> b;

    cout << "Enter value of c: ";
    cin >> c;

    try{

        if(a - b == 0){
            throw "Division by zero is not possible!";
        }

        d = (a + b + c) / (a - b);

        cout << "Result = " << d << endl;
    }

    catch(const char* error){
        cout << error << endl;
    }

    return 0;
}