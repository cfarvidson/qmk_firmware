#include "shift_once.h"
#include "keymap_swedish_pro_mac_iso.h"

static uint8_t shift_holds = 0;
static bool    shift_spent = false;

static bool is_tap_hold(uint16_t keycode) {
    return IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode);
}

static bool is_shift_hold(uint16_t keycode, keyrecord_t *record) {
    return IS_QK_MOD_TAP(keycode) && (QK_MOD_TAP_GET_MODS(keycode) & MOD_LSFT) && record->tap.count == 0;
}

static bool is_letter(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case SE_ARNG:
        case SE_ADIA:
        case SE_ODIA:
            return true;
    }
    return false;
}

void process_shift_once(uint16_t keycode, keyrecord_t *record) {
    if (is_shift_hold(keycode, record)) {
        if (record->event.pressed) {
            shift_holds++;
            shift_spent = false;
        } else if (shift_holds > 0) {
            shift_holds--;
        }
        return;
    }
    if (!record->event.pressed || shift_holds == 0) {
        return;
    }
    if (is_tap_hold(keycode) && record->tap.count == 0) {
        return;
    }
    if (!is_letter(get_tap_keycode(keycode))) {
        return;
    }
    if (shift_spent) {
        del_mods(MOD_MASK_SHIFT);
    }
    shift_spent = true;
}
