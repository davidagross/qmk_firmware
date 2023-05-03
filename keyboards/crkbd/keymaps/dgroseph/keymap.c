/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2023 David A. Gross <@davidagross>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "dgroseph.h" // dgroseph layers and germ-inspired combos

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_wrapper( \
    KC_GESC, _________________QWERTY_L1_________________,         _________________QWERTY_R1_________________, KC_BSPC,\
    KC_TAB , _________________QWERTY_L2_________________,         _________________QWERTY_R2_________________, KC_ENT, \
    KC_CAPS, _________________QWERTY_L3_________________,         _________________QWERTY_R3_________________, _______,\
                               _______QWERTY_LTHM_______,         _______QWERTY_RTHM_______                            \
  ),

  [_NUM] = LAYOUT_wrapper( \
    KC_GESC, _________________NUMBER_L1_________________,         _________________NUMBER_R1_________________, KC_BSPC,\
    KC_TAB , _________________NUMBER_L2_________________,         _________________NUMBER_R2_________________, KC_ENT, \
    KC_CAPS, _________________NUMBER_L3_________________,         _________________NUMBER_R3_________________, _______,\
                               _______NUMBER_LTHM_______,         _______NUMBER_RTHM_______                            \
  ),

  [_SYM] = LAYOUT_wrapper( \
    KC_GESC, _________________SYMBOL_L1_________________,         _________________SYMBOL_R1_________________, KC_BSPC,\
    KC_TAB , _________________SYMBOL_L2_________________,         _________________SYMBOL_R2_________________, KC_ENT, \
    KC_CAPS, _________________SYMBOL_L3_________________,         _________________SYMBOL_R3_________________, _______,\
                               _______SYMBOL_LTHM_______,         _______SYMBOL_RTHM_______                            \
  ),

  [_NAV] = LAYOUT_wrapper( 
    KC_GESC, _________________NAVIG8_L1_________________,         _________________NAVIG8_R1_________________, KC_BSPC,\
    KC_TAB , _________________NAVIG8_L2_________________,         _________________NAVIG8_R2_________________, KC_ENT, \
    KC_CAPS, _________________NAVIG8_L3_________________,         _________________NAVIG8_R3_________________, _______,\
                               _______NAVIG8_LTHM_______,         _______NAVIG8_RTHM_______                            \
  ),

  [_SYS] = LAYOUT_wrapper( \
    KC_GESC, _________________SYSTEM_L1_________________,         _________________SYSTEM_R1_________________, KC_BSPC,\
    KC_TAB , _________________SYSTEM_L2_________________,         _________________SYSTEM_R2_________________, KC_ENT, \
    KC_CAPS, _________________SYSTEM_L3_________________,         _________________SYSTEM_R3_________________, _______,\
                               _______SYSTEM_LTHM_______,         _______SYSTEM_RTHM_______                            \
  ),

  [_FUN] =  LAYOUT_wrapper( \
    KC_GESC, _________________FNCSHN_L1_________________,         _________________FNCSHN_R1_________________, KC_BSPC,\
    KC_TAB , _________________FNCSHN_L2_________________,         _________________FNCSHN_R2_________________, KC_ENT, \
    KC_CAPS, _________________FNCSHN_L3_________________,         _________________FNCSHN_R3_________________, _______,\
                               _______FNCSHN_LTHM_______,          _______FNCSHN_RTHM_______                           \
  )
};

/* Layout Name
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |      |      |      |      |      |      |           |      |      |      |      |      |      |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      |      |      |      |      |      |           |      |      |      |      |      |      |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      |      |      |      |      |      |           |      |      |      |      |      |      |
 * `-----------------------------------------'           `-----------------------------------------'
 *                         ,--------------------.     ,------,-------------.
 *                         |      |      |      |     |      |      |      |
 *                         `-------------|      |     |      |------+------.
 *                                       |      |     |      |
 *                                       `------'     `------'
 */

/*
[_LAYOUT_NAME] =  LAYOUT( \
  _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,\
  _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,\
  _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,\
                             _______, _______, _______,      _______, _______, _______                            \
)

[_LAYOUT_NAME] =  LAYOUT_wrapper( \
  _______, _________________LAYRNM_L1_________________,      _________________LAYRNM_R1_________________, _______,\
  _______, _________________LAYRNM_L2_________________,      _________________LAYRNM_R2_________________, _______,\
  _______, _________________LAYRNM_L3_________________,      _________________LAYRNM_R3_________________, _______,\
                             _______LAYRNM_LTHM_______,      _______LAYRNM_RTHM_______                            \
)
*/