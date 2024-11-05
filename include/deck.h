#ifndef __DECK_H__
#define __DECK_H__
#include "cards.h"

struct Deck {
    struct Card cards[DECKSIZE]; // Array of cards
};
typedef struct Deck Deck;

Deck createDeck();

void shuffleDeck(Deck* deck);

void printDeck(const Deck* deck);

#endif 

