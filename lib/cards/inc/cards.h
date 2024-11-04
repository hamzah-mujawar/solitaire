#ifndef __CARDS_H__
#define __CARDS_H__

#define DECKSIZE 52

enum Card_Categories {
    clubs,
    diamonds,
    hearts,
    spades,
};

enum Card_Names {
    ace,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king
};

struct Card {
    enum Card_Names rank;
    enum Card_Categories suit;
};
typedef struct Card Card;

struct Deck {
    struct Card cards[DECKSIZE]; // Array of cards
};
typedef struct Deck Deck;

Deck createDeck();

void shuffleDeck(Deck* deck);

void printDeck(const Deck* deck);


#endif 
