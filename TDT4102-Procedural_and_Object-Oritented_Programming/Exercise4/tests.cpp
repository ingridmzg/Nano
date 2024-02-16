#include "tests.h"
#include "utilities.h"
#include "std_lib_facilities.h"

// task 1c

void testCallByValue()
{
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    std::cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations
         << " result: " << result << endl;
}

void testCallByReference()
{
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations << endl;
}

void testSwapNumbers()
{
    int a = 5;
    int b = 10;
    std::cout << "Before: " << "a: " << a << " b: " << b << endl;
    swapNumbers(a, b);
    std::cout << "Swap numbers to: " << "a: " << a << " b: " << b << endl;
}

// Task 2
void testStructStudent()
{
    Student Ingrid {"Ingrid", "Nano", 21};
    printStudent(Ingrid);
    std::cout << "Is Ingrid in Bygg? " << isInProgram(Ingrid, "Bygg") << endl;
    std::cout << "Is Ingrid in Nano? " << isInProgram(Ingrid, "Nano") << endl;
}

// Task 3

// grades should contain 8 random char from A to F
// countchar fills gradeCount with the amount of each grade, a = 6, b = 5 ...
// print the mean of the grades
void testString() {
    string grades = randomizeString(8, 'A', 'F'); //Randomize 8 grades from A to F
    vector<int> gradeCount(6); //vector with 6 elements because there are 6 grades
    for (char grade : grades) { //for each grade in grades
        if (grade >= 'A' && grade <= 'F') //if the grade is between A and F
            gradeCount[grade - 'A']++; //increment the gradeCount, which means that the grade is counted
    }

    for (int i = 0; i < gradeCount.size(); i++) { //for each element in gradeCount
        cout << static_cast<char>('A' + i) << ": " << gradeCount[i] << endl; //print the grade
    }

    int sum = 0;
    for (int count : gradeCount) { //for each count in gradeCount
        sum += count; //add the count to sum
    }
    cout << "Average grade: " << static_cast<double>(sum) / grades.size() << endl; //print the mean

}

// task 4c

void testRandomizeString() //test randomizeString
{
    char lower = 'A';
    char upper = 'F';
    int n = 8;
    string result = randomizeString(n, lower, upper);
    cout << "Random string: " << result << endl;
}

void testReadInputToString() //test readInputToString
{
    char lower = 'A';
    char upper = 'F';
    int n = 8;
    string result = readInputToString(n, lower, upper);
    cout << "Result: " << result << endl;
}

void testCountChar() //test countChar
{
    string grades = randomizeString(10, 'A', 'F');
    cout << "A: " << countChar(grades, 'A') << endl;
    cout << "B: " << countChar(grades, 'B') << endl;
    cout << "C: " << countChar(grades, 'C') << endl;
    cout << "D: " << countChar(grades, 'D') << endl;
    cout << "E: " << countChar(grades, 'E') << endl;
    cout << "F: " << countChar(grades, 'F') << endl;
}