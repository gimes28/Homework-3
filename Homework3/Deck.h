#pragma once
#ifndef DECK_h
#define DECK_h

#include "Exception.h"

template <class T>
class Deck {
private:
    struct Card {
        T data;
        Card* next;
    };
    Card* head;
    Card* rear;
    int numCards;
    const int SIZE = 52;
public:
    Deck();
    T drawCard();    //dequeue
    void insertCard(T);  //enqueue
    T pickRandCard(int);  // chooses card from random position
    bool isFull();
    bool isEmpty();
    int Length();
};

template<class T>
Deck<T>::Deck() {
    head = NULL;
    rear = NULL;
    numCards = 0;
}

template<class T>
void Deck<T>::insertCard(T newCard) {  // inserts card at the bottom of the deck
    if (isFull()) {
        throw Exception("Deck is full");
    }
    Card* nn = new Card;
    nn->data = newCard;
    nn->next = NULL;
    if (isEmpty()) {
        head = nn;
        rear = nn;
    }
    else {
        rear->next = nn;
        rear = nn;
    }
    numCards++;
}

template<class T>
T Deck<T>::drawCard() {  // returns card at the top of deck
    if (isEmpty()) {
        throw Exception("Deck is empty");
    }
    T retCard = head->data;
    Card* oh = head;
    head = head->next;
    delete oh;
    numCards--;
    return retCard;
}

template<class T>  // returns a card given a random position
T Deck<T>::pickRandCard(int pos) {
    Card* h = head;
    Card* prev;

    if (pos == 0) {
        return drawCard();
    }

    if (pos == 1) {
        h = head->next;
        head->next = head->next->next;
        T retval = h->data;
        delete h;
        numCards--;
        return retval;
    }
    for (int i = 0; i <= pos; i++) {
        prev = h;
        h = h->next;
        if (i == pos - 1) {
            prev->next = h->next;
            T retval = h->data;
            delete h;
            numCards--;
            return retval;
        }
    }
}

template<class T>
bool Deck<T>::isFull() {
    return numCards == SIZE;
}

template<class T>
bool Deck<T>::isEmpty() {
    return numCards == 0;
}

template<class T>
int Deck<T>::Length() {
    return numCards;
}

#endif
