#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

#define _FN_R 3

#define my_a MT(MOD_LCTL, KC_A)
#define my_s MT(MOD_LSFT, KC_S)
#define my_d MT(MOD_LGUI, KC_D)
#define my_f LT(   _FN_R, KC_F)
/* #define my_g LT(    _NUM, KC_G) */
/* #define my_g LT(    _RAISE, KC_G) */
#define my_ent MT(MOD_LALT, KC_E)

/* #define my_i MT(MOD_LALT, KC_I) */
/* #define my_spc LT( _SYMB, KC_SPC) */
#define my_spc MT(MOD_LALT, KC_SPC)
/* #define my_j LT(   _FN_L, KC_J) */
#define my_j LT(  _LOWER, KC_J)
#define my_k MT(MOD_RGUI, KC_K)
#define my_l MT(MOD_RSFT, KC_L)
#define my_scln MT(MOD_RCTL, KC_SCLN)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  my_a,    my_s,    my_d,    my_f,    KC_G,         KC_H,    my_j,    my_k,    my_l,    my_scln, \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
                    _______, LOWER, my_ent,         my_spc, RAISE, _______                 \
),

[_RAISE] = LAYOUT( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
  KC_TAB,    KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,      _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, \
  KC_LCTL, KC_GRV,  KC_LGUI, KC_LALT, _______,      _______, _______, _______, KC_BSLS, KC_QUOT, \
                    _______, _______, _______,      _______, _______, _______                    \
),

[_LOWER] = LAYOUT( \
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
  KC_BSPC,  KC_ESC,  KC_TAB, _______, _______,      _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, \
  KC_CAPS, KC_TILD, _______, _______, _______,      _______, _______, _______, KC_PIPE,  KC_DQT, \
                    _______, _______, _______,      KC_ENT,  _______, KC_DEL                     \
),

[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_F6,   KC_F7,   KC_UP,   KC_F9,  KC_F10, \
  KC_F11,  KC_F12,  _______, RGB_SAI, RGB_SAD,      _______, KC_LEFT, KC_DOWN, KC_RGHT, CALTDEL, \
  RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD,      RGB_VAI, RGB_VAD,   KC_F8, TSKMGR,  _______, \
                    _______, _______, _______,      _______, _______, _______                    \
),

[_FN_R] = LAYOUT(\
_______, _______, _______, _______, _______,       KC_DOWN, KC_RIGHT,  _______, _______, _______, \
_______, _______, _______, _______, _______,       KC_LEFT, KC_HOME,  KC_PGUP,  KC_PGDN, KC_END,  \
_______, _______, _______, _______, _______,       KC_UP, _______, _______, _______, _______,     \
                  _______, _______, _______,       _______, _______, _______                      \
             )
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
