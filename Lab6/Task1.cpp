#include <iostream>
using namespace std;

class SavingAccount {
    private:
       static float annualInterestRate;
       double savingBalance;

    public:
       SavingAccount(double b);
       static void setAnnualInterestRate(double rate);
       double monthlyInterest(float interestRate, double balance);
       void displayBalance(double &mInterest);   

};

float SavingAccount::annualInterestRate = 0;

SavingAccount::SavingAccount(double b)
{
    savingBalance=b;
}

void SavingAccount::setAnnualInterestRate(double rate)
{
    annualInterestRate=rate;
}

double SavingAccount::monthlyInterest(float interestRate, double balance)
{
    return (interestRate*balance)/12;
}

void SavingAccount::displayBalance(double &mInterest)
{
    savingBalance += mInterest;
    mInterest = savingBalance;
}

int main() {
    
    double balance1,balance2,mInterest1,mInterest2,total1,total2;
    float rate;

    cout<<"Enter Balance for Saver 1: "<<endl;
    cin>>balance1;

    cout<<"Enter Balance for Saver 2: "<<endl;
    cin>>balance2;

    SavingAccount saver1(balance1);
    SavingAccount saver2(balance2);

    cout<<"Set Annual Interest Rate: "<<endl;
    cin>>rate;
    SavingAccount::setAnnualInterestRate(rate);

    cout << "After 1 month interest:" << endl;
    mInterest1 = saver1.monthlyInterest(rate,balance1);
    mInterest2 = saver2.monthlyInterest(rate,balance2);
    saver1.displayBalance(mInterest1);
    saver2.displayBalance(mInterest2);
    cout<<"Current Balance for Saver1 is: $"<<mInterest1<<endl;
    cout<<"Current Balance for Saver2 is: $"<<mInterest2<<endl;

    return 0;
}