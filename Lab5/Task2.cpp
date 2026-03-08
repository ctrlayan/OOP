#include <iostream>
using namespace std;

class Calculator{
    private:
       float num;
    
    public:
       Calculator();
       float getNum();
       void setNum(float n);
       Calculator operator+(const Calculator &n);
       Calculator operator-(const Calculator &n);
       Calculator operator*(const Calculator &n);
       Calculator operator/(const Calculator &n);

};

Calculator::Calculator()
{
    num=0;
}

float Calculator::getNum()
{
    return num;
}

void Calculator::setNum(float n)
{
    num=n;
}

Calculator Calculator::operator+(const Calculator &n)
{
    Calculator temp;
    temp.num = num + n.num;
    return temp;
}

Calculator Calculator::operator-(const Calculator &n)
{
    Calculator temp;
    temp.num = num - n.num;
    return temp;
}

Calculator Calculator::operator*(const Calculator &n)
{
    Calculator temp;
    temp.num = num * n.num;
    return temp;
}

Calculator Calculator::operator/(const Calculator &n)
{
    Calculator temp;

    if(n.num == 0)
    {
        cout << "Error: Division by zero!" << endl;
        temp.num = 0;
    }
    else
    {
        temp.num = num / n.num;
    }

    return temp;
}

int main()
{
    Calculator obj1,obj2,obj3;
    float n1,n2;
    int choice;

    cout<<"Enter a Number:";
    cin>>n1;

    cout<<"Enter another Number:";
    cin>>n2;

    obj1.setNum(n1);
    obj2.setNum(n2);

    cout<< "Arthmetic operations:"<<endl;
    cout<< "1: Addition"<<endl;
    cout<< "2: Subtraction"<<endl;
    cout<< "3: Multiplication"<<endl;
    cout<< "4: Division"<<endl;

    cout<< "Enter Choice (1-4): "<<endl;
    cin>>choice;

    if(choice==1)
    {
        obj3 = obj1 + obj2;
    }
    else if(choice==2)
    {
       obj3 = obj1 - obj2; 
    }
    else if(choice==3)
    {
        obj3 = obj1 * obj2;
    }
    else if(choice==4)
    {
        obj3 = obj1 / obj2;
    }
    else{
        cout<< "Invalid Choice"<<endl;
        return 1;
    }

    cout<< "Result = " << obj3.getNum()<<endl;

}