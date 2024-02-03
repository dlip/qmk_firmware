// Copyright 2023 Dane Lipscombe (@dlip)
// SPDX-License-Identifier: GPL-2.0-or-later
// Special thanks to Whorf for his help with this

#include QMK_KEYBOARD_H
#include "custom_keycodes.h"
#ifndef PENTI_TAP_TIMEOUT
#define PENTI_TAP_TIMEOUT 150
#endif

typedef struct {
    uint16_t keycode;
    bool     hold;
    bool     hold_handled;
} keypress;

typedef struct {
    uint16_t combo;
    uint16_t timer;
    keypress key;
} state;

static state left_state;
static state right_state;

static void clear_state(state* state) {
    state->combo            = 0;
    state->timer            = 0;
    state->key.keycode      = KC_NO;
    state->key.hold         = false;
    state->key.hold_handled = false;
}

static void clear_all_state(void) {
    clear_state(&left_state);
    clear_state(&right_state);
}

#define r 1 << 0
#define s 1 << 1
#define n 1 << 2
#define i 1 << 3
#define a 1 << 4
#define o 1 << 5
#define t 1 << 6
#define e 1 << 7
#define it 1 << 8
#define ot 1 << 9
static uint16_t determine_key(uint16_t val) {
    switch (val) {
        case it:
            return KC_BSPC;
        case ot:
            return KC_SPC;
        case r:
            return KC_R;
        case r | ot:
            return S(KC_R);
        case r | it:
            return KC_GT;
        case r | ot | it:
            return KC_PRINT_SCREEN;
        case s:
            return KC_S;
        case s | ot:
            return S(KC_S);
        case s | it:
            return KC_RCBR;
        case s | ot | it:
            return KC_BRIGHTNESS_UP;
        case n:
            return KC_N;
        case n | ot:
            return S(KC_N);
        case n | it:
            return KC_RBRC;
        case n | ot | it:
            return KC_BRIGHTNESS_DOWN;
        case i:
            return KC_I;
        case i | ot:
            return S(KC_I);
        case i | it:
            return KC_RPRN;
        case i | ot | it:
            return KC_MEDIA_PLAY_PAUSE;
        case a:
            return KC_A;
        case a | ot:
            return S(KC_A);
        case a | it:
            return KC_LT;
        case a | ot | it:
            return KC_MEDIA_NEXT_TRACK;
        case o:
            return KC_O;
        case o | ot:
            return S(KC_O);
        case o | it:
            return KC_LCBR;
        case o | ot | it:
            return KC_KB_VOLUME_UP;
        case t:
            return KC_T;
        case t | ot:
            return S(KC_T);
        case t | it:
            return KC_LBRC;
        case t | ot | it:
            return KC_KB_VOLUME_DOWN;
        case e:
            return KC_E;
        case e | ot:
            return S(KC_E);
        case e | it:
            return KC_LPRN;
        case e | ot | it:
            return KC_MEDIA_PREV_TRACK;
        case e | o:
            return KC_C;
        case e | o | ot:
            return S(KC_C);
        case e | o | it:
            return KC_1;
        case e | o | ot | it:
            return KC_F1;
        case t | o:
            return KC_U;
        case t | o | ot:
            return S(KC_U);
        case t | o | it:
            return KC_2;
        case t | o | ot | it:
            return KC_F2;
        case t | a:
            return KC_Q;
        case t | a | ot:
            return S(KC_Q);
        case t | a | it:
            return KC_3;
        case t | a | ot | it:
            return KC_F3;
        case o | a:
            return KC_L;
        case o | a | ot:
            return S(KC_L);
        case o | a | it:
            return KC_4;
        case o | a | ot | it:
            return KC_F4;
        case i | n:
            return KC_Y;
        case i | n | ot:
            return S(KC_Y);
        case i | n | it:
            return KC_5;
        case i | n | ot | it:
            return KC_F5;
        case i | s:
            return KC_F;
        case i | s | ot:
            return S(KC_F);
        case i | s | it:
            return KC_6;
        case i | s | ot | it:
            return KC_F6;
        case n | s:
            return KC_P;
        case n | s | ot:
            return S(KC_P);
        case n | s | it:
            return KC_7;
        case n | s | ot | it:
            return KC_F7;
        case n | r:
            return KC_Z;
        case n | r | ot:
            return S(KC_Z);
        case n | r | it:
            return KC_8;
        case n | r | ot | it:
            return KC_F8;
        case s | r:
            return KC_B;
        case s | r | ot:
            return S(KC_B);
        case s | r | it:
            return KC_9;
        case s | r | ot | it:
            return KC_F9;
        case e | t:
            return KC_H;
        case e | t | ot:
            return S(KC_H);
        case e | t | it:
            return KC_0;
        case e | t | ot | it:
            return KC_F10;
        case e | a:
            return KC_D;
        case e | a | ot:
            return S(KC_D);
        case e | a | it:
            return KC_AT;
        case e | a | ot | it:
            return KC_F11;
        case i | r:
            return KC_G;
        case i | r | ot:
            return S(KC_G);
        case i | r | it:
            return KC_HASH;
        case i | r | ot | it:
            return KC_F12;
        case t | r:
            return KC_X;
        case t | r | ot:
            return S(KC_X);
        case t | r | it:
            return KC_CIRC;
        case t | r | ot | it:
            return C(KC_X);
        case i | o:
            return KC_K;
        case i | o | ot:
            return S(KC_K);
        case i | o | it:
            return KC_PLUS;
        case i | o | ot | it:
            return C(KC_C);
        case e | s:
            return KC_V;
        case e | s | ot:
            return S(KC_V);
        case e | s | it:
            return KC_ASTR;
        case e | s | ot | it:
            return C(KC_V);
        case n | a:
            return KC_J;
        case n | a | ot:
            return S(KC_J);
        case n | a | it:
            return KC_EQL;
        case n | a | ot | it:
            return C(KC_Z);
        case e | r:
            return KC_M;
        case e | r | ot:
            return S(KC_M);
        case e | r | it:
            return KC_DLR;
        // case e | r | ot | it:
        //     return KC_NO;
        case i | a:
            return KC_W;
        case i | a | ot:
            return S(KC_W);
        case i | a | it:
            return KC_AMPR;
        // case i | a | ot | it:
        //     return KC_NO;
        case t | s:
            return KC_SLSH;
        case t | s | ot:
            return KC_BSLS;
        case t | s | it:
            return KC_PIPE;
        // case t | s | ot | it:
        //     return KC_NO;
        case n | o:
            return KC_MINS;
        case n | o | ot:
            return KC_UNDS;
        case n | o | it:
            return KC_PERC;
        // case n | o | ot | it:
        //     return KC_NO;
        case i | t:
            return KC_QUES;
        case i | t | ot:
            return KC_EXLM;
        // case i | t | it:
        //     return KC_NO;
        // case i | t | ot | it:
        //     return KC_NO;
        case e | n:
            return KC_COMM;
        case e | n | ot:
            return KC_DOT;
        case e | n | it:
            return KC_TILD;
        // case e | n | ot | it:
        //     return KC_NO;
        case o | r:
        case t | o | a:
            return KC_SCLN;
        case o | r | ot:
        case t | o | a | ot:
            return KC_COLN;
        // case o | r | it:
        // case t | o | a | it:
        //     return KC_NO;
        // case o | r | ot | it:
        // case t | o | a | ot | it:
        //     return KC_NO;
        case s | a:
        case n | s | r:
            return KC_QUOT;
        case s | a | ot:
        case n | s | r | ot:
            return KC_DQT;
        case s | a | it:
        case n | s | r | it:
            return KC_GRV;
        // case s | a | ot | it:
        // case n | s | r | ot | it:
        //     return KC_NO;
        case i | n | s:
            return KC_TAB;
        case i | n | s | ot:
            return KC_DEL;
        case i | n | s | it:
            return KC_INS;
        // case i | n | s | ot | it:
        //     return KC_NO;
        case e | t | o:
            return KC_ENTER;
        case e | t | o | ot:
            return KC_ESC;
        case e | t | o | it:
            return KC_RALT;
        // case e | t | o | ot | it:
        //     return KC_NO;
        case a | r:
            return KC_LGUI;
        case a | r | ot:
            return KC_RIGHT;
        case a | r | it:
            return KC_PGUP;
        case a | r | ot | it:
            return KC_LAYER3;
        case o | s:
            return KC_LALT;
        case o | s | ot:
            return KC_UP;
        case o | s | it:
            return KC_HOME;
        case o | s | ot | it:
            return KC_LAYER2;
        case t | n:
            return KC_LCTL;
        case t | n | ot:
            return KC_DOWN;
        case t | n | it:
            return KC_END;
        case t | n | ot | it:
            return KC_LAYER1;
        case e | i:
            return KC_LSFT;
        case e | i | ot:
            return KC_LEFT;
        case e | i | it:
            return KC_PGDN;
        case e | i | ot | it:
            return KC_LAYER0;
        case r | a | s | o:
            return KC_MOD_GA;
        case r | a | n | t:
            return KC_MOD_GC;
        case r | a | i | e:
            return KC_MOD_GS;
        case s | o | n | t:
            return KC_MOD_AC;
        case s | o | i | e:
            return KC_MOD_AS;
        case n | t | i | e:
            return KC_MOD_CS;
        case r | a | s | o | n | t:
            return KC_MOD_GAC;
        case r | a | s | o | i | e:
            return KC_MOD_GAS;
        case r | a | n | t | i | e:
            return KC_MOD_GCS;
        case s | o | n | t | i | e:
            return KC_MOD_ACS;
        case r | a | s | o | n | t | i | e:
            return KC_MOD_GACS;
    }
    return KC_NO;
}

static void handle_key(keypress* key) {
    uint8_t mods = 0;
    switch (key->keycode) {
        case KC_MOD_GA:
            mods = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT);
            break;
        case KC_MOD_GC:
            mods = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL);
            break;
        case KC_MOD_GS:
            mods = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT);
            break;
        case KC_MOD_AC:
            mods = MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL);
            break;
        case KC_MOD_AS:
            mods = MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT);
            break;
        case KC_MOD_CS:
            mods = MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT);
            break;
        case KC_MOD_GAC:
            mods = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL);
            break;
        case KC_MOD_GAS:
            mods = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT);
            break;
        case KC_MOD_GCS:
            mods = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT);
            break;
        case KC_MOD_ACS:
            mods = MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT);
            break;
        case KC_MOD_GACS:
            mods = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT);
            break;
        case KC_LGUI:
        case KC_LALT:
        case KC_RALT:
        case KC_LCTL:
        case KC_LSFT:
            mods = MOD_BIT(key->keycode);
            break;
        case KC_LAYER0:
            layer_move(0);
            clear_all_state();
            break;
        case KC_LAYER1:
            layer_move(1);
            clear_all_state();
            break;
        case KC_LAYER2:
            layer_move(2);
            clear_all_state();
            break;
        case KC_LAYER3:
            layer_move(3);
            clear_all_state();
            break;
        default:
            if (key->hold_handled) {
                unregister_code16(key->keycode);
            } else if (key->hold) {
                register_code16(key->keycode);
                key->hold_handled = true;
            } else {
                tap_code16(key->keycode);
            }
    }
    if (mods) {
        if (key->hold_handled) {
            del_mods(mods);
            send_keyboard_report();
        } else if (key->hold) {
            add_mods(mods);
            send_keyboard_report();
            key->hold_handled = true;
        } else {
            add_oneshot_mods(mods);
        }
    }
}

bool penti_process_record_user(uint16_t keycode, keyrecord_t* record) {
    uint16_t key   = keycode - TP_TLP;
    state*   state = (key / 10) ? &right_state : &left_state;

    if (record->event.pressed) {
        if (state->key.keycode != KC_NO) {
            handle_key(&state->key);
            clear_state(state);
        }
        state->timer = (record->event.time + PENTI_TAP_TIMEOUT) | 1;
        state->combo |= 1 << (key % 10);
    } else {
        if (!state->key.hold) {
            state->key.keycode = determine_key(state->combo);
        }
        handle_key(&state->key);
        clear_state(state);
    }
    return false;
}

void penti_matrix_scan_user(void) {
    if (left_state.timer && timer_expired(timer_read(), left_state.timer)) {
        left_state.key.keycode = determine_key(left_state.combo);
        left_state.key.hold    = true;
        handle_key(&left_state.key);
        left_state.timer = 0;
    }
    if (right_state.timer && timer_expired(timer_read(), right_state.timer)) {
        right_state.key.keycode = determine_key(right_state.combo);
        right_state.key.hold    = true;
        handle_key(&right_state.key);
        right_state.timer = 0;
    }
}
