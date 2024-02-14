
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

// a) Make the Pythagoras function. The 

int main() {

    AnimationWindow win(100, 100, 1500, 1500, "Pythagoras");
    
    // Define the corners of the triangle
    Point point1{250, 250}; 
    Point point2{250, 500};
    Point point3{500, 250};

    win.draw_triangle(point1, point2, point3, Color::black);

    // Draw the squares

    win.draw_quad(point1, point2, {0, 500}, {0, 250}, Color::blue);
    win.draw_quad(point1, point3, {500, 0}, {250, 0}, Color::green);
    win.draw_quad(point2, point3, {750, 500}, {500, 750}, Color::purple);


    win.wait_for_close();
    return 0;
}