#include "../include/windows.h"
#include "../include/common.h"
#include <ncurses.h>
#include <errno.h>
#include <stdlib.h>

void win_malloc(WIN **win){
    if(!(*win = malloc(sizeof(**win)))){
        error_generic(errno, __FILE__, __LINE__);
    }
    (*win)->win = newwin(WIN_HEIGHT, WIN_WIDTH, 0, 0);
}


