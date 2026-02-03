/* Userspace config for cfarvidson */

#pragma once

/* ---------------------- Audio (Planck) ---------------------- */
#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PLANCK_SOUND)
#    define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }
#endif

/* ---------------------- MIDI (Planck) ----------------------- */
#if defined(KEYBOARD_planck_rev7)
#    define MIDI_BASIC
#endif

/* ---------------------- Tapping config ---------------------- */
#undef TAPPING_TERM
#if defined(KEYBOARD_planck_rev7)
#    define TAPPING_TERM 175
#elif defined(KEYBOARD_bastardkb_charybdis_4x6)
#    define TAPPING_TERM 200
#else
#    define TAPPING_TERM 200
#endif
#define TAPPING_TERM_PER_KEY

/* Per-key tap-term helpers used across keymaps */
#ifndef SHIFT_TAPPING_TERM
#    define SHIFT_TAPPING_TERM 145
#endif
#ifndef ALT_TAPPING_TERM
#    define ALT_TAPPING_TERM 300
#endif

/* Enable rapid switch from tap to hold */
#define TAPPING_FORCE_HOLD

/* Quick tap behavior (for Charybdis) */
#if defined(KEYBOARD_bastardkb_charybdis_4x6)
#    define QUICK_TAP_TERM 0
#endif

/* Recommended for heavy chording. */
#define QMK_KEYS_PER_SCAN 4

/* Flow Tap settings shared */
#define FLOW_TAP_TERM 150

/* Auto Shift */
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM

/* Hold behavior */
#define PERMISSIVE_HOLD

/* Mouse keys (only applies if MOUSEKEY_ENABLE) */
#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    60
#define MOUSEKEY_MAX_SPEED      7
#define MOUSEKEY_WHEEL_DELAY    0

/* ---------------------- Charybdis-specific ------------------ */
#if defined(KEYBOARD_bastardkb_charybdis_4x6)
#    define NO_ACTION_ONESHOT
#    define COMBO_COUNT 5

/* OS selection for Charybdis keymap logic */
#    ifndef MAC
#        define MAC 1
#    endif
#    if defined(WIN)
#        undef MAC
#        define MAC 0
#    endif

#    define CHARYBDIS_DRAGSCROLL_REVERSE_Y
#    define CHARYBDIS_MINIMUM_DEFAULT_DPI 800

/* VIA (if enabled) */
#    ifdef VIA_ENABLE
#        define DYNAMIC_KEYMAP_LAYER_COUNT 7
#    endif
#endif

/* ---------------------- Shared key aliases ------------------ */
/* Only define if not already provided by a keymap */
#ifndef HC_A
#    define HC_A LGUI_T(KC_A)
#endif
#ifndef HC_S
#    define HC_S LALT_T(KC_S)
#endif
#ifndef HC_D
#    define HC_D LCTL_T(KC_D)
#endif
#ifndef HC_F
#    define HC_F RSFT_T(KC_F)
#endif
#ifndef HC_J
#    define HC_J RSFT_T(KC_J)
#endif
#ifndef HC_K
#    define HC_K RCTL_T(KC_K)
#endif
#ifndef HC_L
#    define HC_L RALT_T(KC_L)
#endif
#ifndef HC_ODIA
#    define HC_ODIA RGUI_T(SE_ODIA)
#endif
#ifndef CC_Q
#    define CC_Q LT(_Q, KC_Q)
#endif


