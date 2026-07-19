# Apollo Computer A6000

Vial-enabled QMK firmware for the built-in keyboard of the Apollo Computer A6000
(RP2040), used with the Apollo A6000 (Vampire/AC68080 FPGA Amiga).

* Keyboard Maintainer: [ZyberSE](https://github.com/ZyberSE)
* Hardware Supported: Apollo Computer A6000 keyboard (RP2040)
* Matrix: 8 rows × 11 columns
* Row pins: GP7 GP6 GP5 GP4 GP3 GP2 GP1 GP0
* Column pins: GP19 GP17 GP16 GP15 GP14 GP13 GP12 GP11 GP10 GP9 GP8

Make example for this keyboard (after setting up your build environment):

    qmk compile -kb apollo/a6000 -km default

Flashing example for this keyboard:

    qmk flash -kb apollo/a6000 -km default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools)
and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for
more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Custom keycode: Caps Lock (A-Z)

The Amiga doesn't honor the standard Caps Lock keycode, so the `vial` keymap
replaces the physical Caps Lock key with a custom **Caps Lock (A-Z)** keycode:
it toggles a shift-lock that only affects letters (A-Z), leaving numbers and
symbols untouched. It shows up as a regular custom keycode in the Vial app, so
it can be moved to any key or layer without recompiling.

## Bootloader

Enter the bootloader in any of these ways (the RP2040 `RPI-RP2` UF2 drive will
appear — note that macOS sometimes will not auto-mount it in Finder, but the
device is still reachable via `picotool`):

* Hold **Esc** while plugging in the keyboard (bootmagic lite), or
* Press **Right Alt + Esc** while the keyboard is running (combo → `QK_BOOT`).

Then copy the `.uf2` onto `RPI-RP2` (or use `qmk flash` / `picotool load`).
