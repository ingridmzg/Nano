#include "Card.h"
#include <map>
#include <string>

//1c
string suitToString(Suit suit) {
    const std::map<Suit, std::string> suitToMap {
    {Suit::clubs, "Clubs"},
    {Suit::diamonds, "Diamonds"},
    {Suit::hearts, "Hearts"},
    {Suit::spades, "Spades"}
    };
    return suitToMap.at(suit);
}

//1d
string rankToString(Rank rank) {
    const std::map<Rank, std::string> rankToMap {
    {Rank::two, "Two"},
    {Rank::three, "Three"},
    {Rank::four, "Four"},
    {Rank::five, "Five"},
    {Rank::six, "Six"},
    {Rank::seven, "Seven"},
    {Rank::eight, "Eight"},
    {Rank::nine, "Nine"},
    {Rank::ten, "Ten"},
    {Rank::jack, "Jack"},
    {Rank::queen, "Queen"},
    {Rank::king, "King"},
    {Rank::ace, "Ace"}
};
    return rankToMap.at(rank);
}

string Card::toString() const {
            string rankString  = rankToString(r);
            string suitString = suitToString(s);
            return rankString + " of " + suitString;}

Rank Card::getRank() const {
            return r;
            }
Suit Card::getSuit() const { //const means that the function does not change the object it is called on. 
            return s;
            }