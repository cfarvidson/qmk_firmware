#pragma once

// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY

#define COMBO_COUNT 5
// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM

#define EE_HANDS

#define PERMISSIVE_HOLD

/* mouse config */
#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    60
#define MOUSEKEY_MAX_SPEED      7
#define MOUSEKEY_WHEEL_DELAY 0


#if defined(COL2ROW)
#    undef DIODE_DIRECTION
#    define DIODE_DIRECTION COL2ROW
#endif


/* keyboard config windows and mac */
#define MAC 1
#if defined(WIN)
#    undef MAC
#    define MAC 0
#endif
