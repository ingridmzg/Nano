#pragma once
#include "Card.h"
#include "CardDeck.h"
#include "std_lib_facilities.h"

// Blackjack
class Blackjack {
    public:
        void playGame();
    private:
        CardDeck deck;
        vector<Card> playerHand;
        vector<Card> dealerHand;
        int playerHandSum = 0; //start at 0 and add the value of the cards in the hand
        int dealerHandSum = 0;
        bool isAce(const Card& c);
        int getCardValue(const Card& c);
        int getHandScore();
        int getDealerScore();
        bool askPlayerDrawCard();
        void drawPlayerCard();
        void drawDealerCard();
};