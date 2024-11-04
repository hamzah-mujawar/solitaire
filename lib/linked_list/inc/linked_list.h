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

static inline list_item** find_indirect(list* l, Deck* deck);
void insert_before(list* l, list_item* before, Deck* deck);



#endif
