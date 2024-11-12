#include "../include/windows.h"
#include "../include/common.h"
#include <ncurses.h>
#include <errno.h>
#include <stdlib.h>

/*
 * Allocate memory for a WIN struct to store window information
 * We use malloc so that this memory persists beyond the function scope
 * The function checks if memory allocation was successful, if not we do error handing
 */
void win_malloc(WIN **win){
    if(!(*win = malloc(sizeof(**win)))){
    //If memory allocation has failed then we handle the error to
    //ensure that we don't dereference a null pointer.
        error_generic(errno, __FILE__, __LINE__); // errno, __FILE__ and __LINE__ provide info about the source of the error
        return;
    }
    /*
     * Once we know that the memory has been allocated properly within the WIN struct
     * We use the ncurses function newwin to create a window within the struct
     */
    (*win)->window = newwin(WIN_HEIGHT, WIN_WIDTH, 0, 0);
}


