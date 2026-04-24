#include <iostream>
using namespace std;

class Operations{
    public:
       virtual double perform(double n1,double n2) = 0 ;

};

class Addition : public Operations{
    public:
       double perform(double n1,double n2) override;
};

class Subtraction : public Operations{
    public:
       double perform(double n1,double n2) override;
};

class Multiplication : public Operations{
    public:
       double perform(double n1,double n2) override;
};

double Addition::perform(double n1,double n2){
    return n1 + n2;
}

double Subtraction::perform(double n1,double n2){
    return n1 - n2;
}

double Multiplication::perform(double n1,double n2){
    return n1 * n2;
}

int main()
{
    double num1,num2;
    Operations* operation[3];
    Addition add;
    Subtraction sub;
    Multiplication product;

    cout << "Enter Number 1: "<<endl;
    cin >> num1;

    cout << "Enter Number 2: "<<endl;
    cin >> num2;
    
    operation[0] = &add;
    operation[1] = &sub;
    operation[2] = &product;

    cout <<"Sum of numbers: "<< operation[0]->perform(num1,num2)<<endl;
    cout <<"Difference of numbers: "<< operation[1]->perform(num1,num2)<<endl;
    cout <<"Product of numbers: "<< operation[2]->perform(num1,num2)<<endl;


}

