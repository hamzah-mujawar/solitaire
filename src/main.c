#include "../lib/cards/inc/cards.h"
#include "../lib/linked_list/inc/linked_list.h"
int main()
{
    struct Deck deck = createDeck();
    shuffleDeck(&deck);
    printDeck(&deck);
    list_item* l = create_list(&deck);
    printlist(l);
    return 0;
}
