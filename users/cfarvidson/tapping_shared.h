#pragma once

#include QMK_KEYBOARD_H

static inline uint16_t userspace_tapping_term_common(uint16_t keycode) {
	switch (keycode) {
		case HC_A:
			return ALT_TAPPING_TERM;
		case HC_S:
			return ALT_TAPPING_TERM;
		case HC_L:
			return ALT_TAPPING_TERM;
		case HC_F:
			return SHIFT_TAPPING_TERM;
		case HC_J:
			return SHIFT_TAPPING_TERM;
		default:
			return TAPPING_TERM;
	}
}


