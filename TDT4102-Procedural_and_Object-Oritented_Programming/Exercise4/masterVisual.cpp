#include "masterVisual.h"
#include "mastermind.h"
#include "utilities.h"

void addGuess(MastermindWindow &mwin, const string code, const char startLetter)
{
	mwin.guesses.push_back(Guess{code, startLetter}); // add a new guess to the vector guesses
}

void addFeedback(MastermindWindow &mwin, const int correctPosition, const int correctCharacter)
{
	mwin.feedbacks.push_back(Feedback{correctPosition, correctCharacter}); // add a new feedback to the vector feedbacks	
}

void MastermindWindow::drawCodeHider()
{
	if (code_hidden) {
		draw_rectangle(Point{padX, 3 * padY}, winW - size * padX, padY, Color::grey);
	}
}

MastermindWindow::MastermindWindow(int x, int y, int w, int h, int size, const string &title) 
: AnimationWindow(x, y, w, h, title),
guessBtn{{upperLeftCornerBtn.x, upperLeftCornerBtn.y}, btnW, btnH, "Add"},
guess{{upperLeftCornerInBox.x, upperLeftCornerInBox.y}, inBoxW, inBoxH, ""},
size(size)
{
	add(guess);
	add(guessBtn);
	guessBtn.setCallback(std::bind(&MastermindWindow::cb_guess, this));
};

void MastermindWindow::drawGuessesAndFeedbacks()
{
	std::map<int, Color> colorConverter{
		{1, Color::red},
		{2, Color::green},
		{3, Color::yellow},
		{4, Color::blue},
		{5, Color::blue_violet},
		{6, Color::dark_cyan}};

	for (int guessIndex = 0; guessIndex < static_cast<int>(guesses.size()); guessIndex++)
	{
		Guess guess = guesses[guessIndex]; // get the guess at the index guessIndex, current guess
		for (int i = 0; i < size; i++)
		{
			// xPos and yPos for each rectangle
			int xPos = padX + i * (padX + padX/4);
			int yPos = 3*padY + guessIndex * (padY + padY/4); 
			int colorIndex = guess.code.at(i) - guess.startLetter + 1; // get the color index
			
			Color fillColor = colorConverter.at(colorIndex); // get the color from the map. .at() returns a refernce to the element at position n in the map

			draw_rectangle({xPos, yPos}, padX, padY, fillColor, Color::black);// Tegn rektangler ved bruk av draw_rectangle(). 
		}
	}

	for (int feedbackIndex = 0; feedbackIndex < static_cast<int>(feedbacks.size()); feedbackIndex++)
	{
		Feedback feedback = feedbacks[feedbackIndex]; // get the feedback at the index feedbackIndex, current feedback

		// position for the circles, right side of the rectangles
		int xPos = 5 * padX + size * (padX + padX/4);
		int yPos = 4.5 * padY + feedbackIndex * (padY + padY/4);

		// green circle for correct position
		for (int i = 0; i < feedback.correctPosition; i++)
		{
			draw_circle({xPos + i*2 * radCircle, yPos}, radCircle, Color::green); // draw a circle

		}

		// Blue circle for correct character, wrong position
		for (int i = feedback.correctPosition; i < feedback.correctCharacter; i++)
		{
			draw_circle({xPos + i*2*radCircle, yPos}, radCircle, Color::blue); // draw a circle
		}

		// draw unused guesses
		for (int i = feedback.correctCharacter; i < size; i++)
		{
			draw_circle({xPos + i*2*radCircle, yPos}, radCircle, Color::black); // draw a circle
		}

	}
}

string MastermindWindow::wait_for_guess()
{

	while (!button_pressed && !should_close())
	{
		drawGuessesAndFeedbacks();
		// Burde tegnes sist siden den skal ligge på toppen
		drawCodeHider();

		next_frame();
	}
	button_pressed = false;

	string newGuess = guess.getText();
	guess.setText("");

	return newGuess;
}

string MastermindWindow::getInput(unsigned int n, char lower, char upper)
{
	bool validInput = false;
	string guess;
	while (!validInput && !should_close())
	{
		guess.clear();
		string input = wait_for_guess();
		if (input.size() == n)
		{
			for (unsigned int i = 0; i < n; i++)
			{
				char ch = input.at(i);
				if (isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch))
				{
					guess += toupper(ch);
				}
				else
					break;
			}
		}
		if (guess.size() == n)
		{
			validInput = true;
		}
		else
		{
			cout << "Invalid input guess again" << endl;
		}
	}
	return guess;
}

void MastermindWindow::setCodeHidden(bool hidden) {
	code_hidden = hidden;
}

int playMastermindVisual()
{
    cout << "Welcome to Mastermind!\n"
         << "Guess a 4 letter word with the letters A, B, C, D, E, F.\n"
         << "You have 10 tries to guess the word.\n"
         << "After each guess, feedback is at the right.\n"
		 << "Green circle for correct position and character.\n"
		 << "Blue circle for correct character.\n"
		 << "Black circle for unused guesses.\n"
         << "Good luck!\n";

         // constant expressions
		 constexpr int size = 4; //constexpr makes the variable a constant expression, so the user can't change it
         constexpr int letters = 6;
         constexpr int tries = 10;

         int correctCharsAndPosition;
         int correctChars;
         int attempts = 0; // attempts

		 MastermindWindow mwin{900, 20, winW, winH, size, "Mastermind"};
		 mwin.setCodeHidden(true); // hide the code

		 // Hidden code
		 string code = randomizeString(size, 'A', 'A' + (letters - 1));
		 addGuess(mwin, code, 'A');
		 string guess; //the user's guess
 
        do { // do while runs the code at least once and then checks the condition, while a while loop checks the condition first
            cout << "Guess " << attempts + 1 << ": "; //print the number of the guess
            guess = mwin.getInput(size, 'A', 'A' + (letters - 1)); //get the user's guess
            
			// add the guess to the window
			addGuess(mwin, guess, 'A');

			correctCharsAndPosition = checkCharactersAndPosition(code, guess); //check how many letters are correct and in the right position
            correctChars = checkCharacters(code, guess, letters); //check how many letters are correct
			addFeedback(mwin, correctCharsAndPosition, correctChars);

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

		mwin.drawGuessesAndFeedbacks();
		mwin.setCodeHidden(false); // show the code
		mwin.wait_for_close();

        return 0; //return 0 if the program runs without errors

}
