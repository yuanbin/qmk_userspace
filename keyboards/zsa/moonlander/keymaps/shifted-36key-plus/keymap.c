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

#include "custom_process.h"

#define MOON_LED_LEVEL LED_LEVEL
#define L_ONEHAND L_LAST

#define LAYOUT_wrapper(...) LAYOUT_moonlander(__VA_ARGS__)

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

#define __BASE_L0__ KC_MS_BTN2,    KC_MS_BTN1,        KC_MS_BTN3,      ZOOM_IN, ZOOM_OUT,         ZOOM_RESET
#define __BASE_R0__ KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, RGB_TOG, RGB_MODE_FORWARD, MOON_LED_LEVEL

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_wrapper
               (__BASE_L0__, __EMPTY2__, __BASE_R0__,
	              __BASE_L1__, __EMPTY4__, __BASE_R1__,
                __BASE_L2__, __EMPTY4__, __BASE_R2__,
                __BASE_L3__, __EMPTY2__, __BASE_R3__,
                __EMPTY3__, __BASE_LT__, __EMPTY2__, __BASE_RT__, __EMPTY3__,
                __EMPTY6__
	              ),
  [L_SYML] = LAYOUT_wrapper
               (__EMPTY14__,
                __SYML_L1__, __EMPTY9__,
                __SYML_L2__, __EMPTY4__, __HRM_RIGHT__,
                __SYML_L3__, __EMPTY7__,
                __EMPTY3__, __SYML_LT__, __EMPTY7__,
                __EMPTY6__
	              ),
  [L_SYMR] = LAYOUT_wrapper
               (__EMPTY14__,
                __EMPTY9__, __SYMR_R1__,
                __HRM_LEFT__, __EMPTY4__,  __SYMR_R2__,
                __EMPTY7__, __SYMR_R3__,
                __EMPTY12__,
                __EMPTY6__
	              ),
  [L_NUM] = LAYOUT_wrapper
              (__EMPTY14__,
               __NUM_L1__, __EMPTY9__,
               __NUM_L2__, __EMPTY4__, __HRM_RIGHT__,
               __NUM_L3__,__EMPTY7__,
               __EMPTY3__, __NUM_LT__, __EMPTY7__,
               __EMPTY6__
	             ),
  [L_NAV] = LAYOUT_wrapper
              (__EMPTY14__,
               __EMPTY9__,__NAV_R1__,
               __HRM_LEFT__, __EMPTY4__, __NAV_R2__,
               __EMPTY7__, __NAV_R3__,
               __EMPTY12__,
               __EMPTY6__
	             ),
  [L_FNMOUSE] = LAYOUT_wrapper
                  (__EMPTY14__,
                   __FNMOUSE_L1__, __EMPTY4__, __FNMOUSE_R1__,
                   __FNMOUSE_L2__, __EMPTY4__, __FNMOUSE_R2__,
                   __FNMOUSE_L3__, __EMPTY2__, __FNMOUSE_R3__,
                   __EMPTY3__, __FNMOUSE_LT__, __EMPTY2__, __FNMOUSE_RT__, __EMPTY3__,
                   __EMPTY6__
	                 ),
  [L_SYSMEDIA] = LAYOUT_wrapper
                   (__EMPTY14__,
                    RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, MOON_LED_LEVEL, __EMPTY4__, __SYSMEDIA_R1__,
                    _______, RGB_MODE_FORWARD, TOGGLE_LAYER_COLOR, RGB_TOG, __EMPTY5__, __SYSMEDIA_R2__,
                    RGB_SPD, RGB_SPI, RGB_HUD, RGB_HUI, __EMPTY3__, __SYSMEDIA_R3__,
                    __EMPTY3__, __SYSMEDIA_LT__, __EMPTY2__, __SYSMEDIA_RT__, __EMPTY3__,
                    __EMPTY6__
	                  ),
  /* [L_NUMBERS] = LAYOUT_wrapper */
  /*                 (__EMPTY14__, */
  /*                  __NUMBERS_L1__, __EMPTY4__, __NUMBERS_R1__, */
  /*                  __NUMBERS_L2__, __EMPTY4__, __NUMBERS_R2__, */
  /*                  __NUMBERS_L3__, __EMPTY7__, */
  /*                  __EMPTY12__, */
  /*                  __EMPTY6__ */
	/*                  ), */
  [L_ONEHAND] = LAYOUT_wrapper
                  (__EMPTY14__,
                   __ONEHAND_L1__, __EMPTY4__, __ONEHAND_R1__,
                   __ONEHAND_L2__, __EMPTY4__, __ONEHAND_R2__,
                   __ONEHAND_L3__, __EMPTY2__, __ONEHAND_R3__,
                   __EMPTY3__, __ONEHAND_LT__, __EMPTY2__, __ONEHAND_RT__, __EMPTY3__,
                   __EMPTY6__
	                 ),
};
