// dgroseph, Minidox keymap
// Based on keymaps by dustypomerleau, oprietop, and tw1t611
// Thanks for checking out my keymap. The rationale behind the layout is described in the README.

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layers {
  _QWERTY,
  _NUM,
  _SYM,
  _NAV,
  _SYS,
  _ADJUST,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUM,
  SYM,
  NAV,
  SYS,
  ADJUST,
};

// Shortcuts, Mod-Taps, and Thumbs skeleton from oprietop

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
#define SFTHOM LSFT_T(KC_HOME)
#define NUMEND LT(_NUM, KC_END)
// #define CTRBSP CTL_T(KC_BSPC)
// #define CTRSPC CTL_T(KC_SPC)
#define SYMPGU LT(_SYM, KC_PGUP)
#define SFTPGD RSFT_T(KC_PGDN)

#define ADJ_0 LT(_ADJUST, KC_0)

// Home-row  mod-taps from dustypomerleau
#define ALT_2 LALT_T(KC_2)
#define ALT_3 LALT_T(KC_3)
#define ALT_8 LALT_T(KC_8)
#define ALT_D LALT_T(KC_D)
#define ALT_E LALT_T(KC_E)
#define ALT_K LALT_T(KC_K)
#define ALT_LB LALT_T(KC_LBRC)
#define ALT_S LALT_T(KC_S)
#define CTRL_2 LCTL_T(KC_2)
#define CTRL_4 LCTL_T(KC_4)
#define CTRL_5 LCTL_T(KC_5)
#define CTRL_9 LCTL_T(KC_9)
#define CTRL_EQ LCTL_T(KC_EQL)
#define CTRL_I LCTL_T(KC_I)
#define CTRL_L LCTL_T(KC_L)
#define CTRL_R LCTL_T(KC_R)
#define CTRL_S LCTL_T(KC_S)
#define GUI_0 LGUI_T(KC_0)
#define GUI_1 LGUI_T(KC_1)
#define GUI_4 LGUI_T(KC_4)
#define GUI_7 LGUI_T(KC_7)
#define GUI_RB LGUI_T(KC_RBRC)
#define GUI_F LGUI_T(KC_F)
#define GUI_J LGUI_T(KC_J)
#define GUI_N LGUI_T(KC_N)
#define GUI_TEA LGUI_T(KC_T)
#define MAC_EM S(LALT(KC_MINS))
#define MAC_EN LALT(KC_MINS)
#define NAV_BK LT(_NAV, KC_BSPC)
#define NAV_LK TG(_NAV)
#define NUMLK TG(_NUM)
#define NUM_SPC LT(_NUM, KC_SPC)
#define SFT_0 LSFT_T(KC_0)
#define SFT_1 LSFT_T(KC_1)
#define SFT_6 LSFT_T(KC_6)
#define SFT_7 LSFT_T(KC_7)
#define SFT_A LSFT_T(KC_A)
#define SFT_O LSFT_T(KC_O)
#define SFT_OS OSM(MOD_LSFT)
#define SFT_QOT LSFT_T(KC_QUOT)
#define SYM_OS OSL(_SYM)
#define SYS_Z LT(_SYS, KC_Z)
#define VOL_DN S(LALT(KC__VOLDOWN))
#define VOL_UP S(LALT(KC__VOLUP))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SFT/A| CTL/S| ALT/D| GUI/F|   G  |           |   H  | GUI/J| ALT/K| CTL/L| SFT/'|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SYS/Z|   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |SFTHOM|NUMEND|      |    |      |SYMPGU|SFTPGD|
 *                  `-------------| BSPC |    | SPACE|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_QWERTY] = LAYOUT( \
  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,        KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,   \
  SFT_A,   CTRL_S,  ALT_D,   GUI_F,  KC_G,        KC_H,   GUI_J,  ALT_K,   CTRL_L, SFT_QOT,\
  SYS_Z,   KC_X,    KC_C,    KC_V,   KC_B,        KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,\
                    SFTHOM,  NUMEND, KC_BSPC,     KC_SPC, SYMPGU, SFTPGD                   \
),

/* Symbol
 * Focus on one-handed use from tw1t611, symbol layer from oprietop's Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |  (   |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Esc | HOME |  UP  | END  | PGUP |           |   `  |   ;  |   :  |  [   |   ]  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Ins | LEFT | DOWN | RGHT | PGDN |           |   ~  |   \  |   |  |  {   |   }  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |SFTHOM|  NUM |      |    |      |      |      |
 *                  `-------------|  DEL |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_SYM] = LAYOUT( \
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,\
  KC_ESC,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,      KC_GRV,  KC_SCLN, KC_COLN, KC_LBRC, KC_RBRC,\
  KC_INS,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,      KC_TILD, KC_BSLS, KC_PIPE, KC_LCBR, KC_RCBR,\
                    SFTHOM,  NUM,     KC_DEL,       _______, _______, _______                   \
),

/* Number
 * Focus on one-handed use and numpad on right from tw1t611
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Tab | HOME |  UP  | END  | PGUP |           |   _  |   4  |   5  |   6  |   +  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Caps | LEFT | DOWN | RGHT | PGDN |           |   -  |   1  |   2  |   3  |   =  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      | ADJ/0|   .  |
 *                  `-------------|      |    | ENTER|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_NUM] = LAYOUT( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,  KC_8,  KC_9, KC_0,   \
  KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,      KC_UNDS, KC_4,  KC_5,  KC_6, KC_PLUS,\
  KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,      KC_MINS, KC_1,  KC_2,  KC_3, KC_EQL, \
                    _______, _______, _______,      KC_ENT,  ADJ_0,  KC_DOT               \
),

/* System, media, and layer lock keys from dustypomerleau
 *
 * ,----------------------------------.           ,----------------------------------.
 * | RESET|DEBUG |QWERTY|      |      |           |      | VOL--| VOL++|BRITE-|BRITE+|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SHIFT| CTRL |  ALT |  GUI |NAV LK|           | POWER| VOL- | VOL+ | MUTE | MPLY |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |NUM LK| MRWD | MFFD |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_SYS] = LAYOUT( \
  RESET,   DEBUG,   QWERTY,  _______, _______,       _______,  KC_VOLD, KC_VOLU, KC_BRID,  KC_BRIU, \
  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,        KC_POWER, VOL_DN,  VOL_UP,  KC__MUTE, KC_MPLY, \
  _______, _______, _______, _______, _______,       _______,  NUMLK,   KC_MRWD, KC_MFFD,  _______, \
                    _______, _______, _______,       _______,  _______, _______                     \
),

/* Adjust (Number + Symbol)
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
    case NUM:
      if (record->event.pressed) {
        layer_on(_NUM);
        update_tri_layer(_NUM, _SYM, _ADJUST);
      } else {
        layer_off(_NUM);
        update_tri_layer(_NUM, _SYM, _ADJUST);
      }
      return false;
      break;
    case SYM:
      if (record->event.pressed) {
        layer_on(_SYM);
        update_tri_layer(_NUM, _SYM, _ADJUST);
      } else {
        layer_off(_SYM);
        update_tri_layer(_NUM, _SYM, _ADJUST);
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
