#include <iostream>
#include <string>
using namespace std;

class Student{
    protected:
      string name;
      string program;
      static double baseFeeBS;
      static double baseFeeMS;
      static double baseFeePhD;
      static double labCharges;
      static double researchFees;
      static double supervisionFee;

    public:
    Student(string n,string p);
    virtual double calculateFee() = 0;

};

class BSStudent : public Student{
    public:
    BSStudent(string n,string p) : Student(n,p) {}
    double calculateFee()override;
};

class MSStudent : public Student{
    public:
    MSStudent(string n,string p) : Student(n,p) {}
    double calculateFee()override;
};

class PhDStudent : public Student{
    public:
    PhDStudent(string n,string p) : Student(n,p) {}
    double calculateFee()override;
};

double Student::baseFeeBS=40000;
double Student::baseFeeMS=60000;
double Student::baseFeePhD=80000;
double Student::labCharges=5000;
double Student::researchFees=10000;
double Student::supervisionFee=15000;

Student::Student(string n,string p){
    name = n;
    program = p;
}

double BSStudent::calculateFee(){
    return baseFeeBS+labCharges;
}

double MSStudent::calculateFee(){
    return baseFeeMS+researchFees;
}

double PhDStudent::calculateFee(){
    return baseFeePhD+supervisionFee;
}

int main()
{
     
  string name,program;
  Student* student[3];

  cout<< "Enter Your Name: "<< endl;
  cin>> name;

  cout << "Enter Program(Bs/Ms/PhD): "<<endl;
  cin>>program;

  for(int i = 0; i < program.length();i++)
  {
    program[i] = tolower(program[i]);
  }

  if (program == "bs")
  {
    BSStudent bsstudent(name,program);
    student[0] = &bsstudent;
    cout<< "Student Name: "<< name <<endl;
    cout<< "Total Fees: " << student[0]->calculateFee() << endl;
  }

  else if(program == "ms")
  {
    MSStudent msstudent(name,program);
    student[1] = &msstudent;
    cout<< "Student Name: "<< name <<endl;
    cout<< "Total Fees: " << student[1]->calculateFee() << endl;
  }

  else if(program == "phd")
  {
    PhDStudent phdstudent(name,program);
    student[2] = &phdstudent;
    cout<< "Student Name: "<< name <<endl;
    cout<< "Total Fees: " << student[2]->calculateFee() << endl;
  }

  else{
    cout<<"Invalid Program!"<<endl;
  }

  return 0;

}