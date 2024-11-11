#include "../include/deck.h"
#include "../include/linked_list.h"

#include <ncurses.h>


int main()
{
    initscr();
    start_color();
    assume_default_colors(COLOR_BLACK, COLOR_GREEN);
    refresh();
    getch();


    return 0;
}
