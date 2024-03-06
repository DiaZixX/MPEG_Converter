#ifndef ALL_TYPES

#define ALL_TYPES

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

//#define SEQUENCE_END_CODE "00000000000000000000000110110111"  // 0x000001b7
//#define SEQUENCE_HEADER_CODE "00000000000000000000000110110011" // 0x000001b3
//#define EXTENSION_START_CODE "00000000000000000000000000000000" // 

#define LENGTH_SCV 32

typedef enum {
    PICTURE_START_CODE   = 0x00000100,
    SLICE_START_CODE_B   = 0x00000101,
    SLICE_START_CODE_E   = 0x000001af,
    USER_DATA_START_CODE = 0x000001b2,
    SEQUENCE_HEADER_CODE = 0x000001b3,
    SEQUENCE_ERROR_CODE  = 0x000001b4,
    EXTENSION_START_CODE = 0x000001b5,
    SEQUENCE_END_CODE    = 0x000001b7,
    GROUP_START_CODE     = 0x000001b8,
    SYSTEM_START_CODE_B  = 0x000001b9,
    SYSTEM_START_CODE_E  = 0x000001ff,
} START_CODE_VALUES;

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
typedef int vlclbf;  



#endif 
