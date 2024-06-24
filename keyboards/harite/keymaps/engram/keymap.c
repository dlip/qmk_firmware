// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "os_detection.h"

enum custom_keycodes {
    KC_COMBO = SAFE_RANGE,
    KC_CALL,
    KC_CUDO,
    KC_CCUT,
    KC_CCPY,
    KC_CPST,
    KC_SEN,
    KC_MSCL,
};


enum mylayers {
    _BSE,
    _NAV,
    _NUM,
    _FUN,
    _MSE,
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

#define KC_SFT_Q MT(MOD_LSFT, KC_Q)
#define KC_ALT_QUO MT(MOD_LALT, KC_QUOTE)
#define KC_GUI_CMA MT(MOD_LGUI, KC_COMMA)
#define KC_CTL_DOT MT(MOD_LCTL, KC_DOT)
#define KC_CAG_LBC LCAG_T(KC_LBRC)
#define KC_CAG_2 LCAG_T(KC_2)
#define KC_CTL_4 MT(MOD_LCTL, KC_4)
#define KC_GUI_5 MT(MOD_LGUI, KC_5)
#define KC_ALT_6 MT(MOD_LALT, KC_6)
#define KC_SFT_0 MT(MOD_LSFT, KC_0)

#define KC_SFT_BSP MT(MOD_RSFT, KC_BSPC)
#define KC_ALT_DEL MT(MOD_LALT, KC_DEL)
#define KC_GUI_ESC MT(MOD_LGUI, KC_ESC)
#define KC_CTL_ENT MT(MOD_LCTL, KC_ENTER)
#define KC_CAG_NO LCAG_T(KC_NO)
#define KC_CTL_LFT MT(MOD_LCTL, KC_LEFT)
#define KC_GUI_DWN MT(MOD_LGUI, KC_DOWN)
#define KC_ALT_RGT MT(MOD_LALT, KC_RIGHT)
#define KC_SFT_PGD MT(MOD_LSFT, KC_PGDN)

#define KC_SFT_MUT MT(MOD_LSFT, KC_MUTE)
#define KC_ALT_PRV MT(MOD_LALT, KC_MPRV)
#define KC_GUI_PLY MT(MOD_LGUI, KC_MPLY)
#define KC_CTL_NXT MT(MOD_LCTL, KC_MNXT)
#define KC_CAG_BRD LCAG_T(KC_BRID)
#define KC_CAG_F2 LCAG_T(KC_F2)
#define KC_CTL_F4 MT(MOD_LCTL, KC_F4)
#define KC_GUI_F5 MT(MOD_LGUI, KC_F5)
#define KC_ALT_F6 MT(MOD_LALT, KC_F6)
#define KC_SFT_F10 MT(MOD_LSFT, KC_F10)

#define KC_FUN MO(_FUN)
#define KC_COMBO_SFT MT(MOD_LSFT, KC_BSPC)
#define KC_COMBO_ALT1 LT(_NUM, KC_TAB)
#define KC_COMBO_ALT2 LT(_NAV, KC_SPC)

#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BSE] = LAYOUT_split_5x5(
              KC_B,                 KC_Y,                 KC_O,                                KC_U,                                  KC_L,                   KC_D,               KC_W,               KC_V,
        KC_Z, KC_NO, KC_G,  KC_DEL, KC_NO, KC_X,  KC_ESC, KC_NO, KC_CAG_J,           KC_ENTER, KC_NO, KC_K,                     KC_R, KC_NO, KC_R,  KC_CAG_M, KC_NO, KC_R,  KC_F, KC_NO, KC_R,  KC_P, KC_NO, KC_R,
              KC_SFT_C,             KC_ALT_I,             KC_GUI_E,                            KC_CTL_A,                              KC_CTL_H,               KC_GUI_T,           KC_ALT_S,           KC_SFT_N,

                                                                                               KC_BTN1,                               KC_BTN2,
                                                                                KC_COMBO_ALT2, KC_NO, KC_COMBO_ALT1,        KC_COMBO, KC_NO, KC_COMBO_SFT,
                                                                                               KC_BTN3,                               KC_BTN4
    )
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
                return false;
            }
            break;
        case KC_CALL:
            if (record->event.pressed) {
                switch(detected_host_os()) {
                    case OS_MACOS:
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
                        tap_code16(G(KC_C));
                        break;
                    default:
                        tap_code16(C(KC_C));
                        break;
                }
                return false;
            }
            break;
        // case KC_CAG_CPY:
        //     if (record->tap.count && record->event.pressed) {
        //         switch(detected_host_os()) {
        //             case OS_MACOS:
        //                 tap_code16(G(KC_C));
        //                 break;
        //             default:
        //                 tap_code16(C(KC_C));
        //                 break;
        //         }
        //         return false;
        //     }
        //     break;
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
    }

    return true;
};
