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
        KC_ESC,       KC_L,      KC_D,         KC_Y,            KC_M,       KC_O,        KC_U,      KC_BSPC,
        KC_N,         KC_R,      KC_T,         KC_S,            KC_H,       KC_A,        KC_I,      KC_E,
                                 CK_LFT,       KC_SPC,          KC_LSFT,    CK_RGT
    ),
    [_LFT] = LAYOUT_split_2x4_2(
        KC_DEL,       KC_X,      KC_V,         KC_G,            KC_K,       KC_Q,        KC_COMMA,  KC_ENTER,
        KC_P,         KC_W,      KC_B,         KC_C,            KC_F,       KC_Z,        KC_DOT,    KC_J,
                                 KC_TRNS,      KC_TRNS,         KC_TRNS,    KC_TRNS
    ),
    [_RGT] = LAYOUT_split_2x4_2(
        KC_INS,       KC_ESC,    KC_UP,        KC_ENTER,        KC_K,       KC_Q,        KC_COMMA,  KC_ENTER,
        KC_DEL,       KC_LEFT,   KC_DOWN,      KC_RIGHT,        KC_F,       KC_Z,        KC_DOT,    KC_J,
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
            if (IS_LAYER_ON(_LFT)) {
                layer_move(_BASE);
            } else {
                layer_move(_LFT);
            }
        return false;
    default:
        if (record->event.pressed && keycode >= KC_A && keycode <= KC_Z) {
            if (IS_LAYER_ON(_RGT) && keycode != KC_LSFT) {
                tap_code16(keycode);
                layer_move(_BASE);
                // clear_oneshot_layer_state(_RGT);
                return false;
            }
            if (IS_LAYER_ON(_LFT) && keycode != KC_LSFT) {
                tap_code16(keycode);
                layer_move(_BASE);
                // clear_oneshot_layer_state(_LFT);
                return false;
            }
        }
        return true;
  }
}