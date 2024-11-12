#include "../include/windows.h"
#include "../include/common.h"
#include <errno.h>
#include <ncurses.h>
#include <stdlib.h>

/*
 * Allocate memory for a WIN struct to store window information
 * We use malloc so that this memory persists beyond the function scope
 * The function checks if memory allocation was successful, if not we do error handing
 */
void win_malloc(WIN** win)
{
    if (!(*win = malloc(sizeof(**win)))) {
        // If memory allocation has failed then we handle the error to
        // ensure that we don't dereference a null pointer.
        error_generic(errno, __FILE__, __LINE__); // errno, __FILE__ and __LINE__ provide info about the source of the error
        return;
    }
    /*
     * Once we know that the memory has been allocated properly within the WIN struct
     * We use the ncurses function newwin to create a window within the struct
     */
    (*win)->window = newwin(WIN_HEIGHT, WIN_WIDTH, 0, 0);
}

/*
 * Initialise the startx and starty members of WIN struct to zero
 */
void win_init(WIN* win)
{
    win->startx = 0;
    win->starty = 0;
}
/*
 * Free all memory and delete the window created by ncurses
 */
void win_free(WIN* win)
{
    delwin(win->window);
    free(win);
}
/*
 * setter to set window x and y position and to move it using 
 * mvwin() ncurses function.
 */
void win_set(WIN* win, int starty, int startx){
    win->startx = startx;
    win->starty = starty;
    mvwin(win->window, startx, starty);
}
