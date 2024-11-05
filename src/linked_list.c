#include "../include/linked_list.h"
#include <stdio.h>
#include <stdlib.h>

list_item* create_list(Deck* deck)
{
    list l = { NULL };
    list_item* prev = NULL;
    for (int i = 0; i < DECKSIZE; i++) {
        list_item* new = malloc(sizeof(list_item));
        new->card = deck->cards[i];
        new->next = NULL;
        if (i == 0)
            l.head = new;
        else
            prev->next = new;
        prev = new;
    }
    return l.head;
}

void printlist(list_item* head)
{
    list_item* temp = head;
    while (temp != NULL) {
        printf("rank=%d suit=%d- ", temp->card.rank, temp->card.suit);
        temp = temp->next;
    }
    printf("\n");
}

void free_list(list_item* head)
{
    list_item* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
