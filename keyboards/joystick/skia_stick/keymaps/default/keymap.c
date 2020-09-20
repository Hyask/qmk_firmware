#include QMK_KEYBOARD_H

#include "joystick.h"

#ifndef ADC_PIN
#    define ADC_PIN F6
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//      | First Joystick | Second Joystick |
  LAYOUT( JS_BUTTON0,      JS_BUTTON3,
          JS_BUTTON1,      JS_BUTTON4,
          JS_BUTTON2,      JS_BUTTON5
          )
};


//joystick config
joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
    [0] = JOYSTICK_AXIS_IN(F7, 140, 515, 835), // X
    [1] = JOYSTICK_AXIS_IN(F6, 880, 575, 100), // Y
    [2] = JOYSTICK_AXIS_IN(F5, 350, 520, 700)  // Z
};
