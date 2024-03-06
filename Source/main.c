#include "main.h"
#include "bench.h"

/* Convert bit string into hexadecimal value*/
ui string_to_hex(char* bit_string){
    return (ui)strtol(bit_string, NULL, 2);
}

/* Convert hexadecimal value into bit string */
char* hex_to_string(ui hex, int format){
    char *s = malloc(format*sizeof(char));
    for (int i = format-1; i >= 0; i--){
        s[i] = (hex & 1) ? '1' : '0';    
        hex >>= 1;
    }
    return s;
}

/* Literally eat the next bits*/
void eat_bitstream(bslbf* bitstream, char* bit_string){
    assert(nextbits(bitstream, bit_string));
    bitstream->bit_index += strlen(bit_string);
    while (bitstream->bit_index > 7){
        bitstream->bit_index -= 8;
        bitstream->byte_index++;
    }
}

char* readnbits(bslbf* bitstream, int n){
    char* output = malloc(n*sizeof(char));
    for (int i = 0; i < n; i++){
        output[i] = bitstream->data[bitstream->byte_index*8+bitstream->bit_index];
        bitstream->bit_index++;
        if (bitstream->bit_index > 7){
            bitstream->bit_index = 0;
            bitstream->byte_index++;
        }
    }
    return output;
}

/* Check if the bit_string contains the next bits to be read */
ui nextbits(bslbf* bitstream, char* bit_string){
    int length = strlen(bit_string);
    char* sub_string = calloc(length+1,sizeof(char));
    strncpy(sub_string, (bitstream->data)+((bitstream->byte_index*8)+bitstream->bit_index), length);
    bool ret = (strcmp(sub_string, bit_string) == 0);  // 0 is the value for equality of strings
    free(sub_string);
    return ret;  
}

/* Check if the next bit is the first one of a byte */
bool bytealigned(bslbf* bitstream){
    return bitstream->bit_index == 0;
}

/* Removes the zero bit stuffing and locates next start code */
void next_start_code(bslbf* bitstream){
    while (!bytealigned(bitstream)){
        eat_bitstream(bitstream, "0");
    }
    while (!nextbits(bitstream, "000000000000000000000001")){
        eat_bitstream(bitstream, "00000000");
    }
}

void extension_and_user_data(bslbf* bitstream, int i){
    while (nextbits(bitstream, hex_to_string(EXTENSION_START_CODE, LENGTH_SCV)) ||
           nextbits(bitstream, hex_to_string(USER_DATA_START_CODE, LENGTH_SCV))){
        if (i != 1){
            if (nextbits(bitstream, hex_to_string(EXTENSION_START_CODE, LENGTH_SCV))){
                extension_data(bitstream, i);
            }
        }
        if (nextbits(bitstream, hex_to_string(USER_DATA_START_CODE, LENGTH_SCV))){
            user_data(bitstream);
        }
    }
}

void extension_data(bslbf* bitstream, int i){
    
}

void user_data(bslbf* bitstream){
    char* token = hex_to_string(USER_DATA_START_CODE, LENGTH_SCV);
    eat_bitstream(bitstream, token);
    free(token);
    while (!nextbits(bitstream, "000000000000000000000001")){
        char *data = readnbits(bitstream, 8);
        printf("User Data : %s\n", data);
        free(data);
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
    //test_next_bits();
    //printf("\n\n");
    //test_check_size();
    //printf("\n\n");
    //test_string_hex_converter();
    //printf("\n\n");
    //test_user_data();
    
    return EXIT_SUCCESS;
}