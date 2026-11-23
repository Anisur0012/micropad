// Copyright 2026 Sk Izaz Ahmed (@SkIzazAhmed)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_180; // flip with OLED_ROTATION_0 if your module reads upside down
}

static const char *layer_name(uint8_t layer) {
    switch (layer) {
        case 0: return "NUMPAD";
        case 1: return "MEDIA ";
        case 2: return "RGB   ";
        default: return "OTHER ";
    }
}

bool oled_task_kb(void) {
    if (!oled_task_user()) return false;

    oled_write_P(PSTR("Layer: "), false);
    oled_write_ln(layer_name(get_highest_layer(layer_state | default_layer_state)), false);

    led_t led = host_keyboard_led_state();
    oled_write_P(led.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led.caps_lock ? PSTR("CAPS ") : PSTR("     "), false);
    oled_write_ln_P(PSTR(""), false);

#    ifdef RGB_MATRIX_ENABLE
    char buf[22];
    if (rgb_matrix_is_enabled()) {
        snprintf(buf, sizeof(buf), "RGB %2u  bri %3u%%", rgb_matrix_get_mode(),
                 (unsigned)(rgb_matrix_get_val() * 100 / RGB_MATRIX_MAXIMUM_BRIGHTNESS));
    } else {
        snprintf(buf, sizeof(buf), "RGB off");
    }
    oled_write_ln(buf, false);
#    endif
    return false;
}
#endif
