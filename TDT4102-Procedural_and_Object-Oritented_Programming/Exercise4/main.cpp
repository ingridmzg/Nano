#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"
#include "masterVisual.h"

int main() { //test menu

        cout << "Menu\n"
            << "1.\t Quit\n"
            << "2.\t Call by value\n"
            << "3.\t Call by reference\n"
            << "4.\t Swap numbers\n"
            << "5.\t Test struct student\n"
            << "6.\t Test string\n"
            << "7.\t Test randomize string\n"
            << "8.\t Test read input to string\n"
            << "9.\t Test count char\n"
            << "10. \t Play Mastermind\n"
            << "11.\t Play Mastermind with graphics\n"
            << "Choose a number: ";

        int choice;
        std::cin >> choice; //std::cin is used rather than cin to avoid ambiguity (meaning that the compiler knows which cin to use)

        switch (choice)
        {
            case 1:
                return 0;
                break;
            case 2:
                testCallByValue();
                break;
            case 3:
                testCallByReference();
                break;
            case 4:
                testSwapNumbers();
                break;
            case 5:
                testStructStudent();
                break;
            case 6:
                testString();
                break;
            case 7:
                testRandomizeString();
                break;
            case 8:
                testReadInputToString();
                break;
            case 9:
                testCountChar();
                break;
            case 10:
                playMastermind();
                break;
            case 11:
                playMastermindVisual();
                break;
            default:
                return 0;
                break;
        }
    return 0; //return 0 if the program runs without errors
}
