/*
 * Copyright (c) 2018 Charlie Waters
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "vortex.h"

#define _FN_R 1
#define _FN_L 2
#define _SYMB 3
#define _NUM 4

#define my_a MT(MOD_LCTL, KC_A)
#define my_s MT(MOD_LSFT, KC_S)
#define my_d MT(MOD_LGUI, KC_D)
#define my_f LT(   _FN_R, KC_F)
#define my_g LT(    _NUM, KC_G)
#define my_e MT(MOD_LALT, KC_E)

#define my_i MT(MOD_LALT, KC_I)
#define my_spc LT( _SYMB, KC_SPC)
#define my_j LT(   _FN_L, KC_J)
#define my_k MT(MOD_RGUI, KC_K)
#define my_l MT(MOD_RSFT, KC_L)
#define my_scln MT(MOD_RCTL, KC_SCLN)

        /* _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,      _______, */
        /* _______,     _______, _______, _______, _______, _______,          _______, _______,  _______, _______, _______, _______, _______, _______, */
        /* _______,         _______, _______, _______, _______, _______,          _______, _______,  _______, _______, _______,  _______,    _______, */
        /* _______,            _______, _______,  _______, _______, _______,           _______, _______, _______, _______, _______,           _______, */
        /* _______,     _______,    _______,                                 _______                        ,    _______,  _______, _______, _______ */

const uint16_t keymaps_default[][MATRIX_ROWS][MATRIX_COLS] = {
#if defined(KEYMAP_60_ANSI)
    [0] = LAYOUT_60_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    my_e,    KC_R,    KC_T,    KC_Y,    KC_U,    my_i,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, my_a,    my_s,    my_d,    my_f,    my_g,    KC_H,    my_j,    my_k,    my_l, my_scln,    KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, my_spc,  KC_RALT, MO(1),   MO(2), KC_RCTL
    ),
    [_FN_R] = LAYOUT_60_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______,     _______, _______, _______, _______, _______,        KC_DOWN, KC_RIGHT,  _______, _______, _______, _______, _______, _______,
        _______,         _______, _______, _______, _______, _______,          KC_LEFT, KC_HOME,  KC_END, _______, _______,  _______,    _______,
        _______,            _______, _______,  _______, _______, _______,            KC_UP, _______, _______, _______, _______,           _______,
        _______,     _______,    _______,                                 _______                        ,    _______,  _______, _______, _______
    ),
    [_FN_L] = LAYOUT_60_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______,     _______, _______, _______, _______, _______,          _______, _______,  _______, _______, _______, _______, _______, _______,
        _______,          KC_BSPC,  KC_ESC,  KC_TAB,  KC_ENT, _______,          _______, _______,  _______, _______, _______,  _______,    _______,
        _______,            _______, _______,  _______, _______, _______,           _______, _______, _______, _______, _______,           _______,
        _______,     _______,    _______,                                 _______                        ,    _______,  _______, _______, _______
    ),
    [_SYMB] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______,     _______,
        _______,     KC_EXLM,   KC_AT, KC_HASH, KC_DLR,  KC_PERC,           KC_MINUS, KC_PLUS,  KC_EQL, KC_UNDS, _______, _______, _______, _______,
        _______,         KC_CIRC, KC_AMPR, KC_TILD, KC_PIPE, KC_BSLS,          S(KC_P), KC_LPRN,  KC_RPRN, KC_LBRC, KC_RBRC, _______,       _______,
        _______,            KC_DQT, KC_QUOT,  KC_UNDS, KC_GRV,  _______,           _______, _______, _______, _______, _______,             _______,
        _______,     _______,    _______,                                 _______                        ,    _______,  _______, _______, _______
    ),
    [_NUM] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,
        _______,     _______, _______, _______, _______, _______,          KC_PLUS,    KC_7,    KC_8,    KC_9,    KC_0, _______, _______, _______,
        _______,         _______, _______, _______, _______, _______,          _______,    KC_4,    KC_5,    KC_6,  KC_EQL, _______,     _______,
        _______,           _______, _______,  _______, _______, _______,           KC_ASTR,    KC_1,    KC_2,    KC_3, _______,           _______,
        _______,     _______,    _______,                                 _______                        ,    _______,  _______, _______, _______
    ),

#elif defined(KEYMAP_VORTEX_CORE)
    [0] = LAYOUT_core(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,  KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT, MO(2),
        KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   KC_SPC,  KC_SPC,  MO(1),   KC_RALT, KC_APP,  KC_RCTL
    ),
    [1] = LAYOUT_core(
        _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_UP,   KC_PGDN, KC_PSCR, KC_SLCK, KC_PAUS,
        KC_CAPS, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT,KC_INS,  _______,
        _______, _______, _______, _______, _______, _______, KC_END,  _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [2] = LAYOUT_core(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
        _______, _______, _______, _______, _______, _______, KC_SLSH, KC_LBRC, KC_RBRC, KC_BSLS, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
#else
    #error "No Keymap!"
#endif
};
const uint16_t keymaps_default_size = sizeof(keymaps_default);
uint16_t keymaps[MAX_LAYERS][MATRIX_ROWS][MATRIX_COLS];

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void led_set_user(uint8_t usb_led) {

}
