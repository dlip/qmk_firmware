// Copyright 2023 Dane Lipscombe (@dlip)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x4_2(
        KC_A,    KC_B,    KC_C,    KC_D,      KC_M,    KC_N,    KC_O,    KC_P,
        KC_E,    KC_F,    KC_G,    KC_H,      KC_Q,    KC_R,    KC_S,    KC_T,
        KC_I,    KC_J,    KC_K,    KC_L,      KC_U,    KC_V,    KC_W,    KC_X,
                          KC_1,    KC_2,      KC_3,    KC_4
    )
};
