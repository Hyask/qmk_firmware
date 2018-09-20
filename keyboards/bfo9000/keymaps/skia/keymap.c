#include QMK_KEYBOARD_H

#include "action_layer.h"



#define _QWERTY 0
#define _AZERTY 1


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

//Switch Layouts
#define SWQWERTY DF(_QWERTY)
#define SWAZERTY DF(_AZERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 *   http://www.keyboard-layout-editor.com/#/gists/dcf0e81431c5816b875822b7c6f47b6c
 *   ,-----------------------------------------------------. ,-----------------------------------------------------.
 *   | Esc |MWClk| Esc |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 | |  F7 |  F8 |  F9 | F10 | F11 | F12 |PrtSc| Del |     |
 *   |-----+-----+-----+-----+-----+-----+-----+-----+-----| |-----+-----+-----+-----+-----+-----+-----+-----+-----|
 *   |Home | >|| |     |  `  |  1  |  2  |  3  |  4  |  5  | |  6  |  7  |  8  |  9  |  0  |  -  |  =  |BckSp|     |
 *   |-----+-----|-----+-----+-----+-----+-----+-----+-----+ +-----|-----+-----+-----+-----+-----+-----+-----+-----+
 *   | End |VolUp| Tab | Tab |  q  |  w  |  e  |  r  |  t  | |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |Enter|     |
 *   |-----+-----|-----+-----+-----+-----+-----+-----+-----+ +-----|-----+-----+-----+-----+-----+-----+-----+-----+
 *   | PUp |VolDn|Caps |Shift|  a  |  s  |  d  |  f  |  g  | |  h  |  j  |  k  |  l  |  ;  |  '  |  \  |Enter|     |
 *   |-----+-----|-----+-----+-----+-----+-----+-----+-----+ +-----|-----+-----+-----+-----+-----+-----+-----+-----+
 *   |PDown|Mute | Up  |Shift|  z  |  x  |  c  |  v  |  b  | |  n  |  m  |  ,  |  .  |  /  |Shift| Up  |     |     |
 *   |-----+-----|-----+-----+-----+-----+-----+-----+-----+ +-----|-----+-----+-----+-----+-----+-----+-----+-----+
 *   |Enter|Left |Down |Right|Ctrl | Tux | Alt |Space|Space| |Space|Space| Alt | Tux |Ctrl |Left |Down |Right|     |
 *   `-----+-----+-----+-----+-----+-----+-----+-----+-----' `-----+-----+-----+-----+-----+-----+-----+-----+-----'
 *
 */
[_QWERTY] = LAYOUT( \
    KC_ESC,   KC_BTN3,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,  KC_F12,  KC_PSCR, KC_DEL,  SWQWERTY, \
    KC_HOME,  KC_MPLY,  _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,    KC_5,             KC_6,    KC_7,    KC_8,     KC_9,     KC_0,    KC_MINS, KC_EQL,  KC_BSPC, SWAZERTY, \
    KC_END,   KC_VOLU,  KC_TAB,   KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,    KC_LBRC, KC_RBRC, KC_ENT,  _______, \
    KC_PGUP,  KC_VOLD,  KC_CAPS,  KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,    KC_G,             KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN, KC_QUOT, KC_ENT,  KC_ENT,  _______, \
    KC_PGDN,  KC_MUTE,  KC_UP,    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, KC_RSFT, KC_RSFT, KC_UP,   _______, \
    KC_ENT,   KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_LCTL,  KC_LGUI,  KC_LALT,  KC_SPC,  KC_SPC,           KC_SPC,  KC_SPC,  KC_RALT,  KC_RGUI,  KC_RCTL, _______, KC_LEFT, KC_DOWN, KC_RGHT  \
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
[_AZERTY] = LAYOUT( \
    KC_ESC,   KC_BTN3,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,  KC_F12,  KC_PSCR, KC_DEL,  SWQWERTY, \
    KC_HOME,  KC_MPLY,  _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,    KC_5,             KC_6,    KC_7,    KC_8,     KC_9,     KC_0,    KC_MINS, KC_EQL,  KC_BSPC, SWAZERTY, \
    KC_END,   KC_VOLU,  KC_TAB,   KC_TAB,   KC_A,     KC_Z,     KC_E,     KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,    KC_LBRC, KC_RBRC, KC_ENT,  _______, \
    KC_PGUP,  KC_VOLD,  KC_CAPS,  KC_LCTL,  KC_Q,     KC_S,     KC_D,     KC_F,    KC_G,             KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN, KC_QUOT, KC_ENT,  KC_ENT,  _______, \
    KC_PGDN,  KC_MUTE,  KC_UP,    KC_LSFT,  KC_W,     KC_X,     KC_C,     KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, KC_RSFT, KC_RSFT, KC_UP,   _______, \
    KC_ENT,   KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_LCTL,  KC_LGUI,  KC_LALT,  KC_SPC,  KC_SPC,           KC_SPC,  KC_SPC,  KC_RALT,  KC_RGUI,  KC_RCTL, _______, KC_LEFT, KC_DOWN, KC_RGHT  \
),


};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case _AZERTY:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_AZERTY);
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
