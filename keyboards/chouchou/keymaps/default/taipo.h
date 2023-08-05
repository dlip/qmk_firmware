// Copyright 2023 Dane Lipscombe (@dlip)
// SPDX-License-Identifier: GPL-2.0-or-later
// Special thanks to Whorf for his help with this

#pragma once
#include "keycodes.h"
#include "quantum_keycodes.h"
#define IDLE_TIMEOUT_MS 150
#define TAIPO_KEYCODE_OFFSET (SAFE_RANGE + 500)

enum taipo_keycode {
    TP_TLP = TAIPO_KEYCODE_OFFSET,
    TP_TLR,
    TP_TLM,
    TP_TLI,
    TP_BLP,
    TP_BLR,
    TP_BLM,
    TP_BLI,
    TP_LIT,
    TP_LOT,
    TP_TRP,
    TP_TRR,
    TP_TRM,
    TP_TRI,
    TP_BRP,
    TP_BRR,
    TP_BRM,
    TP_BRI,
    TP_RIT,
    TP_ROT,
    KC_LAYER0,
    KC_LAYER1,
    KC_LAYER2,
    KC_LAYER3,
};

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

static keypress determine_key(uint16_t val) {
    switch (val) {
        case it:
            return (keypress){.keycode = KC_BSPC};
        case ot:
            return (keypress){.keycode = KC_SPC};
        case r:
            return (keypress){.keycode = KC_R};
        case r | ot:
            return (keypress){.keycode = S(KC_R)};
        case r | it:
            return (keypress){.keycode = KC_GT};
        case r | ot | it:
            return (keypress){.keycode = KC_PRINT_SCREEN};
        case s:
            return (keypress){.keycode = KC_S};
        case s | ot:
            return (keypress){.keycode = S(KC_S)};
        case s | it:
            return (keypress){.keycode = KC_RCBR};
        case s | ot | it:
            return (keypress){.keycode = KC_BRIGHTNESS_UP};
        case n:
            return (keypress){.keycode = KC_N};
        case n | ot:
            return (keypress){.keycode = S(KC_N)};
        case n | it:
            return (keypress){.keycode = KC_RBRC};
        case n | ot | it:
            return (keypress){.keycode = KC_BRIGHTNESS_DOWN};
        case i:
            return (keypress){.keycode = KC_I};
        case i | ot:
            return (keypress){.keycode = S(KC_I)};
        case i | it:
            return (keypress){.keycode = KC_RPRN};
        case i | ot | it:
            return (keypress){.keycode = KC_MEDIA_PLAY_PAUSE};
        case a:
            return (keypress){.keycode = KC_A};
        case a | ot:
            return (keypress){.keycode = S(KC_A)};
        case a | it:
            return (keypress){.keycode = KC_LT};
        case a | ot | it:
            return (keypress){.keycode = KC_MEDIA_NEXT_TRACK};
        case o:
            return (keypress){.keycode = KC_O};
        case o | ot:
            return (keypress){.keycode = S(KC_O)};
        case o | it:
            return (keypress){.keycode = KC_LCBR};
        case o | ot | it:
            return (keypress){.keycode = KC_KB_VOLUME_UP};
        case t:
            return (keypress){.keycode = KC_T};
        case t | ot:
            return (keypress){.keycode = S(KC_T)};
        case t | it:
            return (keypress){.keycode = KC_LBRC};
        case t | ot | it:
            return (keypress){.keycode = KC_KB_VOLUME_DOWN};
        case e:
            return (keypress){.keycode = KC_E};
        case e | ot:
            return (keypress){.keycode = S(KC_E)};
        case e | it:
            return (keypress){.keycode = KC_LPRN};
        case e | ot | it:
            return (keypress){.keycode = KC_MEDIA_PREV_TRACK};
        case e | o:
            return (keypress){.keycode = KC_C};
        case e | o | ot:
            return (keypress){.keycode = S(KC_C)};
        case e | o | it:
            return (keypress){.keycode = KC_1};
        case e | o | ot | it:
            return (keypress){.keycode = KC_F1};
        case t | o:
            return (keypress){.keycode = KC_U};
        case t | o | ot:
            return (keypress){.keycode = S(KC_U)};
        case t | o | it:
            return (keypress){.keycode = KC_2};
        case t | o | ot | it:
            return (keypress){.keycode = KC_F2};
        case t | a:
            return (keypress){.keycode = KC_Q};
        case t | a | ot:
            return (keypress){.keycode = S(KC_Q)};
        case t | a | it:
            return (keypress){.keycode = KC_3};
        case t | a | ot | it:
            return (keypress){.keycode = KC_F3};
        case o | a:
            return (keypress){.keycode = KC_L};
        case o | a | ot:
            return (keypress){.keycode = S(KC_L)};
        case o | a | it:
            return (keypress){.keycode = KC_4};
        case o | a | ot | it:
            return (keypress){.keycode = KC_F4};
        case i | n:
            return (keypress){.keycode = KC_Y};
        case i | n | ot:
            return (keypress){.keycode = S(KC_Y)};
        case i | n | it:
            return (keypress){.keycode = KC_5};
        case i | n | ot | it:
            return (keypress){.keycode = KC_F5};
        case i | s:
            return (keypress){.keycode = KC_F};
        case i | s | ot:
            return (keypress){.keycode = S(KC_F)};
        case i | s | it:
            return (keypress){.keycode = KC_6};
        case i | s | ot | it:
            return (keypress){.keycode = KC_F6};
        case n | s:
            return (keypress){.keycode = KC_P};
        case n | s | ot:
            return (keypress){.keycode = S(KC_P)};
        case n | s | it:
            return (keypress){.keycode = KC_7};
        case n | s | ot | it:
            return (keypress){.keycode = KC_F7};
        case n | r:
            return (keypress){.keycode = KC_Z};
        case n | r | ot:
            return (keypress){.keycode = S(KC_Z)};
        case n | r | it:
            return (keypress){.keycode = KC_8};
        case n | r | ot | it:
            return (keypress){.keycode = KC_F8};
        case s | r:
            return (keypress){.keycode = KC_B};
        case s | r | ot:
            return (keypress){.keycode = S(KC_B)};
        case s | r | it:
            return (keypress){.keycode = KC_9};
        case s | r | ot | it:
            return (keypress){.keycode = KC_F9};
        case e | t:
            return (keypress){.keycode = KC_H};
        case e | t | ot:
            return (keypress){.keycode = S(KC_H)};
        case e | t | it:
            return (keypress){.keycode = KC_0};
        case e | t | ot | it:
            return (keypress){.keycode = KC_F10};
        case e | a:
            return (keypress){.keycode = KC_D};
        case e | a | ot:
            return (keypress){.keycode = S(KC_D)};
        case e | a | it:
            return (keypress){.keycode = KC_AT};
        case e | a | ot | it:
            return (keypress){.keycode = KC_F11};
        case i | r:
            return (keypress){.keycode = KC_G};
        case i | r | ot:
            return (keypress){.keycode = S(KC_G)};
        case i | r | it:
            return (keypress){.keycode = KC_HASH};
        case i | r | ot | it:
            return (keypress){.keycode = KC_F12};
        case t | r:
            return (keypress){.keycode = KC_X};
        case t | r | ot:
            return (keypress){.keycode = S(KC_X)};
        case t | r | it:
            return (keypress){.keycode = KC_CIRC};
        case t | r | ot | it:
            return (keypress){.keycode = C(KC_X)};
        case i | o:
            return (keypress){.keycode = KC_K};
        case i | o | ot:
            return (keypress){.keycode = S(KC_K)};
        case i | o | it:
            return (keypress){.keycode = KC_PLUS};
        case i | o | ot | it:
            return (keypress){.keycode = C(KC_C)};
        case e | s:
            return (keypress){.keycode = KC_V};
        case e | s | ot:
            return (keypress){.keycode = S(KC_V)};
        case e | s | it:
            return (keypress){.keycode = KC_ASTR};
        case e | s | ot | it:
            return (keypress){.keycode = C(KC_V)};
        case n | a:
            return (keypress){.keycode = KC_J};
        case n | a | ot:
            return (keypress){.keycode = S(KC_J)};
        case n | a | it:
            return (keypress){.keycode = KC_EQL};
        case n | a | ot | it:
            return (keypress){.keycode = C(KC_Z)};
        case e | r:
            return (keypress){.keycode = KC_M};
        case e | r | ot:
            return (keypress){.keycode = S(KC_M)};
        case e | r | it:
            return (keypress){.keycode = KC_DLR};
        // case e | r | ot | it:
        //     return (keypress){.keycode = KC_NO};
        case i | a:
            return (keypress){.keycode = KC_W};
        case i | a | ot:
            return (keypress){.keycode = S(KC_W)};
        case i | a | it:
            return (keypress){.keycode = KC_AMPR};
        // case i | a | ot | it:
        //     return (keypress){.keycode = KC_NO};
        case t | s:
            return (keypress){.keycode = KC_SLSH};
        case t | s | ot:
            return (keypress){.keycode = KC_BSLS};
        case t | s | it:
            return (keypress){.keycode = KC_PIPE};
        // case t | s | ot | it:
        //     return (keypress){.keycode = KC_NO};
        case n | o:
            return (keypress){.keycode = KC_MINS};
        case n | o | ot:
            return (keypress){.keycode = KC_UNDS};
        case n | o | it:
            return (keypress){.keycode = KC_PERC};
        // case n | o | ot | it:
        //     return (keypress){.keycode = KC_NO};
        case i | t:
            return (keypress){.keycode = KC_QUES};
        case i | t | ot:
            return (keypress){.keycode = KC_EXLM};
        // case i | t | it:
        //     return (keypress){.keycode = KC_NO};
        // case i | t | ot | it:
        //     return (keypress){.keycode = KC_NO};
        case e | n:
            return (keypress){.keycode = KC_COMM};
        case e | n | ot:
            return (keypress){.keycode = KC_DOT};
        case e | n | it:
            return (keypress){.keycode = KC_TILD};
        // case e | n | ot | it:
        //     return (keypress){.keycode = KC_NO};
        case o | r:
        case t | o | a:
            return (keypress){.keycode = KC_SCLN};
        case o | r | ot:
        case t | o | a | ot:
            return (keypress){.keycode = KC_COLN};
        // case o | r | it:
        // case t | o | a | it:
        //     return (keypress){.keycode = KC_NO};
        // case o | r | ot | it:
        // case t | o | a | ot | it:
        //     return (keypress){.keycode = KC_NO};
        case s | a:
        case n | s | r:
            return (keypress){.keycode = KC_QUOT};
        case s | a | ot:
        case n | s | r | ot:
            return (keypress){.keycode = KC_DQT};
        case s | a | it:
        case n | s | r | it:
            return (keypress){.keycode = KC_GRV};
        // case s | a | ot | it:
        // case n | s | r | ot | it:
        //     return (keypress){.keycode = KC_NO};
        case i | n | s:
            return (keypress){.keycode = KC_TAB};
        case i | n | s | ot:
            return (keypress){.keycode = KC_DEL};
        case i | n | s | it:
            return (keypress){.keycode = KC_INS};
        // case i | n | s | ot | it:
        //     return (keypress){.keycode = KC_NO};
        case e | t | o:
            return (keypress){.keycode = KC_ENTER};
        case e | t | o | ot:
            return (keypress){.keycode = KC_ESC};
        case e | t | o | it:
            return (keypress){.keycode = KC_RALT};
        // case e | t | o | ot | it:
        //     return (keypress){.keycode = KC_NO};
        case a | r:
            return (keypress){.keycode = KC_LGUI};
        case a | r | ot:
            return (keypress){.keycode = KC_RIGHT};
        case a | r | it:
            return (keypress){.keycode = KC_PGUP};
        case a | r | ot | it:
            return (keypress){.keycode = KC_LAYER3};
        case o | s:
            return (keypress){.keycode = KC_LALT};
        case o | s | ot:
            return (keypress){.keycode = KC_UP};
        case o | s | it:
            return (keypress){.keycode = KC_HOME};
        case o | s | ot | it:
            return (keypress){.keycode = KC_LAYER2};
        case t | n:
            return (keypress){.keycode = KC_LCTL};
        case t | n | ot:
            return (keypress){.keycode = KC_DOWN};
        case t | n | it:
            return (keypress){.keycode = KC_END};
        case t | n | ot | it:
            return (keypress){.keycode = KC_LAYER1};
        case e | i:
            return (keypress){.keycode = KC_LSFT};
        case e | i | ot:
            return (keypress){.keycode = KC_LEFT};
        case e | i | it:
            return (keypress){.keycode = KC_PGDN};
        case e | i | ot | it:
            return (keypress){.keycode = KC_LAYER0};
    }
    return (keypress){.keycode = KC_NO};
}

static void handle_key(keypress* key) {
    switch (key->keycode) {
        case KC_LGUI:
        case KC_LALT:
        case KC_RALT:
        case KC_LCTL:
        case KC_LSFT:
            if (key->hold_handled) {
                del_mods(MOD_BIT(key->keycode));
                send_keyboard_report();
            } else if (key->hold) {
                add_mods(MOD_BIT(key->keycode));
                send_keyboard_report();
                key->hold_handled = true;
            } else {
                add_oneshot_mods(MOD_BIT(key->keycode));
            }
            break;
        case KC_LAYER0:
            layer_move(0);
            break;
        case KC_LAYER1:
            layer_move(1);
            break;
        case KC_LAYER2:
            layer_move(2);
            break;
        case KC_LAYER3:
            layer_move(3);
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
}

bool taipo_process_record_user(uint16_t keycode, keyrecord_t* record) {
    uint16_t key   = keycode - TAIPO_KEYCODE_OFFSET;
    state*   state = (key / 10) ? &right_state : &left_state;

    if (record->event.pressed) {
        if (state->key.keycode != KC_NO) {
            handle_key(&state->key);
            state->combo            = 0;
            state->timer            = 0;
            state->key.keycode      = KC_NO;
            state->key.hold         = false;
            state->key.hold_handled = false;
        }
        state->timer = (record->event.time + IDLE_TIMEOUT_MS) | 1;
        state->combo |= 1 << (key % 10);
    } else {
        if (!state->key.hold) {
            state->key = determine_key(state->combo);
        }
        handle_key(&state->key);
        state->combo            = 0;
        state->timer            = 0;
        state->key.keycode      = KC_NO;
        state->key.hold         = false;
        state->key.hold_handled = false;
    }
    return false;
}

void taipo_matrix_scan_user(void) {
    if (left_state.timer && timer_expired(timer_read(), left_state.timer)) {
        left_state.key      = determine_key(left_state.combo);
        left_state.key.hold = true;
        handle_key(&left_state.key);
        left_state.timer = 0;
    }
    if (right_state.timer && timer_expired(timer_read(), right_state.timer)) {
        right_state.key      = determine_key(right_state.combo);
        right_state.key.hold = true;
        handle_key(&right_state.key);
        right_state.timer = 0;
    }
}
