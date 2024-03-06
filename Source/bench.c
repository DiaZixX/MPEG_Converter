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

void test_string_hex_converter(){
    printf("<=====[TEST OF HEX/STRING CONVERTER]=====>\n");
    char* test1 = "00011101001011110000"; //1d2f0
    ui res1 = string_to_hex(test1);  
    printf("%lx\n", res1);
    char res2[64] = "";
    hex_to_string(res1, res2);
    printf("%s\n", res2);
}
