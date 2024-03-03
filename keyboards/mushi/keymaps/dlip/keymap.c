// Copyright 2023 Dane Lipscombe (@dlip)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    KC_COMBO = SAFE_RANGE,
};


enum mylayers {
    _BSE,
    _NNM,
    _MED,
};

#define KC_SFT_C MT(MOD_LSFT, KC_C)
#define KC_ALT_R MT(MOD_LALT, KC_R)
#define KC_GUI_S MT(MOD_LGUI, KC_S)
#define KC_CTL_T MT(MOD_LCTL, KC_T)
#define KC_CAG_V LCAG_T(KC_V)
#define KC_CAG_SCLN LCAG_T(KC_SCLN)
#define KC_SFT_H MT(MOD_LSFT, KC_H)
#define KC_CTL_N MT(MOD_LCTL, KC_N)
#define KC_GUI_E MT(MOD_LGUI, KC_E)
#define KC_ALT_I MT(MOD_LALT, KC_I)
#define KC_SFT_A MT(MOD_LSFT, KC_A)

#define KC_MED MO(_MED)

#define KC_ALT_LFT MT(MOD_LALT, KC_LEFT)
#define KC_GUI_DWN MT(MOD_LGUI, KC_DOWN)
#define KC_CTL_RGT MT(MOD_LCTL, KC_RIGHT)
#define KC_SFT_END MT(MOD_LSFT, KC_END)
#define KC_CAG_PGDN LCAG_T(KC_PGDN)

#define KC_CAG_2 LCAG_T(KC_2)
#define KC_CTL_4 MT(MOD_LCTL, KC_4)
#define KC_GUI_5 MT(MOD_LGUI, KC_5)
#define KC_ALT_6 MT(MOD_LALT, KC_6)
#define KC_SFT_0 MT(MOD_LSFT, KC_0)

#define KC_SFT_UDO MT(MOD_LSFT, C(KC_Z))
#define KC_ALT_CUT MT(MOD_LALT, C(KC_X))
#define KC_GUI_CPY MT(MOD_LGUI, C(KC_C))
#define KC_CTL_PST MT(MOD_LCTL, C(KC_V))

#define KC_CTL_F4 MT(MOD_LCTL, KC_F4)
#define KC_GUI_F5 MT(MOD_LGUI, KC_F5)
#define KC_ALT_F6 MT(MOD_LALT, KC_F6)
#define KC_SFT_F10 MT(MOD_LSFT, KC_F10)

#define KC_SFT_BSPC MT(MOD_LSFT, KC_BSPC)
#define KC_NNM_TAB LT(_NNM, KC_TAB)
#define KC_MED_SPC LT(_MED, KC_SPC)

#define KC_COMBO_SFT KC_SFT_BSPC
#define KC_COMBO_ALT1 KC_NNM_TAB
#define KC_COMBO_ALT2 KC_MED_SPC

#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BSE] = LAYOUT_split_3x5_3(
         KC_W,     KC_L,     KC_Y,     KC_P,       KC_B,             KC_Z,        KC_F,       KC_O,        KC_U,     KC_QUOT,
         KC_SFT_C, KC_ALT_R, KC_GUI_S, KC_CTL_T,   KC_G,             KC_M,        KC_CTL_N,   KC_GUI_E,    KC_ALT_I, KC_SFT_A,
         KC_Q,     KC_J,     KC_CAG_V, KC_D,       KC_K,             KC_X,        KC_H,       KC_CAG_SCLN, KC_COMMA, KC_DOT,
                             KC_MED,   KC_NNM_TAB, KC_MED_SPC,       KC_SFT_BSPC, KC_COMBO,   QK_REPEAT_KEY
    ),
    [_NNM] = LAYOUT_split_3x5_3(
         KC_GRV,      KC_ESC,     KC_UP,       KC_ENT,     KC_DEL,         KC_BSLS,  KC_7,     KC_8,     KC_9,     KC_SLSH,
         KC_SFT_BSPC, KC_ALT_LFT, KC_GUI_DWN,  KC_CTL_RGT, KC_LBRC,        KC_EQL,   KC_CTL_4, KC_GUI_5, KC_ALT_6, KC_SFT_0,
         KC_HOME,     KC_PGUP,    KC_CAG_PGDN, KC_SFT_END, KC_RBRC,        KC_MINUS, KC_1,     KC_CAG_2, KC_3,     KC_DOT,
                                  KC_TRNS,     KC_TRNS,    KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [_MED] = LAYOUT_split_3x5_3(
         G(KC_Z),    G(KC_X),    G(KC_C),    G(KC_V),     KC_PSCR,        KC_NO,    KC_F7,     KC_F8,     KC_F9,     KC_F11,
         KC_SFT_UDO, KC_ALT_CUT, KC_GUI_CPY, KC_CTL_PST,  KC_VOLU,        KC_NO,    KC_CTL_F4, KC_GUI_F5, KC_ALT_F6, KC_SFT_F10,
         KC_MUTE,    KC_MPRV,    KC_MPLY,    KC_MNXT,     KC_VOLD,        KC_NO,    KC_F1,     KC_F2,     KC_F3,     KC_F12,
                                 QK_BOOT,    KC_TRNS,     KC_TRNS,        KC_TRNS,  KC_TRNS,   KC_TRNS
    ),
    // [_BLANK] = LAYOUT_split_3x5_3(
    //      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    //      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    //      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    //                    KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO
    // ),
};

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SFT_BSPC:
            return 0;
        case KC_MED_SPC:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SFT_BSPC:
        case KC_NNM_TAB:
            return true;
        default:
            return false;
    }
}

