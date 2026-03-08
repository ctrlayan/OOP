#include <iostream>
using namespace std;

class Counter {
    private:
       int count;

    public:
       Counter(int c); 
       Counter operator++();
       int getcount();

};

Counter::Counter(int c)
{
    count=c;
}

Counter Counter::operator++()
{
    ++count;
    return *this;
}

int Counter::getcount()
{
    return count;
}

int main()
{
    Counter c1(5);
    Counter c2(10);

    cout<<"Initial value of C1="<<c1.getcount();
    cout<<"\nInitial value of C2="<<c2.getcount();
    cout<<endl;

    ++c1;

    ++c2;
    ++c2;

    cout << "Value After incrementing in C1="<<c1.getcount();
    cout << "\nValue After incrementing in C2="<<c2.getcount();
    cout << endl;

}
