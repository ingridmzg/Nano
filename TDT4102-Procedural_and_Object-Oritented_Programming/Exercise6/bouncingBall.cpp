#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "bouncingBall.h"

constexpr Point BOUNCE_WINDOW_TOP_LEFT{50, 50}; // top left corner of the window
constexpr int BOUNCE_WINDOW_WIDTH{800}; // width of the window
constexpr int BOUNCE_WINDOW_HEIGHT{500}; // height of the window

//define a map of colors for the ball
std::map<int, Color> colorMap {
    {1, Color::light_sky_blue},
    {2, Color::hot_pink},
    {3, Color::plum},
    {4, Color::gold},
};

void bouncingBall() {
    AnimationWindow window{BOUNCE_WINDOW_TOP_LEFT.x, BOUNCE_WINDOW_TOP_LEFT.y, 
                           BOUNCE_WINDOW_WIDTH, BOUNCE_WINDOW_HEIGHT, "Bouncing ball"};
    
    const int radius{30};
    int alpha{1};
    int velocity{2};
    Color colour_up{Color::blue};
    Color colour_down{Color::blue};
    int x{0};
    int y{360};
    int increment_x{0};
    int increment_y{0};
    int count_bounce_top{0};
    int count_bounce_bottom{0};
    int count_num_passes{0};
    Color colour{colour_up};

    // read from configuration file and save the info as a Config object
    std::filesystem::path config_file{"konfigurasjon.txt"};
    std::ifstream ifs{config_file};
    if (!ifs) {
        std::cerr << "Could not open file for reading" << std::endl;
        exit(1);
    }

    //config should alternate between slow and fast configuration every fifth pass

    Config slow;
    ifs >> slow;
    Config fast;
    ifs >> fast;

    // initialise the run
    velocity = fast.velocity;
    colour_up = colorMap[fast.colorUp];
    colour_down = colorMap[fast.colorDown];

    // initial movement before entering the loop
    increment_y = velocity * sin(alpha);
    increment_x = velocity * cos(alpha);

    while (!window.should_close()) {
        // determine increments based on the velocity

        // movement i x-direction
        if ((increment_x + x) > window.width()) {
            // reached right side - wrap around to the leftmost
            x = 0;
            // increment counter which counts number of full left-to-right passes
            count_num_passes++;
            // alternate between slow and fast configuration every fifth pass
            if (count_num_passes % 5 == 0) {
                // change configuration
                // update both velcity and colors
                if (velocity == slow.velocity) { // if current velocity is slow, change to fast
                    velocity = fast.velocity;
                    colour_up = colorMap[fast.colorUp];
                    colour_down = colorMap[fast.colorDown];
                } else {
                    velocity = slow.velocity;
                    colour_up = colorMap[slow.colorUp];
                    colour_down = colorMap[slow.colorDown];
                }
            }
        } else {
            // moving rightwards
            x += increment_x;
        }

        // movement i y-direction, bouncing off the top and bottom
        if ((increment_y + y) > window.height()) {
            // reached bottom - bounce upwards
            increment_y = -velocity * sin(alpha);
            colour = colour_up;
            count_bounce_bottom++;
            // std::cout << "y: " << y << ", increment_y: " << increment_y << std::endl;
        } else if (increment_y + y < 0) {
            // reached top - bounce downwards
            increment_y = velocity * sin(alpha);
            colour = colour_down;
            count_bounce_top++;
            // std::cout << "y: " << y << ", increment_y: " << increment_y << std::endl;
        } else {
            // move upward
            y += increment_y;
        }

        // draw the ball
        window.draw_circle({x, y}, radius, colour);
        window.next_frame();
    }
}

// define istream operator that should "overlaste" >>-operator.
istream& operator>>(istream& is, Config& cfg) {
    is >> cfg.colorUp >> cfg.colorDown >> cfg.velocity;
    return is;
}

