
#include QMK_KEYBOARD_H

enum layers { _NUM, _MEDIA, _RGB, _SPARE };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_NUM] = LAYOUT(
        KC_MUTE,
        KC_P7,   KC_P8,   KC_P9,   KC_PSLS,
        KC_P4,   KC_P5,   KC_P6,   KC_PAST,
        KC_P1,   KC_P2,   KC_P3,   KC_PMNS,
        KC_P0,   KC_PDOT, KC_PENT, MO(_MEDIA)
    ),

    [_MEDIA] = LAYOUT(
        KC_MPLY,
        KC_MPRV, KC_MPLY, KC_MNXT, TG(_RGB),
        KC_HOME, KC_UP,   KC_END,  KC_PGUP,
        KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
        KC_NUM,  KC_CALC, KC_BSPC, _______
    ),

    [_RGB] = LAYOUT(
        RM_TOGG,
        RM_TOGG, RM_NEXT, RM_PREV, TG(_RGB),
        RM_HUEU, RM_SATU, RM_VALU, RM_SPDU,
        RM_HUED, RM_SATD, RM_VALD, RM_SPDD,
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_SPARE] = LAYOUT(
        _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_NUM]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_MEDIA] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_RGB]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU) },
    [_SPARE] = { ENCODER_CCW_CW(_______, _______) },
};
#endif
