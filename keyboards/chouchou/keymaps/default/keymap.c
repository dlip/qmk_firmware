// Copyright 2023 Dane Lipscombe (@dlip)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
enum my_keycodes {
    KC_STICKY_LGUI = SAFE_RANGE,
    KC_STICKY_LALT,
    KC_STICKY_LCTL,
    KC_STICKY_LSFT,
    KC_R_R,
    KC_R_S,
    KC_R_N,
    KC_R_I,
    KC_R_A,
    KC_R_O,
    KC_R_T,
    KC_R_E,
    KC_R_SPC,
    KC_R_BSPC,
};
// #include "g/keymap_combo.h"


// Separating right side keycodes makes quick letter combos more reliable
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_2x4_2(
        KC_R,    KC_S,    KC_N,    KC_I,        KC_1,    KC_2,    KC_3,  KC_4,
        KC_A,    KC_O,    KC_T,    KC_E,        KC_5,    KC_6,    KC_7,  KC_8,
                          KC_BSPC, KC_SPC,      KC_9,  KC_0
    )
};

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md
// This will need some messing with but it's close
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(record->event.pressed)
        switch(keycode) {
        case KC_STICKY_LGUI: add_oneshot_mods(MOD_BIT(KC_LGUI)); add_mods(MOD_BIT(KC_LGUI)); break;
        case KC_STICKY_LALT: add_oneshot_mods(MOD_BIT(KC_LALT)); add_mods(MOD_BIT(KC_LALT)); break;
        case KC_STICKY_LCTL: add_oneshot_mods(MOD_BIT(KC_LCTL)); add_mods(MOD_BIT(KC_LCTL)); break;
        case KC_STICKY_LSFT: add_oneshot_mods(MOD_BIT(KC_LSFT)); add_mods(MOD_BIT(KC_LSFT)); break;
        case KC_R_R: tap_code(KC_R); break;
        case KC_R_S: tap_code(KC_S); break;
        case KC_R_N: tap_code(KC_N); break;
        case KC_R_I: tap_code(KC_I); break;
        case KC_R_A: tap_code(KC_A); break;
        case KC_R_O: tap_code(KC_O); break;
        case KC_R_T: tap_code(KC_T); break;
        case KC_R_E: tap_code(KC_E); break;
        case KC_R_SPC: tap_code(KC_SPC); break;
        case KC_R_BSPC: tap_code(KC_BSPC); break;
        }
    else
        switch(keycode) {
        case KC_STICKY_LGUI: case KC_STICKY_LALT: case KC_STICKY_LCTL: case KC_STICKY_LSFT: clear_mods(); break;
        }
    return true;
}

// void keyboard_post_init_user(void) {
//   // Customise these values to desired behaviour
//   debug_enable=true;
//   debug_matrix=true;
//   //debug_keyboard=true;
//   //debug_mouse=true;
// }
