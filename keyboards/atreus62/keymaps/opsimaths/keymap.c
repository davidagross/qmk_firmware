#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layers {
  _QWERTY,
  _NUMFUN,
  _NAV,
  _SYS,
};

// Shortcuts
#define SFTPGUP LSFT_T(KC_PGUP)
#define NMFNPGD LT(_NUMFUN,KC_PGDN)
#define LCTL_HM LCTL_T(KC_HOME)
#define LALT_ND LALT_T(KC_END)
#define LCMDTAB LCMD_T(KC_TAB)

#define RSFT_UP RSFT_T(KC_UP)
#define SYS_DWN LT(_SYS,KC_DOWN)
#define RCTL_RT RCTL_T(KC_RGHT)
#define RALT_LF RALT_T(KC_LEFT)
#define RCMDBSL RCMD_T(KC_BSLS)

#define NAV_SPC LT(_NAV,KC_SPC)

#define OSXVOLU KC__VOLUP
#define OSXVOLD KC__VOLDOWN
#define OSXMUTE KC__MUTE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, 
    KC_LBRC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC, 
    KC_EQL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
    SFTPGUP, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_UP, 
    NMFNPGD, LCTL_HM, LALT_ND, KC_DEL,  KC_BSPC, NAV_SPC, LCMDTAB, RCMDBSL, NAV_SPC, KC_ENT,  KC_BSPC, RALT_LF, RCTL_RT, SYS_DWN
  ),

  [_NUMFUN] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC, 
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_PSLS, 
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PAST, 
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_PCMM, 
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  KC_F12,  XXXXXXX, KC_P0,   KC_P0,   KC_PDOT, KC_PEQL, XXXXXXX
  ),

  [_NAV] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
    XXXXXXX, XXXXXXX, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U,                   KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX, XXXXXXX, 
    XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                   KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, 
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_SYS] = LAYOUT(
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PWR,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX 
  )
};