// Copyright 2023 Dane Lipscombe (@dlip)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_2x4_2(
        KC_R,    KC_S,    KC_N,    KC_I,        KC_I,    KC_N,    KC_S,    KC_R,
        KC_A,    KC_O,    KC_T,    KC_E,        KC_E,    KC_T,    KC_O,    KC_A,
                          KC_BSPC, KC_SPC,      KC_SPC,  KC_BSPC
    )
};


// enum my_keycodes {
//     MY_LGUI = SAFE_RANGE,
//     MY_LALT,
//     MY_LCTL,
//     MY_LSFT,
// };

// uint16_t COMBO_LEN = 104;
// const uint16_t PROGMEM CM1[] = {KC_E,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM2[] = {KC_T,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM3[] = {KC_O,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM4[] = {KC_A,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM5[] = {KC_E,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM6[] = {KC_T,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM7[] = {KC_O,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM8[] = {KC_A,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM9[] = {KC_I,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM10[] = {KC_N,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM11[] = {KC_S,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM12[] = {KC_R,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM13[] = {KC_I,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM14[] = {KC_N,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM15[] = {KC_S,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM16[] = {KC_R,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM17[] = {KC_E,KC_T,COMBO_END};
// const uint16_t PROGMEM CM18[] = {KC_O,KC_A,COMBO_END};
// const uint16_t PROGMEM CM19[] = {KC_I,KC_N,COMBO_END};
// const uint16_t PROGMEM CM20[] = {KC_S,KC_R,COMBO_END};
// const uint16_t PROGMEM CM21[] = {KC_E,KC_T,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM22[] = {KC_O,KC_A,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM23[] = {KC_I,KC_N,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM24[] = {KC_S,KC_R,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM25[] = {KC_E,KC_T,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM26[] = {KC_O,KC_A,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM27[] = {KC_I,KC_N,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM28[] = {KC_S,KC_R,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM29[] = {KC_I,KC_R,COMBO_END};
// const uint16_t PROGMEM CM30[] = {KC_T,KC_O,COMBO_END};
// const uint16_t PROGMEM CM31[] = {KC_E,KC_A,COMBO_END};
// const uint16_t PROGMEM CM32[] = {KC_N,KC_S,COMBO_END};
// const uint16_t PROGMEM CM33[] = {KC_I,KC_R,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM34[] = {KC_T,KC_O,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM35[] = {KC_E,KC_A,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM36[] = {KC_N,KC_S,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM37[] = {KC_I,KC_R,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM38[] = {KC_T,KC_O,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM39[] = {KC_E,KC_A,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM40[] = {KC_N,KC_S,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM41[] = {KC_E,KC_O,COMBO_END};
// const uint16_t PROGMEM CM42[] = {KC_T,KC_A,COMBO_END};
// const uint16_t PROGMEM CM43[] = {KC_I,KC_S,COMBO_END};
// const uint16_t PROGMEM CM44[] = {KC_N,KC_R,COMBO_END};
// const uint16_t PROGMEM CM45[] = {KC_E,KC_O,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM46[] = {KC_T,KC_A,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM47[] = {KC_I,KC_S,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM48[] = {KC_N,KC_R,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM49[] = {KC_E,KC_O,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM50[] = {KC_T,KC_A,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM51[] = {KC_I,KC_S,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM52[] = {KC_N,KC_R,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM53[] = {KC_S,KC_E,COMBO_END};
// const uint16_t PROGMEM CM54[] = {KC_R,KC_T,COMBO_END};
// const uint16_t PROGMEM CM55[] = {KC_I,KC_O,COMBO_END};
// const uint16_t PROGMEM CM56[] = {KC_N,KC_A,COMBO_END};
// const uint16_t PROGMEM CM57[] = {KC_S,KC_E,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM58[] = {KC_R,KC_T,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM59[] = {KC_I,KC_O,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM60[] = {KC_N,KC_A,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM61[] = {KC_S,KC_E,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM62[] = {KC_R,KC_T,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM63[] = {KC_I,KC_O,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM64[] = {KC_N,KC_A,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM65[] = {KC_N,KC_O,COMBO_END};
// const uint16_t PROGMEM CM66[] = {KC_I,KC_A,COMBO_END};
// const uint16_t PROGMEM CM67[] = {KC_R,KC_E,COMBO_END};
// const uint16_t PROGMEM CM68[] = {KC_S,KC_T,COMBO_END};
// const uint16_t PROGMEM CM69[] = {KC_N,KC_O,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM70[] = {KC_I,KC_A,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM71[] = {KC_R,KC_E,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM72[] = {KC_S,KC_T,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM73[] = {KC_N,KC_O,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM74[] = {KC_I,KC_A,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM75[] = {KC_R,KC_E,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM76[] = {KC_S,KC_T,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM77[] = {KC_S,KC_A,COMBO_END};
// const uint16_t PROGMEM CM78[] = {KC_R,KC_O,COMBO_END};
// const uint16_t PROGMEM CM79[] = {KC_I,KC_T,COMBO_END};
// const uint16_t PROGMEM CM80[] = {KC_N,KC_E,COMBO_END};
// const uint16_t PROGMEM CM81[] = {KC_S,KC_A,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM82[] = {KC_R,KC_O,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM83[] = {KC_I,KC_T,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM84[] = {KC_N,KC_E,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM85[] = {KC_S,KC_A,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM86[] = {KC_N,KC_E,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM87[] = {KC_E,KC_T,KC_O,COMBO_END};
// const uint16_t PROGMEM CM88[] = {KC_I,KC_N,KC_S,COMBO_END};
// const uint16_t PROGMEM CM89[] = {KC_E,KC_T,KC_O,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM90[] = {KC_I,KC_N,KC_S,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM91[] = {KC_E,KC_T,KC_O,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM92[] = {KC_I,KC_N,KC_S,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM93[] = {KC_A,KC_R,COMBO_END};
// const uint16_t PROGMEM CM94[] = {KC_O,KC_S,COMBO_END};
// const uint16_t PROGMEM CM95[] = {KC_T,KC_N,COMBO_END};
// const uint16_t PROGMEM CM96[] = {KC_E,KC_I,COMBO_END};
// const uint16_t PROGMEM CM97[] = {KC_A,KC_R,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM98[] = {KC_O,KC_S,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM99[] = {KC_T,KC_N,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM100[] = {KC_E,KC_I,KC_SPC,COMBO_END};
// const uint16_t PROGMEM CM101[] = {KC_A,KC_R,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM102[] = {KC_O,KC_S,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM103[] = {KC_T,KC_N,KC_BSPC,COMBO_END};
// const uint16_t PROGMEM CM104[] = {KC_E,KC_I,KC_BSPC,COMBO_END};

// combo_t key_combos[] = {
// 	COMBO(CM1,S(KC_E)),
// 	COMBO(CM2,S(KC_T)),
// 	COMBO(CM3,S(KC_O)),
// 	COMBO(CM4,S(KC_A)),
// 	COMBO(CM5,KC_LPRN),
// 	COMBO(CM6,KC_LBRC),
// 	COMBO(CM7,KC_LCBR),
// 	COMBO(CM8,KC_LT),
// 	COMBO(CM9,S(KC_I)),
// 	COMBO(CM10,S(KC_N)),
// 	COMBO(CM11,S(KC_S)),
// 	COMBO(CM12,S(KC_R)),
// 	COMBO(CM13,KC_RPRN),
// 	COMBO(CM14,KC_RBRC),
// 	COMBO(CM15,KC_RCBR),
// 	COMBO(CM16,KC_GT),
// 	COMBO(CM17,KC_H),
// 	COMBO(CM18,KC_L),
// 	COMBO(CM19,KC_Y),
// 	COMBO(CM20,KC_B),
// 	COMBO(CM21,S(KC_H)),
// 	COMBO(CM22,S(KC_L)),
// 	COMBO(CM23,S(KC_Y)),
// 	COMBO(CM24,S(KC_B)),
// 	COMBO(CM25,KC_0),
// 	COMBO(CM26,KC_4),
// 	COMBO(CM27,KC_5),
// 	COMBO(CM28,KC_9),
// 	COMBO(CM29,KC_G),
// 	COMBO(CM30,KC_U),
// 	COMBO(CM31,KC_D),
// 	COMBO(CM32,KC_P),
// 	COMBO(CM33,S(KC_G)),
// 	COMBO(CM34,S(KC_U)),
// 	COMBO(CM35,S(KC_D)),
// 	COMBO(CM36,S(KC_P)),
// 	COMBO(CM37,KC_HASH),
// 	COMBO(CM38,KC_2),
// 	COMBO(CM39,KC_AT),
// 	COMBO(CM40,KC_7),
// 	COMBO(CM41,KC_C),
// 	COMBO(CM42,KC_Q),
// 	COMBO(CM43,KC_F),
// 	COMBO(CM44,KC_Z),
// 	COMBO(CM45,S(KC_C)),
// 	COMBO(CM46,S(KC_Q)),
// 	COMBO(CM47,S(KC_F)),
// 	COMBO(CM48,S(KC_Z)),
// 	COMBO(CM49,KC_1),
// 	COMBO(CM50,KC_3),
// 	COMBO(CM51,KC_6),
// 	COMBO(CM52,KC_8),
// 	COMBO(CM53,KC_V),
// 	COMBO(CM54,KC_X),
// 	COMBO(CM55,KC_K),
// 	COMBO(CM56,KC_J),
// 	COMBO(CM57,S(KC_V)),
// 	COMBO(CM58,S(KC_X)),
// 	COMBO(CM59,S(KC_K)),
// 	COMBO(CM60,S(KC_J)),
// 	COMBO(CM61,KC_ASTR),
// 	COMBO(CM62,KC_CIRC),
// 	COMBO(CM63,KC_PLUS),
// 	COMBO(CM64,KC_EQL),
// 	COMBO(CM65,KC_MINS),
// 	COMBO(CM66,KC_W),
// 	COMBO(CM67,KC_M),
// 	COMBO(CM68,KC_SLSH),
// 	COMBO(CM69,KC_UNDS),
// 	COMBO(CM70,S(KC_W)),
// 	COMBO(CM71,S(KC_M)),
// 	COMBO(CM72,KC_BSLS),
// 	COMBO(CM73,KC_PERC),
// 	COMBO(CM74,KC_AMPR),
// 	COMBO(CM75,KC_DLR),
// 	COMBO(CM76,KC_PIPE),
// 	COMBO(CM77,KC_QUOT),
// 	COMBO(CM78,KC_SCLN),
// 	COMBO(CM79,KC_QUES),
// 	COMBO(CM80,KC_COMMA),
// 	COMBO(CM81,KC_DQT),
// 	COMBO(CM82,KC_COLN),
// 	COMBO(CM83,KC_EXLM),
// 	COMBO(CM84,KC_DOT),
// 	COMBO(CM85,KC_GRAVE),
// 	COMBO(CM86,KC_TILDE),
// 	COMBO(CM87,KC_ENTER),
// 	COMBO(CM88,KC_TAB),
// 	COMBO(CM89,KC_ESC),
// 	COMBO(CM90,KC_DEL),
// 	COMBO(CM91,KC_ALGR),
// 	// COMBO(CM92,KC_LEAD),
// 	COMBO(CM93,MY_LGUI),
// 	COMBO(CM94,MY_LALT),
// 	COMBO(CM95,MY_LCTL),
// 	COMBO(CM96,MY_LSFT),
// 	COMBO(CM97,KC_RIGHT),
// 	COMBO(CM98,KC_UP),
// 	COMBO(CM99,KC_DOWN),
// 	COMBO(CM100,KC_LEFT),
// 	COMBO(CM101,KC_PGUP),
// 	COMBO(CM102,KC_HOME),
// 	COMBO(CM103,KC_END),
// 	COMBO(CM104,KC_PGDN),

// };

// // https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md
// // This will need some messing with but it's close
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     if(record->event.pressed)
//         switch(keycode) {
//         case MY_LGUI: add_oneshot_mods(MOD_BIT(KC_LGUI)); add_mods(MOD_BIT(KC_LGUI)); break;
//         case MY_LALT: add_oneshot_mods(MOD_BIT(KC_LALT)); add_mods(MOD_BIT(KC_LALT)); break;
//         case MY_LCTL: add_oneshot_mods(MOD_BIT(KC_LCTL)); add_mods(MOD_BIT(KC_LCTL)); break;
//         case MY_LSFT: add_oneshot_mods(MOD_BIT(KC_LSFT)); add_mods(MOD_BIT(KC_LSFT)); break;
//         }
//     else
//         switch(keycode) {
//         case MY_LGUI: case MY_LALT: case MY_LCTL: case MY_LSFT: clear_mods(); break;
//         }
//     return true;
// }

// // Garbage to satisfy the default keymap -Hunner
// uint32_t processQwerty(bool lookup) {
//   return 0;
// }
// size_t keymapsCount  = sizeof(keymaps)/sizeof(keymaps[0]);

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
