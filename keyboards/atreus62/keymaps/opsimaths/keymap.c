#include QMK_KEYBOARD_H

#define OOOOOOO KC_TRNS

#define SFTPGUP LSFT_T(KC_PGUP)
#define CTLPGDN LCTL_T(KC_PGDN)
#define LGUI_HM LGUI_T(KC_HOME)
#define LALT_ND LALT_T(KC_END)

#define RSFT_UP RSFT_T(KC_UP)
#define RCTL_DN RCTL_T(KC_DOWN)
#define RALT_LF RALT_T(KC_LEFT)
#define RGUI_RT RGUI_T(KC_RGHT)

#define LT1_ENT LT(1,KC_ENT)
#define LT2_SPC LT(2,KC_SPC)
#define LT3BSPC LT(3,KC_BSPC)

#define OSXVOLU KC__VOLUP
#define OSXVOLD KC__VOLDOWN

LGUI_T(KC_HOME)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, 
    KC_LBRC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC, 
    KC_EQL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
    SFTPGUP, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_UP, 
    CTLPGDN, LGUI_HM, LALT_ND, LT3BSPC, LT2_SPC, LT1_ENT, KC_TAB,  KC_BSLS, KC_ENT,  KC_SPC,  KC_DEL,  RALT_LF, RGUI_RT, RCTL_DN
  ),

  [1] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   KC_CALC, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_BSPC, 
    _______, KC_F9,  KC_F10,   KC_F11,  KC_F12,  _______,                   _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______, 
    _______, KC_F5,  KC_F6,    KC_F7,   KC_F8,   _______,                   _______, KC_P4,   KC_P5,   KC_P6,   KC_PCMM, _______, 
    _______, KC_F1,  KC_F2,    KC_F3,   KC_F4,   _______,                   _______, KC_P1,   KC_P2,   KC_P3,   KC_PEQL, _______, 
    _______, _______, _______, _______, OOOOOOO, _______, _______, _______, _______, KC_P0,   KC_P0,   KC_PDOT, KC_PENT, _______
  ),

  [2] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, KC_WAKE, KC_SLEP, KC_PWR, 
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, 
    _______, _______, KC_MSTP, OSXVOLU, KC_MPLY, _______,                   _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, 
    _______, _______, KC_MRWD, OSXVOLD, KC_MFFD, _______,                   _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, 
    _______, _______, _______, OOOOOOO, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [3] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, OOOOOOO, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ 
  )
};