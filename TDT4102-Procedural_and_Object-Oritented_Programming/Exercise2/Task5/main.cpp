
#include "std_lib_facilities.h"

// a) Write the function caclulateBalance which caclulates the yearly balance on the account for a given amount of years.
// The function takes the following parameters: deposit, rate, number of years

vector<int> caclulateBalance (double deposit, double rate, int years) {
    vector<int> balance;
    double interest = static_cast<double>(deposit) * rate / 100; // static_cast<double> converts the value to double

    for (int i = 0; i < years; ++i) {
        deposit += interest;
        balance.push_back(deposit); // push_back() adds an element to the end of the vector
    }

    return balance;
}

int main() {

    double deposit;
    double rate;
    int years;

    cout << "Enter deposit: ";
    cin >> deposit;
    cout << "Enter rate: ";
    cin >> rate;
    cout << "Enter number of years: ";
    cin >> years;

    vector<int> balance = caclulateBalance(deposit, rate, years);

    for (int i = 0; i < balance.size(); ++i) {
        cout << "Year " << i + 1 << ": " << balance[i] << endl;
    }

    return 0;

}