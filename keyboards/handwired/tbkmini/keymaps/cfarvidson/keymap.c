/* 
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_swedish_pro_osx_ansi.h"

#define _QWERTY 0
#define _MOUSE 1
#define _CODING 2
#define _TAB 4
#define _TOPROW 5
#define _SHIFTED 6
#define _WORDNAV 7
#define _POWERNAV 8
#define _ARROWS 9
#define _PWRGUI 10


#define CODING MO(_CODING)
#define TAB MO(_TAB)
#define POWERNAV MO(_POWERNAV)
#define PWRGUI LM(_PWRGUI,MOD_LGUI)
#define SCRNSHOT S(G(KC_4))
#define SCRNVID S(G(KC_5))

enum combos {
  ZC_CUT,
  XC_COPY,
  CV_PASTE,
  XV_PASTE_MATCH,
  ZV_SELECT_ALL,
  COMMDOT_QUES,
  MCOMM_EXLM,
  DF_ALT,
};

// Hands down combos https://sites.google.com/alanreiser.com/handsdown/home#h.aplo097wq6hh
const uint16_t PROGMEM cut_combo[] = {KC_Z, KC_C, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM paste_match_combo[] = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM select_all_combo[] = {KC_Z, KC_V, COMBO_END};
// Other combos
const uint16_t PROGMEM question_mark_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM exclamation_mark_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM alt_combo[] = {KC_D, KC_F, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
   [ZC_CUT] = COMBO(cut_combo, LGUI(KC_X)),
   [XC_COPY] = COMBO(copy_combo, LGUI(KC_C)),
   [CV_PASTE] = COMBO(paste_combo, LGUI(KC_V)),
   [XV_PASTE_MATCH] = COMBO(paste_match_combo, LGUI(LSA(KC_V))),
   [ZV_SELECT_ALL] = COMBO(select_all_combo, LGUI(KC_A)),
   [MCOMM_EXLM] = COMBO(exclamation_mark_combo, SE_EXLM),
   [COMMDOT_QUES] = COMBO(question_mark_combo, SE_QUES),
   [DF_ALT] = COMBO(alt_combo, KC_LALT)
};

// Fixes the issue when pressing f och j fast
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_F):
            return true;
        case RSFT_T(KC_J):
            return true;
        default:
            return false;
    }
}


// Tap Dance declarations
enum {
    KC_Y_CAPS,
};
// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [KC_Y_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
LT(_TAB,KC_ESC),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                    TD(KC_Y_CAPS),KC_U,    KC_I,    KC_O,   KC_P,  SE_ARNG,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CODING,    KC_A,    KC_S,    KC_D ,    KC_F,    KC_G,                       KC_H, RSFT_T(KC_J), KC_K,    KC_L,SE_ODIA , SE_ADIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, SE_COMM, SE_DOT ,SE_MINS , KC_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                        LCTL_T(KC_TAB),LT(_WORDNAV,KC_BSPC), PWRGUI,   MO(_TOPROW),LT(_SHIFTED,KC_ENT),LT(_MOUSE,KC_SPC)
                                      //`--------------------------'  `--------------------------'

  ),

  [_CODING] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,SCRNSHOT, SCRNVID,                      SE_LABK, SE_AT  , SE_LPRN, SE_RPRN, SE_HASH, SE_ACUT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,HYPR(KC_P6),                   SE_RABK, SE_EQL , SE_LCBR, SE_RCBR, SE_DLR , SE_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,HYPR(KC_P9),                   SE_TILD, SE_GRV , SE_LBRC, SE_RBRC, SE_PIPE, SE_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 LSFT(KC_TAB),A(KC_BSPC), KC_DELETE,    SE_ASTR, XXXXXXX, KC_SPC
                                      //`--------------------------'  `--------------------------'
  ),

  [_TAB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,MEH(KC_Q),MEH(KC_W),MEH(KC_E),MEH(KC_R),SE_BSLS,                   XXXXXXX,  KC_P7 ,  KC_P8 ,  KC_P9 , XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,MEH(KC_A),MEH(KC_S),MEH(KC_D),MEH(KC_F),MEH(KC_G),                 XXXXXXX,  KC_P4 ,  KC_P5 ,  KC_P6 , XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_P1 ,  KC_P2 ,  KC_P3 , XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              LGUI(KC_NUBS),G(KC_BSPC),A(KC_DELETE),    XXXXXXX, XXXXXXX, KC_P0
                                      //`--------------------------'  `--------------------------'
  ),

  [_TOPROW] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC , KC_1   ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,                       KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  , SE_PLUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, SE_COMM, SE_COLN, XXXXXXX, KC_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_BSPC,KC_LGUI,   XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_SHIFTED] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC , S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),                     S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), SE_PLUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_BSPC,KC_LGUI,   XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_ARROWS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_HOME,  KC_UP , KC_END , XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_PGUP, XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_WORDNAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, KC_UP, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, MO(_ARROWS), _______,                  _______,LALT(KC_LEFT),KC_DOWN,LALT(KC_RGHT), _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, POWERNAV,_______,RCS(KC_TAB),LCTL(KC_TAB), _______,               _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_POWERNAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______,LGUI(KC_LEFT),_______,LGUI(KC_RGHT), _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, KC_SPC
                                      //`--------------------------'  `--------------------------'
  ),

  [_PWRGUI] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______,LSFT(KC_TAB),LGUI(KC_TAB), KC_LALT,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_WH_D, KC_MPRV, KC_MNXT, KC_VOLU,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, KC_BRIU, KC_VOLD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, KC_BRID, KC_MUTE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_BTN1 , KC_BTN2,LALT_T(KC_BTN3),    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

//   [1] = LAYOUT_split_3x6_3(
//   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                           XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
//                                       //`--------------------------'  `--------------------------'
//   ),

//   [1] = LAYOUT_split_3x6_3(
//   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//       _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
//   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                           _______, _______, _______,    _______, _______, _______
//                                       //`--------------------------'  `--------------------------'
//   ),
};
