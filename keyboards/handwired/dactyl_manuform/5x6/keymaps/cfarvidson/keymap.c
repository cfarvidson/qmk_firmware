/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

#define _QWERTY 0
#define _MOUSE 1
#define _ARROWS 2
#define _CODING 3
#define _TAB 4
#define _WORDNAV 5
#define _POWERNAV 6
#define _APPS 7
#define _DO_NOTHING 8

#define CODING MO(_CODING)
#define TAB MO(_TAB)
#define POWERNAV MO(_POWERNAV)
#define RIGHT_THUMB LT(_WORDNAV,KC_BSPC)
// Used to disable some keys
#define DO_NOTHING MO(_DO_NOTHING)


enum combos {
  ZC_CUT,
  XC_COPY,
  CV_PASTE,
  XV_PASTE_MATCH,
  ZV_SELECT_ALL,
  COMMDOT_QUES,
  MCOMM_EXLM,
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

combo_t key_combos[COMBO_COUNT] = {
   [ZC_CUT] = COMBO(cut_combo, LGUI(KC_X)),
   [XC_COPY] = COMBO(copy_combo, LGUI(KC_C)),
   [CV_PASTE] = COMBO(paste_combo, LGUI(KC_V)),
   [XV_PASTE_MATCH] = COMBO(paste_match_combo, LGUI(LSA(KC_V))),
   [ZV_SELECT_ALL] = COMBO(select_all_combo, LGUI(KC_A)),
   [MCOMM_EXLM] = COMBO(exclamation_mark_combo, SE_EXLM),
   [COMMDOT_QUES] = COMBO(question_mark_combo, SE_QUES)
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
    TD_6_CAPS,
};
// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_6_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_CAPS),
};

// Layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_ESC    , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         TD(TD_6_CAPS) , KC_7  , KC_8    , KC_9   , KC_0     , SE_PLUS,
     TAB       , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y          , KC_U  , KC_I    , KC_O   , KC_P     , KC_LBRC,
     CODING    , KC_A  , KC_S  , KC_D  , LSFT_T(KC_F), KC_G  ,                   KC_H          , RSFT_T(KC_J)  , KC_K    , KC_L   , KC_SCLN  , KC_QUOT,
     KC_LSFT   , KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N          , KC_M  , KC_COMM , KC_DOT , KC_SLSH  , KC_LSFT,
                        _______, MO(_ARROWS),                                                    KC_NO , KC_NO,
                                      LCTL_T(KC_TAB),LT(_WORDNAV,KC_BSPC),        KC_ENT, LT(_MOUSE,KC_SPC),
                                      LM(_APPS,MOD_LGUI),KC_LALT,                 KC_PAST, MEH(KC_NO),
                                      _______, KC_DEL,                            MEH(KC_ESC),_______
  ),


  [_MOUSE] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,KC_MPLY,
     _______,_______,_______,KC_MS_U,_______,_______,                         _______,_______,KC_WH_D,KC_MPRV,KC_MNXT,KC_VOLU,
     _______,_______,KC_MS_L,KC_MS_D,KC_MS_R,_______,                         _______,_______,KC_WH_U,_______,KC_BRIU,KC_VOLD,
     _______,_______,_______,_______,_______,_______,                         _______,KC_ACL0,KC_ACL1,KC_ACL2,KC_BRID,KC_MUTE,
                      _______,_______,                                                        _______,_______,
                                          KC_BTN1,KC_BTN2,                  _______,_______,
                                          KC_LGUI,LALT_T(KC_BTN3),          _______,_______,
                                          _______,_______,                  _______,_______
                                 
  ),

  [_ARROWS] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                         KC_CAPS     ,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                         _______     ,KC_HOME, KC_UP ,KC_END ,_______,_______,
     _______,_______,_______,_______,_______,_______,                         LSFT(KC_1)  ,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,
     _______,POWERNAV,_______,_______,_______,_______,                         LSFT(KC_EQL),KC_PGUP,_______,KC_PGDN,_______,_______,
                      _______,_______,                                                           _______,_______,
                                          _______,_______,                  _______,_______,
                                          _______,_______,                  _______,_______,
                                          _______,_______,                  _______,_______
                                 
  ),

  [_CODING] = LAYOUT_5x6(
     _______,_______,_______     ,_______    ,_______ ,_______,                   _______     , SE_BSLS_MAC , _______     , _______     , _______     ,SE_ACUT,
     _______,_______,HYPR(KC_P1) ,HYPR(KC_P2),XXXXXXX ,HYPR(KC_P3),               SE_LABK_MAC , SE_AT_MAC   , SE_LPRN_MAC , SE_RPRN_MAC , SE_HASH_MAC ,_______,
     _______,_______,HYPR(KC_P4) ,HYPR(KC_P5),XXXXXXX      ,HYPR(KC_P6),          SE_RABK_MAC , SE_EQL      , SE_LCBR_MAC , SE_RCBR_MAC , SE_DLR_MAC  ,SE_QUOT,
     _______,_______,HYPR(KC_P7) ,HYPR(KC_P8),XXXXXXX      ,HYPR(KC_P9),          SE_TILD_MAC , SE_GRV      , SE_LBRC_MAC , SE_RBRC_MAC , SE_PIPE_MAC ,_______,
                      _______    ,_______    ,                                                                _______     ,_______,
                                          LSFT(KC_TAB),LALT(KC_BSPC),         _______,KC_SPC,
                                          KC_NO,RCS(KC_TAB),                  KC_PAST,_______,
                                          KC_NO,RALT(KC_DEL),                 _______,_______
                                 
  ),

    [_TAB] = LAYOUT_5x6(
     RESET  ,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
     _______,MEH(KC_Q),MEH(KC_W),MEH(KC_E),MEH(KC_R),MEH(KC_T),               KC_NO  , KC_P7  , KC_P8 , KC_P9 ,_______,_______,
     _______,MEH(KC_A),MEH(KC_S),MEH(KC_D),MEH(KC_F),MEH(KC_G),               _______, KC_P4  , KC_P5 , KC_P6 ,_______,_______,
     _______,_______,_______,_______,_______,_______,                         KC_NO  , KC_P1  , KC_P2 , KC_P3 ,_______,_______,
                       _______,_______,                                                           _______,_______,
                                          LGUI(KC_NUBS),_______,                  _______,_______,
                                          _______,_______,                        _______,_______,
                                          _______,_______,                        _______,_______
                                 
  ),

  [_WORDNAV] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                         _______,_______, KC_UP ,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                         _______,LALT(KC_LEFT),KC_DOWN,LALT(KC_RGHT),_______,_______,
     _______,POWERNAV,_______,RCS(KC_TAB),LCTL(KC_TAB) ,_______,              _______,_______,_______,_______,_______,_______,
                      _______,_______,                                                        _______,_______,
                                          _______,_______,                        _______,_______,
                                          _______,_______,                        _______,_______,
                                          _______,_______,                        _______,_______
                                 
  ),

  [_POWERNAV] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                         _______,LGUI(KC_LEFT),_______,LGUI(KC_RGHT),_______,_______,
     _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
                      _______,_______,                                                        _______,_______,
                                          _______,_______,                  _______,_______,
                                          _______,_______,                  _______,_______,
                                          _______,_______,                  _______,_______
                                 
  ),

  [_APPS] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
     _______,_______,_______,LSFT(KC_TAB),LGUI(KC_TAB),_______,               _______,_______,_______,_______,_______,_______,
                     _______,_______,                                                         _______,_______,
                                          _______,_______,                  _______,KC_SPC ,
                                          _______,_______,                  _______,_______,
                                          _______,_______,                  _______,_______
                                 
  ),

  [_DO_NOTHING] = LAYOUT_5x6(
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                         XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                         XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                         XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                         XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                      XXXXXXX,XXXXXXX,                                                        XXXXXXX,XXXXXXX,
                                          XXXXXXX,XXXXXXX,                  XXXXXXX,XXXXXXX,
                                          XXXXXXX,XXXXXXX,                  XXXXXXX,XXXXXXX,
                                          XXXXXXX,XXXXXXX,                  XXXXXXX,XXXXXXX
                                 
  ),

  // [_QWERTY] = LAYOUT_5x6(
  //    _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
  //    _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
  //    _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
  //    _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
  //                     _______,_______,                                                        _______,_______,
  //                                         _______,_______,                  _______,_______,
  //                                         _______,_______,                  _______,_______,
  //                                         _______,_______,                  _______,_______
                                 
  // ),

  
};
