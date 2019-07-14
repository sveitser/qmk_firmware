#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _COLEMAK 1
#define _LOWER 2
#define _RAISE 3
#define _FNR 4
#define _ADJUST 5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  FN_R,
  FN_L,
  SYMB,
  NUM,
};

// top left
#define lalt LALT_T(KC_E)
#define ladj LT(_ADJUST, KC_R)

// top right
#define ralt LALT_T(KC_I) // emacs needs left alt for meta
#define radj LT(_ADJUST, KC_U)

// middle left
#define _A LT(_FNR, KC_A)
#define _S LGUI_T(KC_S)
#define _D LCTL_T(KC_D)
#define _F LSFT_T(KC_F)

// middle right
#define _SCLN KC_SCLN
#define _L RGUI_T(KC_L)
#define _K RCTL_T(KC_K)
#define _J RSFT_T(KC_J)

// top left colemak
#define lalt_cm LALT_T(KC_F)
#define ladj_cm LT(_ADJUST, KC_P)

// top right colemak
#define ralt_cm LALT_T(KC_U) // emacs needs left alt for meta
#define radj_cm LT(_ADJUST, KC_L)

// middle left colemak
#define _A_CM LT(_FNR, KC_A)
#define _R_CM LGUI_T(KC_R)
#define _S_CM LCTL_T(KC_S)
#define _T_CM LSFT_T(KC_T)

// middle right colemak
#define _O_CM KC_O
#define _I_CM RGUI_T(KC_I)
#define _E_CM RCTL_T(KC_E)
#define _N_CM RSFT_T(KC_N)

// thumb left
#define raise_spc LT(_RAISE, KC_SPC)
#define low_tab LT(_LOWER, KC_TAB)

// thumb right
#define raise_esc LT(_RAISE, KC_ESC)
#define raise_ent LT(_RAISE, KC_ENT)

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \

  KC_Q,    KC_W,    lalt,    ladj,    KC_T,         KC_Y,    radj,    ralt,    KC_O,    KC_P,    \
    _A,      _S,      _D,      _F,    KC_G,         KC_H,      _J,      _K,      _L,    _SCLN,   \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
            KC_BSPC,  raise_esc,   low_tab,     raise_spc,  raise_ent,   KC_DEL                  \
),

[_COLEMAK] = LAYOUT( \

  KC_Q,    KC_W, lalt_cm, ladj_cm,    KC_G,         KC_J, radj_cm, ralt_cm,    KC_Y,    KC_SCLN,    \
    _A_CM,  _R_CM,  _S_CM,  _T_CM,    KC_G,         KC_H,   _N_CM,   _E_CM,   _I_CM,    _O_CM,   \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
            KC_BSPC,  raise_esc,   low_tab,     raise_spc,  raise_ent,   KC_DEL                  \
),

[_RAISE] = LAYOUT( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
  KC_BSPC,  KC_ESC,  KC_TAB, _______, _______,      _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, \
  _______, _______, _______, _______, _______,      _______, _______, _______, KC_BSLS, KC_QUOT, \
                    _______, _______, _______,      _______, _______, _______                    \
),

[_LOWER] = LAYOUT( \
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
  _______,  _______, _______, _______, _______,     _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, \
  KC_CAPS, KC_TILD, _______, _______, _______,      _______, _______, _______, KC_PIPE,  KC_DQT, \
                    _______, _______, _______,      KC_ENT,  _______, KC_DEL                     \
),

[_FNR] = LAYOUT(\
_______, _______, _______, _______, _______,       KC_DOWN, KC_RIGHT,  _______, _______, _______, \
_______, _______, _______, _______, _______,       KC_LEFT, KC_HOME,  KC_PGUP,  KC_PGDN, KC_END,  \
_______, _______, _______, _______, _______,       KC_UP, _______, _______, _______, _______,     \
                  _______, _______, _______,       _______, _______, _______                      \
),

[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_F6,   KC_F7,   KC_UP,   KC_F9,  KC_F10, \
  KC_F11,  KC_F12,  _______, RGB_SAI, RGB_SAD,      _______, KC_LEFT, KC_DOWN, KC_RGHT, CALTDEL, \
  RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD,      RGB_VAI, RGB_VAD,   KC_F8, TSKMGR,  _______, \
                    QWERTY, COLEMAK,  _______,      _______, _______, _______                    \
)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_COLEMAK);
          }
          return false;
          break;
  }
    return true;
};
