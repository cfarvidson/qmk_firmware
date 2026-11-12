#include "cfarvidson.h"
#include "keymap_swedish_pro_mac_iso.h"

#ifdef SHIFT_ONCE_ENABLE
#    include "shift_once.h"
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef SHIFT_ONCE_ENABLE
    process_shift_once(keycode, record);
#endif
    switch (keycode) {
        case AP_GLOB:
            /* macOS treats consumer usage "AC Next Keyboard Layout Select" as Globe */
            host_consumer_send(record->event.pressed ? AC_NEXT_KEYBOARD_LAYOUT_SELECT : 0);
            return false;
    }
    return true;
}

#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case SE_ARNG:
        case SE_ADIA:
        case SE_ODIA:
        case SE_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
            return true;
        default:
            return false;
    }
}
#endif
