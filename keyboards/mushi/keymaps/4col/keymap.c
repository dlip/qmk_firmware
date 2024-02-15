// Copyright 2023 Dane Lipscombe (@dlip)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum mylayers {
    _BSE,
    _NAV,
    _NUM,
    _MED,
};

#define KC_ALT_R MT(MOD_LALT, KC_R)
#define KC_GUI_S MT(MOD_LGUI, KC_S)
#define KC_CTL_T MT(MOD_LCTL, KC_T)
#define KC_SFT_D MT(MOD_LSFT, KC_D)
#define KC_CAG_V LCAG_T(KC_V)
#define KC_CAG_SCLN LCAG_T(KC_SCLN)
#define KC_SFT_H MT(MOD_LSFT, KC_H)
#define KC_CTL_N MT(MOD_LCTL, KC_N)
#define KC_GUI_E MT(MOD_LGUI, KC_E)
#define KC_ALT_I MT(MOD_LALT, KC_I)
#define KC_MED_W LT(_MED, KC_W)
#define KC_MED_C LT(_MED, KC_C)
#define KC_MED_Q LT(_MED, KC_Q)
#define KC_MED_A LT(_MED, KC_A)

#define KC_ALT_ESC MT(MOD_LALT, KC_ESC)
#define KC_GUI_BSPC MT(MOD_LGUI, KC_BSPC)
#define KC_CTL_G MT(MOD_LCTL, KC_G)
#define KC_CTL_M MT(MOD_LCTL, KC_M)

#define KC_NAV OSL(_NAV)
#define KC_NUM OSL(_NUM)
#define KC_MED OSL(_MED)
#define KC_OS_SFT OSM(MOD_LSFT)
#define KC_MED_SPC LT(_MED, KC_SPC)
#define KC_SFT_SPC MT(MOD_LSFT, KC_SPC)

#define KC_ALT_LFT MT(MOD_LALT, KC_LEFT)
#define KC_GUI_DWN MT(MOD_LGUI, KC_DOWN)
#define KC_CTL_RGT MT(MOD_LCTL, KC_RIGHT)
#define KC_SFT_END MT(MOD_LSFT, KC_END)
#define KC_CAG_PGDN LCAG_T(KC_PGDN)

#define KC_CAG_2 LCAG_T(KC_2)
#define KC_ALT_6 MT(MOD_LALT, KC_6)
#define KC_GUI_5 MT(MOD_LGUI, KC_5)
#define KC_CTL_4 MT(MOD_LCTL, KC_4)

#define KC_ALT_MPRV MT(MOD_LALT, KC_MPRV)
#define KC_GUI_MPLY MT(MOD_LGUI, KC_MPLY)
#define KC_CTL_MNXT MT(MOD_LCTL, KC_MNXT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BSE] = LAYOUT_split_3x5_3(
         KC_MED_W, KC_L,     KC_Y,     KC_P,     KC_NO,            KC_NO,      KC_F,     KC_O,        KC_U,     KC_QUOT,
         KC_MED_C, KC_ALT_R, KC_GUI_S, KC_CTL_T, KC_NO,            KC_NO,      KC_CTL_N, KC_GUI_E,    KC_ALT_I, KC_MED_A,
         KC_MED_Q, KC_J,     KC_CAG_V, KC_SFT_D, KC_NO,            KC_NO,      KC_H,     KC_CAG_SCLN, KC_COMMA, KC_DOT,
                             KC_MED,   KC_NUM,   KC_SFT_SPC,       KC_OS_SFT,  KC_NAV,   QK_REPEAT_KEY
    ),
    [_NAV] = LAYOUT_split_3x5_3(
         KC_GRV,     KC_LBRC,    KC_UP,       KC_LBRC,    KC_TRNS,        KC_TRNS,  KC_Z,     KC_ENT,      KC_DEL,     KC_TRNS,
         KC_TAB,     KC_ALT_LFT, KC_GUI_DWN,  KC_CTL_RGT, KC_TRNS,        KC_TRNS,  KC_CTL_M, KC_GUI_BSPC, KC_ALT_ESC, KC_TAB,
         KC_HOME,    KC_PGUP,    KC_CAG_PGDN, KC_SFT_END, KC_TRNS,        KC_TRNS,  KC_X,     KC_TRNS,     KC_TRNS,    KC_TRNS,
                                 KC_TRNS,     KC_TRNS,    KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [_NUM] = LAYOUT_split_3x5_3(
         KC_GRV,     KC_DEL,     KC_ENT,      KC_B,       KC_TRNS,        KC_TRNS,  KC_7,     KC_8,     KC_9,     KC_SLSH,
         KC_TAB,     KC_ALT_ESC, KC_GUI_BSPC, KC_CTL_G,   KC_TRNS,        KC_TRNS,  KC_CTL_4, KC_GUI_5, KC_ALT_6, KC_0,
         KC_BSLS,    KC_MINUS,   KC_EQL,      KC_K,       KC_TRNS,        KC_TRNS,  KC_1,     KC_CAG_2, KC_3,     KC_DOT,
                                 KC_TRNS,     KC_TRNS,    KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [_MED] = LAYOUT_split_3x5_3(
         G(KC_Z), G(KC_X),     G(KC_C),     G(KC_V),     KC_VOLU,        KC_NO,    KC_F7,   KC_F8, KC_F9, KC_F11,
         KC_PSCR, KC_ALT_MPRV, KC_GUI_MPLY, KC_CTL_MNXT, KC_VOLD,        KC_NO,    KC_F4,   KC_F5, KC_F6, KC_F10,
         C(KC_Z), C(KC_X),     C(KC_C),     C(KC_V),     KC_PSCR,        KC_NO,    KC_F1,   KC_F2, KC_F3, KC_F12,
                               KC_TRNS,     KC_TRNS,     KC_TRNS,        KC_TRNS,  KC_TRNS, KC_TRNS
    ),
    // [_BLANK] = LAYOUT_split_3x5_3(
    //      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    //      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    //      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    //                    KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO
    // ),
};


