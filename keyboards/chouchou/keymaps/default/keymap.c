// Copyright 2023 Dane Lipscombe (@dlip)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┐               ┌───┬───┬───┬───┐
      * │ R │ S │ N │ I │               │ I │ N │ S │ R │
      * ├───┼───┼───┼───┤               ├───┼───┼───┼───┤
      * │ A │ O │ T │ E │               │ E │ T │ O │ A │
      * └───┴───┴───┴───┘               └───┴───┴───┴───┘
      *               ┌───┐           ┌───┐
      *               │Bsp├───┐   ┌───┤Bsp│
      *               └───┤Spc│   │Spc├───┘
      *                   └───┘   └───┘
      */
    [0] = LAYOUT_split_2x4_2(
        KC_R,    KC_S,    KC_N,    KC_I,        KC_I,    KC_N,    KC_S,    KC_R,
        KC_A,    KC_O,    KC_T,    KC_E,        KC_E,    KC_T,    KC_O,    KC_A,
                          KC_BSPC, KC_SPC,      KC_SPC,  KC_BSPC
    )
};
