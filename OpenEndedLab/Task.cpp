#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person();
    Person(string n, int a);
    virtual string getRole() = 0;
    string getName();
    int getAge();
    virtual ~Person();
};

class Doctor : public Person {
protected:
    string specialization;
public:
    Doctor(string n, int a, string spec);
    string getRole() override;
    string getSpecialization();
};

class Surgeon : public Doctor {
    int surgeriesPerformed;
public:
    Surgeon(string n, int a, string spec, int s);
    string getRole() override;
    int getSurgeries();
};

class Patient {
    string name;
    int age;
    string disease;
public:
    Patient();
    Patient(string n, int a, string d);
    string getName();
    int getAge();
    string getDisease();
};

class Appointment {
    Doctor* doctor;
    Patient* patient;
    string date;
public:
    Appointment(Doctor* d, Patient* p, string dt);
    Doctor* getDoctor();
    Patient* getPatient();
    string getDate();
};

Person::Person() {
    name = "";
    age = 0;
}

Person::Person(string n, int a) {
    name = n;
    age = a;
}

Person::~Person() {}

string Person::getName() {
    return name;
}

int Person::getAge() {
    return age;
}

Doctor::Doctor(string n, int a, string spec) : Person(n, a) {
    specialization = spec;
}

string Doctor::getRole() {
    return "Doctor";
}

string Doctor::getSpecialization() {
    return specialization;
}

Surgeon::Surgeon(string n, int a, string spec, int s) : Doctor(n, a, spec) {
    surgeriesPerformed = s;
}

string Surgeon::getRole() {
    return "Surgeon";
}

int Surgeon::getSurgeries() {
    return surgeriesPerformed;
}

Patient::Patient() {
    name = "";
    age = 0;
    disease = "";
}

Patient::Patient(string n, int a, string d) {
    name = n;
    age = a;
    disease = d;
}

string Patient::getName() {
    return name;
}

int Patient::getAge() {
    return age;
}

string Patient::getDisease() {
    return disease;
}

Appointment::Appointment(Doctor* d, Patient* p, string dt) {
    doctor = d;
    patient = p;
    date = dt;
}

Doctor* Appointment::getDoctor() {
    return doctor;
}

Patient* Appointment::getPatient() {
    return patient;
}

string Appointment::getDate() {
    return date;
}

int main() {
    int dCount, pCount;

    cout << "-----HOSPITAL MANAGEMENT SYSTEM-----" << endl;
    cout << endl;
    cout << "Enter number of doctors: ";
    cin >> dCount;

    Person** doctors = new Person * [dCount];

    for (int i = 0; i < dCount; i++) {
        int type;
        cout << "\n1. Doctor\n2. Surgeon\nSelect type: ";
        cin >> type;
        string name, spec;
        int age;
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter specialization: ";
        getline(cin, spec);
        if (type == 1) {
            doctors[i] = new Doctor(name, age, spec);
        } else {
            int surgeries;
            cout << "Enter surgeries performed: ";
            cin >> surgeries;
            doctors[i] = new Surgeon(name, age, spec, surgeries);
        }
    }

    cout << "\nEnter number of patients: ";
    cin >> pCount;

    Patient* patients = new Patient[pCount];

    for (int i = 0; i < pCount; i++) {
        string name, disease;
        int age;
        cin.ignore();
        cout << "\nEnter patient name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter disease: ";
        getline(cin, disease);
        patients[i] = Patient(name, age, disease);
    }

    int aCount;
    do {
        cout << "\nEnter number of appointments: ";
        cin >> aCount;
        if (aCount <= 0)
            cout << "Please enter a positive number.\n";
    } while (aCount <= 0);

    Appointment** appointments = new Appointment * [aCount];

    for (int i = 0; i < aCount; i++) {
        cout << "\n--- Creating Appointment " << i + 1 << " ---\n";
        cout << "\nAvailable Doctors:\n";
        for (int j = 0; j < dCount; j++) {
            cout << j + 1 << ". " << doctors[j]->getName() << " (" << doctors[j]->getRole() << ")\n";
        }
        int dChoice;
        cout << "Select doctor (1-" << dCount << "): ";
        cin >> dChoice;
        while (dChoice < 1 || dChoice > dCount) {
            cout << "Invalid choice. Try again: ";
            cin >> dChoice;
        }
        cout << "\nAvailable Patients:\n";
        for (int j = 0; j < pCount; j++) {
            cout << j + 1 << ". " << patients[j].getName() << endl;
        }
        int pChoice;
        cout << "Select patient (1-" << pCount << "): ";
        cin >> pChoice;
        while (pChoice < 1 || pChoice > pCount) {
            cout << "Invalid choice. Try again: ";
            cin >> pChoice;
        }
        string date;
        cout << "Enter appointment date: ";
        cin >> date;
        Doctor* d = (Doctor*)doctors[dChoice - 1];
        Patient* p = &patients[pChoice - 1];
        appointments[i] = new Appointment(d, p, date);
        cout << "Appointment created successfully!\n";
    }

    cout << "\n--- DOCTORS ---\n";
    for (int i = 0; i < dCount; i++) {
        cout << "Role: " << doctors[i]->getRole() << endl;
        cout << "Name: " << doctors[i]->getName() << endl;
        cout << "Age: " << doctors[i]->getAge() << endl;
        Doctor* d = (Doctor*)doctors[i];
        cout << "Specialization: " << d->getSpecialization() << endl;
        if (doctors[i]->getRole() == "Surgeon") {
            Surgeon* s = (Surgeon*)doctors[i];
            cout << "Surgeries: " << s->getSurgeries() << endl;
        }
        cout << "----------------\n";
    }

    cout << "\n--- PATIENTS ---\n";
    for (int i = 0; i < pCount; i++) {
        cout << "Name: " << patients[i].getName() << endl;
        cout << "Age: " << patients[i].getAge() << endl;
        cout << "Disease: " << patients[i].getDisease() << endl;
        cout << "----------------\n";
    }

    cout << "\n--- APPOINTMENTS ---\n";
    for (int i = 0; i < aCount; i++) {
        cout << "Date: " << appointments[i]->getDate() << endl;
        cout << "Doctor: " << appointments[i]->getDoctor()->getName() << endl;
        cout << "Patient: " << appointments[i]->getPatient()->getName() << endl;
        cout << "----------------\n";
    }

    for (int i = 0; i < dCount; i++) {
        delete doctors[i];
    }
    delete[] doctors;

    for (int i = 0; i < aCount; i++) {
        delete appointments[i];
    }
    delete[] appointments;

    delete[] patients;

    return 0;
}