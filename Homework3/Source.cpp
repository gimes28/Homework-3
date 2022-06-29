#include <iostream>
#include <stdlib.h>
#include "Deck.h"
// #include "Sidepile.h"

using namespace std;

int main() {
    struct cardData {
        int num;
        char suit;
    };

    srand(time(NULL));

    //create deck of cards
    cardData cardInfo;
    Deck<cardData> FullDeck;

    for (int s = 0; s < 4; s++) {
        for (int n = 2; n <= 14; n++) {
            if (s == 0) {
                cardInfo = { n, 'S' };
            }
            else if (s == 1) {
                cardInfo = { n, 'C' };
            }
            else if (s == 2) {
                cardInfo = { n, 'D' };
            }
            else if (s == 3) {
                cardInfo = { n, 'H' };
            }
            FullDeck.insertCard(cardInfo);
        }
    }

    // chooses a random card from the pile
    Deck<cardData> playerDeck;
    Deck<cardData> cpuDeck;
    int counter = 0;
    while (!FullDeck.isEmpty()) {
        int num1 = rand() % FullDeck.Length();
        if (counter % 2 == 0) {
            playerDeck.insertCard(FullDeck.pickRandCard(num1));
            counter++;
        }
        else {
            cpuDeck.insertCard(FullDeck.pickRandCard(num1));
            counter++;
        }
    }
    // int* cardI = new int(1);
    // cardData cardT = {1, 'D'};
    // cardData* cardG = new cardData(cardT);
    // deckOfCards.insertCard(cardT);

    cout << playerDeck.Length() << endl;
    cout << cpuDeck.Length() << endl;

    //Totals of wins so we can tell when a total of 7 rounds have been played
    int GAMES = 10;
    int playerWins = 0;
    int compWins = 0;

    cout << "A total of 7 rounds will be played, the winner of the most games total will win." << endl;

    for (int i = 0; i < GAMES; i++) {
        //Player and computer draw cards from the deck
        //Deck<cardData> playerCard = Deck.drawCard();
        //cardData playerCard = Deck.drawCard();
    }


}