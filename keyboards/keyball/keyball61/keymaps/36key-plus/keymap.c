/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "custom_process.h"

#define LAYOUT_wrapper(...)   LAYOUT_universal(__VA_ARGS__)

#define L_AUTOMOUSE L_LAST

/*
  keyball61 on each side: 6 6 6 7 7
  l1 r1
  l2 r2
  l3 r3
  l4 r4
  l5 r5
*/

// clang-format off

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_wrapper(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
	      'L', 'L', 'L', 'L', 'L', 'L',  'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
	      'L', 'L', 'L', 'L', 'L', 'L',  'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R'
	);

#define __BASE_L0__ KC_MS_BTN3,    KC_MS_BTN2,        KC_MS_BTN1,      ZOOM_IN,    ZOOM_OUT,   ZOOM_RESET
#define __BASE_R0__ KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, UG_TOGG,    UG_PREV,    UG_NEXT

#define __KB_BASE_3__ __BASE_L3__, _______, _______, __BASE_R3__

#define __KB_SYMR_3__ __EMPTY5__, _______, _______, __SYMBOLS_R3__
#define __KB_SYMR_T__ __EMPTY3__, __EMPTY3__,   __SYMBOLS_RT__, __EMPTY3__

#define __KB_SYML_3__ __SYMBOLS_L3__, _______, _______, __EMPTY5__
#define __KB_SYML_T__ __EMPTY3__, __SYMBOLS_LT__, __EMPTY3__, __EMPTY3__

#define __KB_NUM_3__ __EMPTY5__, _______, _______, __NUMNAV_R3__
#define __KB_NUM_T__ __EMPTY3__, __EMPTY3__,   __NUMNAV_RT__, __EMPTY3__

#define __KB_NAV_3__ __NUMNAV_L3__, _______, _______, __EMPTY5__
#define __KB_NAV_T__ __EMPTY3__, __NUMNAV_LT__, __EMPTY3__, __EMPTY3__

#define __KB_FNMAC_3__ __EMPTY5__, _______, _______, __FNMOUSE_R3__
#define __KB_FNMAC_T__ __EMPTY3__, __EMPTY3__,   __FNMOUSE_RT__, __EMPTY3__

#define __KB_MOUSE_3__ __FNMOUSE_L3__, _______, _______, __EMPTY5__
#define __KB_MOUSE_T__ __EMPTY3__, __FNMOUSE_LT__, __EMPTY3__, __EMPTY3__

#define __KB_SYSMEDIA_3__ __SYSMEDIA_L3__, _______, _______, __SYSMEDIA_R3__
#define __KB_SYSMEDIA_T__ __EMPTY3__, __SYSMEDIA_LT__, __SYSMEDIA_RT__, __EMPTY3__

#define __KB_NUMBERS_3__ __NUMBERS_L3__, _______, _______, __NUMBERS_R3__
#define __KB_NUMBERS_T__ __EMPTY3__, __NUMBERS_LT__, __NUMBERS_RT__, __EMPTY3__

#define __KB_AUTOMOUSE_3__ __AUTOMOUSE_L3__, _______, _______, __AUTOMOUSE_R3__
#define __KB_AUTOMOUSE_T__ __EMPTY3__, __AUTOMOUSE_LT__, __AUTOMOUSE_RT__, __EMPTY3__

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
              _______, __BASE_1__,     _______,
	            SW_APP,  __BASE_2__,     SW_WIN,
              _______, __KB_BASE_3__, _______,
              __EMPTY3__, MS_BTN1, __BASE_LT__, LT(4, KC_TAB),      LT(2, KC_SPACE), __EMPTY5__
	            ),
[L_SYMR] = LAYOUT_wrapper
             (__EMPTY12__,
              _______, __SYMR_1__,     _______,
              _______, __SYMR_2__,     _______,
              _______, __KB_SYMR_3__, _______,
              _______, __KB_SYMR_T__, _______
	            ),
[L_SYML] = LAYOUT_wrapper
             (__EMPTY12__,
              _______, __SYML_1__,     _______,
              _______, __SYML_2__,     _______,
              _______, __KB_SYML_3__, _______,
              _______, __KB_SYML_T__, _______
	            ),
[L_NUM] = LAYOUT_wrapper
             (__EMPTY12__,
              _______, __NUM_1__,     _______,
              _______, __NUM_2__,     _______,
              _______, __KB_NUM_3__, _______,
              _______, __KB_NUM_T__, _______
	            ),
[L_NAV] = LAYOUT_wrapper
             (__EMPTY12__,
              _______, __NAV_1__,     _______,
              _______, __NAV_2__,     _______,
              _______, __KB_NAV_3__, _______,
              _______, __KB_NAV_T__, _______
	            ),
[L_FNMAC] = LAYOUT_wrapper
             (__EMPTY12__,
              _______, __FNMAC_1__,     _______,
              _______, __FNMAC_2__,     _______,
              _______, __KB_FNMAC_3__, _______,
              _______, __KB_FNMAC_T__, _______
	            ),
[L_MOUSE] = LAYOUT_wrapper
             (__EMPTY12__,
              _______, __MOUSE_1__,     _______,
              _______, __MOUSE_2__,     _______,
              _______, __KB_MOUSE_3__, _______,
              _______, __KB_MOUSE_T__, _______
	            ),
[L_SYSMEDIA] = LAYOUT_wrapper
             (__EMPTY12__,
              _______, __SYSMEDIA_1__,     _______,
              _______, __SYSMEDIA_2__,     _______,
              _______, __KB_SYSMEDIA_3__, _______,
              _______, __KB_SYSMEDIA_T__, _______
	            ),
[L_NUMBERS] = LAYOUT_wrapper
             (__EMPTY12__,
              _______, __NUMBERS_1__,     _______,
              _______, __NUMBERS_2__,     _______,
              _______, __KB_NUMBERS_3__, _______,
              _______, __KB_NUMBERS_T__, _______
	            ),
[L_AUTOMOUSE] = LAYOUT_wrapper
             (__EMPTY12__,
              _______, __AUTOMOUSE_1__,     _______,
              _______, __AUTOMOUSE_2__,     _______,
              _______, __KB_AUTOMOUSE_3__, _______,
              _______, __KB_AUTOMOUSE_T__, _______
	            ),
};


#ifdef OLED_ENABLE
#    include "lib/oledkit/oledkit.h"
void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

#ifdef  POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_layer(L_AUTOMOUSE);
    // always required before the auto mouse feature will work
    set_auto_mouse_enable(true);
}
#endif
