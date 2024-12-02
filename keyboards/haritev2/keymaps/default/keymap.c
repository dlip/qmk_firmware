// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later


#include QMK_KEYBOARD_H
#ifdef JOYSTICK_ENABLE
#   include "analog.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_5x5(
              KC_U,              KC_U,              KC_U,              KC_U,                    KC_U,              KC_U,              KC_U,              KC_U,
        KC_L, KC_C, KC_R,  KC_L, KC_C, KC_R,  KC_L, KC_C, KC_R,  KC_L, KC_C, KC_R,        KC_L, KC_C, KC_R,  KC_L, KC_C, KC_R,  KC_L, KC_C, KC_R,  KC_L, KC_C, KC_R,
              KC_D,              KC_D,              KC_D,              KC_D,                    KC_D,              KC_D,              KC_D,              KC_D,

                                                                       KC_U,                    KC_U,
                                                                 KC_L, KC_C, KC_R,        KC_L, KC_C, KC_R,
                                                                       KC_D,                    KC_D
    )
};

void keyboard_post_init_user(void) {
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  debug_mouse=true;
}

#ifdef JOYSTICK_ENABLE
    /* Joystick axes settings */
    joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
        [0] = JOYSTICK_AXIS_IN(GP26, 900, 575, 285),
        [1] = JOYSTICK_AXIS_IN(GP27, 900, 575, 285)
    };
#endif

