// Copyright 2023 Dane Lipscombe (@dlip)
// SPDX-License-Identifier: GPL-2.0-or-later
// Special thanks to Whorf for his help with this
#include QMK_KEYBOARD_H
enum my_keycodes {
    KC_STICKY_LGUI = SAFE_RANGE,
    KC_STICKY_LALT,
    KC_STICKY_LCTL,
    KC_STICKY_LSFT,
    KC_STICKY_RALT,
};

enum layers {
  TAIPO,
  GAMING,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [TAIPO] = LAYOUT_split_2x4_2(
        0,            1,            2,            3,            13,         12,           11,           10,
        4,            5,            6,            7,            17,         16,           15,           14,
                                    8,            9,            19,         18
    ),
    [GAMING] = LAYOUT_split_2x4_2(
        KC_TAB,       KC_Q,      KC_W,     KC_E,            KC_U,          KC_UP,         KC_O,      KC_ESC,
        KC_LSFT,      KC_A,      KC_S,     KC_D,            KC_LEFT,     KC_DOWN,     KC_RIGHT,     KC_SCLN,
                              KC_LCTL,   KC_SPC,            KC_ENTER,   TO(TAIPO)
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
const uint16_t l3[32] = {
    KC_MEDIA_NEXT_TRACK, KC_F9, KC_F1, KC_F11, KC_MEDIA_PREV_TRACK, KC_F6, KC_F12, KC_F10, KC_MEDIA_PLAY_PAUSE, C(KC_Z), C(KC_C), KC_F4, KC_NO, KC_BRIGHTNESS_DOWN, KC_KB_VOLUME_UP, KC_F7, KC_F3, KC_PRINT_SCREEN, KC_BRIGHTNESS_UP, KC_KB_VOLUME_DOWN, KC_F2, C(KC_V), KC_NO, C(KC_X), KC_F5, KC_F8
};
    

static void process(uint16_t val) {
    uint16_t v = 0;
    #define V(x) v=KC_##x; break;
    bool inner = (val & (1 << 8)) >> 8;
    bool outer = (val & (1 << 9)) >> 9;
    bool both = inner && outer;
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
        case e|i: V(STICKY_LSFT)
        case t|n: V(STICKY_LCTL)
        case o|s: V(STICKY_LALT)
        case a|r: V(STICKY_LGUI)
        case n|s|r: V(QUOT)
        case t|o|a: V(SCLN)
        case e|t|o: V(ENTER)
        case i|n|s: V(TAB)
        default: v=0;
    }
    switch(v){
        case 0: tap_code16(inner?KC_BSPC:(outer?KC_SPC:KC_NO)); break;
        case KC_A...KC_Z:
            if(both) {
                tap_code16(l3[v-KC_A]);
            } else if(inner) {
                tap_code16(l2[v-KC_A]);
            } else if(outer) {
                tap_code16(S(v)); 
            } else {
                tap_code16(v);
            }
            break;
        case KC_MINS: tap_code16(outer?KC_UNDS:(inner?KC_PERC:v)); break;
        case KC_SLSH: tap_code16(outer?KC_BSLS:(inner?KC_PIPE:v)); break;
        case KC_QUOT: tap_code16(outer?KC_DQT:(inner?KC_GRV:v)); break;
        case KC_COMM: tap_code16(outer?KC_DOT:(inner?KC_TILD:v)); break;
        case KC_SCLN: tap_code16(outer?KC_COLN:(inner?KC_NO:v)); break;
        case KC_QUES: tap_code16(outer?KC_EXLM:(inner?KC_CAPS:v)); break;
        case KC_ENTER: both?layer_move(GAMING):(tap_code16(outer?KC_ESC:(inner?KC_STICKY_RALT:v))); break;
        case KC_TAB: tap_code16(outer?KC_DEL:(inner?KC_INS:v)); break;
        case KC_STICKY_LGUI: outer?tap_code16(KC_RIGHT):(inner?tap_code16(KC_PGUP):(add_oneshot_mods(MOD_BIT(KC_LGUI)), add_mods(MOD_BIT(KC_LGUI)))); break;
        case KC_STICKY_LALT: outer?tap_code16(KC_UP):(inner?tap_code16(KC_HOME):(add_oneshot_mods(MOD_BIT(KC_LALT)), add_mods(MOD_BIT(KC_LALT)))); break;
        case KC_STICKY_LCTL: outer?tap_code16(KC_DOWN):(inner?tap_code16(KC_END):(add_oneshot_mods(MOD_BIT(KC_LCTL)), add_mods(MOD_BIT(KC_LCTL)))); break;
        case KC_STICKY_LSFT: outer?tap_code16(KC_LEFT):(inner?tap_code16(KC_PGDN):(add_oneshot_mods(MOD_BIT(KC_LSFT)), add_mods(MOD_BIT(KC_LSFT)))); break;
        case KC_STICKY_RALT: add_oneshot_mods(MOD_BIT(KC_RALT)); add_mods(MOD_BIT(KC_RALT)); break;
        default: 
            tap_code(v);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (IS_LAYER_OFF(TAIPO)) {
        return true;
    }

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
        clear_mods();
        process(state);
        state = 0;
    }
    return false;
};