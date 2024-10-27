
#################################
#  Author    : Mads Bay Jensen
#  Date      : Tue Oct 22 09:58:37 UTC 2024
#  License   : GPLv2
#################################

# return all .c files in SRC_DIR separated by spaces
SRC_FILES = $(wildcard src/*.c)
# UNIX-style GNU-Make jargon for: for SRC_DIR/<filename>.c:
# substitute pattern with OBJ_DIR/<filename> and return that value.
OBJ_FILES = $(patsubst src/%.c, build/%.o, $(SRC_FILES))

# compiler options
CC = gcc
CFLAGS = -O0 -pipe -g -Wall
TARGET = solitaire

all: $(OBJ_FILES)
	$(CC) $(CFLAGS) -I inc $(OBJ_FILES) -o $(TARGET)

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -I inc -c $< -o $@

clean:
	rm -rf $(wildcard build/*) $(TARGET)

.PHONY: all clean

