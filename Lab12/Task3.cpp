#include <iostream>
#include <exception>
using namespace std;

class OutOfRangeException : public exception {
public:
    const char* what() const throw() override {
        return "Error: Mark is out of valid range (0-100).";
    }
};

float calculateAverage(int m1, int m2, int m3, int m4) {

    if (m1 < 0 || m1 > 100 ||
        m2 < 0 || m2 > 100 ||
        m3 < 0 || m3 > 100 ||
        m4 < 0 || m4 > 100) {

        throw OutOfRangeException();
    }

    float avg = (m1 + m2 + m3 + m4) / 4.0f;
    return avg;
}

int main() {

    int m1, m2, m3, m4;

    cout << "Enter marks for 4 courses: ";
    cin >> m1 >> m2 >> m3 >> m4;

    try {

        float avg = calculateAverage(m1, m2, m3, m4);
        cout << "Average = " << avg << endl;
    }

    catch (OutOfRangeException &e) {
        cout << e.what() << endl;
    }

    catch (exception &e) {
        cout << e.what() << endl;
    }

    return 0;
}