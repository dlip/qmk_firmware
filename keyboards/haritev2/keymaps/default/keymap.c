// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "print.h"
#include "timer.h"

#include QMK_KEYBOARD_H
#ifdef JOYSTICK_ENABLE
#   include "analog.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_5x6(
              KC_U,              KC_U,              KC_U,              KC_U,                    KC_U,              KC_U,              KC_U,              KC_U,
        KC_L, KC_C, KC_R,  KC_L, KC_C, KC_R,  KC_L, KC_C, KC_R,  KC_L, KC_C, KC_R,        KC_L, KC_C, KC_R,  KC_L, KC_C, KC_R,  KC_L, KC_C, KC_R,  KC_L, KC_C, KC_R,
              KC_D,              KC_D,              KC_D,              KC_D,                    KC_D,              KC_D,              KC_D,              KC_D,

                                                                       KC_U,                    KC_U,
                                                                 KC_L, KC_C, KC_R,        KC_L, KC_C, KC_R,
                                                                       KC_D,                    KC_D,

                                                                       KC_U,                    KC_U,
                                                                 KC_L, KC_C, KC_R,        KC_L, KC_C, KC_R,
                                                                       KC_D,                    KC_D
    )
};

void keyboard_post_init_user(void) {
  debug_enable=true;
  debug_matrix=false;
  debug_keyboard=true;
  debug_mouse=true;

}

#ifdef POINTING_DEVICE_ENABLE
#define DEADZONE 5
int16_t scrollMinAxisValues[2] = {0,0};
int16_t scrollMaxAxisValues[2] = {0,0};
#define MAX_RATE 50
#define MIN_RATE 500

uint16_t scroll_timer_x = 0;
uint16_t scroll_timer_y = 0;
// auto range with time
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    return mouse_report;

    if (mouse_report.x < scrollMinAxisValues[0]) {
        scrollMinAxisValues[0] = mouse_report.x;
    }
    if (mouse_report.x > scrollMaxAxisValues[0]) {
        scrollMaxAxisValues[0] = mouse_report.x;
    }
    if (mouse_report.y < scrollMinAxisValues[1]) {
        scrollMinAxisValues[1] = mouse_report.y;
    }
    if (mouse_report.y > scrollMaxAxisValues[1]) {
        scrollMaxAxisValues[1] = mouse_report.y;
    }
    // return mouse_report;
#ifdef JOYSTICK_DEBUG
    uprintf("scroll_minx: %i\n", scrollMinAxisValues[0]);
    uprintf("scroll_maxx: %i\n", scrollMaxAxisValues[0]);
    uprintf("scroll_miny: %i\n", scrollMinAxisValues[1]);
    uprintf("scroll_maxy: %i\n", scrollMaxAxisValues[1]);
#endif

    const uint16_t time_elapsed_x = timer_elapsed(scroll_timer_x);
    const uint16_t time_elapsed_y = timer_elapsed(scroll_timer_y);
    if (mouse_report.x < -DEADZONE) {
        float percent = (float)mouse_report.x / (float)scrollMinAxisValues[0];
        float rate = MIN_RATE - (percent * (MIN_RATE - MAX_RATE));
        if (time_elapsed_x > rate) {
            mouse_report.h = -1;
            scroll_timer_x = timer_read();
        }
    }
    else if (mouse_report.x > DEADZONE) {
        float percent = (float)mouse_report.x / (float)scrollMaxAxisValues[0];
        float rate = MIN_RATE - (percent * (MIN_RATE - MAX_RATE));
        if (time_elapsed_x > rate) {
            mouse_report.h = 1;
            scroll_timer_x = timer_read();
        }
    }
    if (mouse_report.y < -DEADZONE) {
        float percent = (float)mouse_report.y / (float)scrollMinAxisValues[1];
        float rate = MIN_RATE - (percent * (MIN_RATE - MAX_RATE));
        if (time_elapsed_y > rate) {
            mouse_report.v = 1;
            scroll_timer_y = timer_read();
        }
    }
    else if (mouse_report.y > DEADZONE) {
        float percent = (float)mouse_report.y / (float)scrollMaxAxisValues[1];
        float rate = MIN_RATE - (percent * (MIN_RATE - MAX_RATE));
        if (time_elapsed_y > rate) {
            mouse_report.v = -1;
            scroll_timer_y = timer_read();
        }
    }

#ifdef JOYSTICK_DEBUG
    uprintf("sx: %i\n", mouse_report.x);
    uprintf("sy: %i\n", mouse_report.y);
#endif
    mouse_report.x = 0;
    mouse_report.y = 0;
    return mouse_report;
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
    joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    [0] = JOYSTICK_AXIS_IN(GP26, ANALOG_JOYSTICK_X_AXIS_MIN, ANALOG_JOYSTICK_X_AXIS_ORIGIN, ANALOG_JOYSTICK_X_AXIS_MAX),
    [1] = JOYSTICK_AXIS_IN(GP27, ANALOG_JOYSTICK_Y_AXIS_MIN, ANALOG_JOYSTICK_Y_AXIS_ORIGIN, ANALOG_JOYSTICK_Y_AXIS_MAX),
    };
#endif


