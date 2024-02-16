# MPEG_Converter

This project involves the creation of an mpeg encoder 

## Using the Makefile

You need to go to the root of the project and run the command : ```make```

If you want to clean the .o files you have created and the executable, go to the root of the project and run the command: ```make clean```

## Progression

Implemented functions of the doc :\
    - bytealigned()\
    - nextbits()\
    - next_start_code()\

Useful implemented functions :
    - eat_bitstream()

Next to do : 
    - Start code values
    - video_sequence()
            -> sequence_header()
            -> sequence_extension()
            -> ...
