#!/usr/bin/env python3

import sys
import os
import argparse
from shutil import copyfile

parser = argparse.ArgumentParser()
parser.add_argument("file", type=str,
                    help="Ducky script file to convert")
parser.add_argument("-k", "--keyboard", type=str,
                    help="Change target keyboard layout")
parser.add_argument("-v", "--verbose", action="store_true",
                    help="increase output verbosity")
args = parser.parse_args()

try:
    ducky_script = open(args.file, 'r')
except IOError:
    print("Error: File not found")
    sys.exit(0)

sketch_name = os.path.splitext(args.file)[0]
os.mkdir(sketch_name)
sketch = open(sketch_name+'/'+sketch_name+'.ino', 'w+')
copyfile('DigiDuck.h',sketch_name+'/'+'DigiDuck.h')


if args.keyboard:
    layout = args.keyboard
else:
    layout = 'mac_azerty'

if os.path.isfile('layouts/'+layout+'.h'):
    copyfile('layouts/'+layout+'.h',sketch_name+'/'+layout+'.h')
else:
    print('Error: Keyboard layout "{}" not found'.format(layout))
    sys.exit(0)


sketch.write('#include "{}.h"\n'.format(layout))
sketch.write('#include "DigiDuck.h"\n')
sketch.write('\n')
sketch.write('void setup() {\n')
sketch.write('  pinMode(0, OUTPUT);\n')
sketch.write('  pinMode(1, OUTPUT);\n')

keys = {
    'SPACE': 'KEY_SPACE',
    'GUI': 'MOD_GUI_LEFT',
    'WINDOWS': 'MOD_GUI_LEFT',
    'ESCAPE': 'KEY_ESC',
    'UP': 'KEY_ARROW_UP',
    'UPARROW': 'KEY_ARROW_UP',
    'DOWN': 'KEY_ARROW_DOWN',
    'DOWNARROW': 'KEY_ARROW_DOWN',
    'LEFT': 'KEY_ARROW_LEFT',
    'LEFTARROW': 'KEY_ARROW_LEFT',
    'RIGHT': 'KEY_ARROW_RIGHT',
    'RIGHTARROW': 'KEY_ARROW_RIGHT',
    'ALT': 'MOD_ALT_LEFT',
    'CTRL': 'MOD_CONTROL_LEFT',
    'CONTROL': 'MOD_CONTROL_LEFT',
    'TAB': 43
}

def key(input):
    if input in keys:
        return keys[input]
    else:
        return ('KEY_'+input.upper())

line = ducky_script.readline()
line_number = 1
while line:
    line = line.rstrip("\n\r")
    words = line.split(' ')
    cmd = words[0].upper()
    options = words[1:]
    
    if cmd == 'REM':
        new_cmd = '// '+' '.join(options)
    elif cmd == 'DEFAULT_DELAY':
        new_cmd = ''
    elif cmd == 'DELAY':
        new_cmd = 'DigiDuck.delay({});'.format(options[0])
    elif cmd == 'STRING':
        new_cmd = 'DigiDuck.print("{}");'.format(' '.join(options))
    elif len(options) == 0:
        new_cmd = 'DigiDuck.sendKeyStroke({});'.format(key(cmd))
    else:
        keys_to_send = []
        for option in words:
            keys_to_send.append(key(option))
        keys_to_send = reversed(keys_to_send)
        new_cmd = 'DigiDuck.sendKeyStroke({});'.format(','.join(keys_to_send))
    
    print(new_cmd)
    sketch.write('  '+new_cmd+'\n')
    line = ducky_script.readline()
    line_number += 1

sketch.write('}\n')
sketch.write('\n')
sketch.write('void loop(){\n')
sketch.write('  digitalWrite(0, HIGH);\n')
sketch.write('  digitalWrite(1, HIGH);\n')
sketch.write('  delay(100);\n')
sketch.write('  digitalWrite(0, LOW);\n')
sketch.write('  digitalWrite(1, LOW);\n')
sketch.write('  delay(100);\n')
sketch.write('}\n')