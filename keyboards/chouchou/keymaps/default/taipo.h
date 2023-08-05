// Copyright 2023 Dane Lipscombe (@dlip)
// SPDX-License-Identifier: GPL-2.0-or-later
// Special thanks to Whorf for his help with this

#pragma once
#include "print.h"
#include "keycodes.h"
#include "quantum_keycodes.h"
#define IDLE_TIMEOUT_MS 100 // Idle timeout in milliseconds.
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
    KC_STICKY_LGUI,
    KC_STICKY_LALT,
    KC_STICKY_LCTL,
    KC_STICKY_LSFT,
    KC_STICKY_RALT,
};

typedef struct {
    uint16_t keycode;
    bool     shifted;
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

/*
// a b c d e f g h i j k l m n o p q r s t u v w x y z
//< 9 1 @ ( 6 # 0 ) = + 4 $ ] { 7 3 > } [ 2 * & ^ 5 8
const uint16_t l2[32] = {KC_LT, KC_9, KC_1, KC_AT, KC_LPRN, KC_6, KC_HASH, KC_0, KC_RPRN, KC_EQL, KC_PLUS, KC_4, KC_DLR, KC_RBRC, KC_LCBR, KC_7, KC_3, KC_GT, KC_RCBR, KC_LBRC, KC_2, KC_ASTR, KC_AMPR, KC_CIRC, KC_5, KC_8};
const uint16_t l3[32] = {KC_MEDIA_NEXT_TRACK, KC_F9, KC_F1, KC_F11, KC_MEDIA_PREV_TRACK, KC_F6, KC_F12, KC_F10, KC_MEDIA_PLAY_PAUSE, C(KC_Z), C(KC_C), KC_F4, KC_NO, KC_BRIGHTNESS_DOWN, KC_KB_VOLUME_UP, KC_F7, KC_F3, KC_PRINT_SCREEN, KC_BRIGHTNESS_UP, KC_KB_VOLUME_DOWN, KC_F2, C(KC_V), KC_NO, C(KC_X), KC_F5, KC_F8};

void process_sticky(enum taipo_mod mod, enum taipo_keycode output, enum taipo_keycode outer, enum taipo_keycode inner, uint16_t both, bool hold, bool release) {
    if (mod == TM_NONE) {
        if (hold) {
            add_mods(MOD_BIT(output));
            send_keyboard_report();
        } else if (release) {
            del_mods(MOD_BIT(output));
            send_keyboard_report();
        } else {
            add_oneshot_mods(MOD_BIT(output));
        }
    } else {
        uint16_t v = 0;
        switch (mod) {
            case TM_OUTER:
                v = outer;
                break;
            case TM_INNER:
                v = inner;
                break;
            case TM_BOTH:
                v = both;
                break;
            default:
        }
        if (hold) {
            register_code(v);
        } else if (release) {
            unregister_code(v);
        } else {
            tap_code16(v);
        }
    }
}
static void process(uint16_t val) {
    uint16_t v = 0;
#define V(x)    \
    v = KC_##x; \
    break;
    enum taipo_mod mod = TM_NONE;
    // check in the 9th or 10th key are set
    bool inner   = (val & (1 << 8)) >> 8;
    bool outer   = (val & (1 << 9)) >> 9;
    bool hold    = (val & (1 << 10)) >> 10;
    bool release = (val & (1 << 11)) >> 11;

#define TAP(x) (hold ? register_code(x) : (release ? unregister_code(x) : tap_code16(x)));
    if (inner && outer) {
        mod = TM_BOTH;
    } else if (inner) {
        mod = TM_INNER;
    } else if (outer) {
        mod = TM_OUTER;
    }
    bool both = inner && outer;
    // this is removing the mods
    val = val & ~(1 << 8);
    val = val & ~(1 << 9);
    val = val & ~(1 << 10);
    val = val & ~(1 << 11);

    switch (val) {
        case e:
            V(E)
        case t:
            V(T)
        case o:
            V(O)
        case a:
            V(A)
        case i:
            V(I)
        case n:
            V(N)
        case s:
            V(S)
        case r:
            V(R)

        case e | t:
            V(H)
        case o | a:
            V(L)
        case i | n:
            V(Y)
        case s | r:
            V(B)

        case i | r:
            V(G)
        case t | o:
            V(U)
        case e | a:
            V(D)
        case n | s:
            V(P)

        case e | o:
            V(C)
        case t | a:
            V(Q)
        case i | s:
            V(F)
        case n | r:
            V(Z)

        case e | s:
            V(V)
        case t | r:
            V(X)
        case i | o:
            V(K)
        case n | a:
            V(J)

        case i | a:
            V(W)
        case e | r:
            V(M)

        case n | o:
            V(MINS)
        case t | s:
            V(SLSH)
        case s | a:
            V(QUOT)
        case e | n:
            V(COMM)
        case o | r:
            V(SCLN)
        case i | t:
            V(QUES)
        case e | i:
            V(STICKY_LSFT)
        case t | n:
            V(STICKY_LCTL)
        case o | s:
            V(STICKY_LALT)
        case a | r:
            V(STICKY_LGUI)
        case n | s | r:
            V(QUOT)
        case t | o | a:
            V(SCLN)
        case e | t | o:
            V(ENTER)
        case i | n | s:
            V(TAB)
        default:
            v = 0;
    }
    switch (v) {
        case 0:
            tap_code16(inner ? KC_BSPC : (outer ? KC_SPC : KC_NO));
            break;
        case KC_A ... KC_Z:
            if (both) {
                v = l3[v - KC_A];
            } else if (inner) {
                v = l2[v - KC_A];
                if (hold) {
                    register_code(v);
                } else if (release) {
                    unregister_code(v);
                } else {
                    tap_code16(v);
                }
            } else if (outer) {
                if (hold) {
                    add_mods(MOD_BIT(KC_LSFT));
                    register_code(v);
                } else if (release) {
                    del_mods(MOD_BIT(KC_LSFT));
                    unregister_code(v);
                } else {
                    tap_code16(S(v));
                }
            } else {
                if (hold) {
                    register_code(v);
                } else if (release) {
                    unregister_code(v);
                } else {
                    tap_code16(v);
                }
            }
            break;
        case KC_MINS:
            tap_code16(outer ? KC_UNDS : (inner ? KC_PERC : v));
            break;
        case KC_SLSH:
            tap_code16(outer ? KC_BSLS : (inner ? KC_PIPE : v));
            break;
        case KC_QUOT:
            tap_code16(outer ? KC_DQT : (inner ? KC_GRV : v));
            break;
        case KC_COMM:
            tap_code16(outer ? KC_DOT : (inner ? KC_TILD : v));
            break;
        case KC_SCLN:
            tap_code16(outer ? KC_COLN : (inner ? KC_NO : v));
            break;
        case KC_QUES:
            tap_code16(outer ? KC_EXLM : (inner ? KC_NO : v));
            break;
        case KC_ENTER:
            tap_code16(outer ? KC_ESC : (inner ? KC_STICKY_RALT : v));
            break;
        case KC_TAB:
            tap_code16(outer ? KC_DEL : (inner ? KC_INS : v));
            break;
        case KC_STICKY_LGUI:
            process_sticky(mod, KC_LGUI, KC_RIGHT, KC_PGUP, 3, hold, release);
            break;
        case KC_STICKY_LALT:
            process_sticky(mod, KC_LALT, KC_UP, KC_HOME, 2, hold, release);
            break;
        case KC_STICKY_LCTL:
            process_sticky(mod, KC_LCTL, KC_DOWN, KC_END, 1, hold, release);
            break;
        case KC_STICKY_LSFT:
            process_sticky(mod, KC_LSFT, KC_LEFT, KC_PGDN, 0, hold, release);
            break;
        case KC_STICKY_RALT:
            add_oneshot_mods(MOD_BIT(KC_RALT));
            add_mods(MOD_BIT(KC_RALT));
            break;
        default:
            tap_code(v);
    }
    if (hold) {
        state |= 1 << 11;
        state = state & ~(1 << 10);
    }
}
*/

static void handle_key(keypress key) {
    if (key.shifted) {
        tap_code16(S(key.keycode));
    } else {
        tap_code16(key.keycode);
    }
}

static keypress determine_key(uint16_t val) {
    switch (val) {
        case it:
            return (keypress){.keycode = KC_BSPC};
        case ot:
            return (keypress){.keycode = KC_SPC};
        case r:
            return (keypress){.keycode = KC_R};
        case r | ot:
            return (keypress){.keycode = KC_R, .shifted = true};
        case r | it:
            return (keypress){.keycode = KC_R};
        case r | ot | it:
            return (keypress){.keycode = KC_R};
        case s:
            return (keypress){.keycode = KC_S};
        case s | ot:
            return (keypress){.keycode = KC_S, .shifted = true};
        case s | it:
            return (keypress){.keycode = KC_S};
        case s | ot | it:
            return (keypress){.keycode = KC_S};
        case n:
            return (keypress){.keycode = KC_N};
        case n | ot:
            return (keypress){.keycode = KC_N, .shifted = true};
        case n | it:
            return (keypress){.keycode = KC_N};
        case n | ot | it:
            return (keypress){.keycode = KC_N};
        case i:
            return (keypress){.keycode = KC_I};
        case i | ot:
            return (keypress){.keycode = KC_I, .shifted = true};
        case i | it:
            return (keypress){.keycode = KC_I};
        case i | ot | it:
            return (keypress){.keycode = KC_I};
        case a:
            return (keypress){.keycode = KC_A};
        case a | ot:
            return (keypress){.keycode = KC_A, .shifted = true};
        case a | it:
            return (keypress){.keycode = KC_A};
        case a | ot | it:
            return (keypress){.keycode = KC_A};
        case e:
            return (keypress){.keycode = KC_E};
        case e | ot:
            return (keypress){.keycode = KC_E, .shifted = true};
        case o:
            return (keypress){.keycode = KC_O};
        case o | ot:
            return (keypress){.keycode = KC_O, .shifted = true};
        case o | it:
            return (keypress){.keycode = KC_O};
        case o | ot | it:
            return (keypress){.keycode = KC_O};
        case t:
            return (keypress){.keycode = KC_T};
        case t | ot:
            return (keypress){.keycode = KC_T, .shifted = true};
        case t | it:
            return (keypress){.keycode = KC_T};
        case t | ot | it:
            return (keypress){.keycode = KC_T};
        case e | o:
            return (keypress){.keycode = KC_C};
        case e | o | ot:
            return (keypress){.keycode = KC_C, .shifted = true};
        case e | o | it:
            return (keypress){.keycode = KC_C};
        case e | o | ot | it:
            return (keypress){.keycode = KC_C};
        case t | o:
            return (keypress){.keycode = KC_U};
        case t | o | ot:
            return (keypress){.keycode = KC_U, .shifted = true};
        case t | o | it:
            return (keypress){.keycode = KC_U};
        case t | o | ot | it:
            return (keypress){.keycode = KC_U};
        case t | a:
            return (keypress){.keycode = KC_Q};
        case t | a | ot:
            return (keypress){.keycode = KC_Q, .shifted = true};
        case t | a | it:
            return (keypress){.keycode = KC_Q};
        case t | a | ot | it:
            return (keypress){.keycode = KC_Q};
        case o | a:
            return (keypress){.keycode = KC_L};
        case o | a | ot:
            return (keypress){.keycode = KC_L, .shifted = true};
        case o | a | it:
            return (keypress){.keycode = KC_L};
        case o | a | ot | it:
            return (keypress){.keycode = KC_L};
        case i | n:
            return (keypress){.keycode = KC_Y};
        case i | n | ot:
            return (keypress){.keycode = KC_Y, .shifted = true};
        case i | n | it:
            return (keypress){.keycode = KC_Y};
        case i | n | ot | it:
            return (keypress){.keycode = KC_Y};
        case i | s:
            return (keypress){.keycode = KC_F};
        case i | s | ot:
            return (keypress){.keycode = KC_F, .shifted = true};
        case i | s | it:
            return (keypress){.keycode = KC_F};
        case i | s | ot | it:
            return (keypress){.keycode = KC_F};
        case n | s:
            return (keypress){.keycode = KC_P};
        case n | s | ot:
            return (keypress){.keycode = KC_P, .shifted = true};
        case n | s | it:
            return (keypress){.keycode = KC_P};
        case n | s | ot | it:
            return (keypress){.keycode = KC_P};
        case n | r:
            return (keypress){.keycode = KC_Z};
        case n | r | ot:
            return (keypress){.keycode = KC_Z, .shifted = true};
        case n | r | it:
            return (keypress){.keycode = KC_Z};
        case n | r | ot | it:
            return (keypress){.keycode = KC_Z};
        case s | r:
            return (keypress){.keycode = KC_B};
        case s | r | ot:
            return (keypress){.keycode = KC_B, .shifted = true};
        case s | r | it:
            return (keypress){.keycode = KC_B};
        case s | r | ot | it:
            return (keypress){.keycode = KC_B};
        case e | t:
            return (keypress){.keycode = KC_H};
        case e | t | ot:
            return (keypress){.keycode = KC_H, .shifted = true};
        case e | t | it:
            return (keypress){.keycode = KC_H};
        case e | t | ot | it:
            return (keypress){.keycode = KC_H};
        case e | a:
            return (keypress){.keycode = KC_D};
        case e | a | ot:
            return (keypress){.keycode = KC_D, .shifted = true};
        case e | a | it:
            return (keypress){.keycode = KC_D};
        case e | a | ot | it:
            return (keypress){.keycode = KC_D};
        case i | r:
            return (keypress){.keycode = KC_G};
        case i | r | ot:
            return (keypress){.keycode = KC_G, .shifted = true};
        case i | r | it:
            return (keypress){.keycode = KC_G};
        case i | r | ot | it:
            return (keypress){.keycode = KC_G};
        case t | r:
            return (keypress){.keycode = KC_X};
        case t | r | ot:
            return (keypress){.keycode = KC_X, .shifted = true};
        case t | r | it:
            return (keypress){.keycode = KC_X};
        case t | r | ot | it:
            return (keypress){.keycode = KC_X};
        case i | o:
            return (keypress){.keycode = KC_K};
        case i | o | ot:
            return (keypress){.keycode = KC_K, .shifted = true};
        case i | o | it:
            return (keypress){.keycode = KC_K};
        case i | o | ot | it:
            return (keypress){.keycode = KC_K};
        case e | s:
            return (keypress){.keycode = KC_V};
        case e | s | ot:
            return (keypress){.keycode = KC_V, .shifted = true};
        case e | s | it:
            return (keypress){.keycode = KC_V};
        case e | s | ot | it:
            return (keypress){.keycode = KC_V};
        case n | a:
            return (keypress){.keycode = KC_J};
        case n | a | ot:
            return (keypress){.keycode = KC_J, .shifted = true};
        case n | a | it:
            return (keypress){.keycode = KC_J};
        case n | a | ot | it:
            return (keypress){.keycode = KC_J};
        case e | r:
            return (keypress){.keycode = KC_M};
        case e | r | ot:
            return (keypress){.keycode = KC_M, .shifted = true};
        case e | r | it:
            return (keypress){.keycode = KC_M};
        case e | r | ot | it:
            return (keypress){.keycode = KC_M};
        case i | a:
            return (keypress){.keycode = KC_W};
        case i | a | ot:
            return (keypress){.keycode = KC_W, .shifted = true};
        case i | a | it:
            return (keypress){.keycode = KC_W};
        case i | a | ot | it:
            return (keypress){.keycode = KC_W};
        case t | s:
            return (keypress){.keycode = KC_SLSH};
        case t | s | ot:
            return (keypress){.keycode = KC_SLSH, .shifted = true};
        case t | s | it:
            return (keypress){.keycode = KC_SLSH};
        case t | s | ot | it:
            return (keypress){.keycode = KC_SLSH};
        case n | o:
            return (keypress){.keycode = KC_MINS};
        case n | o | ot:
            return (keypress){.keycode = KC_MINS, .shifted = true};
        case n | o | it:
            return (keypress){.keycode = KC_MINS};
        case n | o | ot | it:
            return (keypress){.keycode = KC_MINS};
        case i | t:
            return (keypress){.keycode = KC_QUES};
        case i | t | ot:
            return (keypress){.keycode = KC_QUES, .shifted = true};
        case i | t | it:
            return (keypress){.keycode = KC_QUES};
        case i | t | ot | it:
            return (keypress){.keycode = KC_QUES};
        case e | n:
            return (keypress){.keycode = KC_COMM};
        case e | n | ot:
            return (keypress){.keycode = KC_COMM, .shifted = true};
        case e | n | it:
            return (keypress){.keycode = KC_COMM};
        case e | n | ot | it:
            return (keypress){.keycode = KC_COMM};
        case o | r:
            return (keypress){.keycode = KC_SCLN};
        case o | r | ot:
            return (keypress){.keycode = KC_SCLN, .shifted = true};
        case o | r | it:
            return (keypress){.keycode = KC_SCLN};
        case o | r | ot | it:
            return (keypress){.keycode = KC_SCLN};
        case t | o | a:
            return (keypress){.keycode = KC_SCLN};
        case t | o | a | ot:
            return (keypress){.keycode = KC_SCLN, .shifted = true};
        case t | o | a | it:
            return (keypress){.keycode = KC_SCLN};
        case t | o | a | ot | it:
            return (keypress){.keycode = KC_SCLN};
        case s | a:
            return (keypress){.keycode = KC_QUOT};
        case s | a | ot:
            return (keypress){.keycode = KC_QUOT, .shifted = true};
        case s | a | it:
            return (keypress){.keycode = KC_QUOT};
        case s | a | ot | it:
            return (keypress){.keycode = KC_QUOT};
        case n | s | r:
            return (keypress){.keycode = KC_QUOT};
        case n | s | r | ot:
            return (keypress){.keycode = KC_QUOT, .shifted = true};
        case n | s | r | it:
            return (keypress){.keycode = KC_QUOT};
        case n | s | r | ot | it:
            return (keypress){.keycode = KC_QUOT};
        case i | n | s:
            return (keypress){.keycode = KC_TAB};
        case i | n | s | ot:
            return (keypress){.keycode = KC_TAB, .shifted = true};
        case i | n | s | it:
            return (keypress){.keycode = KC_TAB};
        case i | n | s | ot | it:
            return (keypress){.keycode = KC_TAB};
        case e | t | o:
            return (keypress){.keycode = KC_ENTER};
        case e | t | o | ot:
            return (keypress){.keycode = KC_ENTER, .shifted = true};
        case e | t | o | it:
            return (keypress){.keycode = KC_ENTER};
        case e | t | o | ot | it:
            return (keypress){.keycode = KC_ENTER};
        case a | r:
            return (keypress){.keycode = KC_STICKY_LGUI};
        case a | r | ot:
            return (keypress){.keycode = KC_STICKY_LGUI, .shifted = true};
        case a | r | it:
            return (keypress){.keycode = KC_STICKY_LGUI};
        case a | r | ot | it:
            return (keypress){.keycode = KC_STICKY_LGUI};
        case o | s:
            return (keypress){.keycode = KC_STICKY_LALT};
        case o | s | ot:
            return (keypress){.keycode = KC_STICKY_LALT, .shifted = true};
        case o | s | it:
            return (keypress){.keycode = KC_STICKY_LALT};
        case o | s | ot | it:
            return (keypress){.keycode = KC_STICKY_LALT};
        case t | n:
            return (keypress){.keycode = KC_STICKY_LCTL};
        case t | n | ot:
            return (keypress){.keycode = KC_STICKY_LCTL, .shifted = true};
        case t | n | it:
            return (keypress){.keycode = KC_STICKY_LCTL};
        case t | n | ot | it:
            return (keypress){.keycode = KC_STICKY_LCTL};
        case e | i:
            return (keypress){.keycode = KC_STICKY_LSFT};
        case e | i | ot:
            return (keypress){.keycode = KC_STICKY_LSFT, .shifted = true};
        case e | i | it:
            return (keypress){.keycode = KC_STICKY_LSFT};
        case e | i | ot | it:
            return (keypress){.keycode = KC_STICKY_LSFT};
    }
    return (keypress){.keycode = KC_NO};
}

bool taipo_process_record_user(uint16_t keycode, keyrecord_t* record) {
    uint16_t key   = keycode - TAIPO_KEYCODE_OFFSET;
    state*   state = (key / 10) ? &right_state : &left_state;
    uprintf("%i key", key);
    uprintf("%i keycode", keycode);
    uprintf("%i offset", TAIPO_KEYCODE_OFFSET);
    bool right = key / 10;
    if (right) {
        print("right");
    } else {
        print("left");
    }

    if (record->event.pressed) {
        state->timer = (record->event.time + IDLE_TIMEOUT_MS) | 1;
        state->combo |= 1 << (key % 10);

    } else {
        state->key = determine_key(state->combo);
        handle_key(state->key);
        state->combo       = 0;
        state->timer       = 0;
        state->key.keycode = KC_NO;
        state->key.shifted = false;
    }
    return false;
}

void taipo_matrix_scan_user(void) {
    // if (left_idle_timer && timer_expired(timer_read(), left_idle_timer)) {
    //     state |= 1 << 10;
    //     process(state);
    //     left_idle_timer = 0;
    // }
    // if (right_idle_timer && timer_expired(timer_read(), right_idle_timer)) {
    //     state |= 1 << 10;
    //     process(state);
    //     right_idle_timer = 0;
    // }
}

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable = true;
    debug_matrix = true;
    // debug_keyboard=true;
    // debug_mouse=true;
}