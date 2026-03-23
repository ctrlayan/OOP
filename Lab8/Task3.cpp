#include <iostream>
#include <string>
using namespace std;

// Base Class
class Staff {
protected:
    string empName;
    int empID;

public:
    void setBasicInfo(string n, int id) {
        empName = n;
        empID = id;
    }

    string showName() { return empName; }
    int showID() { return empID; }
};

// Manager Class
class Supervisor : public Staff {
    string designation;
    string pay;

public:
    void setManagerData(string n, int id, string d, string p) {
        setBasicInfo(n, id);
        designation = d;
        pay = p;
    }

    string showDesignation() { return designation; }
    string showPay() { return pay; }
};

// Scientist Class
class Researcher : public Staff {
    int totalPapers;
    string pay;

public:
    void setScientistData(string n, int id, int papers, string p) {
        setBasicInfo(n, id);
        totalPapers = papers;
        pay = p;
    }

    int showPapers() { return totalPapers; }
    string showPay() { return pay; }
};

// Clerk Class
class OfficeStaff : public Staff {
    int extraHours;

public:
    void setClerkData(string n, int id, int hrs) {
        setBasicInfo(n, id);
        extraHours = hrs;
    }

    int showHours() { return extraHours; }
};

int main() {
    Supervisor mgr1, mgr2;
    Researcher res1;
    OfficeStaff clerk1;

    string name, role, salary;
    int id, papers, hours;

    // Manager 1
    cout << "Enter details for Manager 1:\n";
    cout << "Name: ";
    getline(cin, name);

    cout << "ID: ";
    cin >> id;
    cin.ignore();

    cout << "Designation: ";
    getline(cin, role);

    cout << "Salary: ";
    getline(cin, salary);

    mgr1.setManagerData(name, id, role, salary);

    cout << "---------------------------------\n";

    // Manager 2
    cout << "\nEnter details for Manager 2:\n";
    cout << "Name: ";
    getline(cin, name);

    cout << "ID: ";
    cin >> id;
    cin.ignore();

    cout << "Designation: ";
    getline(cin, role);

    cout << "Salary: ";
    getline(cin, salary);

    mgr2.setManagerData(name, id, role, salary);

    cout << "---------------------------------\n";

    // Scientist
    cout << "\nEnter details for Scientist:\n";
    cout << "Name: ";
    getline(cin, name);

    cout << "ID: ";
    cin >> id;

    cout << "Number of Publications: ";
    cin >> papers;
    cin.ignore();

    cout << "Salary: ";
    getline(cin, salary);

    res1.setScientistData(name, id, papers, salary);

    cout << "---------------------------------\n";

    // Clerk
    cout << "\nEnter details for Clerk:\n";
    cout << "Name: ";
    getline(cin, name);

    cout << "ID: ";
    cin >> id;

    cout << "Overtime Hours: ";
    cin >> hours;

    clerk1.setClerkData(name, id, hours);

    cout << "---------------------------------\n";

    // Output
    cout << "\n===== EMPLOYEE RECORD =====\n";

    cout << "\nManager 1:\n";
    cout << "Name: " << mgr1.showName() << endl;
    cout << "ID: " << mgr1.showID() << endl;
    cout << "Designation: " << mgr1.showDesignation() << endl;
    cout << "Salary: " << mgr1.showPay() << endl;

    cout << "\nManager 2:\n";
    cout << "Name: " << mgr2.showName() << endl;
    cout << "ID: " << mgr2.showID() << endl;
    cout << "Designation: " << mgr2.showDesignation() << endl;
    cout << "Salary: " << mgr2.showPay() << endl;

    cout << "\nScientist:\n";
    cout << "Name: " << res1.showName() << endl;
    cout << "ID: " << res1.showID() << endl;
    cout << "Publications: " << res1.showPapers() << endl;
    cout << "Salary: " << res1.showPay() << endl;

    cout << "\nClerk:\n";
    cout << "Name: " << clerk1.showName() << endl;
    cout << "ID: " << clerk1.showID() << endl;
    cout << "Overtime Hours: " << clerk1.showHours() << endl;

    return 0;
}