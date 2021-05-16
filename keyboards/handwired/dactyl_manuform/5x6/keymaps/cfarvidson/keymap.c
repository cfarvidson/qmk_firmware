/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _MOUSE 1
#define _ARROWS 2
#define _CODING 3
#define _NUMBERS 4
// #define _LOWER 1
// #define _RAISE 2

#define CODING MO(_CODING)
#define NUMBERS MO(_NUMBERS)
// #define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_ESC     , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8    , KC_9   , KC_0     , KC_MINS,
     NUMBERS    , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I    , KC_O   , KC_P     , KC_LBRC,
     CODING     , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K    , KC_L   , KC_SCLN  , KC_QUOT,
     KC_LSFT    , KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  , KC_COMM , KC_DOT , KC_SLSH  , KC_LSFT,
                      _______, MO(_ARROWS),                                                       KC_NO   , LSFT(KC_NUHS),
                                      LCTL_T(KC_TAB), LT(5,KC_BSPC),           KC_ENT, LT(_MOUSE,KC_SPC),
                                      LM(7,MOD_LGUI), KC_LALT,                 KC_PAST, MEH(KC_NO),
                                      _______, KC_DEL,                         MEH(KC_ESC),_______
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
     _______, MO(6) ,_______,_______,_______,_______,                         LSFT(KC_EQL),KC_PGUP,_______,KC_PGDN,_______,_______,
                      _______,_______,                                                           _______,_______,
                                          KC_TRNS,KC_TRNS,                  _______,_______,
                                          KC_TRNS,KC_TRNS,                  _______,_______,
                                          KC_TRNS,KC_TRNS,                  _______,_______
                                 
  ),

  [_CODING] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                         KC_CAPS      ,LSA(KC_7)   ,_______    ,_______    ,_______    ,_______,
     _______,_______,HYPR(KC_P1),HYPR(KC_P2),LGUI(KC_X),HYPR(KC_P3),          KC_GRV       ,LALT(KC_2)  ,LSFT(KC_8) ,LSFT(KC_9) ,LSFT(KC_3) ,_______,
     _______,_______,HYPR(KC_P4),HYPR(KC_P5),LGUI(KC_C),HYPR(KC_P6),          LSFT(KC_GRV) ,LSFT(KC_0)  ,LSA(KC_8)  ,LSA(KC_9)  ,LALT(KC_4) ,KC_NUHS,
     _______,_______,HYPR(KC_P7),HYPR(KC_P8),LGUI(KC_V),HYPR(KC_P9),          LALT(KC_RBRC),LSFT(KC_EQL),LALT(KC_8) ,LALT(KC_9) ,LALT(KC_7) ,_______,
                      _______,_______,                                                        LSFT(KC_1),LSFT(KC_MINS),
                                          LSFT(KC_TAB),KC_BSPC,               _______,KC_SPC,
                                          KC_NO,RCS(KC_TAB),                  KC_PAST,_______,
                                          KC_NO,RALT(KC_DEL),                 _______,_______
                                 
  ),

    [_NUMBERS] = LAYOUT_5x6(
     RESET  ,_________,_________,_________,_________,_________,                         _____________,________,_______,_______,_______,_______,
     _______,MEH(KC_Q),MEH(KC_W),MEH(KC_E),MEH(KC_R),MEH(KC_T),                         LSFT(KC_MINS), KC_P7  , KC_P8 , KC_P9 ,_______,_______,
     _______,MEH(KC_A),MEH(KC_S),MEH(KC_D),MEH(KC_F),MEH(KC_G),                         _____________, KC_P4  , KC_P5 , KC_P6 ,_______,_______,
     _______,_________,_________,_________,_________,_________,                         LSFT(KC_1)   , KC_P1  , KC_P2 , KC_P3 ,_______,_______,
                       _________,_________,                                                           ________,_______,
                                          LGUI(KC_NUBS),_______,                  _______,_______,
                                          _____________,_______,                  _______,_______,
                                          _____________,_______,                  _______,_______
                                 
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
