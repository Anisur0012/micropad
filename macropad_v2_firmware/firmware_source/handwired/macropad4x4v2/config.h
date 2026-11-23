// Copyright 2026 Sk Izaz Ahmed (@SkIzazAhmed)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

/* Key matrix (COL2ROW). Scanned by matrix.c so the encoder button can be row 4. */
#define MATRIX_ROW_PINS_CUSTOM { GP5, GP4, GP3, GP2 }
#define MATRIX_COL_PINS_CUSTOM { GP6, GP7, GP21, GP23 }
#define ENCODER_SWITCH_PIN GP28

/* OLED: 0.91" SSD1306 128x32 on I2C0 (GP0 = SDA, GP1 = SCL) */
#define I2C_DRIVER I2CD0
#define I2C1_SDA_PIN GP0
#define I2C1_SCL_PIN GP1
#define OLED_DISPLAY_128X32
#define OLED_TIMEOUT 60000
#define OLED_BRIGHTNESS 160

/* Double-tap reset to enter the UF2 bootloader */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

/* GP8 (TX) / GP9 (RX) are wired to the TRRS jack and left free for a future link. */
