// Copyright 2023 Dane Lipscombe (@dlip)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
enum my_keycodes {
    MY_LGUI = SAFE_RANGE,
    MY_LALT,
    MY_LCTL,
    MY_LSFT,
};
#include "g/keymap_combo.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_2x4_2(
        KC_R,    KC_S,    KC_N,    KC_I,        KC_I,    KC_N,    KC_S,    KC_R,
        KC_A,    KC_O,    KC_T,    KC_E,        KC_E,    KC_T,    KC_O,    KC_A,
                          KC_BSPC, KC_SPC,      KC_SPC,  KC_BSPC
    )
};

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md
// This will need some messing with but it's close
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(record->event.pressed)
        switch(keycode) {
        case MY_LGUI: add_oneshot_mods(MOD_BIT(KC_LGUI)); add_mods(MOD_BIT(KC_LGUI)); break;
        case MY_LALT: add_oneshot_mods(MOD_BIT(KC_LALT)); add_mods(MOD_BIT(KC_LALT)); break;
        case MY_LCTL: add_oneshot_mods(MOD_BIT(KC_LCTL)); add_mods(MOD_BIT(KC_LCTL)); break;
        case MY_LSFT: add_oneshot_mods(MOD_BIT(KC_LSFT)); add_mods(MOD_BIT(KC_LSFT)); break;
        }
    else
        switch(keycode) {
        case MY_LGUI: case MY_LALT: case MY_LCTL: case MY_LSFT: clear_mods(); break;
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
