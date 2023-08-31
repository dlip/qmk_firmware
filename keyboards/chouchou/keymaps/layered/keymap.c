// Copyright 2023 Dane Lipscombe (@dlip)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
enum custom_keycodes {
    CB_LFT = QK_USER, 
    CB_RGT
};


enum my_layers {
    _BASE,
    _ALPHA,
    _NAV,
    _LEFT
};

// #include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_2x4_2(
        KC_Q,         KC_W,      KC_F,         KC_P,            KC_L,       KC_U,        KC_Y,      KC_BSPC,
        KC_A,         KC_R,      KC_S,         KC_T,            KC_N,       KC_E,        KC_I,      KC_O,
                                 CB_LFT,       KC_SPC,          KC_LSFT,    CB_RGT
    ),
    [_ALPHA] = LAYOUT_split_2x4_2(
        KC_GRAVE,     KC_B,      KC_G,         KC_V,            KC_K,       KC_M,        KC_J,      KC_SCLN,
        KC_Z,         KC_X,      KC_C,         KC_D,            KC_H,       KC_COMMA,    KC_DOT,    KC_QUOT,
                                 KC_TRNS,      KC_LSFT,         KC_TRNS,    KC_TRNS
    ),
    [_NAV] = LAYOUT_split_2x4_2(
        KC_INS,       KC_ESC,    KC_UP,        KC_ENTER,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_DEL,       KC_LEFT,   KC_DOWN,      KC_RIGHT,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
                                 KC_TRNS,      KC_LSFT,         KC_TRNS,    KC_TRNS
    ),
    [_LEFT] = LAYOUT_split_2x4_2(
        KC_PSCR,      KC_ESC,    C(KC_Z),      KC_ENTER,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_DEL,       C(KC_X),   C(KC_C),      C(KC_V),         KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
                                 KC_TRNS,      KC_LSFT,         KC_TRNS,    KC_TRNS
    ),
};
int oneshot = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case CB_RGT:
    //     if (record->tap.count > 0) {
    //         if (record->event.pressed) {
    //             if (IS_LAYER_ON(_ALPHA)) {
    //                 clear_oneshot_layer_state(ONESHOT_PRESSED);
    //             } else {
    //                 set_oneshot_layer(_ALPHA, ONESHOT_START);
    //                 // custom_oneshots.timer = timer_read();
    //             }
    //         }
    //         return false;
    //     }
    case CB_RGT:
      if (record->event.pressed) {
        set_oneshot_layer(_ALPHA, ONESHOT_START);
            oneshot = 1;
      }
      return false; // Skip all further processing of this key
    default:
      // if (!record->event.pressed) {

      // if (IS_LAYER_ON(_ALPHA)) {
      if (record->event.pressed) {

      if (oneshot == 1) {
         oneshot = 2;
    } else if (oneshot == 2) {
          clear_oneshot_layer_state(_ALPHA);
      }
            }
      return true; // Process all other keycodes normally
  }
};
