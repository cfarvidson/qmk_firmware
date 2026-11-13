#include QMK_KEYBOARD_H
#include "flow_tap.h"
#include "keymap_swedish_pro_mac_iso.h"

bool is_flow_tap_key(uint16_t keycode) {
	if ((get_mods() & (MOD_MASK_CG | MOD_BIT(KC_LEFT_ALT))) != 0) {
		return false;
	}
	switch (get_tap_keycode(keycode)) {
		case KC_SPC:
		case KC_A ... KC_Z:
		case KC_DOT:
		case KC_COMM:
		case SE_ODIA:
		case SE_ARNG:
		case SE_ADIA:
		case SE_MINS:
			return true;
	}
	return false;
}
