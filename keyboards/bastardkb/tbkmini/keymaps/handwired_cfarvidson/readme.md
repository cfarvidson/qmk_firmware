# TBK Mini (Handwired)

The main difference from the original firmware are diode direction (this is wired like a dactyl manuform).

Example builds using this firmware:

-   <https://carl-fredrik.arvidson.io/posts/tbk-mini>
-   <https://carl-fredrik.arvidson.io/posts/another-tbk-mini>

Supported Micro-controllers: Pro Micro and elite-C V4

Make example for this keyboard (after setting up your build environment):

## Pro Micro

    make bastardkb/tbkmini:handwired_cfarvidson

or

    util/docker_build.sh bastardkb/tbkmini:handwired_cfarvidson

## Elite-C

    MAKEFLAGS="ELITE_C=yes" make bastardkb/tbkmini:handwired_cfarvidson

or

    MAKEFLAGS="ELITE_C=yes" util/docker_build.sh bastardkb/tbkmini:handwired_cfarvidson
