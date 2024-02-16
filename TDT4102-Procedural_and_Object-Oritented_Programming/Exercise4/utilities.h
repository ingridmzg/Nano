#pragma once
#include "std_lib_facilities.h"

//Oppgave 1
int incrementByValueNumTimes(int startValue, int increment, int numTimes);

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes); //startValue as refernce

void swapNumbers(int& a, int& b); //a and b as reference

//oppgave 2: Struct

struct Student 
{
    string name;
    string studyProgram;
    int age;
};
void printStudent(const Student& student); //student as reference
bool isInProgram(const Student& student, const string& studyProgram); //student and studyProgram as const reference

// Task 2e: Given the error "error: redefinition of 'Student'".
// The errror is caused by the fact that "struct Student" is defined in utilities.h as "struct Student {...}" and in
// tests.h as "struct Student {...}". The error is resolved by removing the definition of "struct Student" in tests.h.
// Therefore, the struct is double defined.
// The error is resolved by #pragma once in utilities.h and tests.h. This ensures that the file is only included once.

// task 3
string randomizeString(int n, char lower, char upper);

string readInputToString(int n, char lower, char upper);

int countChar(string str, char c);

// task 4
int checkCharactersAndPosition(string code, string guess);
int checkCharacters(const string& code, const string& guess, const int& letters);