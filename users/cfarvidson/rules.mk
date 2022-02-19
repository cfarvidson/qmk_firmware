SRC += cfarvidson.c

BOOTMAGIC_ENABLE = no     # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes            # USB Nkey Rollover
AUTO_SHIFT_ENABLE = yes # Auto Shift
COMBO_ENABLE = yes

# Disable lighting since you don't ever use on any keyboard
AUDIO_SUPPORTED = no
RGB_MATRIX_SUPPORTED = no
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow

ELITE_C ?= no
ifeq ($(strip $(ELITE_C)), yes)
	BOOTLOADER = atmel-dfu
endif


PRO_MICRO ?= no
ifeq ($(strip $(PRO_MICRO)), yes)
	BOOTLOADER = atmel-dfu
endif

COL2ROW ?= no
ifeq ($(strip $(COL2ROW)), yes)
	COL2ROW = yes
endif
