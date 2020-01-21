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
bool is_alt_tab_active = false;
bool is_navlock_active = false;
bool is_numlock_active = false;
bool is_symlock_active = false;
bool is_syslock_active = false;
uint16_t bespoke_tap_timer = 0;

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
// #define NAVHOM LT(_NAV, KC_HOME) // these are now in process_record_user to ...
// #define NUMEND LT(_NUM, KC_END)  // and these are now in process_record_user to >>>
#define CTL_BK LCTL_T(KC_BSPC)
#define SFT_SP RSFT_T(KC_SPC)
// #define SYMPGU LT(_SYM, KC_PGUP) // <<< be able to keep the layer on after the momentary with a lock
// #define NAVPGD LT(_NAV, KC_PGDN) // ... unregister ALT on release for ALTTAB

#define FUN_0 LT(_FUN, KC_0)

// some mod-taps from dustypomerleau
// #define NAV_LK TG(_NAV) // these are now in process_record_user to ... 
// #define NUM_LK TG(_NUM) // ...
// #define SYM_LK TG(_SYM) // ...
// #define SYS_LK TG(_SYS) // ... work properly independent of the layer from which they are pressed
#define VOL_DN S(LALT(KC__VOLDOWN))
#define VOL_UP S(LALT(KC__VOLUP))

/* Combos on the base layer
 * inspired by germ's gergoplex layout
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
 *                  |NAVHOM|NUMEND|      |    |      |SYMPGU|NAVPGD|
 *                  `-------------| CTLBK|    | SFTSP|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_QWERTY] = LAYOUT( \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
                    NAVHOM,  NUMEND,  CTL_BK,       SFT_SP,  SYMPGU,  NAVPGD                     \
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
 * |      | CTLLT| GUIUP| CTLRT|      |           |   `  |   ;  |   :  |  [   |   ]  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      | GUILT| GUIDN| GUIRT|      |           |   ~  |   \  |   |  |  {   |   }  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |NUM LK|  FUN |      |    |      |      |SYM LK|
 *                  `-------------|  DEL |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_SYM] = LAYOUT( \
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
  _______, CTLLT,   GUIUP,   CTLRT,   _______,      KC_GRV,  KC_SCLN, KC_COLN, KC_LBRC, KC_RBRC, \
  _______, GUILT,   GUIDN,   GUIRT,   _______,      KC_TILD, KC_BSLS, KC_PIPE, KC_LCBR, KC_RCBR, \
                    NUM_LK,  FUN,     KC_DEL,       _______, _______, SYM_LK                     \
),

/* NAV
 * Navigation + mouse keys
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  ESC |SFALTB|CTLCTV|ALTTAB|      |           |  INS | ACL0 | ACL1 | ACL2 | PSCR |
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
[_NAV] = LAYOUT( 
  KC_ESC,  SFALTB,  CTLCTV,  ALTTAB,  _______,      KC_INS,  KC_ACL0, KC_ACL1, KC_ACL2, KC_PSCR, \
  KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,      KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_PAUS, \
  KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,      KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_SLCK, \
                    SYS,     NUM_LK,  NAV_LK,       SYS_LK,  SYM_LK,  SYS                        \
),

/* SYS (NAV + NAV)
 * System, media, and layer lock keys from dustypomerleau
 *
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
[_SYS] = LAYOUT( \
  RESET,   DEBUG,   QWERTY,  _______, _______,       VOL_DN,  VOL_UP,  KC_MUTE, KC_VOLD, KC_VOLU,\
  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_BRIU,       _______, KC_MRWD, KC_MPLY, KC_MFFD, _______,\
  _______, _______, _______, _______, KC_BRID,       _______, _______, _______, _______, _______,\
                    _______, NUM_LK,  NAV_LK,        SYS_LK,  SYM_LK,  _______                   \
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
    case NUMEND:
      if (record->event.pressed) {
        // Records press timer
        bespoke_tap_timer = timer_read();
        // turn on the NUM layer
        layer_on(_NUM);
        update_tri_layer(_NUM, _SYM, _FUN);
      } else if (timer_elapsed(bespoke_tap_timer) < TAPPING_TERM) {
        // Sends out 'end' if the key is held for less than tapping term 
        tap_code(KC_END);
        if (!is_numlock_active) {
          // turn off the NUM layer
          layer_off(_NUM);
          update_tri_layer(_NUM, _SYM, _FUN);
        }
      } else if (!is_numlock_active) {
        // turn off the NUM layer
        layer_off(_NUM);
        update_tri_layer(_NUM, _SYM, _FUN);
      } 
      return false;
      break;
    case SYMPGU:
      if (record->event.pressed) {
        // Records press timer
        bespoke_tap_timer = timer_read();
        // turn on the SYM layer
        layer_on(_SYM);
        update_tri_layer(_NUM, _SYM, _FUN);
      } else if (timer_elapsed(bespoke_tap_timer) < TAPPING_TERM) {
        // Sends out 'pgup' if the key is held for less than tapping term 
        tap_code(KC_PGUP);
        if (!is_symlock_active) {
          // turn off the SYM layer
          layer_off(_SYM);
          update_tri_layer(_NUM, _SYM, _FUN);
        }
      } else if (!is_symlock_active) {
        // turn off the SYM layer
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
    case CTLCTV:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("ctv")SS_TAP(X_ENT)); // copies, opens new tab, pastes, and enters
      }
      return false;
      break;
    // NAVHOM and NAVPGD modified from http://blog.hgao.net/post/qmk-mod-key/ because i'm afraid to tap-dance
    case NAVHOM:
      if (record->event.pressed) {
        // Records press timer
        bespoke_tap_timer = timer_read();
        // turn on the NAV layer
        layer_on(_NAV);
      } else if (is_alt_tab_active) {
        // deactivate alt-tab
        is_alt_tab_active = false;
        unregister_code(KC_LALT);
        if (!is_navlock_active) {
          // turn off the NAV layer
          layer_off(_NAV);
        }
      } else if (timer_elapsed(bespoke_tap_timer) < TAPPING_TERM) {
        // turn off the NAV layer
        layer_off(_NAV);
        // Sends out 'home' if the key is held for less than tapping term 
        tap_code(KC_HOME);
      } else if (!is_navlock_active) {
        // turn off the NAV layer
        layer_off(_NAV);
      } 
      return false;
      break;
    case NAVPGD:
      if (record->event.pressed) {
        // Records press time.
        bespoke_tap_timer = timer_read();
        // turn on the NAV layer
        layer_on(_NAV);
      } else if (is_alt_tab_active) {
        // deactivate alt-tab
        is_alt_tab_active = false;
        unregister_code(KC_LALT);
        if (!is_navlock_active) {
          // turn off the NAV layer
          layer_off(_NAV);
        }
      } else if (timer_elapsed(bespoke_tap_timer) < TAPPING_TERM) {
        // turn off the NAV layer
        layer_off(_NAV);
        // Sends out 'pgdn' if the key is held for less than tapping term 
        tap_code(KC_PGDN);
      } else if (!is_navlock_active) {
        // turn off the NAV layer
        layer_off(_NAV);
      } 
      return false;
      break;
    // modified from https://beta.docs.qmk.fm/features/feature_macros#super-alt-tab
    case ALTTAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        tap_code(KC_TAB);
      }
      return false;
      break;
    case SFALTB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        } 
        register_code(KC_LSFT);
        tap_code(KC_TAB);
        unregister_code(KC_LSFT);
      }
      return false;
      break;
    case NAV_LK:
      if (record->event.pressed) {
        is_navlock_active = !is_navlock_active;
      }
      if (is_navlock_active) {
        layer_on(_NAV);
      } else {
        layer_off(_NAV);
      }
      return false;
      break;
    case NUM_LK:
      if (record->event.pressed) {
        is_numlock_active = !is_numlock_active;
      }
      if (is_numlock_active) {
        layer_on(_NUM);
      } else {
        layer_off(_NUM);
      }
      return false;
      break;
    case SYM_LK:
      if (record->event.pressed) {
        is_symlock_active = !is_symlock_active;
      }
      if (is_symlock_active) {
        layer_on(_SYM);
      } else {
        layer_off(_SYM);
      }
      return false;
      break;
    case SYS_LK:
      if (record->event.pressed) {
        is_syslock_active = !is_syslock_active;
      }
      if (is_syslock_active) {
        layer_on(_SYS);
      } else {
        layer_off(_SYS);
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
