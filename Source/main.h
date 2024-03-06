#ifndef MAIN_H

#define MAIN_H

#include "all_types.h"

extern ui string_to_hex(char* bit_string);
extern void hex_to_string(ui hex, char* s);
extern ui nextbits(bslbf* bitstream, char* bit_string);
extern bool check_horizontal_size(uimsbf h_size);
extern bool check_vertical_size(uimsbf v_size);

#endif
