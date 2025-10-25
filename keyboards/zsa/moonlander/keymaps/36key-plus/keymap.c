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
               (__BASE_L0__, _______, _______, __BASE_R0__,
	              _______, __BASE_L1__, _______, _______, __BASE_R1__, _______,
	              SW_APP, __BASE_L2__, _______, _______, __BASE_R2__, SW_WIN,
	              _______, __BASE_3__, _______,
	              _______, _______, _______, KC_MS_BTN1, STICKY_SHIFT_L_NUM, _______,
	              _______, STICKY_SHIFT_L_NAV, QK_REP, _______, _______, _______,
	              LT(1, KC_ENTER),    LT(5,KC_BSPC), _______, _______, LT(6, KC_TAB),      LT(2, KC_SPACE)
	              ),
  [L_SYMR] = LAYOUT_wrapper
               (__EMPTY14__,
                _______, _______, _______, TO(L_LAST), _______, _______, _______, _______, __SYMBOLS_R1__, _______,
                _______, __HRM_LEFT__, _______, _______, __SYMBOLS_R2__, _______,
                _______, __SYMR_3__, _______,
                __EMPTY12__,
                __EMPTY5__, KC_ESC
	                 ),
  [L_SYML] = LAYOUT_wrapper
               (__EMPTY14__,
                _______, __SYMBOLS_L1__, _______, __EMPTY7__,
                _______, __SYMBOLS_L2__, _______, _______, __HRM_RIGHT__, _______,
                _______, __SYML_3__, _______,
                __EMPTY12__,
                CW_TOGG, KC_DEL, _______, __EMPTY3__
	                 ),
  [L_NUM] = LAYOUT_wrapper
               (__EMPTY14__,
                __EMPTY7__, _______, __NUMNAV_R1__, _______,
                _______, __HRM_LEFT__, _______, _______, __NUMNAV_R2__, _______,
                _______, __NUM_3__, _______,
                __EMPTY6__, _______, KC_EQUAL, __EMPTY4__,
                __EMPTY3__, _______, NUMWORD, LAR
	                 ),
  [L_NAV] = LAYOUT_wrapper
               (__EMPTY14__,
                _______, __NUMNAV_L1__, _______, __EMPTY7__,
                _______, __NUMNAV_L2__, _______, _______, __HRM_RIGHT__, _______,
                _______, __NAV_3__, _______,
                __EMPTY12__,
                __EMPTY6__
	                 ),
  [L_FNMAC] = LAYOUT_wrapper
               (__EMPTY14__,
                __EMPTY7__, _______, __FNMOUSE_R1__, _______,
                _______, __HRM_LEFT__, _______, _______, __FNMOUSE_R2__, _______,
                _______, __FNMAC_3__, _______,
                __EMPTY12__,
                __EMPTY4__, DM_PLY1, DM_PLY2
	                 ),
  [L_MOUSE] = LAYOUT_wrapper
               (__EMPTY14__,
                _______, __FNMOUSE_L1__, _______, __EMPTY7__,
                _______, __FNMOUSE_L2__, _______, _______, __HRM_RIGHT__, _______,
                _______, __MOUSE_3__, _______,
                __EMPTY12__,
                __EMPTY6__
	                 ),
  [L_SYSMEDIA] = LAYOUT_wrapper
                   (__EMPTY14__,
                    _______, __SYSMEDIA_L1__, _______, _______, MOON_LED_LEVEL, RGB_VAI, RGB_VAD, RGB_SAI, RGB_SAD , _______,
	                  _______, __SYSMEDIA_L2__, _______, _______, _______, RGB_TOG, TOGGLE_LAYER_COLOR, RGB_MODE_FORWARD,  _______, _______,
	                  _______, __SYSMEDIA_L3__, _______, RGB_HUI, RGB_HUD, RGB_SPI, RGB_SPD, _______,
	                  __EMPTY12__,
                    KC_CAPS, QK_BOOT, _______, _______, QK_BOOT, KC_SYRQ
	                 ),
  [L_NUMBERS] = LAYOUT_wrapper
                  (__EMPTY14__,
                   _______, __NUMBERS_L1__, _______, _______, __NUMBERS_R1__, _______,
                   _______, __NUMBERS_L2__, _______, _______, __NUMBERS_R2__, _______,
                   _______, __NUMBERS_3__, _______,
                   __EMPTY6__, _______, KC_EQUAL, __EMPTY4__,
                   __EMPTY6__
	                 ),
  [L_ONEHAND] = LAYOUT_wrapper
                  (__EMPTY14__,
                   _______, __ONEHAND_L1__, _______, _______, __ONEHAND_R1__, _______,
                   _______, __ONEHAND_L2__, _______, _______, __ONEHAND_R2__, _______,
                   _______, __ONEHAND_3__, _______,
                   __EMPTY12__,
                   _______, TO(L_BASE), _______, __EMPTY3__
	                 ),
};
