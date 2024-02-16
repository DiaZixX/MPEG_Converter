# MPEG_Converter

This project involves the creation of an mpeg encoder 

## Using the Makefile

You need to go to the root of the project and run the command : ```make```

If you want to clean the .o files you have created and the executable, go to the root of the project and run the command: ```make clean```

## Progression

Implemented functions of the doc :\
&nbsp;&nbsp;    * bytealigned()\
&nbsp;&nbsp;    * nextbits()\
&nbsp;&nbsp;    * next_start_code()\

Useful implemented functions :\
&nbsp;&nbsp;    * eat_bitstream()\

Next to do :\
&nbsp;&nbsp;    * Start code values\
&nbsp;&nbsp;    * video_sequence()\
&nbsp;&nbsp;&nbsp;&nbsp;            -> sequence_header()\
&nbsp;&nbsp;&nbsp;&nbsp;            -> sequence_extension()\
&nbsp;&nbsp;&nbsp;&nbsp;            -> ...\
