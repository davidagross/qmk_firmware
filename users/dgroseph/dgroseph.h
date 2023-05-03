#include "quantum.h"

// dgroseph, split combos config
# include "combos.h"

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
  NUMEND,
  SYMPGU,
  SYS,
  FUN,
  NAVHOM,
  NAVPGD,
  CTLCTV,
  ALTTAB,
  SFALTB,
  NAV_LK,
  NUM_LK,
  SYM_LK,
  SYS_LK
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

#define GUIUP RGUI(KC_UP)
#define GUIDN RGUI(KC_DOWN)
#define GUILT RGUI(KC_LEFT)
#define GUIRT RGUI(KC_RGHT)

#define CTLLT LCTL(KC_LEFT)
#define CTLRT RCTL(KC_RGHT)

// Thumbs
#define NAVHOM LT(_NAV, KC_HOME)
#define NUMEND LT(_NUM, KC_END)
#define CTL_BK LCTL_T(KC_BSPC)
#define SFT_SP RSFT_T(KC_SPC)
#define SYMPGU LT(_SYM, KC_PGUP)
#define NAVPGD LT(_NAV, KC_PGDN)

#define FUN_0 LT(_FUN, KC_0)
#define FNFNLK LT(_FUN, FUN_LK)

// some mod-taps from dustypomerleau
#define NAV_LK TG(_NAV)
#define NUM_LK TG(_NUM)
#define FUN_LK TG(_FUN)
#define SYM_LK TG(_SYM)
#define SYS_LK TG(_SYS)
#define VOL_DN S(LALT(KC__VOLDOWN))
#define VOL_UP S(LALT(KC__VOLUP))

/* Combos on the base layer
 * inspired by germ's gergoplex layout
 * NOTE: If you're using MT,LT or anything you must
 * define it here. Note this if you change your layout!
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  GRAVE_ESC  |      |      (      |           |      )    BTN1    BTN2  BKSPC    |
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

// register combos from _QWERTY even when on another layer
#define COMBO_ONLY_FROM_LAYER _QWERTY

combo_t key_combos[COMBO_COUNT] = {
    // Horizontal 2-Chords

    [QW] = COMBO(qw_combo, KC_GESC),
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

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

/* QWERTY
* ,----------------------------------.           ,----------------------------------.
* |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
* |------+------+------+------+------|           |------+------+------+------+------|
* |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   '  |
* |------+------+------+------+------|           |------+------+------+------+------|
* |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
* `----------------------------------'           `----------------------------------'
*                  ,--------------------.    ,------,-------------.
*                  |NAVHOM|NUMEND|      |    |      |SYMPGU|NAVPGD|
*                  `-------------| CTLBK|    | SFTSP|------+------.
*                                |      |    |      |
*                                `------'    `------'
*/

#define _________________QWERTY_L1_________________ KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________ KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________ KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________ KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT
#define _________________QWERTY_R3_________________ KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _______QWERTY_LTHM_______ NAVHOM,  NUMEND,  CTL_BK
#define _______QWERTY_RTHM_______ SFT_SP,  SYMPGU,  NAVPGD

/* NUM
* Number - Focus on one-handed use and numpad on right from tw1t611
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

#define _________________NUMBER_L1_________________ KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _________________NUMBER_L2_________________ KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________NUMBER_L3_________________ KC_SLSH, KC_DOT,  KC_ASTR, KC_PLUS, KC_MINS

#define _________________NUMBER_R1_________________ KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________NUMBER_R2_________________ KC_UNDS, KC_4,    KC_5,    KC_6,    KC_PLUS
#define _________________NUMBER_R3_________________ KC_MINS, KC_1,    KC_2,    KC_3,    KC_EQL

#define _______NUMBER_LTHM_______ NUM_LK,  _______, _______
#define _______NUMBER_RTHM_______ KC_ENT,  FUN_0,   KC_DOT

/* SYM
* Symbol - Focus on one-handed use from tw1t611, symbol layer from oprietop's Lower
* ,----------------------------------.           ,----------------------------------.
* |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |  (   |   )  |
* |------+------+------+------+------|           |------+------+------+------+------|
* |      | CTLLT| GUIUP| CTLRT|      |           |   `  |   ;  |   :  |  [   |   ]  |
* |------+------+------+------+------|           |------+------+------+------+------|
* |      | GUILT| GUIDN| GUIRT|      |           |   ~  |   \  |   |  |  {   |   }  |
* `----------------------------------'           `----------------------------------'
*                  ,--------------------.    ,------,-------------.
*                  |NUM LK|FNFNLK|      |    |      |      |SYM LK|
*                  `-------------|  DEL |    |      |------+------.
*                                |      |    |      |
*                                `------'    `------'
*/

#define _________________SYMBOL_L1_________________ KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________SYMBOL_L2_________________ _______, CTLLT,   GUIUP,   CTLRT,   _______
#define _________________SYMBOL_L3_________________ _______, GUILT,   GUIDN,   GUIRT,   _______

#define _________________SYMBOL_R1_________________ KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define _________________SYMBOL_R2_________________ KC_GRV,  KC_SCLN, KC_COLN, KC_LBRC, KC_RBRC
#define _________________SYMBOL_R3_________________ KC_TILD, KC_BSLS, KC_PIPE, KC_LCBR, KC_RCBR

#define _______SYMBOL_LTHM_______ NUM_LK,  FNFNLK,  KC_DEL
#define _______SYMBOL_RTHM_______ _______, _______, SYM_LK

/* NAV
* Navigation + mouse keys
* ,----------------------------------.           ,----------------------------------.
* |  ESC |SFALTB|CTLCTV|ALTTAB| CALC |           |  INS | ACL0 | ACL1 | ACL2 | PSCR |
* |------+------+------+------+------|           |------+------+------+------+------|
* |  TAB | HOME |  UP  |  END | PGUP |           | WH U | BTN1 | MS U | BTN2 | PAUSE|
* |------+------+------+------+------|           |------+------+------+------+------|
* | CAPS | LEFT | DOWN | RGHT | PGDN |           | WH D | MS L | MS D | MS R | SCRLK|
* `----------------------------------'           `----------------------------------'
*                  ,--------------------.    ,--------------------.
*                  |  SYS |NUM LK|      |    |      |SYM LK|  SYS |
*                  `------+------|NAV LK|    |SYS LK|------+------'
*                                |      |    |      |
*                                `------'    `------'
*/

#define _________________NAVIG8_L1_________________ KC_ESC,  SFALTB,  CTLCTV,  ALTTAB,  KC_CALC
#define _________________NAVIG8_L2_________________ KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_PGUP
#define _________________NAVIG8_L3_________________ KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN

#define _________________NAVIG8_R1_________________ KC_INS,  KC_ACL0, KC_ACL1, KC_ACL2, KC_PSCR
#define _________________NAVIG8_R2_________________ KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_PAUS
#define _________________NAVIG8_R3_________________ KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_SLCK

#define _______NAVIG8_LTHM_______ SYS,     NUM_LK,  NAV_LK
#define _______NAVIG8_RTHM_______ SYS_LK,  SYM_LK,  SYS

/* SYS (NAV + NAV)
* System, media, and layer lock keys from dustypomerleau
* ,----------------------------------.           ,----------------------------------.
* | RESET| DEBUG|QWERTY|      |      |           | VOL- | VOL+ | MUTE | VOL--| VOL++|
* |------+------+------+------+------|           |------+------+------+------+------|
* | SHIFT| CTRL |  ALT |  GUI |BRITE+|           |      | MRWD | MPLY | MFFD |      |
* |------+------+------+------+------|           | -----+------+------+------+------|
* |      |      |      |      |BRITE-|           |      |      |      |      |      |
* `----------------------------------'           `----------------------------------'
*                  ,--------------------.    ,------,-------------.
*                  |      |NUM LK|      |    |      |SYM LK|      |
*                  `-------------|NAV LK|    |SYS LK|------+------.
*                                |      |    |      |
*                                `------'    `------'
*/

#define _________________SYSTEM_L1_________________ RESET,   DEBUG,   QWERTY,  _______, _______
#define _________________SYSTEM_L2_________________ KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_BRIU
#define _________________SYSTEM_L3_________________ _______, _______, _______, _______, KC_BRID

#define _________________SYSTEM_R1_________________ VOL_DN,  VOL_UP,  KC_MUTE, KC_VOLD, KC_VOLU
#define _________________SYSTEM_R2_________________ _______, KC_MRWD, KC_MPLY, KC_MFFD, _______
#define _________________SYSTEM_R3_________________ _______, _______, _______, _______, _______

#define _______SYSTEM_LTHM_______ _______, NUM_LK,  NAV_LK
#define _______SYSTEM_RTHM_______ SYS_LK,  SYM_LK,  _______ 

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
  *                  |TSKMGR|FUN LK|      |    |      |      |CALTDE|
  *                  `-------------|      |    |      |------+------.
  *                                |      |    |      |
  *                                `------'    `------'
  */

#define _________________FNCSHN_L1_________________ KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FNCSHN_L2_________________ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define _________________FNCSHN_L3_________________ _______, _______, _______, KC_F11,  KC_F12

#define _________________FNCSHN_R1_________________ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define _________________FNCSHN_R2_________________ _______, KC_F4,   KC_F5,   KC_F6,   KC_F11
#define _________________FNCSHN_R3_________________ _______, KC_F1,   KC_F2,   KC_F3,   KC_F12

#define _______FNCSHN_LTHM_______ TSKMGR,  FUN_LK,  _______
#define _______FNCSHN_RTHM_______ _______, _______, CALTDEL