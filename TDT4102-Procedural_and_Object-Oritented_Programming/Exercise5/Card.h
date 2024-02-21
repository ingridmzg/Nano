#pragma once
#include "std_lib_facilities.h"


// task 1a). Suit is an enum class
enum class Suit {
    clubs = 1, diamonds, hearts, spades
};

// task 1b). Rank is an enum class with thirteen values: two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, and ace.

enum class Rank {
    two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace
};

// task 1c) suit to string using map.
// a map in C++ "is like" a dictionary in Python. It is a collection of key-value pairs.
string suitToString(Suit suit);

// task 1d) rank to string using map.
string rankToString(Rank rank);


//Task 1e)
// Pros using enum instead of integer and string:
// (Enumerators are named constants defined by the user)
// Enumerators are strongly typed (typestrengt), which means that an enumerator of one type cannot be implicitly converted to another type.
// The biggest advantage of using enum is that it makes the code more readable and understandable.


//Task 2a). Declare the class Card. This class should have two private members:
class Card {
    public:
    //2b) Define the constructor Card.
    //Initialize r and s with a initializer list.
        Card(Suit suit, Rank rank) {s = suit;   r = rank;}
    //Task 2c) Define getSuit(), which returns the suit of the card.
        Suit getSuit() const; 
    //Task 2d) Define getRank(), which returns the rank of the card.
        Rank getRank() const;
    //Task 2e) Define toString(), which returns a string representation of the card.
        string toString() const;
    private:
        Suit s;
        Rank r;
};

