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

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Shorcuts, Mod-Taps, and Thumbs skeleton from oprietop

// Shortcuts
#define ADJUST MO(_ADJUST)
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))
#define COPY LCTL(KC_INS)
#define CUT LSFT(KC_DEL)
#define PASTE RSFT(KC_INS)

// Mod-Taps
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md
#define LST(X) LSFT_T(X)
#define RST(X) RSFT_T(X)
#define LCT(X) LCTL_T(X)
#define RCT(X) RCTL_T(X)
#define LGT(X) LGUI_T(X)
#define RGT(X) RGUI_T(X)
#define TAT(X) LALT_T(X)
#define AGT(X) RALT_T(X)

// Thumbs
#define GUIHOM LGUI_T(KC_HOME)
#define LOWEND LT(_LOWER, KC_END)
#define CTRBSP CTL_T(KC_BSPC)
// #define CTRSPC CTL_T(KC_SPC)
#define RAIPGU LT(_RAISE, KC_PGUP)
#define ALTPGP RALT_T(KC_PGDN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Z/SFT|   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  | /-SFT|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |GUIHOM|LOWEND|      |    |      |RAIPGD|ALTPGU|
 *                  `-------------|CTRBSP|    |SPACE |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_QWERTY] = LAYOUT( \
  KC_Q,     KC_W,  KC_E,   KC_R,   KC_T,        KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,        \
  KC_A,     KC_S,  KC_D,   KC_F,   KC_G,        KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN,     \
  LST(KC_Z),KC_X,  KC_C,   KC_V,   KC_B,        KC_N,   KC_M,   KC_COMM, KC_DOT, LST(KC_SLSH),\
                   GUIHOM, LOWEND, CTRBSP,      KC_SPC, RAIPGU, ALTPGD                        \
),

/*
 * TODO: What about a layer on the letter "N" that gives me an apostrophe when tapping "T" for contractions?
 */

// focus on one-handed use from tw1t611, symbol layer from oprietop's Lower
/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |  (   |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Esc | HOME |  UP  | END  | PGUP |           |   `  |   '  |   "  |  [   |   ]  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Ins | LEFT | DOWN | RGHT | PGDN |           |   ~  |   \  |   |  |  {   |   }  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      |      |      |
 *                  `-------------|  DEL |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_RAISE] = LAYOUT( \
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,\
  KC_ESC,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,      KC_GRV,  KC_QUOT, KC_DQT,  KC_LBRC, KC_RBRC,\
  KC_INS,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,      KC_TILD, KC_BSLS, KC_PIPE, KC_LCBR, KC_RCBR,\
                    _______, LOWER,   KC_DEL,       _______, _______, _______                   \
),

// focus on one-handed use and numpad on right from tw1t611
/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Tab | HOME |  UP  | END  | PGUP |           |   _  |   4  |   5  |   6  |   +  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Caps | LEFT | DOWN | RGHT | PGDN |           |   -  |   1  |   2  |   3  |   =  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      | RAISE|   .  |
 *                  `-------------|      |    | ENTR |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_LOWER] = LAYOUT( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,  KC_8,  KC_9, KC_0,   \
  KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,      KC_UNDS, KC_4,  KC_5,  KC_6, KC_PLUS,\
  KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,      KC_MINS, KC_1,  KC_2,  KC_3, KC_EQL, \
                    _______, _______, _______,      KC_ENT,  RAISE, KC_DOT               \
),

/*
 * TODO: oprietop's MOVE layer may be a great idea someday...
 */

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |      |      |      |           |      |      |      |Taskmg|caltde|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Reset|      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, \
  KC_F11,  KC_F12,  _______, _______, _______,      _______, _______, _______, TSKMGR,  CALTDEL,\
  RESET,   _______, _______, _______, _______,      _______, _______, _______, _______, _______,\
                    _______, _______, _______,      _______, _______, _______                   \
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
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
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

/* Layout Name
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.     ,------,-------------.
 *                  |      |      |      |     |      |      |      |
 *                  `-------------|      |     |      |------+------.
 *                                |      |     |      |
 *                                `------'     `------'
 */

/*
[_LAYOUT_NAME] =  LAYOUT( \
  _______,  _______, _______, _______, _______,      _______, _______, _______, _______, _______,\
  _______,  _______, _______, _______, _______,      _______, _______, _______, _______, _______,\
  _______,  _______, _______, _______, _______,      _______, _______, _______, _______, _______,\
                     _______, _______, _______,      _______, _______, _______                   \
)
*/
