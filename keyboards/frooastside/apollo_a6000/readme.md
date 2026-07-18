# Apollo A6000

An RP2040-based Amiga-layout keyboard by Frooastside, intended for use with the
Apollo A6000 (Vampire/AC68080 FPGA Amiga). Standard USB HID keyboard; on the FPGA
side the ribbon connection is USB and the Apollo core translates HID to Amiga
raw-key codes.

This QMK port was **reconstructed by reverse-engineering the stock firmware**
(matrix dimensions, row/column pin assignments, USB VID/PID and the base keymap
were read back from a flash dump). The physical key layout coordinates are
approximate and the diode direction is an assumption — verify against hardware
before relying on it.

* Keyboard Maintainer: [ZyberSE](https://github.com/ZyberSE)
* Hardware Supported: Frooastside Apollo A6000 (RP2040)
* Matrix: 8 rows × 11 columns
* Row pins: GP7 GP6 GP5 GP4 GP3 GP2 GP1 GP0
* Column pins: GP19 GP17 GP16 GP15 GP14 GP13 GP12 GP11 GP10 GP9 GP8

Make example for this keyboard (after setting up your build environment):

    qmk compile -kb frooastside/apollo_a6000 -km default

Flashing example for this keyboard:

    qmk flash -kb frooastside/apollo_a6000 -km default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools)
and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for
more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader by holding **Esc** while plugging in the keyboard (the RP2040
`RPI-RP2` UF2 drive will appear), then copy the `.uf2` onto it.
