#include "main.h"
#include "bench.h"

/* Convert bit string into hexadecimal value*/
ui string_to_hex(char* bit_string){
    return (ui)strtol(bit_string, NULL, 2);
}

/* Convert hexadecimal value into bit string */
void hex_to_string(ui hex, char* s){
    sprintf(s, "%lx", hex);
}

/* Literally eat the next bits*/
void eat_bitstream(bslbf* bitstream, char* bit_string){
    assert(nextbits(bitstream, bit_string));
    bitstream->bit_index += strlen(bit_string);
    while (bitstream->bit_index > 7){
        bitstream->bit_index -= 8;
        bitstream->byte_index ++;
    }
}

char* readnbits(bslbf* bitstream, int n){

}

/* Check if the bit_string contains the next bits to be read */
ui nextbits(bslbf* bitstream, char* bit_string){
    int length = strlen(bit_string);
    char* sub_string = malloc(length*sizeof(char));
    strncpy(sub_string, (bitstream->data)+((bitstream->byte_index*8)+bitstream->bit_index), length);
    bool ret = (strcmp(sub_string, bit_string) == 0);  // 0 is the value for equality of strings
    free(sub_string);
    return ret;  
}

/* Check if the next bit is the first one of a byte */
bool bytealigned(bslbf* bitstream){
    return bitstream->bit_index == 7;
}

/* Removes the zero bit stuffing and locates next start code */
void next_start_code(bslbf* bitstream){
    while (!bytealigned(bitstream)){
        eat_bitstream(bitstream, "0");
    }
    while (nextbits(bitstream, "000000000000000000000001")){
        eat_bitstream(bitstream, "00000000");
    }
}

void user_data(bslbf* bitstream){
    char* token[32];
    hex_to_string(USER_DATA_START_CODE, token);
    eat_bitstream(bitstream, token);
    while (nextbits(bitstream, "000000000000000000000001")){

    }
    next_start_code(bitstream);
}

/* Return true if the vertical size is a multiple of 4096 */
bool check_horizontal_size(uimsbf h_size){
    return !(h_size % 4096);
}

/* Return true if the vertical size is a multiple of 4096 */
bool check_vertical_size(uimsbf v_size){
    return !(v_size % 4096);
}

int main(int argc, char* argv[]){
    test_next_bits();
    printf("\n\n");
    test_check_size();
    printf("\n\n");
    test_string_hex_converter();
    
    return EXIT_SUCCESS;
}