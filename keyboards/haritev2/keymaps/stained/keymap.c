// SPDX-License-Identifier: GPL-2.0-or-later

#include "print.h"
#include "timer.h"

#include QMK_KEYBOARD_H
#include "os_detection.h"
#ifdef JOYSTICK_ENABLE
#include "analog.h"
#include "drivers/sensors/analog_joystick.h"
#include "drivers/sensors/analog_joystick.c"
#endif

enum custom_keycodes {
    KC_COMBO = SAFE_RANGE,
    KC_CALL,
    KC_CUDO,
    KC_CCUT,
    KC_CCPY,
    KC_CPST,
    KC_SEN,
    KC_GAM,
    KC_GPD,
    MSE_SCR,
    GP_DPU,
    GP_DPD,
    GP_DPL,
    GP_DPR,
    GP_X,
    GP_A,
    GP_B,
    GP_Y,
    GP_LB,
    GP_LT,
    GP_LSB,
    GP_RB,
    GP_RT,
    GP_RSB,
    GP_STA,
    GP_BCK,
    GP_HOM
};


enum mylayers {
    _BSE,
    _NUM,
    _FUN,
    _GAM,
    _GPD,
};

// _BSE
#define KC_CAG_W LCAG_T(KC_W)
#define KC_CAG_U LCAG_T(KC_U)
#define KC_SFT_CMA MT(MOD_LSFT, KC_COMMA)
#define KC_ALT_S MT(MOD_LALT, KC_S)
#define KC_GUI_T MT(MOD_LGUI, KC_T)
#define KC_CTL_A MT(MOD_LCTL, KC_A)
#define KC_CTL_N MT(MOD_LCTL, KC_N)
#define KC_GUI_E MT(MOD_LGUI, KC_E)
#define KC_ALT_D MT(MOD_LALT, KC_D)
#define KC_SFT_DOT MT(MOD_LSFT, KC_DOT)

#define KC_TAB_NUM LT(_NUM, KC_TAB)
#define KC_ENT_NUM LT(_NUM, KC_ENT)
#define KC_ESC_FUN LT(_FUN, KC_ESC)
#define KC_BSP_SFT MT(MOD_LSFT, KC_BSPC)

// _NUM
#define KC_CAG_PLU LCAG_T(KC_PLUS)
#define KC_CAG_8 LCAG_T(KC_8)
#define KC_ALT_EXL MT(MOD_LALT, KC_EXLM)
#define KC_GUI_UND MT(MOD_LGUI, KC_UNDS)
#define KC_CTL_MIN MT(MOD_LCTL, KC_MINUS)
#define KC_CTL_1 MT(MOD_LCTL, KC_1)
#define KC_GUI_2 MT(MOD_LGUI, KC_2)
#define KC_ALT_3 MT(MOD_LALT, KC_3)

// _FUN
#define KC_CAG_F8 LCAG_T(KC_F8)
#define KC_CAG_VLU LCAG_T(KC_VOLU)
#define KC_ALT_BRD MT(MOD_LALT, KC_BRID)
#define KC_GUI_VLD MT(MOD_LGUI, KC_VOLD)
#define KC_CTL_CPY MT(MOD_LCTL, KC_CCPY)
#define KC_CTL_F1 MT(MOD_LCTL, KC_F1)
#define KC_GUI_F2 MT(MOD_LGUI, KC_F2)
#define KC_ALT_F3 MT(MOD_LALT, KC_F3)


// COMBO
#define KC_COMBO_SFT KC_DEL
#define KC_COMBO_ALT1 KC_TAB_NUM
#define KC_COMBO_ALT2 KC_SPC
#define KC_COMBO_ALT3 QK_REP

#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BSE] = LAYOUT_split_5x6(
              KC_Q,                     KC_F,              KC_CAG_W,           KC_O,                     KC_L,                KC_CAG_U,           KC_B,                  KC_Z,
     KC_BSLS, QK_BOOT, KC_QUOT,  KC_X, KC_NO, KC_K,  KC_Y, KC_NO, KC_H,  KC_M, KC_GAM, KC_C,       KC_I, KC_GPD, KC_G,  KC_R, KC_NO, KC_V,  KC_P, KC_NO, KC_J,  KC_SCLN, QK_BOOT, KC_SLSH,
              KC_SFT_CMA,               KC_ALT_S,          KC_GUI_T,           KC_CTL_A,                 KC_CTL_N,            KC_GUI_E,           KC_ALT_D,              KC_SFT_DOT,

                                                                               KC_ESC_FUN,                 KC_COMBO,
                                                                       KC_SPC, KC_NO, QK_REP,      KC_DEL, KC_NO, KC_BSP_SFT,
                                                                               KC_TAB_NUM,                 KC_ENT_NUM,

                                                                               MSE_SCR,                    KC_UP,
                                                                      KC_BTN1, KC_NO, KC_BTN2,    KC_LEFT, KC_NO, KC_RIGHT,
                                                                               KC_BTN3,                    KC_DOWN
    ),
    [_NUM] = LAYOUT_split_5x6(
                 KC_GRV,                   KC_AMPR,                KC_CAG_PLU,               KC_EQUAL,                     KC_7,               KC_CAG_8,              KC_9,                    KC_TILD,
        KC_HASH, KC_NO, KC_TRNS,  KC_CIRC, KC_NO, KC_AT,  KC_LPRN, KC_NO, KC_RPRN,  KC_LBRC, KC_NO, KC_RBRC,         KC_4, KC_NO, KC_0,  KC_5, KC_NO, KC_ASTR,  KC_6, KC_NO, KC_PERC,  KC_DLR, KC_NO, KC_TRNS,
                 KC_TRNS,                  KC_ALT_EXL,             KC_GUI_UND,               KC_CTL_MIN,                   KC_CTL_1,           KC_GUI_2,              KC_ALT_3,                KC_TRNS,

                                                                                             KC_TRNS,                      KC_TRNS,
                                                                                    KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                             KC_TRNS,                      KC_TRNS,

                                                                                             KC_TRNS,                      KC_TRNS,
                                                                                    KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                             KC_TRNS,                      KC_TRNS
    ),
    [_FUN] = LAYOUT_split_5x6(
               KC_PSCR,                KC_BRIU,                  KC_CAG_VLU,               KC_CPST,                      KC_F7,                 KC_CAG_F8,             KC_F9,                 KC_NO,
        KC_NO, KC_NO, KC_NO,  KC_MSTP, KC_NO, KC_MPLY,  KC_MPRV, KC_NO, KC_MNXT,  KC_CUDO, KC_NO, KC_CCUT,        KC_F4, KC_NO, KC_F10,  KC_F5, KC_NO, KC_F11,  KC_F6, KC_NO, KC_F12,  KC_NO, KC_NO, KC_NO,
               KC_LSFT,                KC_ALT_BRD,               KC_GUI_VLD,               KC_CTL_CPY,                   KC_CTL_F1,             KC_GUI_F2,             KC_ALT_F3,             KC_RSFT,

                                                                                           KC_TRNS,                      KC_TRNS,
                                                                                  KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                           KC_TRNS,                      KC_TRNS,

                                                                                           KC_TRNS,                      KC_PGUP,
                                                                                  KC_TRNS, KC_TRNS, KC_TRNS,    KC_HOME, KC_TRNS, KC_END,
                                                                                           KC_TRNS,                      KC_PGDN
    ),
    [_GAM] = LAYOUT_split_5x6(
               KC_NO,                KC_Q,                KC_SPC,              KC_BTN2,                   KC_7,                 KC_8,                KC_9,              KC_NO,
        KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,  KC_A, KC_NO, KC_D,  KC_E,  KC_GAM, KC_R,        KC_4, KC_GPD, KC_0,   KC_5, KC_NO, KC_NO,  KC_6, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,
               KC_NO,                KC_C,                KC_SPC,              KC_BTN1,                   KC_1,                 KC_2,                KC_3,              KC_NO,

                                                                               KC_W,                      KC_UP,
                                                                         KC_A, KC_NO, KC_D,      KC_LEFT, KC_NO, KC_RIGHT,
                                                                               KC_S,                      KC_DOWN,

                                                                               MSE_SCR,                   KC_NO,
                                                                      KC_BTN1, KC_NO, KC_BTN3,    KC_ESC, KC_NO, KC_ENTER,
                                                                               KC_BTN2,                   KC_LSFT
    ),
    [_GPD] = LAYOUT_split_5x6(
                GP_HOM,                   KC_NO,                GP_Y,                GP_LT,                    KC_7,                 KC_8,                KC_9,              KC_NO,
        GP_BCK, QK_BOOT, GP_STA,  GP_LSB, KC_NO, GP_RSB,  GP_X, KC_NO, GP_B,  GP_LB, KC_NO, GP_RB,       KC_4, KC_GPD, KC_0,   KC_5, KC_NO, KC_NO,  KC_6, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,
                KC_NO,                    KC_NO,                GP_A,                GP_RT,                    KC_1,                 KC_2,                KC_3,              KC_NO,

                                                                                     GP_DPU,                   GP_Y,
                                                                             GP_DPL, KC_NO, GP_DPR,      GP_X, KC_NO, GP_B,
                                                                                     GP_DPD,                   GP_A,

                                                                                     QK_REP,                   KC_NO,
                                                                            KC_BTN1, KC_NO, KC_BTN3,    KC_NO, KC_NO, KC_NO,
                                                                                     KC_BTN2,                  KC_NO
    )

    // [_NEW] = LAYOUT_split_5x6(
    //            KC_NO,                KC_NO,                KC_NO,                KC_NO,                            KC_NO,                KC_NO,                KC_NO,                KC_NO,
    //     KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,
    //            KC_NO,                KC_NO,                KC_NO,                KC_NO,                             KC_NO,                KC_NO,                KC_NO,                KC_NO,
    //
    //                                                                              KC_TRNS,                          KC_TRNS,
    //                                                                     KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,
    //                                                                              KC_TRNS,                          KC_TRNS,
    //
    //                                                                              KC_TRNS,                          KC_TRNS,
    //                                                                     KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,
    //                                                                              KC_TRNS,                          KC_TRNS
    // )
};

bool set_scrolling = false;
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = -mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BSP_SFT:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BSP_SFT:
        case KC_COMBO_ALT1:
        case KC_ESC_FUN:
            return true;
        default:
            return false;
    }
}

bool DPU_STATE = false;
bool DPD_STATE = false;
bool DPL_STATE = false;
bool DPR_STATE = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_COMBO:
            if (record->event.pressed) {
                switch(detected_host_os()) {
                    case OS_MACOS:
                    case OS_IOS:
                        tap_code16(A(KC_BSPC));
                        break;
                    default:
                        tap_code16(C(KC_BSPC));
                        break;
                }
                return false;
            }
            break;
        case KC_CALL:
            if (record->event.pressed) {
                switch(detected_host_os()) {
                    case OS_MACOS:
                    case OS_IOS:
                        tap_code16(G(KC_A));
                        break;
                    default:
                        tap_code16(C(KC_A));
                        break;
                }
                return false;
            }
            break;
        case KC_CUDO:
            if (record->event.pressed) {
                switch(detected_host_os()) {
                    case OS_MACOS:
                    case OS_IOS:
                        tap_code16(G(KC_Z));
                        break;
                    default:
                        tap_code16(C(KC_Z));
                        break;
                }
                return false;
            }
            break;
        case KC_CCUT:
            if (record->event.pressed) {
                switch(detected_host_os()) {
                    case OS_MACOS:
                    case OS_IOS:
                        tap_code16(G(KC_X));
                        break;
                    default:
                        tap_code16(C(KC_X));
                        break;
                }
                return false;
            }
            break;
        case KC_CCPY:
            if (record->event.pressed) {
                switch(detected_host_os()) {
                    case OS_MACOS:
                    case OS_IOS:
                        tap_code16(G(KC_C));
                        break;
                    default:
                        tap_code16(C(KC_C));
                        break;
                }
                return false;
            }
            break;
        case KC_CTL_CPY:
            if (record->tap.count && record->event.pressed) {
                switch(detected_host_os()) {
                    case OS_MACOS:
                    case OS_IOS:
                        tap_code16(G(KC_C));
                        break;
                    default:
                        tap_code16(C(KC_C));
                        break;
                }
                return false;
            }
            break;
        case KC_CPST:
            if (record->event.pressed) {
                switch(detected_host_os()) {
                    case OS_MACOS:
                    case OS_IOS:
                        tap_code16(G(KC_V));
                        break;
                    default:
                        tap_code16(C(KC_V));
                        break;
                }
                return false;
            }
            break;
        case KC_SEN:
            if (record->event.pressed) {
                tap_code16(KC_DOT);
                tap_code16(KC_SPC);
                set_oneshot_mods(MOD_BIT(KC_LSFT));
                return false;
            }
            break;
        case KC_GAM:
            if (record->event.pressed) {
                if (layer_state_is(_GAM)) {
                    layer_off(_GAM);
                    combo_enable();
                } else {
                    layer_on(_GAM);
                    combo_disable();
                }
                return false;
            }
            break;
        case KC_GPD:
            if (record->event.pressed) {
                if (layer_state_is(_GPD)) {
                    layer_off(_GPD);
                    combo_enable();
                } else {
                    layer_on(_GPD);
                    combo_disable();
                }
                return false;
            }
            break;
        case MSE_SCR:
            set_scrolling = record->event.pressed;
            if (record->event.pressed) {
                pointing_device_set_cpi(PMW33XX_CPI/8);
            } else {
                pointing_device_set_cpi(PMW33XX_CPI);
            }
            return false;

        // DPAD INPUTS
        case GP_DPU:
            if (record->event.pressed) {
                DPU_STATE = true;
                if (DPD_STATE) {
                    unregister_joystick_button(16);
                } else {
                    register_joystick_button(18);
                }
            } else {
                DPU_STATE = false;
                unregister_joystick_button(18);
                if (DPD_STATE) {
                    register_joystick_button(16);
                }
            }
            return false;
        case GP_DPD:
            if (record->event.pressed) {
                DPD_STATE = true;
                if (DPU_STATE) {
                    unregister_joystick_button(18);
                } else {
                    register_joystick_button(16);
                }
            } else {
                DPD_STATE = false;
                unregister_joystick_button(16);
                if (DPU_STATE) {
                    register_joystick_button(18);
                }
            }
            return false;
        case GP_DPL:
            if (record->event.pressed) {
                DPL_STATE = true;
                if (DPR_STATE) {
                    unregister_joystick_button(17);
                } else {
                    register_joystick_button(15);
                }
            } else {
                DPL_STATE = false;
                unregister_joystick_button(15);
                if (DPR_STATE) {
                    register_joystick_button(17);
                }
            }
            return false;
        case GP_DPR:
            if (record->event.pressed) {
                DPR_STATE = true;
                if (DPL_STATE) {
                    unregister_joystick_button(15);
                } else {
                    register_joystick_button(17);
                }
            } else {
                DPR_STATE = false;
                unregister_joystick_button(17);
                if (DPL_STATE) {
                    register_joystick_button(15);
                }
            }
            return false;
        case GP_X:
            if (record->event.pressed) {
                register_joystick_button(0);
            } else {
                unregister_joystick_button(0);
            }
            return false;
        case GP_A:
            if (record->event.pressed) {
                register_joystick_button(1);
            } else {
                unregister_joystick_button(1);
            }
            return false;
        case GP_B:
            if (record->event.pressed) {
                register_joystick_button(2);
            } else {
                unregister_joystick_button(2);
            }
            return false;
        case GP_Y:
            if (record->event.pressed) {
                register_joystick_button(3);
            } else {
                unregister_joystick_button(3);
            }
            return false;
        case GP_LB:
            if (record->event.pressed) {
                register_joystick_button(4);
            } else {
                unregister_joystick_button(4);
            }
            return false;
        case GP_RB:
            if (record->event.pressed) {
                register_joystick_button(5);
            } else {
                unregister_joystick_button(5);
            }
            return false;
        case GP_LT:
            if (record->event.pressed) {
                register_joystick_button(6);
            } else {
                unregister_joystick_button(6);
            }
            return false;
        case GP_RT:
            if (record->event.pressed) {
                register_joystick_button(7);
            } else {
                unregister_joystick_button(7);
            }
            return false;
        case GP_BCK:
            if (record->event.pressed) {
                register_joystick_button(8);
            } else {
                unregister_joystick_button(8);
            }
            return false;
        case GP_STA:
            if (record->event.pressed) {
                register_joystick_button(9);
            } else {
                unregister_joystick_button(9);
            }
            return false;
        case GP_LSB:
            if (record->event.pressed) {
                register_joystick_button(10);
            } else {
                unregister_joystick_button(10);
            }
            return false;
        case GP_RSB:
            if (record->event.pressed) {
                register_joystick_button(11);
            } else {
                unregister_joystick_button(11);
            }
            return false;
        case GP_HOM:
            if (record->event.pressed) {
                register_joystick_button(12);
            } else {
                unregister_joystick_button(12);
            }
            return false;
    }

    return true;
};


#if defined(DIP_SWITCH_MAP_ENABLE)
const uint16_t PROGMEM dip_switch_map[NUM_DIP_SWITCHES][NUM_DIP_STATES] = {
    DIP_SWITCH_OFF_ON(DF(0), DF(1)),
};
#endif

// bool dip_switch_update_user(uint8_t index, bool active) {
//     print("dip");
//     switch (index) {
//         case 0:
//             if(active) { tap_code(KC_A); } else {  }
//             break;
//     }
//     return true;
// }

#ifdef JOYSTICK_ENABLE
    joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    [0] = JOYSTICK_AXIS_IN(GP27, ANALOG_JOYSTICK_X_AXIS_MIN, ANALOG_JOYSTICK_X_AXIS_ORIGIN, ANALOG_JOYSTICK_X_AXIS_MAX),
    [1] = JOYSTICK_AXIS_IN(GP28, ANALOG_JOYSTICK_Y_AXIS_MIN, ANALOG_JOYSTICK_Y_AXIS_ORIGIN, ANALOG_JOYSTICK_Y_AXIS_MAX),
    };
#endif



#define DEADZONE 5
int16_t scrollMinAxisValues[2] = {0,0};
int16_t scrollMaxAxisValues[2] = {0,0};
#define MAX_RATE 50
#define MIN_RATE 500

uint16_t scroll_timer_x = 0;
uint16_t scroll_timer_y = 0;
// auto range with time
void matrix_scan_user(void) {
    return;
    if (!is_keyboard_left()) return;
    report_mouse_t mouse_report;
    mouse_report = analog_joystick_get_report(mouse_report);

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
    uprintf("mouse_report.x: %i\n", mouse_report.x);
    uprintf("mouse_report.y: %i\n", mouse_report.y);
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
            tap_code(QK_MOUSE_WHEEL_LEFT);
            uprintf("scroll left");
            scroll_timer_x = timer_read();
        }
    }
    else if (mouse_report.x > DEADZONE) {
        float percent = (float)mouse_report.x / (float)scrollMaxAxisValues[0];
        float rate = MIN_RATE - (percent * (MIN_RATE - MAX_RATE));
        if (time_elapsed_x > rate) {
            tap_code(QK_MOUSE_WHEEL_RIGHT);
            uprintf("scroll right");
            scroll_timer_x = timer_read();
        }
    }
    if (mouse_report.y < -DEADZONE) {
        float percent = (float)mouse_report.y / (float)scrollMinAxisValues[1];
        float rate = MIN_RATE - (percent * (MIN_RATE - MAX_RATE));
        if (time_elapsed_y > rate) {
            tap_code(QK_MOUSE_WHEEL_UP);
            uprintf("scroll up");
            scroll_timer_y = timer_read();
        }
    }
    else if (mouse_report.y > DEADZONE) {
        float percent = (float)mouse_report.y / (float)scrollMaxAxisValues[1];
        float rate = MIN_RATE - (percent * (MIN_RATE - MAX_RATE));
        if (time_elapsed_y > rate) {
            tap_code(QK_MOUSE_WHEEL_DOWN);
            uprintf("scroll down");
            scroll_timer_y = timer_read();
        }
    }
}
