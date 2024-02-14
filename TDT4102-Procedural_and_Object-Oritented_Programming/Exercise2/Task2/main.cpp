#include "std_lib_facilities.h"

//------LØKKER---------

// a) Define a function that reads a specified number of integers from the user, and write the sum of these integers to cout.

void sumIntegers() {
    int n = 0; // number of integers
    int sum = 0; // sum of integers
    int x = 0; // integer input

    cout << "Angi antall heltall som skal summeres: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Skriv inn et heltall: ";
        cin >> x;
        sum += x;
    }

    cout << "Summen av tallene er: " << sum << endl;
}

// b) define a functtion that reads a integer from the user, until the user inputs 0, and writes the sum of these integers to cout.

void sumIntegersUntilZero() {
    int sum = 1;
    int x = 1;

    while (x != 0) {
        cout << "Skriv inn et heltall: ";
        cin >> x;
        sum += x;
    }

    cout << "Summen av tallene er: " << sum << endl;
}

// c) 
// Oppgave a) ble løst med en for-løkke fordi brukeren definerte inn et bestemt antall ganger som løkken skal kjøres,
// mens oppgave b) ble løst med en while-løkke fordi vi ikke vet hvor mange runder funksjonen må kjøres før vi får input 0.


// d) Define a function inputDouble that function as task a), but reads doubles instead of integers.

void sumDoubles() {
    int n = 0; // number of integers
    double sum = 0; // sum of doubles

    cout << "Angi antall desimaltall som skal summeres: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        double x = 0;
        cout << "Skriv inn et desimaltall: ";
        cin >> x;
        sum += x;
    }

    cout << "Summen av tallene er: " << sum << endl;
}

// e) Define a function that converts from NOK to Euro. Only for positive numbers.
void convertNOKtoEuro() {
    double NOK = 0;
    double Euro = 0;
    double conversionRate = 0.088;

    cout << "Angi antall NOK som skal konverteres til Euro: ";
    cin >> NOK;

    if (NOK < 0) {
        cout << "Kan ikke konvertere negative tall." << endl;
    } else {
        Euro = NOK * conversionRate;
        cout << NOK << " NOK er " << Euro << " Euro." << endl;
    }
}

// f)
// Jeg brukte input Double istedenfor Integer slik at brukeren kan skrive inn desimaltall.

// g) Define a function that writes a multiplication table. The user input both hight and width of the table. Provide a nice table layout.

void multiplicationTable() {
    int height = 0;
    int width = 0;

    cout << "Angi hoyde pa tabellen: ";
    cin >> height;
    cout << "Angi bredde pa tabellen: ";
    cin >> width;

    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= width; ++j) {
            cout << i * j << "\t";
        }
        cout << endl;
    }
}

int main() {
    // cout << "a)" << endl;
    // sumIntegers(); 

    // cout << "b)" << endl;
    // sumIntegersUntilZero();

    // cout << "d)" << endl;
    // sumDoubles();

    // cout << "e) " << endl;
    // convertNOKtoEuro();

    cout << "g)" << endl;
    multiplicationTable();

    return 0;
}
