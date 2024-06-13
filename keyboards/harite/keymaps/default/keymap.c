// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_5x5(
              KC_A,              KC_A,              KC_A,              KC_A,                    KC_A,              KC_A,              KC_A,              KC_A,
        KC_D, KC_E, KC_B,  KC_D, KC_E, KC_B,  KC_D, KC_E, KC_B,  KC_D, KC_E, KC_B,        KC_D, KC_E, KC_B,  KC_D, KC_E, KC_B,  KC_D, KC_E, KC_B,  KC_D, KC_E, KC_B,
              KC_C,              KC_C,              KC_C,              KC_C,                    KC_C,              KC_C,              KC_C,              KC_C,

                                                                       KC_A,                    KC_A,
                                                                 KC_D, KC_E, KC_B,        KC_D, KC_E, KC_B,
                                                                       KC_C,                    KC_C
    )
};

