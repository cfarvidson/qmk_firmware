#include QMK_KEYBOARD_H
#include "flow_tap.h"

bool is_flow_tap_key(uint16_t keycode) {
	if ((get_mods() & (MOD_MASK_CG | MOD_BIT(KC_LEFT_ALT))) != 0) {
		return false;
	}
	switch (get_tap_keycode(keycode)) {
		case KC_SPC:
		case KC_A ... KC_Z:
		case KC_DOT:
		case KC_COMM:
#ifdef SE_ODIA
		case SE_ODIA:
#endif
#ifdef SE_ARNG
		case SE_ARNG:
#endif
#ifdef SE_ADIA
		case SE_ADIA:
#endif
			return true;
	}
	return false;
}


