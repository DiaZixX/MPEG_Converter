#include "main.h"
#include "bench.h"

char* bitstream = "00000001";

void parse(){
    //A faire
}

ui nextbits(bslbf* bitstream, char* bit_string){
    /* Check if the bit_string contains the next bits to be read */
    // A refaire
    return 0;
}

bool bytealigned(bslbf* bitstream){
    /* Check if the next bit is the first one of a byte */
    return bitstream->bit_index == 7;
}

bool check_horizontal_size(uimsbf h_size){
    /* Return true if the vertical size is a multiple of 4096 */
    return !(h_size % 4096);
}

bool check_vertical_size(uimsbf v_size){
    /* Return true if the vertical size is a multiple of 4096 */
    return !(v_size % 4096);
}



int main(int argc, char* argv[]){
    test_next_bits();
    printf("\n\n");
    test_check_size();
    
    return EXIT_SUCCESS;
}