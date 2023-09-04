// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum mylayers {
    _ALPHA,
};

#define KC_ALT_R  MT(MOD_LALT, KC_R)
#define KC_GUI_S  MT(MOD_LGUI, KC_S)
#define KC_CTL_T  MT(MOD_LCTL, KC_T)
#define KC_CTL_N  MT(MOD_LCTL, KC_N)
#define KC_GUI_E  MT(MOD_LGUI, KC_E)
#define KC_ALT_I  MT(MOD_LALT, KC_I)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ALPHA] = LAYOUT_split_3x5_3(
         KC_Q,    KC_W,     KC_F,     KC_P,     KC_B,      KC_J,    KC_L,     KC_U,     KC_Y,     KC_SCLN,
         KC_A,    KC_ALT_R, KC_GUI_S, KC_CTL_T, KC_G,      KC_M,    KC_CTL_N, KC_GUI_E, KC_ALT_I, KC_O,
         KC_Z,    KC_X,     KC_C,     KC_D,     KC_V,      KC_K,    KC_H,     KC_COMMA, KC_DOT,   KC_QUOT,
                            KC_LGUI,  KC_BSPC,  KC_SPC,    KC_SPC,  KC_ENT,   KC_RALT
    ),
};
