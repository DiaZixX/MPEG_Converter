#ifndef MAIN_H

#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//Custom types
typedef unsigned int ui;

//Types defined in the documentation
typedef struct bslbf{
    char* data;
    ui byte_index;
    ui bit_index;   //In [0;7]
} bslbf; 

typedef unsigned int uimsbf;
typedef signed int simsbf;
typedef int vlclbf;  //Je suis pas sur pour celui la




#endif
