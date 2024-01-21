#include "main.h"

ui nextbits(bslbf* bitstream, int n){
    /* Return the n next bits after the current position in the bitstream */
    ui ret = 0;
    while (n > 0) {
        ret = (ret << 1) | (bitstream->data[bitstream->byte_index*8+bitstream->bit_index] & 1);
        bitstream->bit_index++;
        if (bitstream->bit_index > 7) {
            bitstream->bit_index = 0;
            bitstream->byte_index++;
        }
        n--;
    }
    return ret;
}

bool check_horizontal_size(uimsbf h_size){
    /* Return true if the vertical size is a multiple of 4096 */
    return !(h_size % 4096);
}

bool check_vertical_size(uimsbf v_size){
    /* Return true if the vertical size is a multiple of 4096 */
    return !(v_size % 4096);
}

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

int main(int argc, char* argv[]){
    test_next_bits();
    printf("\n\n");
    test_check_size();
    
    return EXIT_SUCCESS;
}