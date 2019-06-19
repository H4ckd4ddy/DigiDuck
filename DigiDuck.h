#include "DigiKeyboard.h"

// DigiDuck object is made to use all method of DigiKeyboard,
// with only print method redefined to use keyboard layout

class DigiDuckDevice: public DigiKeyboardDevice
{
  public:
    void print(String str){
      byte ascii_code;
      for(int i = 0;i < str.length();i++){  // Get string to print char by char
        ascii_code = str.charAt(i);
        ascii_code *= 2;  // Double the ascii code, cause we have a modifier for each char in keyboard layout
        DigiKeyboard.sendKeyStroke(pgm_read_word_near(layout + ascii_code),pgm_read_word_near(layout + ascii_code + 1));  // Send the key code, with the modifier
      }
    }
};

DigiDuckDevice DigiDuck = DigiDuckDevice();
