# Userspace rules for cfarvidson

COMBO_ENABLE = yes

VIA_ENABLE = no
AUTO_SHIFT_ENABLE = no # Auto Shift

SRC += cfarvidson.c

# Needed for the Apple Globe key (AP_GLOB) to be recognised by macOS
KEYBOARD_SHARED_EP = yes

CAPS_WORD_ENABLE = yes
SHIFT_ONCE_ENABLE = yes

ifeq ($(strip $(SHIFT_ONCE_ENABLE)), yes)
    SRC += shift_once.c
    OPT_DEFS += -DSHIFT_ONCE_ENABLE
endif
