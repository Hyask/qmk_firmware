#include QMK_KEYBOARD_H

#include "action_layer.h"

#include <print.h>
#include <joystick.h>
#include <avr/pro_micro.h>
#include <analog.h>

joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
  [0] = JOYSTICK_AXIS_VIRTUAL,
  [1] = JOYSTICK_AXIS_VIRTUAL,
  [2] = JOYSTICK_AXIS_IN(ADC7, 600, 300, 0),
};

static void print_analog_pins(void) {
  int16_t val3 = analogRead(7);
  print("  7:"); print_dec(7);
  print(" val3:"); print_decs(val3); println();
}


#define _QWERTY 0
#define _FLIGHT_MODE 1


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

//Switch Layouts
#define SWQWERTY DF(_QWERTY)
#define SWFLIGHT DF(_FLIGHT_MODE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 *   http://www.keyboard-layout-editor.com/#/gists/dcf0e81431c5816b875822b7c6f47b6c
 *   ,-----------------------------------------------------. ,-----------------------------------------------------.
 *   | Esc |MWClk| Esc |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 | |  F7 |  F8 |  F9 | F10 | F11 | F12 |PrtSc| Del | Esc |
 *   |-----+-----+-----+-----+-----+-----+-----+-----+-----| |-----+-----+-----+-----+-----+-----+-----+-----+-----|
 *   |Home | >|| |     |  `  |  1  |  2  |  3  |  4  |  5  | |  6  |  7  |  8  |  9  |  0  |  -  |  =  |BckSp|Home |
 *   |-----+-----|-----+-----+-----+-----+-----+-----+-----+ +-----|-----+-----+-----+-----+-----+-----+-----+-----+
 *   | End |VolUp| Tab | Tab |  q  |  w  |  e  |  r  |  t  | |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |Enter| End |
 *   |-----+-----|-----+-----+-----+-----+-----+-----+-----+ +-----|-----+-----+-----+-----+-----+-----+-----+-----+
 *   | PUp |VolDn|Caps |Shift|  a  |  s  |  d  |  f  |  g  | |  h  |  j  |  k  |  l  |  ;  |  '  |  \  |Enter| PUp |
 *   |-----+-----|-----+-----+-----+-----+-----+-----+-----+ +-----|-----+-----+-----+-----+-----+-----+-----+-----+
 *   |PDown|Mute | Up  |Shift|  z  |  x  |  c  |  v  |  b  | |  n  |  m  |  ,  |  .  |  /  |Shift| Up  | Tab |PDown|
 *   |-----+-----|-----+-----+-----+-----+-----+-----+-----+ +-----|-----+-----+-----+-----+-----+-----+-----+-----+
 *   |Enter|Left |Down |Right|Ctrl | Tux | Alt |Space|Space| |Space|Space| Alt | Tux |Ctrl |Left |Down |Right|Enter|
 *   `-----+-----+-----+-----+-----+-----+-----+-----+-----' `-----+-----+-----+-----+-----+-----+-----+-----+-----'
 *
 */
[_QWERTY] = LAYOUT( \
    KC_ESC,   SWFLIGHT, KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,  KC_F12,  KC_PSCR, KC_DEL,  KC_ESC, \
    KC_HOME,  KC_MPLY,  KC_BTN3,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,    KC_5,             KC_6,    KC_7,    KC_8,     KC_9,     KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME, \
    KC_END,   KC_VOLU,  KC_TAB,   KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,    KC_LBRC, KC_RBRC, KC_ENT,  KC_END, \
    KC_PGUP,  KC_VOLD,  KC_CAPS,  KC_LSFT,  KC_A,     KC_S,     KC_D,     KC_F,    KC_G,             KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,  KC_PGUP, \
    KC_PGDN,  KC_MUTE,  KC_UP,    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, KC_RSFT, KC_UP,   KC_TAB,  KC_PGDN, \
    KC_ENT,   KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_LCTL,  KC_LGUI,  KC_LALT,  KC_SPC,  KC_SPC,           KC_SPC,  KC_SPC,  KC_RALT,  KC_RGUI,  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT  \
),

/*
 *   ,-----------------------------------------------------. ,-----------------------------------------------------.
 *   | Esc | SwL | Esc |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 | |  F7 |  F8 |  F9 | F10 | F11 | F12 |PrtSc| Del |     |
 *   |-----+-----+-----+-----+-----+-----+-----+-----+-----| |-----+-----+-----+-----+-----+-----+-----+-----+-----|
 *   |Home | >|| |     |  ²  |  &  |  é  |  "  |  '  |  (  | |  -  |  è  |  _  |  ç  |  à  |  )  |  =  |BckSp|     |
 *   |-----+-----|-----+-----+-----+-----+-----+-----+-----+ +-----|-----+-----+-----+-----+-----+-----+-----+-----+
 *   | End |VolUp| Tab | Tab |  a  |  z  |  e  |  r  |  t  | |  y  |  u  |  i  |  o  |  p  |  ^  |  $  |Enter|     |
 *   |-----+-----|-----+-----+-----+-----+-----+-----+-----+ +-----|-----+-----+-----+-----+-----+-----+-----+-----+
 *   | PUp |VolDn|Caps |Shift|  q  |  s  |  d  |  f  |  g  | |  h  |  j  |  k  |  l  |  m  |  ù  |  *  |Enter|     |
 *   |-----+-----|-----+-----+-----+-----+-----+-----+-----+ +-----|-----+-----+-----+-----+-----+-----+-----+-----+
 *   |PDown|Mute | Up  |Shift|  w  |  x  |  c  |  v  |  b  | |  n  |  ,  |  ;  |  :  |  !  |Shift| Up  |     |     |
 *   |-----+-----|-----+-----+-----+-----+-----+-----+-----+ +-----|-----+-----+-----+-----+-----+-----+-----+-----+
 *   |Enter|Left |Down |Right|Ctrl | Tux | Alt |Space|Space| |Space|Space| Alt | Tux |Ctrl |Left |Down |Right|     |
 *   `-----+-----+-----+-----+-----+-----+-----+-----+-----' `-----+-----+-----+-----+-----+-----+-----+-----+-----'
 *
 */
[_FLIGHT_MODE] = LAYOUT( \
    _______,    SWQWERTY,    _______,   _______,    _______,    _______,     _______,     _______,   _______,            _______,    _______,    _______,    _______,   _______,   _______,  _______,  _______,  _______, \
    JS_BUTTON0, JS_BUTTON1,  JS_BUTTON2,   _______,    _______,    _______,     _______,     _______,   _______,            _______,    _______,    _______,    _______,   _______,   _______,  _______,  _______,  _______, \
    KC_P7,      KC_P8,       KC_P9,     _______,    _______,    _______,     _______,     _______,   _______,            _______,    _______,    _______,    _______,   _______,   _______,  _______,  _______,  _______, \
    KC_P4,      KC_P5,       KC_P6,     _______,    _______,    _______,     _______,     _______,   _______,            _______,    _______,    _______,    _______,   _______,   _______,  _______,  _______,  _______, \
    KC_P1,      KC_P2,       KC_P3,     _______,    _______,    _______,     _______,     _______,   _______,            _______,    _______,    _______,    _______,   _______,   _______,  _______,  _______,  _______, \
    _______,    _______,     _______,   _______,    _______,    _______,     _______,     _______,   _______,            _______,    _______,    _______,    _______,   _______,   _______,  _______,  _______,  _______  \
),


};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case _FLIGHT_MODE:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_FLIGHT_MODE);
          }
          break;
        case _QWERTY:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_QWERTY);
          }
          break;
      }
    return MACRO_NONE;
};

#ifdef JOYSTICK_ENABLE
static uint8_t axesFlags = 0;
enum Axes{
  Precision = 1,
  Axis1High = 2,
  Axis1Low = 4,
  Axis2High = 8,
  Axis2Low = 16
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode){
#ifdef JOYSTICK_ENABLE
    // virtual joystick
    #if JOYSTICK_AXES_COUNT>1
    case KC_P8:
      if (record->event.pressed){
        joystick_status.axes[1] = -127;
        axesFlags |= Axis2Low;
      } else {
        joystick_status.axes[1] = 0;
        axesFlags &= ~Axis2Low;
      }
      joystick_status.status |= JS_UPDATED;
    break;
    case KC_P2:
      if (record->event.pressed){
        joystick_status.axes[1] = 127;
        axesFlags |= Axis2High;
      } else {
        joystick_status.axes[1] = 0;
        axesFlags &= ~Axis2High;
      }
      joystick_status.status |= JS_UPDATED;
    break;
    #endif
    case KC_P4:
      if (record->event.pressed){
        joystick_status.axes[0] = -127;
        axesFlags |= Axis1Low;
      } else {
        joystick_status.axes[0] = 0;
        axesFlags &= ~Axis1Low;
      }
      joystick_status.status |= JS_UPDATED;
    break;
    case KC_P6:
      if (record->event.pressed){
        joystick_status.axes[0] = 127;
        axesFlags |= Axis1High;
      } else {
        joystick_status.axes[0] = 0;
        axesFlags &= ~Axis1High;
      }
      joystick_status.status |= JS_UPDATED;
    break;
    case KC_P5:
    if (record->event.pressed){
        axesFlags |= Precision;
      } else {
        axesFlags &= ~Precision;
      }
    joystick_status.status |= JS_UPDATED;
    break;
#endif
  }
  print_analog_pins();

  return true;
}
