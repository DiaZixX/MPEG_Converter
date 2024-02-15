#include "bench.h"

void test_check_size(){
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
    bslbf* stream = malloc(sizeof(bslbf));
    stream->data = "101010111101000110111001";
    printf("Carac : %i\n", stream->data[5]);
    stream->bit_index = 0;
    stream->byte_index = 0;
    printf("%i\n", nextbits(stream, 3));
    printf("%i\n", nextbits(stream, 1));
    printf("%i\n", nextbits(stream, 4));
}
