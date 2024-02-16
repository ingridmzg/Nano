#include "std_lib_facilities.h"
#include "utilities.h"

// task 1b

int incrementByValueNumTimes(int startValue, int increment, int numTimes)
{
    for (int i = 0; i < numTimes; i++)
    {
        startValue += increment;
    }
    return startValue;
}

// task 1d. Increment value by reference

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes)
{
    for (int i = 0; i < numTimes; i++)
    {
        startValue += increment;
    }
}

// task 1e

void swapNumbers(int& a, int& b) // changing the value of two integers. The function use reference to change the value of the varibles. By the use of pass by value, the function would not be able to change the value.
{
    int c = a;
    a = b;
    b = c;
}

//task 2b

void printStudent(const Student& student) //
{
    cout << "Name:\t" << student.name << "\n"
         << "Study program:\t" << student.studyProgram << "\n"
         << "Age:\t" << student.age << "\n";
}

//task 2c. Student and string as paramter and return if the student is in the study program

bool isInProgram(const Student& student, const string& studyProgram) //using const & to avoid copying the string and the student. The function returns a boolean value.
{
    return student.studyProgram == studyProgram;
}

// task 3
string randomizeString(int n, char lower, char upper)
{
    int lowerInt = static_cast<int>(lower); //static_cast is used to convert the char to an int
    int upperInt = static_cast<int>(upper);

    random_device rd; //random_device is used to generate a random number
    default_random_engine generator(rd()); // seed the generator
    uniform_int_distribution<int> distribution(lowerInt, upperInt); //uniform_int_distribution is used to generate a random number between lowerInt and upperInt

    string result = "";
    for (int i = 0; i < n; i++)
    {
        result += static_cast<char>(distribution(generator)); //static_cast is used to convert the int to a char
    }

    return result;
}

// The function returns a string of length n, where the characters are between lower and upper
// The returnes function is filled by cin.
// If the input is not in the range of lower and upper, the user is asked to enter a new input.

string readInputToString(int n, char lower, char upper)
{
      string result;
      cout << "Enter " << n << " characters between " << lower << " and " << upper << ":\n";

      while (result.length() < n)
      {
        char inputChar;
        cin >> inputChar;

        if (inputChar >= lower && inputChar <= upper)
        {
          result += inputChar;
        }
        else
        {
          cout << "Invalid input. Please enter a character between " << lower << " and " << upper << ":\n";
        }
      }
    
    return result;
}

//count the number of times a character "c" appears in a string str
int countChar(string str, char c)
{
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            count++;
        }
    }
    return count;
}

// Task 4
// Mastermind game

int checkCharactersAndPosition(string code, string guess)
{
    int correct = 0;
    for (int i = 0; i < code.length(); i++)
    {
        if (code[i] == guess[i]) // check if the character in the code is the same as the character in the guess
        {
            correct++;
        }
    }
    return correct;
}

//reeturns the number of right characters the user has guessed, independent of position
// The result is how many charachters is in the code and the guess

int checkCharacters(const string& code, const string& guess, const int& letters)
{
    int totCorrect = 0;

    const char lower = 'A';
    const char upper = lower + letters - 1;

    for (char c = lower; c <= upper; c++)
    {
        int codeCount = countChar(code, c);
        int guessCount = countChar(guess, c);
        totCorrect += min(codeCount, guessCount);
    }

    return totCorrect;
}
