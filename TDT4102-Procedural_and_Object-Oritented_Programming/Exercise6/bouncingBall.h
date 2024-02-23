#pragma once
#include "AnimationWindow.h"

void bouncingBall();

// difference between struct and class to a config is that struct is public by default and class is private by default
// i chose to use struct because i want to make the members public


//config has 3 int, one for the color on the way up, one for the ball color on the way down and the velocity of the ball
struct Config {
    int colorUp;
    int colorDown;
    int velocity;
};

// define istream operator that should "overlaste" >>-operator.
istream& operator>>(istream& is, Config& cfg);