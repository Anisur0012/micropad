# Macropad 4x4 v2

4x4 hot-swap macropad with per-key RGB (SK6812MINI-E), EC11 encoder, 0.91" OLED, Qwiic port and TRRS jack.

* Maintainer: [SkIzazAhmed](https://github.com/SkIzazAhmed)
* Hardware: RP2040 Pro Micro (Community Edition pinout)

Build:

    qmk compile -kb handwired/macropad4x4v2 -km default
    qmk compile -kb handwired/macropad4x4v2 -km via

Bootloader: hold BOOT while plugging in, double-tap RESET, or press QK_BOOT (RGB layer, bottom-left).
