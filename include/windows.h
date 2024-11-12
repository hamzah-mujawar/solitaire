#ifndef __WINDOWS_H__
#define __WINDOWS_H__

#include <ncurses.h>

//Setting the width and the height of the windows for the cards
#define WIN_WIDTH  7
#define WIN_HEIGHT 5

/*
 * This structure encapsulates the position of the window (x, y) 
 * and provides a window reference which can be passed to functions
*/
struct win_struct{
    int startx, starty;
    WINDOW *window;
};
typedef struct win_struct WIN;


// -------------------- Function Definitions -------------------
void win_malloc(WIN **);
void win_init(WIN *);
void win_free(WIN *);
void win_set(WIN *, int, int);

#endif  
