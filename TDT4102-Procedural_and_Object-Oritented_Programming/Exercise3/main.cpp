#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"

//------------------------------------------------------------------------------

//3b) Testfunction, declare
void testDeviation(double compareOperand, double toOperand, double maxError, string name);

// C++ programs start by executing the function main
int main() {
    // 3b) Test functions
    cout << "acclY(): " << acclY() << endl;
    cout << "velY(): " << velY(25, 2.5) << endl;
    cout << "posX(): " << posX(0, 50, 2.5) << endl;
    cout << "posY(): " << posY(0, 25, 2.5) << endl;
    cout << "printTime(): ";
    printTime(3661); // 1 hour, 1 minute and 1 second
    cout << "flightTime(): " << flightTime(25) << endl;

    // 3c) Test testDeviation
    double maxError = 0.001;

    // t = 2.5
    testDeviation(velY(25, 2.5), 0.475, maxError, "velY() at t = 2.5");
    testDeviation(posX(0, 50, 2.5), 125, maxError, "posX() at t = 2.5");
    testDeviation(posY(0, 25, 2.5), 31.84, maxError, "posY() at t = 2.5");

    // t = 5
    testDeviation(velY(25, 5), -24.05, maxError, "velY() at t = 5");
    testDeviation(posX(0, 50, 5), 250, maxError, "posX() at t = 5");
    testDeviation(posY(0, 25, 5), 2.375, maxError, "posY() at t = 5");

    //4a) run   getVelocityVector with 27.5 and 15.64 initial velocity, where expect values are: ≈{13.8728,7.22175}
    testDeviation(getVelocityX(27.5, 15.64), 13.8728, maxError, "getVelocityX");
    testDeviation(getVelocityY(27.5, 15.64), 7.22175, maxError, "getVelocityY");

    vector<double> velocityVector = getVelocityVector(27.5, 15.64);
    testDeviation(velocityVector[0], 13.8728, maxError, "getVelocityVector X");
    testDeviation(velocityVector[1], 7.22175, maxError, "getVelocityVector Y");

    // 4b) Given the values from 4a), the distance traveled should be ≈ 20.4253
    double velocityX = getVelocityX(27.5, 15.64);
    double velocityY = getVelocityY(27.5, 15.64);
    testDeviation(getDistanceTraveled(velocityX, velocityY), 20.4253, maxError, "getDistanceTraveled");

    // 4c) Return the distance to target. With distanceToTarget = 20, the return value should be ≈ -0.4253
    double distanceToTarget = 20;
    testDeviation(targetPractice(distanceToTarget, velocityX, velocityY), 0, maxError, "targetPractice");

    // 5b) Test randomWithLimits
    for(int i = 0; i < 10; i++) {
        cout << "random numbers: " << randomWithLimits(1, 10) << endl;
    }

    // 5c) Test playTargetPractice
    playTargetPractice();

return 0;
}

//------------------------------------------------------------------------------

//3b) Testfunction, implement
void testDeviation(double compareOperand, double toOperand, double maxError, string name) {
    if (abs(compareOperand - toOperand) <= maxError) {
        cout << name << " is valid." << endl;
    } else {
        cout << name << " is not valid." << " Expected: " << toOperand << ", got: " << compareOperand << endl;
    }
}
