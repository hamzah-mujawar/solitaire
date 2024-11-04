#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
#include "../../cards/inc/cards.h"

struct list_item{
    Card card;
    struct list_item* next;
};
typedef struct list_item list_item;

struct list{
    struct list_item* head;
};
typedef struct list list;

list_item* create_list(Deck* deck);

void printlist(list_item* head);

#endif
