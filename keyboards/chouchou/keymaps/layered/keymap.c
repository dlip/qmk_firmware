// Copyright 2023 Dane Lipscombe (@dlip)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
enum custom_keycodes {
    CB_LFT = QK_USER, 
    CB_RGT
};

#include "g/keymap_combo.h"

enum my_layers {
    _BASE,
    _ALPHA2,
    _NAV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_2x4_2(
        KC_Q,         KC_W,      KC_F,         KC_P,            KC_L,       KC_U,        KC_Y,      KC_SCLN,
        KC_A,         KC_R,      KC_S,         KC_T,            KC_N,       KC_E,        KC_I,      KC_O,
                                 CB_LFT,       KC_SPC,          KC_LSFT,    CB_RGT
    ),
    [_ALPHA2] = LAYOUT_split_2x4_2(
        KC_NO,        KC_B,      KC_G,         KC_V,            KC_K,       KC_M,        KC_J,      KC_NO,
        KC_Z,         KC_X,      KC_C,         KC_D,            KC_H,       KC_COMMA,    KC_DOT,    KC_QUOT,
                                 KC_TRNS,      KC_TRNS,         KC_TRNS,    KC_TRNS
    ),
    [_NAV] = LAYOUT_split_2x4_2(
        KC_NO,        KC_ESC,    KC_UP,        KC_ENTER,        KC_K,       KC_M,        KC_J,      KC_NO,
        KC_Z,         KC_LEFT,   KC_DOWN,      KC_RIGHT,        KC_H,       KC_BSPC,     KC_DOT,    KC_QUOT,
                                 KC_TRNS,      KC_TRNS,         KC_TRNS,    KC_TRNS
    ),
};
