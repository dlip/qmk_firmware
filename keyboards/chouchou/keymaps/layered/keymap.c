// Copyright 2023 Dane Lipscombe (@dlip)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
enum custom_keycodes {
    CK_LFT = QK_USER, 
    CK_RGT
};


enum my_layers {
    _BASE,
    _LFT,
    _RGT,
    _NAV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_2x4_2(
        KC_Q,         KC_W,      KC_F,         KC_Y,            KC_L,       KC_U,        KC_Y,      KC_BSPC,
        KC_A,         KC_R,      KC_S,         KC_T,            KC_N,       KC_E,        KC_I,      KC_O,
                                 CK_LFT,       KC_SPC,          KC_LSFT,    CK_RGT
    ),
    [_LFT] = LAYOUT_split_2x4_2(
        KC_NO,        KC_B,      KC_G,         KC_V,            KC_5,       KC_6,        KC_7,      KC_8,
        KC_Z,         KC_X,      KC_C,         KC_D,            KC_1,       KC_2,        KC_3,      KC_4,
                                 KC_TRNS,      KC_LSFT,         KC_0,       KC_9
    ),
    [_RGT] = LAYOUT_split_2x4_2(
        KC_INS,       KC_ESC,    KC_UP,        KC_ENTER,        KC_K,       KC_M,        KC_J,      KC_SCLN,
        KC_DEL,       KC_LEFT,   KC_DOWN,      KC_RIGHT,        KC_H,       KC_COMM,     KC_DOT,    KC_QUOT,
                                 KC_TRNS,      KC_TRNS,         KC_TRNS,    KC_TRNS
    ),
    [_NAV] = LAYOUT_split_2x4_2(
        KC_INS,       KC_ESC,    KC_UP,        KC_ENTER,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_DEL,       KC_LEFT,   KC_DOWN,      KC_RIGHT,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
                                 KC_TRNS,      KC_LSFT,         KC_TRNS,    KC_TRNS
    ),
    // [_LFT] = LAYOUT_split_2x4_2(
    //     KC_PSCR,      KC_ESC,    C(KC_Z),      KC_ENTER,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
    //     KC_DEL,       C(KC_X),   C(KC_C),      C(KC_V),         KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
    //                              KC_TRNS,      KC_LSFT,         KC_TRNS,    KC_TRNS
    // ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CK_RGT:
        if (record->event.pressed) {
            if (IS_LAYER_ON(_RGT)) {
                layer_move(_BASE);
            } else {
                layer_move(_RGT);
            }
        }
        return false;
    case CK_LFT:
        if (record->event.pressed) {
            if (IS_LAYER_ON(_LFT)) {
                layer_move(_BASE);
            } else {
                layer_move(_LFT);
            }
        }
        return false;
    default:
        if (record->event.pressed) {
            if (IS_LAYER_ON(_RGT) && keycode != KC_LSFT) {
                tap_code16(keycode);
                layer_move(_BASE);
                return false;
            }
            if (IS_LAYER_ON(_LFT) && keycode != KC_LSFT) {
                tap_code16(keycode);
                layer_move(_BASE);
                return false;
            }
        }
        return true;
  }
}