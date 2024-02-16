#include "bench.h"
#include "main.h"

void test_check_size(){
    printf("<=====[TEST OF CHECKSIZE]=====>\n");
    if (check_horizontal_size(4096)) {
        printf("True\n");
    }
    if (!check_horizontal_size(4097)) {
        printf("False\n");
    }
    if (check_vertical_size(4096)) {
        printf("True\n");
    }
    if (!check_vertical_size(4097)) {
        printf("False\n");
    }
}

void test_next_bits(){
    printf("<=====[TEST OF NEXTBITS]=====>\n");
    bslbf* stream = malloc(sizeof(bslbf));
    stream->data = "101010111101000110111001";
    stream->bit_index = 0;
    stream->byte_index = 0;
    if (nextbits(stream, "101010")) {
        printf("GOOD\n");
    }
    else {
        printf("BAD\n");
    }
}
