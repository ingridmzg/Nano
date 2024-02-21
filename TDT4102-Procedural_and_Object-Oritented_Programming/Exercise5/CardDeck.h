#pragma once
#include "Card.h"

//3a) Declare the class CardDeck. This class should have one private member:
    // vector<Card> cards
class CardDeck {
    public:
    //3b) Define the constructor CardDEck. Each card should be added right with right suit and right rank.
        CardDeck();
    //3d) Define print(). Should print out all the cards in the deck.
        void print() const;
    //3e) Define shuffle(). Should shuffle the cards to random in the cards vector.
        void shuffle();
    //3f) Draw the top card from the deck. Should remove the top card from the deck and return it.
        Card drawCard();
    private:
        vector<Card> cards;
    //3c) Define swap(). Should take two integers to cards-vector and swap the cards that is in these two positions.
    // the function should be private because it is only swapping members of the class.
        void swap(int i, int j);
    
        
};
