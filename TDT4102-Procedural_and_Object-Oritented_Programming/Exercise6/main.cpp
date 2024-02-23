#include "writeToFile.h"
#include "debug.h"
#include "courseCatalog.h"
#include "bouncingBall.h"

int main() {
    // Task 1: Write to file
    writeToFile();
    addLineNumberToFile();

    // Task 2: Debugging
    cout << "Capitals:" << endl;
    for (pair<const string, const string> elem : capitalsMap)
    {
        cout << getCapital(elem.first) << endl;
    }

    //Task 3: Course catalog
    CourseCatalog catalog;
    catalog.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
    catalog.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    catalog.addCourse("TMA4100", "Matematikk 1");
    cout << endl << "Course catalog:" << endl << catalog;

    catalog.saveToFile("courseCatalog.csv");

    // Bouncing ball
    bouncingBall();

    return 0;
}