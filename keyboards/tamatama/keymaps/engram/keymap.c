// Copyright 2023 Dane Lipscombe (@dlip)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "os_detection.h"

enum custom_keycodes {
    KC_COMBO = SAFE_RANGE,
    KC_CUDO,
    KC_CCUT,
    KC_CCPY,
    KC_CPST,
};


enum mylayers {
    _BSE,
    _SYM,
    _NUM,
    _MED,
};

#define KC_SFT_C MT(MOD_LSFT, KC_C)
#define KC_ALT_I MT(MOD_LALT, KC_I)
#define KC_GUI_E MT(MOD_LGUI, KC_E)
#define KC_CTL_A MT(MOD_LCTL, KC_A)
#define KC_CAG_J LCAG_T(KC_J)
#define KC_CAG_M LCAG_T(KC_M)
#define KC_CTL_H MT(MOD_LCTL, KC_H)
#define KC_GUI_T MT(MOD_LGUI, KC_T)
#define KC_ALT_S MT(MOD_LALT, KC_S)
#define KC_SFT_N MT(MOD_LSFT, KC_N)

#define KC_SFT_UDO MT(MOD_LSFT, KC_CUDO)
#define KC_ALT_CUT MT(MOD_LALT, KC_CCUT)
#define KC_GUI_CPY MT(MOD_LGUI, KC_CCPY)
#define KC_CTL_PST MT(MOD_LCTL, KC_CPST)
#define KC_CAG_BN2 LCAG_T(KC_BTN2)
#define KC_CAG_LBC LCAG_T(KC_LBRC)
#define KC_CTL_QUO MT(MOD_LCTL, KC_QUOT)
#define KC_GUI_CMA MT(MOD_LGUI, KC_COMMA)
#define KC_ALT_DOT MT(MOD_LALT, KC_DOT)
#define KC_SFT_SCN MT(MOD_LSFT, KC_SCLN)

#define KC_SFT_DOT MT(MOD_LSFT, KC_DOT)
#define KC_ALT_LFT MT(MOD_LALT, KC_LEFT)
#define KC_GUI_DWN MT(MOD_LGUI, KC_DOWN)
#define KC_CTL_RGT MT(MOD_LCTL, KC_RIGHT)
#define KC_CAG_MIN LCAG_T(KC_MINUS)
#define KC_CAG_2 LCAG_T(KC_2)
#define KC_CTL_4 MT(MOD_LCTL, KC_4)
#define KC_GUI_5 MT(MOD_LGUI, KC_5)
#define KC_ALT_6 MT(MOD_LALT, KC_6)
#define KC_SFT_0 MT(MOD_LSFT, KC_0)

#define KC_SFT_BRU MT(MOD_LSFT, KC_BRIU)
#define KC_ALT_HME MT(MOD_LALT, KC_HOME)
#define KC_GUI_PGDN MT(MOD_LGUI, KC_PGDN)
#define KC_CTL_END MT(MOD_LCTL, KC_END)
#define KC_CAG_PLY LCAG_T(KC_MPLY)
#define KC_CAG_F2 LCAG_T(KC_F2)
#define KC_CTL_F4 MT(MOD_LCTL, KC_F4)
#define KC_GUI_F5 MT(MOD_LGUI, KC_F5)
#define KC_ALT_F6 MT(MOD_LALT, KC_F6)
#define KC_SFT_F10 MT(MOD_LSFT, KC_F10)

#define KC_MED MO(_MED)
#define KC_COMBO_SFT MT(MOD_LSFT, KC_BSPC)
#define KC_COMBO_ALT1 LT(_SYM, KC_TAB)
#define KC_COMBO_ALT2 LT(_NUM, KC_SPC)

#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BSE] = LAYOUT_split_3x4_2(
         KC_B,     KC_Y,     KC_O,          KC_U,             KC_L,         KC_D,        KC_W,     KC_V,
         KC_SFT_C, KC_ALT_I, KC_GUI_E,      KC_CTL_A,         KC_CTL_H,     KC_GUI_T,    KC_ALT_S, KC_SFT_N,
         KC_G,     KC_X,     KC_CAG_J,      KC_K,             KC_R,         KC_CAG_M,    KC_F,     KC_P,
                             KC_COMBO_ALT1, KC_COMBO_ALT2,    KC_COMBO_SFT, KC_COMBO
    ),
    [_SYM] = LAYOUT_split_3x4_2(
         KC_GRV,       KC_ESC,     KC_DEL,     KC_ENT,        KC_Z,       KC_MINUS,   KC_EQL,     KC_BSLS,
         KC_SFT_UDO,   KC_ALT_CUT, KC_GUI_CPY, KC_CTL_PST,    KC_CTL_QUO, KC_GUI_CMA, KC_ALT_DOT, KC_SFT_SCN,
         KC_PSCR,      KC_BTN3,    KC_CAG_BN2, KC_BTN1,       KC_Q,       KC_CAG_LBC, KC_RBRC,    KC_SLSH,
                                   KC_TRNS,    KC_MED,        KC_TRNS,    KC_TRNS
    ),
    [_NUM] = LAYOUT_split_3x4_2(
         KC_ASTR,      KC_ESC,     KC_UP,      KC_ENT,        KC_7,     KC_8,     KC_9,     KC_CIRC,
         KC_SFT_DOT,   KC_ALT_LFT, KC_GUI_DWN, KC_CTL_RGT,    KC_CTL_4, KC_GUI_5, KC_ALT_6, KC_SFT_0,
         KC_SLSH,      KC_CAG_MIN, KC_EQL,     KC_PLUS,       KC_1,     KC_CAG_2, KC_3,     KC_PERC,
                                   KC_MED,     KC_TRNS,       KC_TRNS,  KC_TRNS
    ),
    [_MED] = LAYOUT_split_3x4_2(
         QK_BOOT,    KC_VOLD,    KC_PGUP,     KC_VOLU,       KC_F7,     KC_F8,     KC_F9,     KC_F11,
         KC_SFT_BRU, KC_ALT_HME, KC_GUI_PGDN, KC_CTL_END,    KC_CTL_F4, KC_GUI_F5, KC_ALT_F6, KC_SFT_F10,
         KC_BRID,    KC_MPRV,    KC_CAG_PLY,  KC_MNXT,       KC_F1,     KC_CAG_F2, KC_F3,     KC_F12,
                                 KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS
    ),
    // [_BLANK] = LAYOUT_split_3x4_2(
    //      KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO,
    //      KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO,
    //      KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO,
    //                    KC_NO, KC_NO,    KC_NO, KC_NO
    // ),
};

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_COMBO_SFT:
            return 0;
        case KC_COMBO_ALT2:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_COMBO_SFT:
        case KC_COMBO_ALT1:
            return true;
        default:
            return false;
    }
}

// sets the left side pointing device to scroll only
void keyboard_post_init_user(void) {
    pointing_device_set_cpi_on_side(true, 1000); //Set cpi on left side to a low value for slower scrolling.
    pointing_device_set_cpi_on_side(false, 8000); //Set cpi on right side to a reasonable value for mousing.
}

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    left_report.h = left_report.x;
    left_report.v = left_report.y;
    left_report.x = 0;
    left_report.y = 0;
    return pointing_device_combine_reports(left_report, right_report);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_COMBO:
            if (record->event.pressed) {
                switch(detected_host_os()) {
                    case OS_MACOS:
                        tap_code16(A(KC_BSPC));
                        break;
                    default:
                        tap_code16(C(KC_BSPC));
                        break;
                }
            }
            break;
        case KC_CUDO:
            if (record->event.pressed) {
                switch(detected_host_os()) {
                    case OS_MACOS:
                        tap_code16(G(KC_Z));
                        break;
                    default:
                        tap_code16(C(KC_Z));
                        break;
                }
            }
            break;
        case KC_CCUT:
            if (record->event.pressed) {
                switch(detected_host_os()) {
                    case OS_MACOS:
                        tap_code16(G(KC_X));
                        break;
                    default:
                        tap_code16(C(KC_X));
                        break;
                }
            }
            break;
        case KC_CCPY:
            if (record->event.pressed) {
                switch(detected_host_os()) {
                    case OS_MACOS:
                        tap_code16(G(KC_C));
                        break;
                    default:
                        tap_code16(C(KC_C));
                        break;
                }
            }
            break;
        case KC_CPST:
            if (record->event.pressed) {
                switch(detected_host_os()) {
                    case OS_MACOS:
                        tap_code16(G(KC_V));
                        break;
                    default:
                        tap_code16(C(KC_V));
                        break;
                }
            }
            break;
    }

    return true;
};
