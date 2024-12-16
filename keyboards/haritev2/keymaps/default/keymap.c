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

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    left_report.h = left_report.x;
    left_report.v = left_report.y;
    left_report.x = 0;
    left_report.y = 0;
    return pointing_device_combine_reports(left_report, right_report);
}

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
    [0] = JOYSTICK_AXIS_IN(GP26, 25, 807, 1023),
    [1] = JOYSTICK_AXIS_IN(GP27, 127, 908, 1023),
    };

void matrix_scan_user(void) {
    uint16_t val = analogReadPin(GP26);
    char val_str[3];
    itoa(val, val_str, 10);
    print("x:");
    print(val_str);
    print("\n");
    val = analogReadPin(GP27);
    itoa(val, val_str, 10);
    print("y:");
    print(val_str);
    print("\n");
}
#endif


