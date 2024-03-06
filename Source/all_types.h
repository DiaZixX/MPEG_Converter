#ifndef ALL_TYPES

#define ALL_TYPES

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>

//#define SEQUENCE_END_CODE "00000000000000000000000110110111"  // 0x000001b7
//#define SEQUENCE_HEADER_CODE "00000000000000000000000110110011" // 0x000001b3
//#define EXTENSION_START_CODE "00000000000000000000000000000000" // 

typedef enum {
    PICTURE_START_CODE   = 0x00,
    SLICE_START_CODE_B   = 0x01,
    SLICE_START_CODE_E   = 0xaf,
    USER_DATA_START_CODE = 0xb2,
    SEQUENCE_HEADER_CODE = 0xb3,
    SEQUENCE_ERROR_CODE  = 0xb4,
    EXTENSION_START_CODE = 0xb5,
    SEQUENCE_END_CODE    = 0xb7,
    GROUP_START_CODE     = 0xb8,
    SYSTEM_START_CODE_B  = 0xb9,
    SYSTEM_START_CODE_E  = 0xff,
} START_CODE_VALUES;

//Custom types
typedef uint64_t ui;

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
