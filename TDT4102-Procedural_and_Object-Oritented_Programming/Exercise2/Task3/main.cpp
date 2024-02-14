#include "std_lib_facilities.h"

// a) discriminant function calculates b**2 - 4ac

double discriminant(double a, double b, double c) {
    double d = pow(b, 2) - 4 * a * c;
    return d;
}

// b) Define a function printRealRoots that prints the real roots of a quadratic equation. ax**2 + bx + c = 0
int printRealRoots(double a, double b, double c) {
    double d = discriminant(a, b, c);
    if (d < 0) {
        cout << "No real roots" << endl;
        return 1;
    } else if (d == 0) {
        double x = (-b + sqrt(d)) / (2 * a);
        cout << "One real root: " << x << endl;
        return 0;
    } else {
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        cout << "Two real roots: " << x1 << " and " << x2 << endl;
        return 0;
    }
}

// c) Make a function solveQuadraticEquation that let the user write 3 desimal and use printRealRoots to print the real roots of the equation.

void solveQuadraticEquation() {
    double a, b, c;
    cout << "Write a, b and c: ";
    cin >> a >> b >> c;
    printRealRoots(a, b, c);
}

// e) Use the main() function to test the functions.

int main() {
    cout << "a)" << endl;
    cout << discriminant(1, 2, 4) << endl;

    cout << "b)" << endl;
    printRealRoots(4, 4, 1);

    cout << "c)" << endl;
    solveQuadraticEquation();

    return 0;
}