// Copyright 2026 Sk Izaz Ahmed (@SkIzazAhmed)
// SPDX-License-Identifier: GPL-2.0-or-later
//
// 4x4 COL2ROW key matrix plus the encoder's push switch as an extra row (row 4, col 0).
// QMK still applies debouncing on top of this ("lite" custom matrix).
#include "quantum.h"
#include "matrix.h"

static const pin_t row_pins[] = MATRIX_ROW_PINS_CUSTOM;
static const pin_t col_pins[] = MATRIX_COL_PINS_CUSTOM;
#define KEY_ROWS (sizeof(row_pins) / sizeof(row_pins[0]))
#define KEY_COLS (sizeof(col_pins) / sizeof(col_pins[0]))

void matrix_init_custom(void) {
    for (uint8_t r = 0; r < KEY_ROWS; r++) gpio_set_pin_input_high(row_pins[r]);
    for (uint8_t c = 0; c < KEY_COLS; c++) gpio_set_pin_input_high(col_pins[c]);
    gpio_set_pin_input_high(ENCODER_SWITCH_PIN);
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;

    for (uint8_t r = 0; r < KEY_ROWS; r++) {
        // select row: drive it low
        gpio_set_pin_output(row_pins[r]);
        gpio_write_pin_low(row_pins[r]);
        matrix_output_select_delay();

        matrix_row_t row = 0;
        for (uint8_t c = 0; c < KEY_COLS; c++) {
            if (!gpio_read_pin(col_pins[c])) row |= (MATRIX_ROW_SHIFTER << c);
        }

        // unselect row and let the columns float back high
        gpio_set_pin_input_high(row_pins[r]);
        matrix_output_unselect_delay(r, row != 0);

        if (current_matrix[r] != row) {
            current_matrix[r] = row;
            changed = true;
        }
    }

    // encoder push switch (to GND, internal pull-up)
    matrix_row_t enc = gpio_read_pin(ENCODER_SWITCH_PIN) ? 0 : 1;
    if (current_matrix[KEY_ROWS] != enc) {
        current_matrix[KEY_ROWS] = enc;
        changed = true;
    }
    return changed;
}
