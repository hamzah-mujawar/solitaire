#include "../inc/cards.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct Deck createDeck()
{
    struct Deck deck;
    int index = 0;
    for (int suit = clubs; suit <= spades; suit++) {
        for (int rank = ace; rank <= king; rank++) {
            deck.cards[index].rank = rank;
            deck.cards[index].suit = suit;
            index++;
        }
    }

    return deck;
}

void shuffleDeck(struct Deck* deck)
{ // Fisher-Yates Algo
    srand(time(0));

    for (int i = DECKSIZE - 1; i > 0; i--) {
        int r = rand() % (i + 1);
        struct Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[r];
        deck->cards[r] = temp;
    }
}

void printDeck(const struct Deck* deck)
{
    for (int i = 0; i < DECKSIZE; i++) {
        printf("Card %d: Rank = %d, Suit = %d\n", i + 1, deck->cards[i].rank, deck->cards[i].suit);
    }
}

