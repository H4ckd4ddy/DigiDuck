const uint8_t layout[] PROGMEM = {0,0,
0,  0,//#########################################
0,  0,//#     Layout of Mac AZERTY keyboard     #
0,  0,//#       For DigiDuck by Hackdaddy       #
0,  0,//# https://github.com/H4ckD4ddy/DigiDuck #
0,  0,//#########################################
0,  0,//-------------- Data format --------------
0,  0,//
0,  0,//  Line number        ->  ASCII code
0,  0,//  1st number of line ->  HID USB code
0,  0,//  2nd number of line ->  Modifier code
0,  0,//
0,  0,//------------ Modifier format ------------
0,  0,//
0,  0,// The 2nd number of line is the modifier.
0,  0,// This modifier corresponds to the key 
0,  0,// that must be maintained to obtain the 
0,  0,// desired character.
0,  0,//
0,  0,// To add a key that must be pressed,
0,  0,// change the corresponding bit in number:
0,  0,//
0,  0,//  bit 0 -> No effect
0,  0,//  bit 1 -> Shift key
0,  0,//  bit 2 -> Alt key
0,  0,//  bit 3 -> Cmd key
0,  0,//  bit 4 -> No idea...
0,  0,//  bit 5 -> No idea...
0,  0,//  bit 6 -> No idea...
0,  0,//  bit 7 -> No idea...
0,  0,//
0,  0,//-----------------------------------------
44, 0,
40, 0,
32, 0,
100,2,
51, 0,
52, 2,
30, 0,
33, 0,
37, 0,
48, 0,
84, 0,
86, 0,
16, 0,
46, 0,
54, 2,
84, 0,
98, 0,
89, 0,
90, 0,
91, 0,
92, 0,
93, 0,
94, 0,
95, 0,
96, 0,
97, 0,
55, 0,
57, 0,
56, 0,
56, 0,
53, 2,
16, 2,
100,0,
20, 2,
5,  2,
6,  2,
7,  2,
8,  2,
9,  2,
10, 2,
11, 2,
12, 2,
13, 2,
14, 2,
15, 2,
51, 2,
17, 2,
18, 2,
19, 2,
4,  2,
21, 2,
22, 2,
23, 2,
24, 2,
25, 2,
29, 2,
27, 2,
28, 2,
26, 2,
34, 6,
55, 6,
45, 6,
50, 0,
46, 2,
49, 0,
20, 0,
5,  0,
6,  0,
7,  0,
8,  0,
9,  0,
10, 0,
11, 0,
12, 0,
13, 0,
14, 0,
15, 0,
51, 0,
17, 0,
18, 0,
19, 0,
4,  0,
21, 0,
22, 0,
23, 0,
24, 0,
25, 0,
29, 0,
27, 0,
28, 0,
26, 0,
34, 4,
15, 6,
45, 4,
17, 4,
0,  0};
