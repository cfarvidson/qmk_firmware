# cfarvidson

```bash
qmk compile -c -kb bastardkb/charybdis/4x6/v2/splinky_3 -km cfarvidson
```

```bash
./util/docker_build.sh bastardkb/charybdis/4x6/v2/splinky_3:cfarvidson
```


```
./util/docker_build.sh \
    bastardkb/charybdis/4x6/v2/splinky_3:cfarvidson \
    && mv bastardkb_charybdis_4x6_v2_splinky_3_cfarvidson{,_$(date +'%Y-%m-%d_%H%M')}.uf2
```


```
MAKEFLAGS="EXTRAFLAGS=-DWIN" util/docker_build.sh bastardkb/charybdis/4x6/v2/splinky_3:cfarvidson && mv bastardkb_charybdis_4x6_v2_splinky_3_cfarvidson{,_win_$(date +'%Y-%m-%d_%H%M')}.uf2
```

```
util/docker_build.sh bastardkb/charybdis/4x6/v2/splinky_3:cfarvidson && mv bastardkb_charybdis_4x6_v2_splinky_3_cfarvidson{,_mac_$(date +'%Y-%m-%d_%H%M')}.uf2
```
