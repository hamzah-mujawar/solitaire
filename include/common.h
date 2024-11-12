#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdbool.h>

#define ERR_BUFF_SIZE 100 //buffer for any errors

extern const char *program_name;
//-------------------- Function Definitions-------------------
void error_generic(int, char *, int);

#endif 
