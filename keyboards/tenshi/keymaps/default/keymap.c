// Copyright 2023 Dane Lipscombe (@dlip)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x4_4(
        KC_Q,    KC_W,    KC_E,    KC_R,        KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,        KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,        KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                          KC_1,    KC_2,        KC_5,    KC_6,
                          KC_3,    KC_4,        KC_7,    KC_8
    )
};

void keyboard_post_init_user(void) {
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  debug_mouse=true;
}
