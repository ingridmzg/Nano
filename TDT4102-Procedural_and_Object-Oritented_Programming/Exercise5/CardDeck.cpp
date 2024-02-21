#include "CardDeck.h"

//3b. Define the constructor CardDeck.
// the constructor should add all 52 cards to the vector cards.
// Four suits
// Thirteen ranks: 
CardDeck::CardDeck() {
    for (int suit = 1; suit <= 4; ++suit) {
        for (int rank = 2; rank <= 14; ++rank) {
            cards.push_back(Card(static_cast<Suit>(suit), static_cast<Rank>(rank))); //static_cast is used to convert the integer to the enum class.
        }
    }
}

void CardDeck::swap(int i, int j) {
    std::swap(cards[i], cards[j]);
}

//print out the deck, using toString() from Card.
void CardDeck::print() const {
    for (Card c : cards) {
        cout << c.toString() << '\n';
    }
}

// shuffle the deck
void CardDeck::shuffle() {

    int upper = 51;

    std::random_device rd; //random device to seed the random number generator
    std::default_random_engine generator(rd()); //seed the generator
    std::uniform_int_distribution<int> distribution(0, upper); //distribution
    for (int i = 0; i < upper; ++i) {
        int random = distribution(generator); //generate a random number for each card in the deck
        swap(i, random); //swap the cards at position i and random
    }
}

//draw the top card from the deck
Card CardDeck::drawCard() {
    Card topCard = cards.back(); //get the top card from the deck
    cards.pop_back(); //remove the top card from the deck
    return topCard; //return the top card
}