#include "debug.h"

string getCapital(const string& country) {
    return capitalsMap.at(country);
}

// Error: no viable overloaded operator[] for type 'const map<string, string>' (aka 'const map<basic_string<char>, basic_string<char>>') 9 |     return capitalsMap[country];
// Cant use [] on a const map, use .at() instead