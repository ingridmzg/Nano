#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "Blackjack.h"

int main(){
    // Rank r = Rank::king;
    // Suit s = Suit::hearts;
    // string rank = rankToString.at(r);
    // string suit = suitToString.at(s);
    // cout << "Rank: " << rank << ", Suit: " << suit << endl;

    // Card c{Suit::spades, Rank::ace};
    // cout << c.toString() << '\n';

    //---------------shuffle the deck-------------
    // CardDeck deck;
    // deck.shuffle();
    // cout << endl << endl << "Shuffled deck: " << endl;
    // deck.print();

    // --------------draw the top card from the deck-----------
    // Card topCard = deck.drawCard();
    // cout << "Top card: " << topCard.toString() << endl;

    Blackjack b;
    b.playGame();

    return 0;
}