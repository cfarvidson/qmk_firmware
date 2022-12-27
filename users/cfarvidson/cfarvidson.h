#include QMK_KEYBOARD_H

#if MAC > 0
#include "keymap_swedish_osx_iso.h"
#endif

#if MAC < 1
#include "keymap_swedish.h"
#endif

#define _BASE 0
#define _NAV 1
#define _MOUSE 2
#define _MEDIA 3
#define _NUM 4
#define _SYM 5
#define _FUN 6
#define _Q 7


enum combos {
  ZC_CUT,
  XC_COPY,
  CV_PASTE,
  XV_PASTE_MATCH,
  ZV_SELECT_ALL,
};

#define HC_A LGUI_T(KC_A)
#define HC_S LALT_T(KC_S)
#define HC_D LCTL_T(KC_D)
#define HC_F RSFT_T(KC_F)

#define HC_J RSFT_T(KC_J)
#define HC_K RCTL_T(KC_K)
#define HC_L RALT_T(KC_L)
#define HC_ODIA RGUI_T(SE_ODIA)

#define CC_Q LT(_Q,KC_Q)
