#include <gtest/gtest.h>

extern "C" {
#include "../include/windows.h"
#include "../include/common.h"
}

TEST(WinTests, InitWinValues){
    WIN *win;

    win_malloc(&win); //allocate memory for the window

    win_init(win); //initialise window values
    
    //Check if the window has initialised correctly
    EXPECT_EQ(win->window, nullptr);
    EXPECT_EQ(win->starty, 0);
    EXPECT_EQ(win->startx, 0);

    win_free(win);
}
