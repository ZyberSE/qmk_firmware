# Apollo Computer A6000

An RP2040-based Amiga-layout keyboard sold by Apollo Computer for the Apollo A6000
(Vampire/AC68080 FPGA Amiga), to which it connects via a ribbon cable.

The controller/firmware is by Frooastside: the stock firmware's USB manufacturer
string is `Frooastside` and the vendor ID is `0x4642` (Frooastside's). This port
keeps the vendor ID but reports `Apollo Computer` as the manufacturer, since Apollo
Computer is the product's vendor.

The keyboard runs QMK and presents as a **standard USB HID keyboard** — it sends
ordinary HID keycodes, not Amiga raw-key codes. The stock firmware contains no
Amiga-specific keyboard protocol: there is no bit-banged or PIO serial output and
nothing that encodes the Amiga keyboard protocol. How the Apollo side consumes the
input over the ribbon cable was not investigated and is outside the scope of this
firmware.

This QMK port was **reconstructed by reverse-engineering the stock firmware**. The
following were read back from a flash dump and are therefore authoritative:

* Matrix dimensions and row/column pin assignments
* Diode direction (`ROW2COL`, determined from the firmware's matrix-scan routine)
* USB VID/PID and HID descriptors (byte-identical to the original)
* The base keymap (byte-identical to the original)

The physical key-layout coordinates were matched to photos of the keyboard.

* Keyboard Maintainer: [ZyberSE](https://github.com/ZyberSE)
* Hardware Supported: Apollo Computer A6000 keyboard (RP2040, Frooastside controller)
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

## Bootloader

Enter the bootloader in any of these ways (the RP2040 `RPI-RP2` UF2 drive will
appear — note that macOS sometimes will not auto-mount it in Finder, but the
device is still reachable via `picotool`):

* Hold **Esc** while plugging in the keyboard (bootmagic lite), or
* Press **Right Alt + Esc** while the keyboard is running (combo → `QK_BOOT`).

Then copy the `.uf2` onto `RPI-RP2` (or use `qmk flash` / `picotool load`).
