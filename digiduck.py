#!/usr/bin/env python3

import sys
import os
import argparse
parser = argparse.ArgumentParser()
parser.add_argument("file", type=str,
                    help="Ducky script file to convert")
parser.add_argument("-v", "--verbose", action="store_true",
                    help="increase output verbosity")
args = parser.parse_args()

try:
    ducky_script = open(args.file, 'r')
except IOError:
    print("Error: File not found")
    sys.exit(0)

sketch_name = os.path.splitext(args.file)[0]+'.ino'
sketch = open(sketch_name, 'w+')

sketch.write('#include "DigiKeyboard.h"\n')
sketch.write('void setup() {\n')

line = ducky_script.readline()
line_number = 1
while line:
    line = line.rstrip("\n\r")
    words = line.split(' ')
    cmd = words[0].upper()
    args = words[1:]
    
    if cmd == 'REM':
        new_cmd = '// '+' '.join(args)
    elif cmd == 'DELAY':
        new_cmd = 'DigiKeyboard.delay({});'.format(args[0])
    elif cmd == 'STRING':
        new_cmd = 'DigiKeyboard.print("{}");'.format(' '.join(args))
    elif cmd == 'GUI' or cmd == 'WINDOWS':
        new_cmd = 'DigiKeyboard.sendKeyStroke(MOD_GUI_LEFT, KEY_SPACE);'.format(' '.join(args))
    elif cmd == 'UP' or cmd == 'UPARROW':
        new_cmd = 'DigiKeyboard.sendKeyStroke(KEY_ARROW_UP);'
    elif cmd == 'DOWN' or cmd == 'DOWNARROW':
        new_cmd = 'DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN);'
    elif cmd == 'LEFT' or cmd == 'LEFTARROW':
        new_cmd = 'DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT);'
    elif cmd == 'RIGHT' or cmd == 'RIGHTARROW':
        new_cmd = 'DigiKeyboard.sendKeyStroke(KEY_ARROW_RIGHT);'
    elif cmd == 'ENTER':
        new_cmd = 'DigiKeyboard.sendKeyStroke(KEY_ENTER);'
    else:
        new_cmd = ' '.join(words)
    
    print(new_cmd)
    sketch.write(new_cmd+"\n")
    line = ducky_script.readline()
    line_number += 1

sketch.write('}\n')
sketch.write('void loop(){}\n')