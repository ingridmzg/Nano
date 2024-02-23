#include "writeToFile.h"

// Task 1a) Read a word from the user and write it to a file

void writeToFile() {
    std::ofstream file; // create an output file stream
    file.open("file.txt"); // open the file
    if (!file) error("Could not open file for writing"); // check if the file was opened successfully
    std::string input;

    std::cout << "Enter a word: ";
    std::cin >> input;
    file << input; // write the input to the file
    file.close(); // close the file

}

// task 2b) Read the output.txt file and make a new file with the same text and Add line numbers to the new file

void addLineNumberToFile() {
    std::ifstream file; // create an input file stream
    file.open("file.txt"); // open the file
    
    if (!file) {
        std:cerr << "Could not open file for reading" << std::endl; // check if the file was opened successfully
        exit(1); // exit the program
    }

    std::ofstream newFile;
    newFile.open("fileWithLineNumbers.txt"); // open the file
    std::string line;
    int lineNumber = 1;

    while (std::getline(file, line)) {
        newFile << lineNumber << " " << line << std::endl; // write the line number and the line to the new file
        lineNumber++;
    }
}

