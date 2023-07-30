// Copyright 2023 Dane Lipscombe (@dlip)
// SPDX-License-Identifier: GPL-2.0-or-later
// This is the config based on the code whorf gave me which uses custom combos
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_2x4_2(
        0,            1,            2,            3,            13,         12,           11,           10,
        4,            5,            6,            7,            17,         16,           15,           14,
                                    8,            9,            19,         18
    )
};

static uint16_t state;
uint16_t start = 0;
enum SIDE{NONE,RIGHT,LEFT};
enum SIDE side = NONE;
#define r 1<<0
#define s 1<<1
#define n 1<<2
#define i 1<<3
#define a 1<<4
#define o 1<<5
#define t 1<<6
#define e 1<<7
#define it 1<<8
#define ot 1<<9

//a b c d e f g h i j k l m n o p q r s t u v w x y z 
//< 9 1 @ ( 6 # 0 ) = + 4 $ ] { 7 3 > } [ 2 * & ^ 5 8
const uint16_t l2[32] = {
    KC_LT,KC_9, KC_1, KC_AT, KC_LPRN, KC_6, KC_HASH, KC_0, KC_RPRN, KC_EQL, KC_PLUS, KC_4, KC_DLR, KC_RBRC, KC_LCBR, KC_7, KC_3, KC_GT, KC_RCBR, KC_LBRC, KC_2, KC_ASTR, KC_AMPR, KC_CIRC, KC_5, KC_8
};

static void process(uint16_t val) {
    uint16_t v = 0;
    #define V(x) v=KC_##x; break;
    bool inner = (val & (1 << 8)) >> 8;
    bool outer = (val & (1 << 9)) >> 9;
    val = val & ~(1 << 8);
    val = val & ~(1 << 9);

    switch (val) {
        case e: V(E)
        case t: V(T)
        case o: V(O)
        case a: V(A)
        case i: V(I)
        case n: V(N)
        case s: V(S)
        case r: V(R)

        case e|t: V(H)
        case o|a: V(L)
        case i|n: V(Y)
        case s|r: V(B)
                            
        case i|r: V(G)
        case t|o: V(U)
        case e|a: V(D)
        case n|s: V(P)
                            
        case e|o: V(C)
        case t|a: V(Q)
        case i|s: V(F)
        case n|r: V(Z)
                            
        case e|s: V(V)
        case t|r: V(X)
        case i|o: V(K)
        case n|a: V(J)
                            
        case i|a: V(W)
        case e|r: V(M)

        case n|o: V(MINS)
        case t|s: V(SLSH)
        case s|a: V(QUOT)
        case e|n: V(COMM)
        case o|r: V(SCLN)
        case i|t: V(QUES)
        default: v=0;
    }
    switch(v){
        case 0: tap_code16(inner?KC_SPC:(outer?KC_BSPC:KC_NO)); break;
        case KC_A...KC_Z: 
            if(inner) {
                tap_code16(S(v)); 
            } else if(outer) {
                tap_code16(l2[v-KC_A]);
            } else {
                tap_code16(v);
            }
            break;
        case KC_MINS: tap_code16(inner?KC_UNDS:(outer?KC_PERC:v)); break;
        case KC_SLSH: tap_code16(inner?KC_BSLS:(outer?KC_PIPE:v)); break;
        case KC_QUOT: tap_code16(inner?KC_DQT:(outer?KC_GRV:v)); break;
        case KC_COMM: tap_code16(inner?KC_DOT:(outer?KC_TILD:v)); break;
        case KC_SCLN: tap_code16(inner?KC_COLN:(outer?KC_NO:v)); break;
        case KC_QUES: tap_code16(inner?KC_EXLM:(outer?KC_NO:v)); break;
        default: 
            tap_code(v);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(record->event.pressed) {
        if(side == keycode/10+1){
            state |= 1 << (keycode%10); 
        } else {
            if(side != NONE) {
                process(state);
                state = 0;
            }
            side = keycode/10+1;
            state |= 1 << (keycode%10);
        }
    } else {
        process(state);
        state = 0;
    }
    return false;
};

// #include QMK_KEYBOARD_H
// enum my_keycodes {
//     KC_STICKY_LGUI = SAFE_RANGE,
//     KC_STICKY_LALT,
//     KC_STICKY_LCTL,
//     KC_STICKY_LSFT,
//     KC_R_R,
//     KC_R_S,
//     KC_R_N,
//     KC_R_I,
//     KC_R_A,
//     KC_R_O,
//     KC_R_T,
//     KC_R_E,
//     KC_R_SPC,
//     KC_R_BSPC,
// };
// #include "g/keymap_combo.h"


// // Separating right side keycodes makes quick letter combos more reliable
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     [0] = LAYOUT_split_2x4_2(
//         KC_R,    KC_S,    KC_N,    KC_I,        KC_R_I,    KC_R_N,    KC_R_S,  KC_R_R,
//         KC_A,    KC_O,    KC_T,    KC_E,        KC_R_E,    KC_R_T,    KC_R_O,  KC_R_A,
//                           KC_BSPC, KC_SPC,      KC_R_SPC,  KC_R_BSPC
//     )
// };

// // https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md
// // This will need some messing with but it's close
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     if(record->event.pressed)
//         switch(keycode) {
//         case KC_STICKY_LGUI: add_oneshot_mods(MOD_BIT(KC_LGUI)); add_mods(MOD_BIT(KC_LGUI)); break;
//         case KC_STICKY_LALT: add_oneshot_mods(MOD_BIT(KC_LALT)); add_mods(MOD_BIT(KC_LALT)); break;
//         case KC_STICKY_LCTL: add_oneshot_mods(MOD_BIT(KC_LCTL)); add_mods(MOD_BIT(KC_LCTL)); break;
//         case KC_STICKY_LSFT: add_oneshot_mods(MOD_BIT(KC_LSFT)); add_mods(MOD_BIT(KC_LSFT)); break;
//         case KC_R_R: tap_code(KC_R); break;
//         case KC_R_S: tap_code(KC_S); break;
//         case KC_R_N: tap_code(KC_N); break;
//         case KC_R_I: tap_code(KC_I); break;
//         case KC_R_A: tap_code(KC_A); break;
//         case KC_R_O: tap_code(KC_O); break;
//         case KC_R_T: tap_code(KC_T); break;
//         case KC_R_E: tap_code(KC_E); break;
//         case KC_R_SPC: tap_code(KC_SPC); break;
//         case KC_R_BSPC: tap_code(KC_BSPC); break;
//         }
//     else
//         switch(keycode) {
//         case KC_STICKY_LGUI: case KC_STICKY_LALT: case KC_STICKY_LCTL: case KC_STICKY_LSFT: clear_mods(); break;
//         }
//     return true;
// }

// // void keyboard_post_init_user(void) {
// //   // Customise these values to desired behaviour
// //   debug_enable=true;
// //   debug_matrix=true;
// //   //debug_keyboard=true;
// //   //debug_mouse=true;
// // }
