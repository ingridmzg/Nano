#include "mastermind.h"
#include "utilities.h"

// constexpr int size = 4, letters 6
int playMastermind()
{
    cout << "Welcome to Mastermind!\n"
         << "Guess a 4 letter word with the letters A, B, C, D, E, F.\n"
         << "You have 10 tries to guess the word.\n"
         << "After each guess, I will tell you how many letters are correct in the reight position and how many correct letters in total.\n"
         << "Good luck!\n";

         constexpr int size = 4; //constexpr makes the variable a constant expression, so the user can't change it
         constexpr int letters = 6;
         constexpr int tries = 10;

         string code = randomizeString(size, 'A', 'A' + (letters - 1)); //randomize a string with 4 letters from A to F.
         string guess; //the user's guess

         int correctCharsAndPosition;
         int correctChars;
         int attempts = 0; // attempts

         // use readInputToString to get the user's guess and store them in guess 
        do { // do while runs the code at least once and then checks the condition, while a while loop checks the condition first
            cout << "Guess " << attempts + 1 << ": "; //print the number of the guess
            guess = readInputToString(size, 'A', 'A' + (letters - 1)); //get the user's guess
            correctCharsAndPosition = checkCharactersAndPosition(code, guess); //check how many letters are correct and in the right position
            correctChars = checkCharacters(code, guess, letters); //check how many letters are correct

            cout << "Correct characters in the right position: " << correctCharsAndPosition << endl; //print how many letters are correct and in the right position
            cout << "Correct characters: " << correctChars << endl; //print how many letters are correct

            attempts++; //increment the number of attempts
         } while (correctCharsAndPosition < size && attempts < tries); //while the number of correct characters and position is not 4 and the number of attempts is less than 10

        if (correctCharsAndPosition == size) //if the number of correct characters and position is 4
        {
            cout << "Congratulations! You guessed the word!\n"; //print congratulations
        }
        else
        {
            cout << "Sorry, you lost! The word was: " << code << endl; //print that the user lost and the word
        }

        return 0; //return 0 if the program runs without errors

}