#include <iostream>
#include <string>
using namespace std;

// Base class
class Product {
protected:
    string name;
    double cost;

public:
    Product(string n = "Unknown", double c = 0.0) {
        name = n;
        cost = c;
    }

    void setProduct(string n, double c) {
        name = n;
        cost = c;
    }

    void showProduct() {
        cout << "Product: " << name << endl;
        cout << "Price: Rs. " << cost << endl;
    }
};

// Derived class 1
class Electronics : public Product {
protected:
    string company;
    int warrantyYears;

public:
    Electronics(string comp = "Unknown", int w = 0) {
        company = comp;
        warrantyYears = w;
    }

    void setElectronics(string comp, int w) {
        company = comp;
        warrantyYears = w;
    }

    void showElectronics() {
        cout << "Brand: " << company << endl;
        cout << "Warranty: " << warrantyYears << " year(s)" << endl;
    }
};

// Derived class 2 (multilevel)
class MobilePhone : public Electronics {
private:
    int battery_mAh;
    string camera;

public:
    MobilePhone(int b = 4000, string cam = "Basic") {
        battery_mAh = b;
        camera = cam;
    }

    void setMobile(int b, string cam) {
        battery_mAh = b;
        camera = cam;
    }

    void showMobile() {
        cout << "Battery: " << battery_mAh << " mAh" << endl;
        cout << "Camera: " << camera << endl;
    }
};

int main() {
    MobilePhone phone;

    phone.setProduct("iPhone 15 Plus", 200000);
    phone.setElectronics("Apple", 1);
    phone.setMobile(3200, "24 MP");

    cout << "\n--- Mobile Phone Details ---\n";
    phone.showProduct();
    phone.showElectronics();
    phone.showMobile();

    return 0;
}