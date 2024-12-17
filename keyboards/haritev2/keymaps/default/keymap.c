// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "print.h"
#include "timer.h"

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
  debug_matrix=false;
  debug_keyboard=true;
  debug_mouse=true;

}

#ifdef POINTING_DEVICE_ENABLE
// Modify these values to adjust the scrolling speed
#define SCROLL_DIVISOR_H 3.0
#define SCROLL_DIVISOR_V 3.0
#define DEADZONE 1
#define SCROLL_MAX 2A
int16_t scrollMinAxisValues[2] = {0,0};
int16_t scrollMaxAxisValues[2] = {0,0};
#define MAX_SPEED 2.f
#define MAX_RATE 100
#define MIN_RATE 500

uint16_t scroll_timer_x = 0;
uint16_t scroll_timer_y = 0;
// auto range with time
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
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

    // uprintf("x: %i\n", mouse_report.x);
    // uprintf("y: %i\n", mouse_report.y);

    const uint16_t time_elapsed_x = timer_elapsed(scroll_timer_x);
    const uint16_t time_elapsed_y = timer_elapsed(scroll_timer_y);
    if (mouse_report.x < -DEADZONE) {
        float percent = (float)mouse_report.x / (float)scrollMinAxisValues[0];
        float rate = MIN_RATE - (percent * (MIN_RATE - MAX_RATE));
        uprintf("time: %i\n", time_elapsed_x);
        uprintf("rate: %i\n", (int16_t)rate);
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
            mouse_report.v = -1;
            scroll_timer_y = timer_read();
        }
    }
    else if (mouse_report.y > 0) {
        float percent = (float)mouse_report.y / (float)scrollMaxAxisValues[1];
        float rate = MIN_RATE - (percent * (MIN_RATE - MAX_RATE));
        if (time_elapsed_y > rate) {
            mouse_report.v = 1;
            scroll_timer_y = timer_read();
        }
    }
    uprintf("sx: %i\n", mouse_report.x);
    uprintf("sy: %i\n", mouse_report.y);
    mouse_report.x = 0;
    mouse_report.y = 0;
    return mouse_report;
}
// basic clamp
// report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
//     if (mouse_report.x > DEADZONE) {
//         mouse_report.h = mouse_report.x/mouse_report.x;
//     }
//     if (mouse_report.x < -DEADZONE) {
//         mouse_report.h = -(mouse_report.x/mouse_report.x);
//     }
//     if (mouse_report.y > DEADZONE) {
//         mouse_report.v = -(mouse_report.y/mouse_report.y);
//     }
//     if (mouse_report.y < -DEADZONE) {
//         mouse_report.v = mouse_report.y/mouse_report.y;
//     }
//
//     uprintf("x: %i\n", mouse_report.x);
//     uprintf("y: %i\n", mouse_report.y);
//     uprintf("v: %i\n", mouse_report.v);
//     uprintf("h: %i\n", mouse_report.h);
//     mouse_report.x = 0;
//     mouse_report.y = 0;
//     return mouse_report;
// }
// auto range
// report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
//     if (mouse_report.x < scrollMinAxisValues[0]) {
//         scrollMinAxisValues[0] = mouse_report.x;
//     }
//     if (mouse_report.x > scrollMaxAxisValues[0]) {
//         scrollMaxAxisValues[0] = mouse_report.x;
//     }
//     if (mouse_report.y < scrollMinAxisValues[1]) {
//         scrollMinAxisValues[1] = mouse_report.y;
//     }
//     if (mouse_report.y > scrollMaxAxisValues[1]) {
//         scrollMaxAxisValues[1] = mouse_report.y;
//     }
//     uprintf("x: %i\n", mouse_report.x);
//     uprintf("y: %i\n", mouse_report.y);
//     if (mouse_report.x < 0) {
//         float percent = (float)mouse_report.x / (float)scrollMinAxisValues[0];
//         mouse_report.x = -(int8_t)(percent * MAX_SPEED);
//     }
//     else if (mouse_report.x > 0) {
//         float percent = (float)mouse_report.x / (float)scrollMaxAxisValues[0];
//         mouse_report.x = (int8_t)(percent * MAX_SPEED);
//     }
//     if (mouse_report.y < 0) {
//         float percent = (float)mouse_report.y / (float)scrollMinAxisValues[1];
//         mouse_report.y = -(int8_t)(percent * MAX_SPEED);
//     }
//     else if (mouse_report.y > 0) {
//         float percent = (float)mouse_report.y / (float)scrollMaxAxisValues[1];
//         mouse_report.y = (int8_t)(percent * MAX_SPEED);
//     }
//
//     uprintf("sx: %i\n", mouse_report.x);
//     uprintf("sy: %i\n", mouse_report.y);
//     mouse_report.h = mouse_report.x;
//     mouse_report.v = mouse_report.y;
//     mouse_report.x = 0;
//     mouse_report.y = 0;
//     return mouse_report;
// }
// report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
//     // return mouse_report;
//     if (mouse_report.x < 0) {
//         mouse_report.x *= 2;
//     }
//     if (mouse_report.y < 0) {
//         mouse_report.y *= 2;
//     }
//     if (abs(mouse_report.x) <= DEADZONE) {
//         mouse_report.x = 0;
//     }
//     if (abs(mouse_report.y) <= DEADZONE) {
//         mouse_report.y = 0;
//     }
//     if (abs(mouse_report.x) >= SCROLL_MAX) {
//         mouse_report.x = SCROLL_MAX;
//     }
//     if (abs(mouse_report.y) >= SCROLL_MAX) {
//         mouse_report.y = SCROLL_MAX;
//     }
//     uprintf("x: %i\n", mouse_report.x);
//     uprintf("y: %i\n", mouse_report.y);
//     mouse_report.h = mouse_report.x;
//     mouse_report.v = -mouse_report.y;
//     mouse_report.x = 0;
//     mouse_report.y = 0;
//     return mouse_report;
// }
// report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
//     // left_report.h = (int8_t)((float)left_report.x / SCROLL_DIVISOR_H);
//     // left_report.v = (int8_t)((float)-left_report.y / SCROLL_DIVISOR_V);
//     //
//     uprintf("x: %i\n", left_report.x);
//     uprintf("y: %i\n", left_report.y);
//     left_report.h = left_report.x;
//     left_report.v = left_report.y;
//     left_report.x = 0;
//     left_report.y = 0;
//
//     right_report.h = 0;
//     right_report.v = 0;
//     right_report.x = 0;
//     right_report.y = 0;
//     return pointing_device_combine_reports(left_report, right_report);
// }
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


