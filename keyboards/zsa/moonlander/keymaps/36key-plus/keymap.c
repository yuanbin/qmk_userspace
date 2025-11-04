/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// compile with firmware24

//#include "alias.h"
#include "custom_process.h"

#define MOON_LED_LEVEL LED_LEVEL
#define L_ONEHAND L_LAST

#define LAYOUT_wrapper(...)   LAYOUT_moonlander(__VA_ARGS__)

/*
  moonlander on each side: 7 7 7 6 6 3
  l1 r1
  l2 r2
  l3 r3
  l4 r4
  l5 r5
  lt rt
*/

// clang-format off

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_wrapper(
        'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
	      'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
	      'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
	      'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
	      'L', 'L', 'L', 'R', 'R', 'R'
	);

#define __BASE_L0__ KC_MS_BTN3,    KC_MS_BTN2,        KC_MS_BTN1,      ZOOM_IN, ZOOM_OUT,         ZOOM_RESET
#define __BASE_R0__ KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, RGB_TOG, RGB_MODE_FORWARD, MOON_LED_LEVEL

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_wrapper
               (__BASE_L0__, __EMPTY2__, __BASE_R0__,
	              _______, __BASE_L1__, __EMPTY2__, __BASE_R1__, _______,
                _______, __BASE_L2__, SW_APP, SW_WIN, __BASE_R2__, _______,
                _______, __BASE_L3__, __BASE_R3__, _______,
                __EMPTY4__, LT(L_NAV, KC_BSPC), __EMPTY2__, LT(L_NUM, KC_TAB), __EMPTY4__,
                LT(L_SYMR, KC_ENTER), KC_BSPC, __EMPTY2__, KC_TAB, LT(L_SYML, KC_SPACE)
	              ),
  [L_SYML] = LAYOUT_wrapper
               (__EMPTY14__,
                _______, __SYML_L1__, _______, __EMPTY7__,
                _______, __SYML_L2__, _______, _______, __HRM_RIGHT__, _______,
                _______, __SYML_L3__, __EMPTY5__, _______,
                __EMPTY4__, KC_DEL, __EMPTY7__,
                CW_TOGG, KC_DEL, _______, __EMPTY3__
	              ),
  [L_SYMR] = LAYOUT_wrapper
               (__EMPTY14__,
                _______, __TO_LAST__, _______, _______, __SYMR_R1__, _______,
                _______, __HRM_LEFT__, _______, _______, __SYMR_R2__, _______,
                _______, __EMPTY5__, __SYMR_R3__, _______,
                __EMPTY12__,
                __EMPTY5__, KC_ESC
	              ),
  [L_NUM] = LAYOUT_wrapper
              (__EMPTY14__,
               _______, __NUM_L1__, __EMPTY8__,
               _______, __NUM_L2__, __EMPTY2__, __HRM_RIGHT__, _______,
               _______, __NUM_L3__,__EMPTY6__,
               __EMPTY4__, NUMWORD, __EMPTY7__,
               LAR, __EMPTY5__
	             ),
  [L_NAV] = LAYOUT_wrapper
              (__EMPTY14__,
               __EMPTY8__,__NAV_R1__,  _______,
               _______,__HRM_LEFT__, __EMPTY2__, __NAV_R2__,  _______,
               __EMPTY6__, __NAV_R3__,  _______,
               __EMPTY7__, KC_PGUP, __EMPTY4__,
               __EMPTY5__, KC_PGDN
	             ),
  [L_FNMOUSE] = LAYOUT_wrapper
                  (__EMPTY14__,
                   _______, __FNMOUSE_L1__, __EMPTY2__, __FNMOUSE_R1__, _______,
                   _______, __FNMOUSE_L2__, __EMPTY2__, __FNMOUSE_R2__, _______,
                   _______, __FNMOUSE_L3__, __FNMOUSE_R3__, _______,
                   __EMPTY4__, DM_PLY1, __EMPTY7__,
                   DM_PLY2, __EMPTY5__
	                 ),
  [L_SYSMEDIA] = LAYOUT_wrapper
                   (__EMPTY14__,
                    _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, MOON_LED_LEVEL, _______, _______, __SYSMEDIA_R1__, _______,
                    _______, _______, RGB_MODE_FORWARD, TOGGLE_LAYER_COLOR, RGB_TOG, _______, _______, _______, __SYSMEDIA_R2__, _______,
                    _______, RGB_SPD, RGB_SPI, RGB_HUD, RGB_HUI, _______, __SYSMEDIA_R3__, _______,
                    __EMPTY12__,
                    KC_CAPS, QK_BOOT, _______, _______, QK_BOOT, KC_SYRQ
	                  ),
  [L_NUMBERS] = LAYOUT_wrapper
                  (__EMPTY14__,
                   _______, __NUMBERS_L1__, _______, _______, __NUMBERS_R1__, _______,
                   _______, __NUMBERS_L2__, _______, _______, __NUMBERS_R2__, _______,
                   _______, __NUMBERS_L3__, __EMPTY5__, _______,
                   __EMPTY12__,
                   __EMPTY6__
	                 ),
  [L_ONEHAND] = LAYOUT_wrapper
                  (__EMPTY14__,
                   _______, __ONEHAND_L1__, _______, _______, __ONEHAND_R1__, _______,
                   _______, __ONEHAND_L2__, _______, _______, __ONEHAND_R2__, _______,
                   _______, __ONEHAND_L3__, __ONEHAND_R3__, _______,
                   __EMPTY4__, TO(L_BASE), __EMPTY7__,
                   __EMPTY6__
	                 ),
};
