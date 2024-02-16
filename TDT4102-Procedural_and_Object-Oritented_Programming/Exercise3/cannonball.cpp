//Implementationfile for the cannonball game

#include "cannonball.h"
#include "utilities.h"

// -------Oppgave 2------------

// 2a) Implement acclY()
double acclY() {
    return -9.81; // m/s^2
}

// 2b) Implement velY()
double velY(double initVelocityY, double time) {
    return initVelocityY + acclY() * time;
}

// 2c) Position in x, y-direction
double posX(double initPositionX, double initVelocityX, double time) {
    return initPositionX + initVelocityX * time;
}

double posY(double initPositionY, double initVelocityY, double time) {
    return initPositionY + initVelocityY * time + ((acclY() * pow(time,2)) / 2);
}

// 2d) Print function of time, 
void printTime(double seconds) {
    int hours = static_cast<int>(seconds / 3600);
    int minutes = static_cast<int>((seconds - hours * 3600) / 60);
    seconds = seconds - hours * 3600 - minutes * 60;

    cout << "Time: " << hours << " hours, " << minutes << " minutes and " << seconds << " seconds." << endl;
}

// 2e) Flight time of cannonball
double flightTime(double initVelocityY) {
    return (-2*initVelocityY) / acclY();
}

// 4a) Implement functions

// Angle in degrees - user input
double getUserInputTheta() {
    double inputTheta;
    cout << "Enter an angle in degrees: ";
    cin >> inputTheta;
    return inputTheta;

}

// Initial velocity - user input
double getUserInputAbsVelocity() {
    double inputVelocity;
    cout << "Enter an initial velocity: ";
    cin >> inputVelocity;
    return inputVelocity;

}

// convert from degrees to radians
double degToRad(double deg) {
    return deg * (M_PI / 180);
}

// return the velocity in x- and y- direction, given an angle.
//Theta in degrees and a initial velocity in initVelocity.
double getVelocityX(double theta, double initVelocity) {
    double velX = initVelocity * cos(degToRad(theta));
    return velX;
}

double getVelocityY(double theta, double initVelocity) {
    double velY = initVelocity * sin(degToRad(theta));
    return velY;
}

// Decomposes the velocity in initVelocity, in x- and y-components, given the angle theta.
// Calls getVelocityX and getVelocityY and stores the return values in a vector.
vector<double> getVelocityVector(double theta, double initVelocity) {
    vector<double> velocityVector; // Create a vector to store the x- and y- components of the velocity.
    velocityVector.push_back(getVelocityX(theta, initVelocity)); // Store the x- component in the vector. Push_back stores the return value of getVelocityX in the vector.
    velocityVector.push_back(getVelocityY(theta, initVelocity));
    return velocityVector;
}

// 4b) Implement functions

// Returns the horisontal distance the canonball travels before it hits the ground.
// (Value of x-position when y-position is 0)
double getDistanceTraveled(double velocityX, double velocityY) {
    double distanceTraveled = posX(0, velocityX, flightTime(velocityY));
    return distanceTraveled;
}

//4c)
// Implement targetPrice() which takes the distance distanceToTarget and returns
// the error in meters between distanceToTarget and the landing position of the cannonball.
double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
    double error = distanceToTarget - getDistanceTraveled(velocityX, velocityY);
    return error;
}

// 5c) Implement the game, where a cannonball is shot at a target.
// The user wins if the target is hit.
// The target is randomly placed between 100 and 1000 meters away.
// The user gets 10 attempts to hit the target.
// The user is asked to input an angle and an initial velocity for each attempt.
void playTargetPractice() {
    int targetDistance = randomWithLimits(100, 1000);

    cout << "Welcome to the cannonball game!" << endl;
    cout << "You have 10 attempts to hit the target, placed " << targetDistance << " meters away." << endl;
    cout << "Good luck!" << endl;

    for(int i = 0; i < 10; i++) {
        cout << "Attempt " << i+1 << ": " << endl;
        double angle = getUserInputTheta();  // Get the user input for angle
        double velocity = getUserInputAbsVelocity(); // Get the user input for velocity
        vector<double> velocityVector = getVelocityVector(angle, velocity); // Store the return value of getVelocityVector in a vector
        double error = targetPractice(targetDistance, velocityVector[0], velocityVector[1]); //velocityVector[0] is the x- component, velocityVector[1] is the y- component

        cout << "You shot the cannonball with an angle of " << angle << " degrees and an initial velocity of " << velocity << " m/s." << endl;
        if(error < 0.1) {
            cout << "Congratulations! You hit the target!" << endl;
            break;
        } else {
            cout << "You missed the target by " << error << " meters." << endl;
        }
}
    cout << "Game over!" << endl;
}