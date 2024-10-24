#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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

struct Deck {
    int deckSize;
    struct Card cards[52];  // Array of cards
};


struct Deck createDeck() {
    struct Deck deck;
    deck.deckSize = 52;

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


void shuffleDeck(struct Deck* deck) { //Fisher-Yates Algo
    srand(time(0));  

    for (int i = 51; i > 0; i--) {
        int r = rand() % (i + 1); 
        struct Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[r];
        deck->cards[r] = temp;
    }
}

void printDeck(const struct Deck* deck) {
    for (int i = 0; i < deck->deckSize; i++) {
        printf("Card %d: Rank = %d, Suit = %d\n", i + 1, deck->cards[i].rank, deck->cards[i].suit);
    }
}

int main() {
    struct Deck deck = createDeck();
    shuffleDeck(&deck);               
    printDeck(&deck);                 

    return 0;
}
