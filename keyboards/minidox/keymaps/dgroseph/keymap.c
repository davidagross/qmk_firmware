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

// Shortcuts and Thumbs skeleton from oprietop

// Shortcuts
#define FUN MO(_FUN)
#define SYS MO(_SYS)
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))
#define COPY LCTL(KC_INS)
#define CUT LSFT(KC_DEL)
#define PASTE RSFT(KC_INS)

// Thumbs
#define SFTHOM LSFT_T(KC_HOME)
#define NUMEND LT(_NUM, KC_END)
#define NAV_BK LT(_NAV, KC_BSPC)
#define NAV_SP LT(_NAV, KC_SPC)
#define SYMPGU LT(_SYM, KC_PGUP)
#define SFTPGD RSFT_T(KC_PGDN)

#define FUN_0 LT(_FUN, KC_0)

// some mod-taps from dustypomerleau
#define NAV_LK TG(_NAV)
#define NUM_LK TG(_NUM)
#define SYM_LK TG(_SYM)
#define SYS_LK TG(_SYS)
#define VOL_DN S(LALT(KC__VOLDOWN))
#define VOL_UP S(LALT(KC__VOLUP))

/* Combos on the base layer (or maybe all layers?)
 * from germ's gergoplex
 * NOTE: If you're using MT,LT or anything you must
 * define it here. Note this if you change your layout!
 *
 * ,----------------------------------.           ,----------------------------------.
 * |     ESC     |      |      (      |           |      )    BTN1    BTN2  BKSPC    |
 * |------+------+--UP--+---{--+--DEL-|           |---:--+--}---+-MSUP-+------+------|
 * |     TAB   LEFT    RGHT    [      |           |      ]    MSLF    MSRT  ENTER    |
 * |------+------+--DN--+------+--SPC-|           |---;--+------+-MSDN-+------+------|
 * |    SHIFT  CTRL    ALT    GUI     |           |     GUI    ALT    CTRL  SHIFT    |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.     ,------,-------------.
 *                  |      |      |      |     |      |      |      |
 *                  `-------------|      |     |      |------+------.
 *                                |      |     |      |
 *                                `------'     `------'
 */
combo_t key_combos[COMBO_COUNT] = {
    // Horizontal 2-Chords

    [QW] = COMBO(qw_combo, KC_ESC),
    // WE,ER,
    [RT] = COMBO(rt_combo, KC_LPRN),
    [YU] = COMBO(yu_combo, KC_RPRN),
    [UI] = COMBO(ui_combo, KC_BTN1),
    [IO] = COMBO(io_combo, KC_BTN2),
    [OP] = COMBO(op_combo, KC_BSPC),
    [AS] = COMBO(as_combo, KC_TAB),
    [SD] = COMBO(sd_combo, KC_LEFT),
    [DF] = COMBO(df_combo, KC_RIGHT),
    [FG] = COMBO(fg_combo, KC_LBRC),
    [HJ] = COMBO(hj_combo, KC_RBRC),
    [JK] = COMBO(jk_combo, KC_MS_L),
    [KL] = COMBO(kl_combo, KC_MS_R),
    [LQ] = COMBO(lq_combo, KC_ENT),
    [ZX] = COMBO(zx_combo, KC_LSFT),
    [XC] = COMBO(xc_combo, KC_LCTL),
    [CV] = COMBO(cv_combo, KC_LALT),
    [VB] = COMBO(vb_combo, KC_LGUI),
    [NM] = COMBO(nm_combo, KC_RGUI),
    [MC] = COMBO(mc_combo, KC_RALT),
    [CD] = COMBO(cd_combo, KC_RCTL),
    [DS] = COMBO(ds_combo, KC_RSFT),

    // Vertical 2-Chords

    // QA,WS,
    [ED] = COMBO(ed_combo, KC_UP),
    [RF] = COMBO(rf_combo, KC_LCBR),
    [TG] = COMBO(tg_combo, KC_DEL),
    [YH] = COMBO(yh_combo, KC_COLN),
    [UJ] = COMBO(uj_combo, KC_RCBR),
    [IK] = COMBO(ik_combo, KC_MS_U),
    // OL,PQ,
    // AZ,SX,
    [DC] = COMBO(dc_combo, KC_DOWN),
    // FV,
    [GB] = COMBO(gb_combo, KC_SPC),
    [HN] = COMBO(hn_combo, KC_SCLN),
    // JM,
    [KC] = COMBO(kc_combo, KC_MS_D),
    // LD,QS,

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

/* QWERTY
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   '  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |SFTHOM|NUMEND|      |    |      |SYMPGU|SFTPGD|
 *                  `-------------| NAVBK|    | NAVSP|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_QWERTY] = LAYOUT( \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
                    SFTHOM,  NUMEND,  NAV_BK,       NAV_SP,  SYMPGU,  SFTPGD                     \
),

/* NUM
 * Number - Focus on one-handed use and numpad on right from tw1t611
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

/* SYM
 * Symbol - Focus on one-handed use from tw1t611, symbol layer from oprietop's Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |  (   |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |   `  |   ;  |   :  |  [   |   ]  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |   ~  |   \  |   |  |  {   |   }  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |NUM LK|  FUN |      |    |      |      |SYM LK|
 *                  `-------------|  DEL |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_SYM] = LAYOUT( \
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
  _______, _______, _______, _______, _______,      KC_GRV,  KC_SCLN, KC_COLN, KC_LBRC, KC_RBRC, \
  _______, _______, _______, _______, _______,      KC_TILD, KC_BSLS, KC_PIPE, KC_LCBR, KC_RCBR, \
                    NUM_LK,  FUN,     KC_DEL,       _______, _______, SYM_LK                     \
),

/* NAV
 * Navigation + mouse keys
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  ESC |      |      |      |      |           | PAUSE| ACL0 | ACL1 | ACL2 | PSCR |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  TAB | HOME |  UP  |  END | PGUP |           | WH U | BTN1 | MS U | BTN2 |  INS |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | CAPS | LEFT | DOWN | RGHT | PGDN |           | WH D | MS L | MS D | MS R | SCRLK|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |NUM LK|NAV LK|      |    |      |SYS LK|SYM LK|
 *                  `------+------|  SYS |    |  SYS |------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_NAV] = LAYOUT( \
  KC_ESC,  _______, _______, _______, _______,      KC_PAUS, KC_ACL0, KC_ACL1, KC_ACL2, KC_PSCR, \
  KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,      KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_INS,  \
  KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,      KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_SLCK, \
                    NUM_LK,  NAV_LK,  SYS,          SYS,     SYS_LK,  SYM_LK                     \
),

/* SYS (NAV + NAV)
 * System, media, and layer lock keys from dustypomerleau
 *
 * ,----------------------------------.           ,----------------------------------.
 * | RESET| DEBUG|QWERTY|      |      |           | VOL--| VOL- | MUTE | VOL+ | VOL++|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SHIFT| CTRL |  ALT |  GUI |BRITE+|           |      | MRWD | MPLY | MFFD | POWER|
 * |------+------+------+------+------|           | -----+------+------+------+------|
 * |      |      |      |      |BRITE-|           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |NUM LK|NAV LK|      |    |      |SYS LK|SYM LK|
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_SYS] = LAYOUT( \
  RESET,   DEBUG,   QWERTY,  _______, _______,       KC_VOLD, VOL_DN,  KC_MUTE, VOL_UP,  KC_VOLU,\
  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_BRIU,       _______, KC_MRWD, KC_MPLY, KC_MFFD, _______,\
  _______, _______, _______, _______, KC_BRID,       _______, _______, _______, _______, _______,\
                    NUM_LK,  NAV_LK,  _______,       _______, SYS_LK,  SYM_LK                    \
),

/* FUN (NUM + SYM)
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
