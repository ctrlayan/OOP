#include <iostream>
using namespace std;

class Sum{
    private:
       static int total;

    public:
       void addNum(int num); 
       int getTotal();  
};

int Sum::total = 0;

void Sum::addNum(int num)
{
    total += num;
}

int Sum::getTotal()
{
    return total;
}

int main()
{
    Sum calc;
   cout<<"***Static Variable***"<<endl;
   cout<<endl;
   cout<<"Please enter 5 numbers to be summed"<<endl;

   for (int i=0;i<5;i++)
   {
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    calc.addNum(num);
    cout<<"The current total is "<<calc.getTotal()<<endl;
   }

   cout <<"Program Completed"<<endl;
}