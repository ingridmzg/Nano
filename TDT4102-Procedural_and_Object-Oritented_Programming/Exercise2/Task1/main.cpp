#include "std_lib_facilities.h"

// b) Input and print int
void inputAndPrintInteger() {
    int x = 0;

    cout << "Skriv inn et heltall: ";
    cin >> x;

    cout << "Du skrev: " << x << "\n";
}

// c) Input and return int
int inputInteger() {
    int x = 0;

    cout << "Skriv inn et heltall: ";
    cin >> x;

    cout << "Du skrev: " << x << "\n";
    return x;
}

// d) Input integers and print sum
void inputIntegersAndPrintSum() {
    int x = 0;
    int y = 0;

    cout << "Skriv inn et heltall: ";
    cin >> x;
    cout << "Skriv inn et heltall til: ";
    cin >> y;

    int sum = x + y;
    cout << x << " + " << y << " = " << sum << endl;
}

// e) Jeg brukte void funksjonen istedenfor int fordi input kommer fra brukeren og output skrives av programmet. Altså, vi trenger ikke å returnere noe og en void funksjon returnerer ikke resultatet, slik som en int funksjon gjør.

// f) Oddetall mellom to tall

bool isOdd(int n) {
    if (n % 2 == 0) {
        cout << n << " er ikke et oddetall" << endl;
        return false;
    }
    else {
        cout << n << " er et oddetall" << endl;
        return true;
    }
}

// switch case / switch main function
int main() {
    while (1) { // infinite loop
        cout << "Menu\n"
                << "1.\t Avslutt\n"
                << "2.\t Input and print int\n"
                << "3.\t Input and return int\n"
                << "4.\t Input integers and print sum\n"
                << "5.\t Odd numbers\n"
                << "Angi valg: ";

        int menu_choice;
        std::cin >> menu_choice;

        switch (menu_choice)
        {
        case 1:
            return 0; // exit program
            break;
        case 2:
            inputAndPrintInteger();
            break;
        case 3:
            inputInteger();
        case 4:
            inputIntegersAndPrintSum();
        case 5:
            isOdd(4);

        default:
            return 0; // exit program
            break;

        }
    }
}

//------------------------------------------------------------------------------
