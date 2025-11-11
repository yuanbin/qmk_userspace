/* Copyright 2020 Richard Titmuss (richard.titmuss@gmail.com)
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

/* #include "alias.h" */
#include "custom_process.h"

#define LAYOUT_wrapper(...) LAYOUT_split_3x6_4(__VA_ARGS__)

/*
  torn on each side: 6 6 6 4
  l1 r1
  l2 r2
  l3 r3
  lt rt
*/

// clang-format off

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_wrapper(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
	      'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R'
	);

#define L_ONEHAND L_LAST

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.    ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |    |   Y  |   U  |   I  |   O  |   P  |  '   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | `    |   A  |   S  |   D  |   F  |   G  |    |   H  |   J  |   K  |   L  |   ;  |  [   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | \    |   Z  |   X  |   C  |   V  |   B  |    |   N  |   M  |   ,  |   .  |   /  |  ]   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               | ____ | Ctrl | Bksp | Del  |    |Enter |Space | Alt  | ____ |
 *               |      |      |Shift |Raise |    | Gui  |Lower |      |      |
 *               `---------------------------'    `---------------------------'
[_QWERTY] = LAYOUT_split_3x6_4(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
    KC_GRV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_LBRC,
    KC_BSLS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC ,
                      R_DEL,   KC_LCTL, S_BSPC,  R_DEL,     G_ENT,   L_SPC,   KC_RALT, G_ENT
),
*/

[L_BASE] = LAYOUT_wrapper
             (__BASE_L1__, MS_BTN3, _______, __BASE_R1__,
              __BASE_L2__, MS_BTN1, _______, __BASE_R2__,
              __BASE_L3__, MS_BTN2, _______, __BASE_R3__,
              __BASE_LT__, __EMPTY2__, __BASE_RT__
	            ),
[L_SYML] = LAYOUT_wrapper
             (__SYML_L1__, __EMPTY7__,
              __SYML_L2__, __EMPTY2__, __HRM_RIGHT__,
              __SYML_L3__, __EMPTY7__,
              __SYML_LT__, __EMPTY5__
	            ),
[L_SYMR] = LAYOUT_wrapper
             (__EMPTY7__, __SYMR_R1__,
              __HRM_LEFT__, __EMPTY2__, __SYMR_R2__,
              __EMPTY7__, __SYMR_R3__,
              __EMPTY5__,   __SYMR_RT__
	            ),
[L_NUM] = LAYOUT_wrapper
            (__NUM_L1__, __EMPTY7__,
             __NUM_L2__, __EMPTY2__, __HRM_RIGHT__,
             __NUM_L3__,__EMPTY7__,
             __NUM_LT__, __EMPTY5__
	           ),
[L_NAV] = LAYOUT_wrapper
            (__EMPTY7__,__NAV_R1__,
             __HRM_LEFT__, __EMPTY2__, __NAV_R2__,
             __EMPTY7__, __NAV_R3__,
             __EMPTY5__, __NAV_RT__
	           ),
[L_FNMOUSE] = LAYOUT_wrapper
                (__FNMOUSE_L1__, __EMPTY2__, __FNMOUSE_R1__,
                 __FNMOUSE_L2__, __EMPTY2__, __FNMOUSE_R2__,
                 __FNMOUSE_L3__, __EMPTY2__, __FNMOUSE_R3__,
                 __FNMOUSE_LT__, __EMPTY2__, __FNMOUSE_RT__
	               ),
[L_SYSMEDIA] = LAYOUT_wrapper
                 (__SYSMEDIA_L1__, __EMPTY2__, __SYSMEDIA_R1__,
                  __SYSMEDIA_L2__, __EMPTY2__, __SYSMEDIA_R2__,
                  __SYSMEDIA_L3__, __EMPTY2__, __SYSMEDIA_R3__,
                  __SYSMEDIA_LT__,  __EMPTY2__, __SYSMEDIA_RT__
	                ),
/* [L_NUMBERS] = LAYOUT_wrapper */
/*                 (__NUMBERS_L1__, __EMPTY2__, __NUMBERS_R1__, */
/*                  __NUMBERS_L2__, __EMPTY2__, __NUMBERS_R2__, */
/*                  __NUMBERS_L3__, __EMPTY2__, __NUMBERS_R3__, */
/*                  __NUMBERS_LT__,  __EMPTY2__, __NUMBERS_RT__ */
/* 	               ), */
[L_ONEHAND] = LAYOUT_wrapper
                (__ONEHAND_L1__, __EMPTY2__, __ONEHAND_R1__,
                 __ONEHAND_L2__, __EMPTY2__, __ONEHAND_R2__,
                 __ONEHAND_L3__, __EMPTY2__, __ONEHAND_R3__,
                 __ONEHAND_LT__,  __EMPTY2__, __ONEHAND_RT__
	               ),
};

// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    torn_set_led(0, IS_LAYER_ON_STATE(state, L_ONEHAND));
    /* torn_set_led(1, IS_LAYER_ON_STATE(state, L_NUMBERS)); */
    return state;
}
