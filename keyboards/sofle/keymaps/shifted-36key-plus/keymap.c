/* Copyright 2020 Josef Adamcik
 * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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

/* shifted one column out */

/* #include "alias.h" */
#include "custom_process.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#define L_ONEHAND L_LAST

/*
  sofle_v2 on each side: 6 6 6 7 5
  l1 r1
  l2 r2
  l3 r3
  l4 r4
  lt rt
*/

// clang-format off

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [L_BASE] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD),         ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [L_SYML] = { ENCODER_CCW_CW(C(S(KC_TAB)) , C(KC_TAB)), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [L_SYMR] = { ENCODER_CCW_CW(KC_NO, KC_NO),             ENCODER_CCW_CW(A(S(KC_TAB)), A(KC_TAB))},
    [L_NUM] =      { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [L_NAV] =      { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [L_FNMOUSE] =    { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [L_SYSMEDIA] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    /* [L_NUMBERS] =  { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) }, */
    [L_ONEHAND] =  { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) }
};
#endif

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_wrapper(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
	      'L', 'L', 'L', 'L', 'L', 'L',  'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
	      'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R'
	);

#define __BASE_L0__ MS_BTN2,       MS_BTN1,           MS_BTN3,         ZOOM_IN,    ZOOM_OUT,   ZOOM_RESET
#define __BASE_R0__ KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, MS_BTN3,    MS_BTN1,    MS_BTN2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
  QWERTY
  ,-----------------------------------------.                    ,-----------------------------------------.
  |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
  |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
  |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
  |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
  |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
  `-----------------------------------------/       /     \      \-----------------------------------------'
             | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
             |      |      |      |      |/       /         \      \ |      |      |      |      |
             `----------------------------------'           '------''---------------------------'

[0] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 KC_LGUI,KC_LALT,KC_LCTL, MO(2), KC_ENT,      KC_SPC,  MO(3), KC_RCTL, KC_RALT, KC_RGUI
),
*/

[L_BASE] = LAYOUT_wrapper
             (__BASE_L0__, __BASE_R0__,
              __BASE_L1__, __EMPTY2__, __BASE_R1__,
	            __BASE_L2__, __EMPTY2__, __BASE_R2__,
              __BASE_L3__, __EMPTY4__, __BASE_R3__,
              _______, __BASE_LT__, __EMPTY4__, __BASE_RT__, _______
	            ),
[L_SYML] = LAYOUT_wrapper
             (__EMPTY12__,
              __SYML_L1__, __EMPTY7__,
              __SYML_L2__, __EMPTY2__, __HRM_RIGHT__,
              __SYML_L3__, __EMPTY9__,
              _______, __SYML_LT__, __EMPTY7__
	            ),
[L_SYMR] = LAYOUT_wrapper
             (__EMPTY12__,
              __EMPTY7__, __SYMR_R1__,
              __HRM_LEFT__, __EMPTY2__, __SYMR_R2__,
              __EMPTY9__, __SYMR_R3__,
              __EMPTY7__, __SYMR_RT__, _______
	            ),
[L_NUM] = LAYOUT_wrapper
            (__EMPTY12__,
             __NUM_L1__, __EMPTY7__,
             __NUM_L2__, __EMPTY2__, __HRM_RIGHT__,
             __NUM_L3__,__EMPTY9__,
             _______, __NUM_LT__, __EMPTY7__
	           ),
[L_NAV] = LAYOUT_wrapper
            (__EMPTY12__,
             __EMPTY7__,__NAV_R1__,
             __HRM_LEFT__, __EMPTY2__, __NAV_R2__,
             __EMPTY9__, __NAV_R3__,
             __EMPTY7__, __NAV_RT__, _______
	           ),
[L_FNMOUSE] = LAYOUT_wrapper
                (__EMPTY12__,
                 __FNMOUSE_L1__, __EMPTY2__, __FNMOUSE_R1__,
                 __FNMOUSE_L2__, __EMPTY2__, __FNMOUSE_R2__,
                 __FNMOUSE_L3__, __EMPTY4__, __FNMOUSE_R3__,
                 _______, __FNMOUSE_LT__, __EMPTY4__, __FNMOUSE_RT__, _______
	               ),
[L_SYSMEDIA] = LAYOUT_wrapper
                 (__EMPTY12__,
                  __SYSMEDIA_L1__, __EMPTY2__, __SYSMEDIA_R1__,
                  __SYSMEDIA_L2__, __EMPTY2__, __SYSMEDIA_R2__,
                  __SYSMEDIA_L3__, __EMPTY4__, __SYSMEDIA_R3__,
                  _______, __SYSMEDIA_LT__,  __EMPTY4__, __SYSMEDIA_RT__, _______
	                ),
/* [L_NUMBERS] = LAYOUT_wrapper */
/*                 (__EMPTY12__, */
/*                  __NUMBERS_L1__, __EMPTY2__, __NUMBERS_R1__, */
/*                  __NUMBERS_L2__, __EMPTY2__, __NUMBERS_R2__, */
/*                  __NUMBERS_L3__, __EMPTY4__, __NUMBERS_R3__, */
/*                  _______, __NUMBERS_LT__,  __EMPTY4__, __NUMBERS_RT__, _______ */
/* 	               ), */
[L_ONEHAND] = LAYOUT_wrapper
                (__EMPTY12__,
                 __ONEHAND_L1__, __EMPTY2__, __ONEHAND_R1__,
                 __ONEHAND_L2__, __EMPTY2__, __ONEHAND_R2__,
                 __ONEHAND_L3__, __EMPTY4__, __ONEHAND_R3__,
                 _______, __ONEHAND_LT__,  __EMPTY4__, __ONEHAND_RT__, _______
	               ),
};
