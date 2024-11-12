#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/common.h"

const char *program_name = "solitaire";
/*
 * The error_generic function that is used to handle any errors
 * that might occur due to malloc() not being able to allocate
 * memory.
 */
void error_generic(int errno, char *file, int line){
    char message[ERR_BUFF_SIZE];
    snprintf(message, ERR_BUFF_SIZE, "%s: %s (%s:%d)", program_name, strerror(errno), file, line - 1);
    fprintf(stderr, "%s\n", message);
    exit(errno);
}
