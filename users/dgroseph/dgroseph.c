#include "dgroseph.h"

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
    case CTLCTV:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("ctv")SS_TAP(X_ENT)); // copies, opens new tab, pastes, and enters
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
  }
  return true;
}