#include "../lib/cards/inc/cards.h"
int main()
{
    struct Deck deck = createDeck();
    shuffleDeck(&deck);
    printDeck(&deck);
    return 0;
}
