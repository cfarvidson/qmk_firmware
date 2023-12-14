#/bin/bash

# Windows
MAKEFLAGS="EXTRAFLAGS=-DWIN" util/docker_build.sh bastardkb/charybdis/4x6/v2/splinky_3:cfarvidson && mv bastardkb_charybdis_4x6_v2_splinky_3_cfarvidson{,_win_$(date +'%Y-%m-%d_%H%M')}.uf2

# Mac
util/docker_build.sh bastardkb/charybdis/4x6/v2/splinky_3:cfarvidson && mv bastardkb_charybdis_4x6_v2_splinky_3_cfarvidson{,_mac_$(date +'%Y-%m-%d_%H%M')}.uf2

