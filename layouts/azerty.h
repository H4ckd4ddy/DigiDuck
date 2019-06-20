const int8_t layout[] PROGMEM = {0,0,  0,0, //[NUL] & [SOH] (2 chars on this line in cause of synchronization between the array who begin at 0 and lines numbers who begin at 1)
0,  0, //[STX]
0,  0, //[ETX]
0,  0, //[EOT]      ###########################################
0,  0, //[ENQ]      #   Layout of standard AZERTY keyboard    #
0,  0, //[ACK]      #        For DigiDuck by Hackdaddy        #
0,  0, //[BEL]      #  https://github.com/H4ckD4ddy/DigiDuck  #
0,  0, //[BS]       ###########################################
0,  0, //[HT]       #-------------- Data format --------------#
0,  0, //[LF]       #                                         #
0,  0, //[VT]       #  Line number        ->  ASCII code      #
0,  0, //[FF]       #  1st number of line ->  HID USB code    #
0,  0, //[CR]       #  2nd number of line ->  Modifier code   #
0,  0, //[SO]       #  Comment at end     ->  Char            #
0,  0, //[SI]       #                                         #
0,  0, //[DLE]      #------------ Modifier format ------------#
0,  0, //[DC1]      #                                         #
0,  0, //[DC2]      # The 2nd number of line is the modifier. #
0,  0, //[DC3]      # This modifier corresponds to the key    #
0,  0, //[DC4]      # that must be maintained to obtain the   #
0,  0, //[NAK]      # desired character.                      #
0,  0, //[SYN]      #                                         #
0,  0, //[ETB]      # To add a key that must be pressed,      #
0,  0, //[CAN]      # change the corresponding bit in number: #
0,  0, //[EM]       #                                         #
0,  0, //[SUB]      #  bit 0 -> No idea...                    #
0,  0, //[ESC]      #  bit 1 -> Shift key                     #
0,  0, //[FS]       #  bit 2 -> No idea...                    #
0,  0, //[GS]       #  bit 3 -> No idea...                    #
0,  0, //[RS]       #  bit 4 -> No idea...                    #
0,  0, //[US]       #  bit 5 -> No idea...                    #
44, 0, //[SPACE]	  #  bit 6 -> Alt Gr                        #
40, 0, //!          #  bit 7 -> No idea...                    #
32, 0, //"          #                                         #
32, 64,//#          ###########################################
48, 0, //$
52, 2, //%
30, 0, //&
33, 0, //'
34, 0, //(
45, 0, //)
84, 0, //*
86, 0, //+
16, 0, //,
35, 0, //-
54, 2, //.
55, 2, ///
98, 0, //0
89, 0, //1
90, 0, //2
91, 0, //3
92, 0, //4
93, 0, //5
94, 0, //6
95, 0, //7
96, 0, //8
97, 0, //9
55, 0, //:
54, 0, //;
100,0, //<
46, 0, //=
100,2, //>
16, 2, //?
39, 64,//@
20, 2, //A
5,  2, //B
6,  2, //C
7,  2, //D
8,  2, //E
9,  2, //F
10, 2, //G
11, 2, //H
12, 2, //I
13, 2, //J
14, 2, //K
15, 2, //L
51, 2, //M
17, 2, //N
18, 2, //O
19, 2, //P
4,  2, //Q
21, 2, //R
22, 2, //S
23, 2, //T
24, 2, //U
25, 2, //V
29, 2, //W
27, 2, //X
28, 2, //Y
26, 2, //Z
34, 64,//[
37, 64,
45, 64,//]
47, 0, //^
37, 0, //_
36, 64,//`
20, 0, //a
5,  0, //b
6,  0, //c
7,  0, //d
8,  0, //e
9,  0, //f
10, 0, //g
11, 0, //h
12, 0, //i
13, 0, //j
14, 0, //k
15, 0, //l
51, 0, //m
17, 0, //n
18, 0, //o
19, 0, //p
4,  0, //q
21, 0, //r
22, 0, //s
23, 0, //t
24, 0, //u
25, 0, //v
29, 0, //w
27, 0, //x
28, 0, //y
26, 0, //z
33, 64,//{
35, 64,//|
46, 64,//}
31, 64,//~
0,  0};//[DEL]