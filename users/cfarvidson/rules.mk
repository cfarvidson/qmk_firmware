# Userspace rules for cfarvidson

COMBO_ENABLE = yes

VIA_ENABLE = no
AUTO_SHIFT_ENABLE = no # Auto Shift

SRC += cfarvidson.c

# Needed for the Apple Globe key (AP_GLOB) to be recognised by macOS
KEYBOARD_SHARED_EP = yes
