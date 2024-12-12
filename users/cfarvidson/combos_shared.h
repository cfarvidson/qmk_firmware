#pragma once

#include QMK_KEYBOARD_H

/* Shared combo enum */
enum combos { ZC_CUT, XC_COPY, CV_PASTE, XV_PASTE_MATCH, ZV_SELECT_ALL };

/* Shared combo key sequences */
static const uint16_t PROGMEM cut_combo[] = {KC_Z, KC_C, COMBO_END};
static const uint16_t PROGMEM copy_combo[] = {KC_X, KC_C, COMBO_END};
static const uint16_t PROGMEM paste_combo[] = {KC_C, KC_V, COMBO_END};
static const uint16_t PROGMEM paste_match_combo[] = {KC_X, KC_V, COMBO_END};
static const uint16_t PROGMEM select_all_combo[] = {KC_Z, KC_V, COMBO_END};


