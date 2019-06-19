# DigiDuck

A ducky script parser and converter to DigiSparks Sketch

Why buy a rubber ducky for 45$ when you can buy a DigiSpark for 1$ ?

This script can convert a ducky script file to an Arduino Digispark sketch without passing by an useless compiled binary.


### Why ?

All project I'v found to do this jobs use the rubber ducky compiler and then addapt the payload for Digispark. But its useless and that does not allow you to modify the sketch later

Anyway, even if a simple convertion script is pretty simple, the hardest issue is the compatibility with differents keyboards layouts.
So, instead of an ugly char convertion, DigiDuck send the good combination of keys to produce the char at the runtime. The layout file use a direct correspondence between the ASCII code and the HID USB code.

### Usage

Convert a script for the default keyboard layout (azerty) : 

```
./digiduck.py input_ducky_script.txt
```

Use a different keyboard layout :

```
./digiduck.py input_ducky_script.txt --keyboard mac_azerty
```
