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
    
    return EXIT_SUCCESS;
}