#include "Blackjack.h"

bool Blackjack::isAce(const Card& c) { //check if the card is an ace
    return c.getRank() == Rank::ace; //if the rank of the card is ace, return true
}

int Blackjack::getCardValue(const Card& c) {
    if (isAce(c)) {
        return 11; //as default, the value of the ace is 11
    } else if (c.getRank() >= Rank::jack) {
        return 10; //if the rank of the card is equal to or greater than jack (card with image), return 10
    } else {
        return static_cast<int>(c.getRank()); //c.getRank() returns the rank of the card, and static_cast<int> converts the rank to an integer
    }
}

int Blackjack::getHandScore() {
    int score = 0; //start at 0 and add the value of the cards in the hand
    int aceCount = 0;
    for (const Card& c : playerHand) { //for each card in the player's hand
        score += getCardValue(c); //add the value of the card to the score
        if (isAce(c)) { //if the card is an ace
            ++aceCount; //increment the ace count
        }
    }
    while (score > 21 && aceCount > 0) { //if the score is greater than 21 and there are aces in the hand
        score -= 10; //subtract 10 from the score
        --aceCount; //decrement the ace count
    }
    return score;
}

int Blackjack::getDealerScore() {
    int score = 0; 
    int aceCount = 0;
    for (const Card& c : dealerHand) { 
        score += getCardValue(c); //add the value of the card to the score
        if (isAce(c)) {
            ++aceCount;
        }
    }
    while (score > 21 && aceCount > 0) { //if the score is greater than 21 and there are aces in the hand
        score -= 10; //subtract 10 from the score
        --aceCount; //decrement the ace count
    }
    return score;
}

void Blackjack::drawPlayerCard() { //draw a card for the player
    Card c = deck.drawCard(); //draw a card from the deck
    playerHand.push_back(c); //add the card to the player's hand
    playerHandSum = getHandScore(); //get the score of the player's hand
}

void Blackjack::drawDealerCard() { //draw a card for the dealer
    Card c = deck.drawCard(); //draw a card from the deck
    dealerHand.push_back(c); //add the card to the dealer's hand
    dealerHandSum = getDealerScore(); //get the score of the dealer's hand
}

bool Blackjack::askPlayerDrawCard() {
    cout << "Player hand: " << endl;
    for (const Card& c : playerHand) {
        cout << c.toString() << endl; //c.toString() returns the string representation of the card
    }
    cout << "Player hand score: " << playerHandSum << endl;

    cout << "Do you want to draw a card? (y/n) ";
    char answer;
    cin >> answer;
    return answer == 'y';
}

void Blackjack::playGame() {
    deck.shuffle();
    drawPlayerCard();
    drawPlayerCard();
    drawDealerCard();
    drawDealerCard();

    while (askPlayerDrawCard()) { //ask the player if they want to draw a card
        drawPlayerCard(); //draw a card for the player
        cout << "Player hand score: " << playerHandSum << endl; //print the score of the player's hand
        if (playerHandSum > 21) {
            break;
        }
    }

    while (dealerHandSum < 17) {
        drawDealerCard();
    }

    cout << "Dealer hand: " << dealerHandSum << endl;

    if (playerHandSum > 21) {
        cout << "Player busts!" << endl; //player has more than 21
    } else if (dealerHandSum > 21) {
        cout << "Dealer busts!" << endl;
    } else if (playerHandSum > dealerHandSum) {
        cout << "Player wins!" << endl;
    } else if (dealerHandSum > playerHandSum) {
        cout << "Dealer wins!" << endl;
    } else {
        cout << "Tie!" << endl; //same score player and dealer
    }
}