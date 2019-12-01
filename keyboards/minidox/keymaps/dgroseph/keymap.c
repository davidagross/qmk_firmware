// dgroseph, Minidox keymap
// Based on keymaps by dustypomerleau, oprietop, tw1t611, and combos from germ's gergoplex
// Thanks for checking out my keymap. The rationale behind the layout is described in the README.

#include QMK_KEYBOARD_H
#include "combos.h" // Combos from germ

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
  _FUN,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUM,
  SYM,
  NAV,
  SYS,
  FUN,
};

// Shortcuts, Mod-Taps, and Thumbs skeleton from oprietop

// Shortcuts
#define FUN MO(_FUN)
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

#define FUN_0 LT(_FUN, KC_0)

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
#define NAV_SP LT(_NAV, KC_BSPC)
#define NAV_LK TG(_NAV)
#define NUM_LK TG(_NUM)
#define NUM_SPC LT(_NUM, KC_SPC)
#define SFT_0 LSFT_T(KC_0)
#define SFT_1 LSFT_T(KC_1)
#define SFT_6 LSFT_T(KC_6)
#define SFT_7 LSFT_T(KC_7)
#define SFT_A LSFT_T(KC_A)
#define SFT_O LSFT_T(KC_O)
#define SFT_OS OSM(MOD_LSFT)
#define SFT_QOT LSFT_T(KC_QUOT)
#define SYM_LK TG(_SYM)
#define SYM_OS OSL(_SYM)
#define SYS_LK TG(_SYS)
#define SYS_Z LT(_SYS, KC_Z)
#define SYS_SLH LT(_SYS, KC_SLSH)
#define VOL_DN S(LALT(KC__VOLDOWN))
#define VOL_UP S(LALT(KC__VOLUP))

/* Combos on the base layer (or maybe all layers?)
 * from germ's gergoplex
 * NOTE: If you're using MT,LT or anything you must
 * define it here. Note this if you change your layout!
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      (      |           |      )      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      [      |           |      ]      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      {      |           |      }      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.     ,------,-------------.
 *                  |      |      |      |     |      |      |      |
 *                  `-------------|      |     |      |------+------.
 *                                |      |     |      |
 *                                `------'     `------'
 */
combo_t key_combos[COMBO_COUNT] = {
    // Horizontal 2-Chords

    // QW,WE,ER
    [RT] = COMBO(rt_combo, KC_LPRN),
    [YU] = COMBO(yu_combo, KC_RPRN),
    // UI,IO,OP,
    // AS,SD,DF
    [FG] = COMBO(fg_combo, KC_LBRC),
    [HJ] = COMBO(hj_combo, KC_RBRC),
    // JK,KL,LQ,
    // ZX,XC,CV
    [VB] = COMBO(vb_combo, KC_LCBR),
    [NM] = COMBO(nm_combo, KC_RCBR),
    // MC,CD,DS,

    // Vertical 2-Chords

    // QA,WS,ED,RF,TG,YH,UJ,IK,OL,PQ,
    // AZ,SX,DC,FV,GB,HN,JM,KC,LD,QS,

    // Horizontal 3-Chords

    // QWE,WER,ERT,YUI,UIO,IOP,
    // ASD,SDF,DFG,HJK,JKL,KLQ,
    // ZXC,XCV,CVB,NMC,MCD,CDS,

    // Horizontal 4-Chords

    // QWER,WERT,YUIO,UIOP,
    // ASDF,SDFG,HJKL,JKLQ,
    // ZXCV,XCVB,NMCD,MCDS,

    // Split Chords

    // SDJK

    // [**] = COMBO(**_combo, KC_****),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SFT/A| CTL/S| ALT/D| GUI/F|   G  |           |   H  | GUI/J| ALT/K| CTL/L| SFT/'|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SYS/Z|   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |SYS/SL|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |SFTHOM|NUMEND|      |    |      |SYMPGU|SFTPGD|
 *                  `-------------| NAVBK|    | NAVSP|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_QWERTY] = LAYOUT( \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  SFT_A,   CTRL_S,  ALT_D,   GUI_F,   KC_G,         KC_H,    GUI_J,   ALT_K,   CTRL_L,  SFT_QOT, \
  SYS_Z,   KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  SYS_SLH, \
                    SFTHOM,  NUMEND,  NAV_BK,       NAV_SP,  SYMPGU,  SFTPGD                     \
),

/* Number
 * Focus on one-handed use and numpad on right from tw1t611
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   6  |   7  |   8  |   9  |   0  |           |   _  |   4  |   5  |   6  |   +  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   /  |   .  |   *  |   +  |   -  |           |   -  |   1  |   2  |   3  |   =  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |NUM LK|      |      |    |      | FUN/0|   .  |
 *                  `-------------|      |    | ENTER|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_NUM] = LAYOUT( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,         KC_UNDS, KC_4,    KC_5,    KC_6,    KC_PLUS, \
  KC_SLSH, KC_DOT,  KC_ASTR, KC_PLUS, KC_MINS,      KC_MINS, KC_1,    KC_2,    KC_3,    KC_EQL,  \
                    NUM_LK,  _______, _______,      KC_ENT,  FUN_0,   KC_DOT                     \
),

/* Symbol
 * Focus on one-handed use from tw1t611, symbol layer from oprietop's Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |  (   |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |   `  |   ;  |   :  |  [   |   ]  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |   ~  |   \  |   |  |  {   |   }  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |SFTHOM|  FUN |      |    |      |      |SYM LK|
 *                  `-------------|  DEL |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_SYM] = LAYOUT( \
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
  _______, _______, _______, _______, _______,      KC_GRV,  KC_SCLN, KC_COLN, KC_LBRC, KC_RBRC, \
  _______, _______, _______, _______, _______,      KC_TILD, KC_BSLS, KC_PIPE, KC_LCBR, KC_RCBR, \
                    SFTHOM,  FUN,     KC_DEL,       _______, _______, SYM_LK                     \
),

/* Navigation + mouse keys
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  ESC |      |      |      |NAV LK|           | PAUSE| ACL0 | ACL1 | ACL2 | PSCR |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  TAB | HOME |  UP  |  END | PGUP |           | WH U | BTN1 | MS U | BTN2 |  INS |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | CAPS | LEFT | DOWN | RGHT | PGDN |           | WH D | MS L | MS D | MS R | SCRLK|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  | SHIFT| CTRL |      |    |      | CTRL | SHIFT|
 *                  `------+------|  GUI |    |  GUI |------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_NAV] = LAYOUT( \
  KC_ESC,  _______, _______, _______, NAV_LK,       KC_PAUS, KC_ACL0, KC_ACL1, KC_ACL2, KC_PSCR, \
  KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,      KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_INS,  \
  KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,      KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_SLCK, \
                    KC_LSFT, KC_LCTL, LGUI_T,       RGUI_T,  KC_RCTL, KC_RSFT                    \
),

/* System, media, and layer lock keys from dustypomerleau
 *
 * ,----------------------------------.           ,----------------------------------.
 * | RESET| DEBUG|QWERTY|      |NAV LK|           | VOL- | VOL+ | MUTE | VOL--| VOL++|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SHIFT| CTRL |  ALT |  GUI |BRITE+|           |      | MRWD | MPLY | MFFD | POWER|
 * |------+------+------+------+------|           | -----+------+------+------+------|
 * |      |      |      |      |BRITE-|           |      |NUM LK|      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |NUM LK|      |      |    |      |      |SYM LK|
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_SYS] = LAYOUT( \
  RESET,   DEBUG,   QWERTY,  _______, NAV_LK,        VOL_DN,  VOL_UP,  KC_MUTE, KC_VOLD, KC_VOLU,\
  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_BRIU,       _______, KC_MRWD, KC_MPLY, KC_MFFD, _______,\
  _______, _______, _______, _______, KC_BRID,       _______, NUM_LK,  _______, _______, _______,\
                    NUM_LK,  _______, _______,       _______, _______, SYM_LK                    \
),

/* FUN (Number + Symbol)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |  F6  |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F6  |  F7  |  F8  |  F9  |  F10 |           |      |  F4  |  F5  |  F6  |  F11 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |  F11 |  F12 |           |      |  F1  |  F2  |  F3  |  F12 |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |TSKMGR|      |      |    |      |      |CALTDE|
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_FUN] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, \
  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,        _______, KC_F4,   KC_F5,   KC_F6,   KC_F11, \
  _______, _______, _______, KC_F11,  KC_F12,        _______, KC_F1,   KC_F2,   KC_F3,   KC_F12, \
                    TSKMGR,  _______, _______,       _______, _______, CALTDEL                   \
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
        update_tri_layer(_NUM, _SYM, _FUN);
      } else {
        layer_off(_NUM);
        update_tri_layer(_NUM, _SYM, _FUN);
      }
      return false;
      break;
    case SYM:
      if (record->event.pressed) {
        layer_on(_SYM);
        update_tri_layer(_NUM, _SYM, _FUN);
      } else {
        layer_off(_SYM);
        update_tri_layer(_NUM, _SYM, _FUN);
      }
      return false;
      break;
    case FUN:
      if (record->event.pressed) {
        layer_on(_FUN);
      } else {
        layer_off(_FUN);
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
