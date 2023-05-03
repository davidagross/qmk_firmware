/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#pragma once

/* One valid hand configuration for trackball */
#define MASTER_RIGHT

#define POINTING_DEVICE_ROTATION_90
#define PIMORONI
#ifdef TRACKBALL_RIGHT
    #define POINTING_DEVICE_INVERT_X
    #define POINTING_DEVICE_INVERT_Y
#endif

// dgroseph, combos config

#define COMBO_ALLOW_ACTION_KEYS
#define COMBO_COUNT 75
#define COMBO_TERM 16
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 150