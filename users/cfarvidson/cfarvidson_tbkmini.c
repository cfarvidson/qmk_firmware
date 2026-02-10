#include QMK_KEYBOARD_H
#include "keymap_swedish_pro_mac_iso.h"
#include "flow_tap.h"
#include "combos_shared.h"
#include "tapping_shared.h"

#ifndef LAYOUT_cfarvidson_wrapper
#define LAYOUT_cfarvidson_wrapper( \
    k00, k01, k02, k03, k04, k05,            k40, k41, k42, k43, k44, k45, \
    k10, k11, k12, k13, k14, k15,            k50, k51, k52, k53, k54, k55, \
    k20, k21, k22, k23, k24, k25,            k60, k61, k62, k63, k64, k65, \
                   k31, k32, k33,                     k71, k72, k73  \
) \
LAYOUT_split_3x6_3( \
    k00, k01, k02, k03, k04, k05,            k40, k41, k42, k43, k44, k45, \
    k10, k11, k12, k13, k14, k15,            k50, k51, k52, k53, k54, k55, \
    k20, k21, k22, k23, k24, k25,            k60, k61, k62, k63, k64, k65, \
                   k31, k32, k33,                     k71, k72, k73  \
)
#endif

enum tbkmini_layers { _BASE, _NAV, _MOUSE, _MEDIA, _NUM, _SYM, _FUN, _Q };

#ifndef COMBO_COUNT
#    define COMBO_COUNT 5
#endif

combo_t key_combos[COMBO_COUNT] = {
[ZC_CUT] = COMBO(cut_combo, LGUI(KC_X)),
[XC_COPY] = COMBO(copy_combo, LGUI(KC_C)),
[CV_PASTE] = COMBO(paste_combo, LGUI(KC_V)),
[XV_PASTE_MATCH] = COMBO(paste_match_combo, LGUI(LSA(KC_V))),
[ZV_SELECT_ALL] = COMBO(select_all_combo, LGUI(KC_A)),
};

#define CC_Q LT(_Q, KC_Q)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_cfarvidson_wrapper(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_ESCAPE,    CC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, SE_ARNG,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_ESCAPE,    HC_A,    HC_S,    HC_D,    HC_F,    KC_G,                         KC_H,    HC_J,    HC_K,    HC_L, HC_ODIA, SE_ADIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, SE_COMM, SE_DOT , SE_MINS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                   LT(_SYM,KC_TAB),LT(_NUM,KC_BSPC),LT(_FUN,KC_DEL),   LT(_MEDIA,KC_ENTER),LT(_NAV, KC_SPACE),LT(_MOUSE, KC_ESCAPE)
                                      //`--------------------------'  `--------------------------'

  ),

  [_NAV] = LAYOUT_cfarvidson_wrapper(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_PGUP, KC_HOME,   KC_UP, KC_END,KC_INSERT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_CAPS,                      XXXXXXX, KC_RSFT,KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_TAB, KC_BSPC,  KC_DEL,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_MOUSE] = LAYOUT_cfarvidson_wrapper(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_WH_D, KC_WH_R, KC_MS_U, KC_WH_L, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                      XXXXXXX, KC_RSFT,KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_BTN4, XXXXXXX, XXXXXXX, KC_BTN5, XXXXXXX,                      XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BTN3, KC_BTN1, KC_BTN2,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_MEDIA] = LAYOUT_cfarvidson_wrapper(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_BRIU, XXXXXXX,KC_VOLU, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   QK_BOOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_BRID, KC_MPRV,KC_VOLD, KC_MNXT, XXXXXXX,                       XXXXXXX, KC_RSFT,KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_MUTE, KC_MPLY, KC_MSTP,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT_cfarvidson_wrapper(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, HYPR(KC_1),                   SE_DIAE,    KC_7,    KC_8,    KC_9, SE_ACUT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL,KC_RSFT, XXXXXXX,                      SE_PLUS,    KC_4,    KC_5,    KC_6, SE_QUOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_1,    KC_2,    KC_3, SE_LABK, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    SE_MINS,    KC_0, SE_DOT
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_cfarvidson_wrapper(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      SE_LABK, SE_AT  , SE_LPRN, SE_RPRN, SE_HASH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_END, KC_LGUI, KC_LALT, KC_LCTL,KC_RSFT, XXXXXXX,                      SE_RABK, SE_EQL , SE_LCBR, SE_RCBR, SE_DLR , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      SE_TILD, SE_GRV , SE_LBRC, SE_RBRC, SE_PIPE, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUN] = LAYOUT_cfarvidson_wrapper(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F7,   KC_F8,   KC_F9, SE_ARNG, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL,KC_RSFT, XXXXXXX,                      XXXXXXX,   KC_F4,   KC_F5,   KC_F6, SE_ADIA, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F12, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,KC_SPACE, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_Q] = LAYOUT_cfarvidson_wrapper(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, HYPR(KC_U), HYPR(KC_I), HYPR(KC_O), HYPR(KC_P), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      HYPR(KC_H), HYPR(KC_J), HYPR(KC_K), HYPR(KC_L), HYPR(KC_SEMICOLON), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      HYPR(KC_N), HYPR(KC_M), HYPR(KC_COMMA), HYPR(KC_DOT), HYPR(KC_MINUS), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LGUI(KC_GRV), XXXXXXX, XXXXXXX,    XXXXXXX, KC_ESCAPE, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

//   [1] = LAYOUT_cfarvidson_wrapper(
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

//   [1] = LAYOUT_cfarvidson_wrapper(
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