#include <iostream>
using namespace std;

// Base Class
class Device {
protected:
    int id;
    bool isOn;

public:
    Device(int i = 0, bool status = false) {
        id = i;
        isOn = status;
    }

    void setDeviceInfo(int i, bool status) {
        id = i;
        isOn = status;
    }

    void showDevice() {
        cout << "Device ID: " << id << endl;
        cout << "Power: " << (isOn ? "ON" : "OFF") << endl;
    }
};

// Smartphone class (virtual inheritance)
class Smartphone : virtual public Device {
protected:
    bool hasSIM;
    float displaySize;

public:
    Smartphone(bool sim = true, float size = 6.5) {
        hasSIM = sim;
        displaySize = size;
    }

    void setPhone(bool sim, float size) {
        hasSIM = sim;
        displaySize = size;
    }

    void showPhone() {
        cout << "SIM Support: " << (hasSIM ? "Yes" : "No") << endl;
        cout << "Screen Size: " << displaySize << " inches" << endl;
    }
};

// Laptop class (virtual inheritance)
class Laptop : virtual public Device {
protected:
    string keyboard;
    int refreshRate;

public:
    Laptop(string type = "Standard", int rate = 60) {
        keyboard = type;
        refreshRate = rate;
    }

    void setLaptop(string type, int rate) {
        keyboard = type;
        refreshRate = rate;
    }

    void showLaptop() {
        cout << "Keyboard Type: " << keyboard << endl;
        cout << "Refresh Rate: " << refreshRate << " Hz" << endl;
    }
};

// SmartTablet class (multiple inheritance)
class SmartTablet : public Smartphone, public Laptop {
private:
    int battery;
    bool supportsPen;

public:
    SmartTablet(int id, bool status)
        : Device(id, status) {}  // only ONE Device constructor called

    void setTablet(int b, bool pen) {
        battery = b;
        supportsPen = pen;
    }

    void showTablet() {
        cout << "Battery: " << battery << " mAh" << endl;
        cout << "Stylus Support: " << (supportsPen ? "Yes" : "No") << endl;
    }
};

int main() {
    Smartphone s;
    Laptop l;
    SmartTablet t(3, true);

    // Smartphone
    s.setDeviceInfo(1, true);
    s.setPhone(true, 6.8);

    cout << "\n--- Smartphone ---\n";
    s.showDevice();
    s.showPhone();

    // Laptop
    l.setDeviceInfo(2, false);
    l.setLaptop("Mechanical", 120);

    cout << "\n--- Laptop ---\n";
    l.showDevice();
    l.showLaptop();

    // SmartTablet
    t.setPhone(true, 10.5);
    t.setLaptop("Detachable", 90);
    t.setTablet(8000, true);

    cout << "\n--- Smart Tablet ---\n";
    t.showDevice();   // proves only ONE Device exists
    t.showPhone();
    t.showLaptop();
    t.showTablet();

    return 0;
}