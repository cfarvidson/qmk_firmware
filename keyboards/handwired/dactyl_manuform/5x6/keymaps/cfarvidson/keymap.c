/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _MOUSE 1
// #define _LOWER 1
// #define _RAISE 2

// #define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8    , KC_9   , KC_0     , KC_MINS,
     MO(4)  , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I    , KC_O   , KC_P     , KC_LBRC,
     MO(3)  , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K    , KC_L   , KC_SCLN  , KC_QUOT,
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  , KC_COMM , KC_DOT , KC_SLSH  , KC_LSFT,
                      _______, MO(_ARROWS),                                                       KC_NO   , LSFT(KC_NUHS),
                                      LCTL_T(KC_TAB), LT(5,KC_BSPC),          KC_ENT, LT(_MOUSE,KC_SPC),
                                      LM(7,MOD_LGUI), KC_LALT,                KC_PAST, MEH(KC_NO),
                                      _______, KC_DEL,                        MEH(KC_ESC),_______
  ),


  [_MOUSE] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,KC_MPLY,
     _______,_______,_______,KC_MS_U,_______,_______,                         _______,_______,KC_WH_D,KC_MPRV,KC_MNXT,KC_VOLU,
     _______,_______,KC_MS_L,KC_MS_D,KC_MS_R,_______,                         _______,_______,KC_WH_U,_______,KC_BRIU,KC_VOLD,
     _______,_______,_______,_______,_______,_______,                         _______,KC_ACL0,KC_ACL1,KC_ACL2,KC_BRID,KC_MUTE,
                      _______,_______,                                                        _______,_______
                                          KC_BTN1,KC_BTN2,                  _______,_______,
                                          KC_LGUI,LALT_T(KC_BTN3),          _______,_______,
                                          _______,_______,                  _______,_______
                                 
  ),

  [_ARROWS] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                         KC_CAPS     ,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                         _______     ,KC_HOME, KC_UP ,KC_END ,_______,_______,
     _______,_______,_______,_______,_______,_______,                         LSFT(KC_1)  ,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,
     _______, MO(6) ,_______,_______,_______,_______,                         LSFT(KC_EQL),KC_PGUP,_______,KC_PGDN,_______,_______,
                      _______,_______,                                                           _______,_______
                                          KC_TRNS,KC_TRNS,                  _______,_______,
                                          KC_TRNS,KC_TRNS,                  _______,_______,
                                          KC_TRNS,KC_TRNS,                  _______,_______
                                 
  ),

  // [_QWERTY] = LAYOUT_5x6(
  //    _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
  //    _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
  //    _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
  //    _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
  //                     _______,_______,                                                        _______,_______
  //                                         _______,_______,                  _______,_______,
  //                                         _______,_______,                  _______,_______,
  //                                         _______,_______,                  _______,_______
                                 
  // ),

  
};
