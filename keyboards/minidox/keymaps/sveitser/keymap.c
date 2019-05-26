#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FNR 3
#define _ADJUST 4

// top left
#define lalt LALT_T(KC_E)
#define ladj LT(_ADJUST, KC_R)

// top right
#define ralt LALT_T(KC_I) // emacs needs left alt for meta
#define radj LT(_ADJUST, KC_U)

// middle left
#define lctl LCTL_T(KC_A)
#define lsft LSFT_T(KC_S)
#define lgui LGUI_T(KC_D)
#define fnr LT(_FNR, KC_F)

// middle right
// KC_J does not have second role yet
#define rgui RGUI_T(KC_K)
#define rsft RSFT_T(KC_L)
#define rctl RCTL_T(KC_SCLN)

// thumb left
#define low_spc LT(_LOWER, KC_SPC)
#define low_bspc LT(_LOWER, KC_BSPC)

// thumb right
#define raise_esc LT(_RAISE, KC_ESC)
#define raise_ent LT(_RAISE, KC_ENT)

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \

  KC_Q,    KC_W,    lalt,    ladj,    KC_T,         KC_Y,    radj,    ralt,    KC_O,    KC_P,    \

  lctl,    lsft,    lgui,     fnr,    KC_G,         KC_H,    KC_J,    rgui,    rsft,    rctl,    \

  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \

            KC_TAB,  raise_esc,   low_bspc,       low_spc,  raise_ent,   KC_DEL                  \
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
                    _______, _______, _______,      _______, _______, _______                    \
)
};
