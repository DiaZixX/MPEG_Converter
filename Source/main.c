#include "main.h"
#include "bench.h"

char* bitstream = "00000001";

void eat_bitstream(bslbf* bitstream, char* bit_string){
    /* Literally eat the next */
    assert(nextbits(bitstream, bit_string));
    bitstream->bit_index += strlen(bit_string);
    while (bitstream->bit_index > 7){
        bitstream->bit_index -= 8;
        bitstream->byte_index ++;
    }
}

ui nextbits(bslbf* bitstream, char* bit_string){
    /* Check if the bit_string contains the next bits to be read */
    int length = strlen(bit_string);
    char* sub_string = malloc(length*sizeof(char));
    strncpy(sub_string, (bitstream->data)+((bitstream->byte_index*8)+bitstream->bit_index), length);
    bool ret = (strcmp(sub_string, bit_string) == 0);  // 0 is the value for equality of strings
    free(sub_string);
    return ret;  
}

bool bytealigned(bslbf* bitstream){
    /* Check if the next bit is the first one of a byte */
    return bitstream->bit_index == 7;
}

void next_start_code(bslbf* bitstream){
    /* Removes the zero bit stuffing and locates next start code */
    while (!bytealigned(bitstream)){
        eat_bitstream(bitstream, "0");
    }
    while (nextbits(bitstream, "000000000000000000000001")){
        eat_bitstream(bitstream, "00000000");
    }
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