#include "CourseCatalog.h"

void CourseCatalog::addCourse(string courseCode, string courseName) {
    //using insert
    // courseMap.insert(pair<string, string>(courseCode, courseName));
    
    if (CourseCatalog::courseMap.find(courseCode) != CourseCatalog::courseMap.end()) // If courseCode is already in courseMap
    {
        cout << "Course already exists in course catalog." << endl;
    }
    else
    {
        courseMap[courseCode] = courseName; // Adds courseCode and courseName to courseMap
        cout << courseName << " added to the course catalog." << endl;
    }
    
}

// difference between operator[] and insert() is that operator[] will overwrite the value of the key if it already exists, while insert() will not overwrite the value of the key if it already exists.

void CourseCatalog::removeCourse(string courseCode) {
    courseMap.erase(courseCode); // Removes courseCode from courseMap
}

string CourseCatalog::getCourse(string courseCode) {
    return courseMap.at(courseCode); // Returns courseName for courseCode
}

//save courseMap to file
void CourseCatalog::saveToFile(string fileName) {
    std::ofstream os{std::filesystem::current_path() / fileName}; // Opens file for writing
    if (!os) error("Could not open file for writing"); // Checks if file was opened successfully
    for (pair<const string, string> elem : courseMap) // Iterates through courseMap
    {
        os << elem.first << "|" << elem.second << endl; // Writes courseCode and courseName to file
    }
    os.close(); // Closes file
}


// print courseMap to os
std::ostream& operator<<(std::ostream& os, const CourseCatalog& cc) {
    for (pair<const string, string> elem : cc.courseMap) // Iterates through courseMap
    {
        os << elem.first << " " << elem.second << endl; // Prints courseCode and courseName to os
    }
    return os;
}