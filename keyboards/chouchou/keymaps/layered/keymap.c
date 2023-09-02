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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_2x4_2(
        KC_ESC,       KC_L,      KC_D,         KC_Y,            KC_M,       KC_O,        KC_U,      KC_BSPC,
        KC_N,         KC_R,      KC_T,         KC_S,            KC_H,       KC_A,        KC_I,      KC_E,
                                 CB_LFT,       KC_SPC,          KC_LSFT,    CB_RGT
    ),
    [_ALPHA] = LAYOUT_split_2x4_2(
        KC_DEL,       KC_X,      KC_V,         KC_G,            KC_K,       KC_Q,        KC_COMMA,  KC_ENTER,
        KC_P,         KC_W,      KC_B,         KC_C,            KC_F,       KC_Z,        KC_DOT,    KC_J,
                                 KC_TRNS,      KC_TRNS,         KC_TRNS,    KC_TRNS
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


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CB_RGT:
        if (record->event.pressed) {
           set_oneshot_layer(_ALPHA, ONESHOT_START);
        }
        return false;
    default:
        if (IS_LAYER_ON(_ALPHA) && keycode != KC_LSFT) {
            tap_code16(keycode);
            clear_oneshot_layer_state(_ALPHA);
            return false;
        }
        return true;
  }
}