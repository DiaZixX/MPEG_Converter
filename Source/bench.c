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
    free(stream);
}

void test_string_hex_converter(){
    printf("<=====[TEST OF HEX/STRING CONVERTER]=====>\n");
    char* test1 = "00011101001011110000"; //1d2f0
    ui res1 = string_to_hex(test1);  
    printf("%x\n", res1);
    char* res2 = hex_to_string(res1, 32);
    printf("%s\n", res2);
    free(res2);
}

void test_user_data(){
    printf("<=====[TEST OF USER_DATA]=====>\n");
    bslbf* stream = malloc(sizeof(bslbf));
    stream->data = "10110010101010111101000110111001000000000000000000000001";
    stream->bit_index = 0;
    stream->byte_index = 0;
    user_data(stream);
    free(stream);
}
