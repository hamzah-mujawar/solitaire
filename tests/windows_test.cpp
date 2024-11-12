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

TEST(WinTests, SetWinValues){
    WIN *win;
    
    //test values where we move our window
    int startx = 7;
    int starty = 45;

    win_malloc(&win);
    win_init(win);
    win_set(win, starty, startx);
    
    //if the set values are equal to the test values then test will pass
    EXPECT_EQ(win->startx, startx);
    EXPECT_EQ(win->starty, starty);

    win_free(win);
}
