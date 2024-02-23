#pragma once
#include "std_lib_facilities.h"

class CourseCatalog {
    public:
        void addCourse(string courseCode, string courseName);
        void removeCourse(string courseCode);
        string getCourse(string courseCode);
        void saveToFile(string fileName);

        friend std::ostream& operator<<(std::ostream& os, const CourseCatalog& cc); // friend function to overload << operator

    private:
        map<string, string> courseMap;
};