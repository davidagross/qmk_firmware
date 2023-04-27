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