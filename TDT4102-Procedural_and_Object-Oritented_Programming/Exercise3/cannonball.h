// Declare functions for cannonball game
#include "std_lib_facilities.h"

// -------Oppgave 1------------

// 1a) Declare accelleration in y-direction (upwards)
double acclY();

// 1b) Declare velocity in y-direction
double velY(double initVelocityY, double time);

// 1c) Declare position in x, y-direction
double posX(double initPositionX, double initVelocityX, double time);

double posY(double initPositionY, double initVelocityY, double time);

// 1d) Declare print function of time
void printTime(double seconds); // time in seconds

// 1e) Flight time of cannonball
double flightTime(double initVelocityY);

// ------------- oppgave 4 ----------
// 4a)
// The functions below are used to read user input angle and velocity and convert
//them to x- and y- components of the velocity vector.

// Angle in degrees - user input
double getUserInputTheta();

// Initial velocity - user input
double getUserInputAbsVelocity();

// convert from degrees to radians
double degToRad(double deg);

// return the velocity in x- and y- direction, given an angle. Theta in degrees and a initial velocity in initVelocity.
double getVelocityX(double theta, double initVelocity);
double getVelocityY(double theta, double initVelocity);

// Decomposes the velocity in initVelocity, in x- and y-components, given the angle theta.
vector<double> getVelocityVector(double theta, double initVelocity); //where vector<> means a geometric vector

//4b)
// Returns the horisontal distance the canonball travels before it hits the ground.
// (Value of x-position when y-position is 0)
double getDistanceTraveled(double velocityX, double velocityY);

//4c)
// Implement targetPrice() which takes the distance distanceToTarget and returns
// the error in meters between distanceToTarget and the landing position of the cannonball.
double targetPractice(double distanceToTarget, double velocityX, double velocityY);

// 5c) implement the game
void playTargetPractice();