// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "print.h"

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

#ifdef POINTING_DEVICE_ENABLE
// Modify these values to adjust the scrolling speed
#define SCROLL_DIVISOR_H 4.0
#define SCROLL_DIVISOR_V 4.0
report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    left_report.h = (int8_t)((float)left_report.x / SCROLL_DIVISOR_H);
    left_report.v = (int8_t)((float)-left_report.y / SCROLL_DIVISOR_V);
    left_report.x = 0;
    left_report.y = 0;
    return pointing_device_combine_reports(left_report, right_report);
}
#endif

#if defined(DIP_SWITCH_MAP_ENABLE)
const uint16_t PROGMEM dip_switch_map[NUM_DIP_SWITCHES][NUM_DIP_STATES] = {
    DIP_SWITCH_OFF_ON(DF(0), DF(1)),
};
#endif

bool dip_switch_update_user(uint8_t index, bool active) {
    print("dip");
    switch (index) {
        case 0:
            if(active) { tap_code(KC_A); } else {  }
            break;
    }
    return true;
}

#ifdef JOYSTICK_ENABLE
    /* Joystick axes settings */
    joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    [0] = JOYSTICK_AXIS_IN(GP26, 25, 322, 807),
    [1] = JOYSTICK_AXIS_IN(GP27, 127, 536, 908),
    };

#ifdef JOYSTICK_DEBUG
void matrix_scan_user(void) {
    uint16_t val = analogReadPin(GP26);
    uprintf("x: %i\n", val);
    val = analogReadPin(GP27);
    uprintf("y: %i\n", val);
}
#endif
#endif


