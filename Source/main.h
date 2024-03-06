#ifndef MAIN_H

#define MAIN_H

#include "all_types.h"

extern ui string_to_hex(char* bit_string);
extern char* hex_to_string(ui hex, int format);
extern void eat_bitstream(bslbf* bitstream, char* bit_string);
extern char* readnbits(bslbf* bitstream, int n);
extern ui nextbits(bslbf* bitstream, char* bit_string);
extern void user_data(bslbf* bitstream);
extern bool check_horizontal_size(uimsbf h_size);
extern bool check_vertical_size(uimsbf v_size);

#endif
