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

#include "alias.h"
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
             (
              _______, __BASE_1__, _______,
	            SW_APP,  __BASE_2__, SW_WIN,
              _______, __BASE_3__, _______,
              MS_BTN1, __BASE_T__, QK_REP
	            ),
[L_SYMR] = LAYOUT_wrapper
             (_______, __SYMR_1__, _______,
              _______, __SYMR_2__, _______,
              _______, __SYMR_3__, _______,
              _______, __SYMR_T__, _______
	            ),
[L_SYML] = LAYOUT_wrapper
             (_______, __SYML_1__, _______,
              _______, __SYML_2__, _______,
              _______, __SYML_3__, _______,
              _______, __SYML_T__, _______
	            ),
[L_NUM] = LAYOUT_wrapper
            (_______, __NUM_1__, _______,
             _______, __NUM_2__, _______,
             _______, __NUM_3__, _______,
             _______, __NUM_T__, _______
	           ),
[L_NAV] = LAYOUT_wrapper
            (_______, __NAV_1__, _______,
             _______, __NAV_2__, _______,
             _______, __NAV_3__, _______,
             _______, __NAV_T__, _______
	           ),
[L_FNMAC] = LAYOUT_wrapper
              (_______, __FNMAC_1__, _______,
               _______, __FNMAC_2__, _______,
               _______, __FNMAC_3__, _______,
               _______, __FNMAC_T__, _______
	             ),
[L_MOUSE] = LAYOUT_wrapper
              (_______, __MOUSE_1__, _______,
               _______, __MOUSE_2__, _______,
               _______, __MOUSE_3__, _______,
               _______, __MOUSE_T__, _______
	             ),
[L_SYSMEDIA] = LAYOUT_wrapper
                 (_______, __SYSMEDIA_1__, _______,
                  _______, __SYSMEDIA_2__, _______,
                  _______, __SYSMEDIA_3__, _______,
                  _______, __SYSMEDIA_T__, _______
	                ),
[L_NUMBERS] = LAYOUT_wrapper
                (_______, __NUMBERS_1__, _______,
                 _______, __NUMBERS_2__, _______,
                 _______, __NUMBERS_3__, _______,
                 _______, __NUMBERS_T__, _______
	               ),
[L_ONEHAND] = LAYOUT_wrapper
                (_______, __ONEHAND_1__, _______,
                 _______, __ONEHAND_2__, _______,
                 _______, __ONEHAND_3__, _______,
                 _______, __ONEHAND_T__, _______
	               ),
};

// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    torn_set_led(0, IS_LAYER_ON_STATE(state, L_ONEHAND));
    torn_set_led(1, IS_LAYER_ON_STATE(state, L_NUMBERS));
    return state;
}
