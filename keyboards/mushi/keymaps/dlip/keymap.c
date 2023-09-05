// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum mylayers {
    _BSE,
    _NUM,
    _NAV,
    _MED,
};

#define KC_MED_A LT(_MED, KC_A)
#define KC_ALT_R MT(MOD_LALT, KC_R)
#define KC_GUI_S MT(MOD_LGUI, KC_S)
#define KC_CTL_T MT(MOD_LCTL, KC_T)
#define KC_CTL_N MT(MOD_LCTL, KC_N)
#define KC_GUI_E MT(MOD_LGUI, KC_E)
#define KC_ALT_I MT(MOD_LALT, KC_I)
#define KC_MED_O LT(_MED, KC_O)
#define KC_NAV MO(_NAV)
#define KC_NUM MO(_NUM)
#define KC_OS_SFT OSM(KC_LSFT)

#define KC_ALT_DEL MT(MOD_LALT, KC_DEL)
#define KC_GUI_BSPC MT(MOD_LGUI, KC_BSPC)
#define KC_CTL_ENT MT(MOD_LCTL, KC_ENT)

#define KC_ALT_MPRV MT(MOD_LALT, KC_MPRV)
#define KC_GUI_MPLY MT(MOD_LGUI, KC_MPLY)
#define KC_CTL_MNXT MT(MOD_LCTL, KC_MNXT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BSE] = LAYOUT_split_3x5_3(
         KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,             KC_J,      KC_L,     KC_U,     KC_Y,     KC_SCLN,
         KC_MED_A, KC_ALT_R, KC_GUI_S, KC_CTL_T, KC_G,             KC_M,      KC_CTL_N, KC_GUI_E, KC_ALT_I, KC_MED_O,
         KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,             KC_K,      KC_H,     KC_COMMA, KC_DOT,   KC_QUOT,
                             KC_NUM,   KC_SPC,   KC_OS_SFT,        KC_OS_SFT, KC_BSPC,  KC_NAV
    ),
    [_NUM] = LAYOUT_split_3x5_3(
         KC_NO,  KC_NO,      KC_NO,       KC_NO,      KC_NO,          KC_NO,    KC_7,    KC_8, KC_9, KC_NO,
         KC_ESC, KC_ALT_DEL, KC_GUI_BSPC, KC_CTL_ENT, KC_EQL,         KC_NO,    KC_4,    KC_5, KC_6, KC_0,
         KC_NO,  KC_NO,      KC_NO,       KC_NO,      KC_NO,          KC_MINUS, KC_1,    KC_2, KC_3, KC_SLSH,
                             KC_TRNS,     KC_TRNS,    KC_TRNS,        KC_TRNS,  KC_TRNS, KC_TRNS
    ),
    [_NAV] = LAYOUT_split_3x5_3(
         KC_NO,   KC_PGUP, KC_UP,   KC_PGDN,  KC_NO,          KC_NO,   KC_NO,        KC_NO, KC_NO, KC_NO,
         KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,         KC_NO,   KC_CTL_ENT,   KC_GUI_BSPC,  KC_ALT_DEL, KC_ESC,
         KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,          KC_NO,   KC_NO,        KC_NO, KC_NO, KC_NO,
                           KC_TRNS, KC_TRNS,  KC_TRNS,        KC_TRNS, KC_TRNS,      KC_TRNS
    ),
    [_MED] = LAYOUT_split_3x5_3(
         KC_NO, KC_VOLD,     KC_NO,       KC_VOLU,     KC_NO,          KC_NO,   KC_F7,   KC_F8, KC_F9, KC_F11,
         KC_NO, KC_ALT_MPRV, KC_GUI_MPLY, KC_CTL_MNXT, KC_NO,          KC_NO,   KC_F4,   KC_F5, KC_F6, KC_F10,
         KC_NO, KC_NO,       KC_NO,       KC_NO,       KC_NO,          KC_NO,   KC_F1,   KC_F2, KC_F3, KC_F12,
                             KC_TRNS,     KC_TRNS,     KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS
    ),
    // [_BLANK] = LAYOUT_split_3x5_3(
    //      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    //      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    //      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    //                    KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO
    // ),
};
