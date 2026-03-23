#include <iostream>
using namespace std;

// Base class
class SquareCalculator {
protected:
    double value;

public:
    // Function to calculate square
    double getSquare(double num) {
        value = num;
        return value * value;
    }
};

// Derived class
class CubeCalculator : public SquareCalculator {
public:
    // Function to calculate cube
    double getCube(double num) {
        double resultSquare = getSquare(num);
        return resultSquare * num;
    }
};

int main() {
    CubeCalculator calcObj;
    double userInput;

    cout << "Enter a number: ";
    cin >> userInput;

    double squareResult = calcObj.getSquare(userInput);
    double cubeResult = calcObj.getCube(userInput);

    cout << "Square: " << squareResult << endl;
    cout << "Cube: " << cubeResult << endl;

    return 0;
}