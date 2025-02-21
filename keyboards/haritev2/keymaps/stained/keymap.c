// SPDX-License-Identifier: GPL-2.0-or-later

#include "print.h"
#include "timer.h"

#include QMK_KEYBOARD_H
#include "os_detection.h"
#ifdef ANALOG_JOYSTICK_SCROLL
#include "analog.h"
#include "drivers/sensors/analog_joystick.h"
#include "drivers/sensors/analog_joystick.c"
bool joystick_scroll_enabled = true;
#endif
#include "features/achordion.h"
#include "keymap_japanese.h"
#include "ja.h"

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
    KC_GP2,
    KC_JPN,
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
    GP_HOM,
    GP_20
};


enum mylayers {
    _BSE,
    _JP1,
    _NUM,
    _FUN,
    _JP2,
    _GAM,
    _GPD,
    _GP2,
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

#define KC_TAB_SNM LT(_NUM, KC_TAB)
#define KC_BSP_NUM LT(_NUM, KC_BSPC)
#define KC_DEL_FUN LT(_FUN, KC_DEL)
#define KC_ESC_SFT MT(MOD_LSFT, KC_ESC)
#define KC_ENT_SFT MT(MOD_LSFT, KC_ENT)
#define KC_JP2 MO(_JP2)

// _NUM
#define KC_CAG_LBC LCAG_T(KC_LBRC)
#define KC_CAG_8 LCAG_T(KC_8)
#define KC_ALT_GRV MT(MOD_LALT, KC_GRV)
#define KC_GUI_RBC MT(MOD_LGUI, KC_RBRC)
#define KC_CTL_MIN MT(MOD_LCTL, KC_MINUS)
#define KC_CTL_1 MT(MOD_LCTL, KC_1)
#define KC_GUI_2 MT(MOD_LGUI, KC_2)
#define KC_ALT_3 MT(MOD_LALT, KC_3)

// _FUN
#define KC_CAG_PSC LCAG_T(KC_PSCR)
#define KC_CAG_F8 LCAG_T(KC_F8)
#define KC_ALT_VLD MT(MOD_LALT, KC_VOLD)
#define KC_GUI_PLY MT(MOD_LGUI, KC_MPLY)
#define KC_CTL_CPY MT(MOD_LCTL, KC_CCPY)
#define KC_CTL_F1 MT(MOD_LCTL, KC_F1)
#define KC_GUI_F2 MT(MOD_LGUI, KC_F2)
#define KC_ALT_F3 MT(MOD_LALT, KC_F3)


// COMBO
#define KC_COMBO_SFT QK_REP
#define KC_COMBO_ALT1 KC_BSP_NUM
#define KC_COMBO_ALT2 KC_TAB_SNM
#define KC_COMBO_ALT3 KC_DEL_FUN

#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BSE] = LAYOUT_split_5x6(
              KC_Q,                    KC_F,               KC_CAG_W,            KC_O,                         KC_L,                KC_CAG_U,            KC_B,                  KC_Z,
     KC_BSLS, QK_BOOT, KC_QUOT,  KC_X, KC_NO, KC_K,  KC_Y, KC_JPN, KC_H,  KC_M, KC_GAM, KC_C,           KC_I, KC_GPD, KC_G,  KC_R, KC_GP2, KC_V,  KC_P, KC_NO, KC_J,  KC_SCLN, QK_BOOT, KC_SLSH,
              KC_SFT_CMA,              KC_ALT_S,           KC_GUI_T,            KC_CTL_A,                     KC_CTL_N,            KC_GUI_E,            KC_ALT_D,              KC_SFT_DOT,

                                                                                KC_TAB_SNM,                   KC_COMBO,
                                                                    KC_BSP_NUM, KC_NO, KC_DEL_FUN,    QK_REP, KC_NO, KC_SPC,
                                                                                KC_ESC_SFT,                   KC_ENT_SFT,

                                                                                MSE_SCR,                      KC_UP,
                                                                       KC_BTN1, KC_NO, KC_BTN3,      KC_LEFT, KC_NO, KC_RIGHT,
                                                                                KC_BTN2,                      KC_DOWN
    ),
    [_NUM] = LAYOUT_split_5x6(
               KC_NO,                  KC_VOLU,                  KC_CAG_PSC,               KC_CPST,                      KC_7,               KC_CAG_8,               KC_9,                      KC_GRV,
        KC_NO, KC_NO, KC_NO,  KC_BRID, KC_NO, KC_BRIU,  KC_MPRV, KC_NO, KC_MNXT,  KC_CUDO, KC_NO, KC_CCUT,         KC_4, KC_NO, KC_0,  KC_5, KC_NO, KC_MINUS,  KC_6, KC_NO, KC_EQUAL,  KC_LBRC, KC_NO, KC_RBRC,
               KC_LSFT,                KC_ALT_VLD,               KC_GUI_PLY,               KC_CTL_CPY,                   KC_CTL_1,           KC_GUI_2,               KC_ALT_3,                  KC_SFT_DOT,

                                                                                           KC_TRNS,                      QK_LLCK,
                                                                                  KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                           KC_TRNS,                      KC_TRNS,

                                                                                           KC_TRNS,                      KC_TRNS,
                                                                                  KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                           KC_TRNS,                      KC_TRNS
    ),
    [_FUN] = LAYOUT_split_5x6(
               KC_NO,                  KC_VOLU,                  KC_CAG_PSC,               KC_CPST,                      KC_F7,                 KC_CAG_F8,             KC_F9,                 KC_NO,
        KC_NO, KC_NO, KC_NO,  KC_BRID, KC_NO, KC_BRIU,  KC_MPRV, KC_NO, KC_MNXT,  KC_CUDO, KC_NO, KC_CCUT,        KC_F4, KC_NO, KC_F10,  KC_F5, KC_NO, KC_F11,  KC_F6, KC_NO, KC_F12,  KC_NO, KC_NO, KC_NO,
               KC_LSFT,                KC_ALT_VLD,               KC_MPLY,                  KC_CTL_CPY,                   KC_CTL_F1,             KC_GUI_F2,             KC_ALT_F3,             KC_RSFT,

                                                                                           KC_TRNS,                      KC_TRNS,
                                                                                  KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                           KC_TRNS,                      KC_TRNS,

                                                                                           KC_TRNS,                      KC_PGUP,
                                                                                  KC_TRNS, KC_TRNS, KC_TRNS,    KC_HOME, KC_TRNS, KC_END,
                                                                                           KC_TRNS,                      KC_PGDN
    ),
    [_JP1] = LAYOUT_split_5x6(
                JA_TEN,                JA_TO,                JA_N,                 JA_HA,                           JA_TA,                JA_SHI,               JA_A,                  JA_MAR,
        JA_SEN, KC_NO, JA_LQU,  JA_RI, KC_NO, JA_MA,  JA_KI, KC_JPN, JA_SA, JA_NO, KC_NO, JA_TSU,            JA_KU, KC_NO, JA_WO,  JA_YO, KC_NO, JA_KO,  JA_NA, KC_NO, JA_RE,  JA_RQU, KC_NO, JA_SLS,
                JA_COM,                JA_SU,                JA_I,                 JA_KA,                           JA_TE,                JA_U,                 JA_NI,                 JA_DOT,

                                                                                   KC_TRNS,                         QK_LLCK,
                                                                          KC_TRNS, KC_TRNS, KC_DEL_FUN,    KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                   KC_TRNS,                         KC_TRNS,

                                                                                   KC_JP2,                          KC_TRNS,
                                                                          KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                   KC_TRNS,                         KC_TRNS
    ),
    [_JP2] = LAYOUT_split_5x6(
                JA_TEN,                 JA_NE,                JA_WA,                JA_SE,                       JA_CHI,               JA_RA,               JA_HI,                  JA_MAR,
        JA_SEN, KC_NO, JA_LQU,  JA_LQU, KC_NO, JA_HE,  JA_MU, KC_NO, JA_SO,  JA_ME, KC_NO, JA_MI,         JA_YA, KC_NO, JA_NU,  JA_FU, KC_NO, JA_E,  JA_RO, KC_NO, JA_RQU,  JA_RQU, KC_NO, JA_SLS,
                JA_COM,                 JA_MO,                JA_O,                 JA_YU,                       JA_KE,                JA_RU,               JA_HO,                  JA_DOT,

                                                                                   KC_TRNS,                      KC_TRNS,
                                                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                   KC_TRNS,                      KC_TRNS,

                                                                                   KC_TRNS,                      KC_TRNS,
                                                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                   KC_TRNS,                      KC_TRNS
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

                                                                                     MSE_SCR,                  KC_NO,
                                                                            KC_BTN1, KC_NO, KC_BTN3,    KC_NO, KC_NO, KC_NO,
                                                                                     KC_BTN2,                  KC_NO
    ),
    [_GP2] = LAYOUT_split_5x6(
                GP_HOM,                   GP_DPL,               GP_DPU,              GP_DPR,                    GP_RB,                  GP_Y,                   GP_X,              KC_NO,
        GP_BCK, QK_BOOT, GP_STA,  GP_LSB, KC_NO, GP_RSB,  GP_X, KC_NO, GP_B,  GP_LB, KC_NO, GP_RB,       GP_LT, KC_GPD, GP_20,   GP_LB, KC_GP2, KC_NO,  GP_LSB, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,
                KC_NO,                    GP_DPL,               GP_DPD,              GP_DPR,                    GP_RT,                  GP_B,                   GP_A,              KC_NO,

                                                                                     GP_DPU,                   GP_Y,
                                                                             GP_DPL, KC_NO, GP_DPR,      GP_X, KC_NO, GP_B,
                                                                                     GP_DPD,                   GP_A,

                                                                                     MSE_SCR,                  KC_NO,
                                                                            KC_BTN1, KC_NO, KC_BTN3,    KC_NO, KC_NO, KC_NO,
                                                                                     KC_BTN2,                  KC_NO
    )
    // [_NEW] = LAYOUT_split_5x6(
    //            KC_NO,                KC_NO,                KC_NO,                KC_NO,                        KC_NO,                KC_NO,                KC_NO,                KC_NO,
    //     KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,
    //            KC_NO,                KC_NO,                KC_NO,                KC_NO,                        KC_NO,                KC_NO,                KC_NO,                KC_NO,
    //
    //                                                                              KC_TRNS,                      KC_TRNS,
    //                                                                     KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
    //                                                                              KC_TRNS,                      KC_TRNS,
    //
    //                                                                              KC_TRNS,                      KC_TRNS,
    //                                                                     KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
    //                                                                              KC_TRNS,                      KC_TRNS
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



#ifdef POINTING_DEVICE_COMBINED
#define SCROLL_DIVISOR_H 100.0
#define SCROLL_DIVISOR_V 100.0

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;
report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    // Calculate and accumulate scroll values based on mouse movement and divisors
    scroll_accumulated_h += (float)left_report.x / SCROLL_DIVISOR_H;
    scroll_accumulated_v += (float)left_report.y / SCROLL_DIVISOR_V;

    // Assign integer parts of accumulated scroll values to the mouse report
    left_report.h = (int8_t)scroll_accumulated_h;
    left_report.v = -(int8_t)scroll_accumulated_v;

    // Clear the X and Y values of the mouse report
    left_report.x = 0;
    left_report.y = 0;
    if (set_scrolling) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)right_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v += (float)right_report.y / SCROLL_DIVISOR_V;

        // Assign integer parts of accumulated scroll values to the mouse report
        right_report.h = (int8_t)scroll_accumulated_h;
        right_report.v = -(int8_t)scroll_accumulated_v;

        // Clear the X and Y values of the mouse report
        right_report.x = 0;
        right_report.y = 0;
    }

    // Update accumulated scroll values by subtracting the integer parts
    scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
    scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

    return pointing_device_combine_reports(left_report, right_report);
}
#endif

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ESC_SFT:
        case KC_ENT_SFT:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_TAB_SNM:
        case KC_BSP_NUM:
        case KC_DEL_FUN:
        case KC_ESC_SFT:
        case KC_ENT_SFT:
            return true;
        default:
            return false;
    }
}

void housekeeping_task_user(void) {
    achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {

    // Allow thumb cluster to be used with same side
    if (tap_hold_record->event.key.col >= 4 || other_record->event.key.col >= 4) {
        return true;
    }
    return achordion_opposite_hands(tap_hold_record, other_record);
}

bool DPU_STATE = false;
bool DPD_STATE = false;
bool DPL_STATE = false;
bool DPR_STATE = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) { return false; }
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
                        // chrome sometimes missing the hold
                        send_string_with_delay(SS_LCTL("v"),10);
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
#ifdef ANALOG_JOYSTICK_SCROLL
                    joystick_scroll_enabled = true;
#endif
                } else {
                    layer_on(_GAM);
                    combo_disable();
#ifdef ANALOG_JOYSTICK_SCROLL
                    joystick_scroll_enabled = false;
#endif
                }
                return false;
            }
            break;
        case KC_GPD:
            if (record->event.pressed) {
                if (layer_state_is(_GPD)) {
                    layer_off(_GPD);
                    combo_enable();
#ifdef ANALOG_JOYSTICK_SCROLL
                    joystick_scroll_enabled = true;
#endif
                } else {
                    layer_on(_GPD);
                    combo_disable();
#ifdef ANALOG_JOYSTICK_SCROLL
                    joystick_scroll_enabled = false;
#endif
                }
                return false;
            }
            break;
        case KC_GP2:
            if (record->event.pressed) {
                if (layer_state_is(_GP2)) {
                    layer_off(_GP2);
                    combo_enable();
#ifdef ANALOG_JOYSTICK_SCROLL
                    joystick_scroll_enabled = true;
#endif
                } else {
                    layer_on(_GP2);
                    combo_disable();
#ifdef ANALOG_JOYSTICK_SCROLL
                    joystick_scroll_enabled = false;
#endif
                }
                return false;
            }
            break;
        case KC_JPN:
            if (record->event.pressed) {
                if (layer_state_is(_JP1)) {
                    layer_off(_JP1);
                    SEND_STRING(SS_LCTL(" "));
                } else {
                    layer_on(_JP1);
                    SEND_STRING(SS_LCTL(" "));
                }
                return false;
            }
            break;
        case KC_TAB_SNM:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_TAB);
            } else if (record->event.pressed) {
                add_mods(MOD_BIT(KC_LSFT));
                layer_on(_NUM);
            } else {
                del_mods(MOD_BIT(KC_LSFT));
                layer_off(_NUM);
            }
            return false;
        case MSE_SCR:
            set_scrolling = record->event.pressed;

#if defined(POINTING_DEVICE_DRIVER_pmw3389)
            if (record->event.pressed) {
                pointing_device_set_cpi(PMW33XX_SCROLL_CPI);
            } else {
                pointing_device_set_cpi(PMW33XX_CPI);
            }
#endif
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
        case GP_20:
            if (record->event.pressed) {
                register_joystick_button(20);
            } else {
                unregister_joystick_button(20);
            }
            return false;
    }

    return true;
};

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable=true;
    debug_matrix=true;
    //debug_keyboard=true;
    debug_mouse=true;
#ifdef ANALOG_JOYSTICK_SCROLL
    analog_joystick_init();
#endif
}

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


#ifdef ANALOG_JOYSTICK_SCROLL
#define DEADZONE 0
int16_t scrollMinAxisValues[2] = {0,0};
int16_t scrollMaxAxisValues[2] = {0,0};
#define MAX_RATE 50
#define MIN_RATE 200

uint16_t joystick_timer = 0;
uint16_t scroll_timer_x = 0;
uint16_t scroll_timer_y = 0;
// auto range with time
void matrix_scan_user(void) {
    if (!is_keyboard_left()) return;
    if (!joystick_scroll_enabled) return;
    if (timer_elapsed(joystick_timer) < ANALOG_JOYSTICK_READ_INTERVAL) return;
    joystick_timer = timer_read();

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
#ifdef JOYSTICK_DEBUG
    uprintf("mouse_report.x: %i\n", mouse_report.x);
    uprintf("mouse_report.y: %i\n", mouse_report.y);
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
#endif

bool jp = false;
bool eisu = false;
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _BSE:
    case _NUM:
        if (jp) {
            SEND_STRING(SS_LCTL(" "));
            jp = false;
        }
        break;
    case _JP1:
        if (!jp) {
            SEND_STRING(SS_LCTL(" "));
            jp = true;
        }
        break;
    }
  return state;
}
