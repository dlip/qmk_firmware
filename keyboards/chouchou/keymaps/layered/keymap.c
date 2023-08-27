// Copyright 2023 Dane Lipscombe (@dlip)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
enum custom_keycodes {
    CB_LFT = QK_USER, 
    CB_RGT
};


enum my_layers {
    _BASE,
    _NAV,
    _LEFT
};

#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_2x4_2(
        KC_Q,         KC_W,      KC_F,         KC_P,            KC_L,       KC_U,        KC_Y,      KC_BSPC,
        KC_A,         KC_R,      KC_S,         KC_T,            KC_N,       KC_E,        KC_I,      KC_O,
                                 CB_LFT,       KC_SPC,          KC_LSFT,    CB_RGT
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
