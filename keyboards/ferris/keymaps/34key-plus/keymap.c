/* #include "alias.h" */
#include "custom_process.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#define L_ONEHAND L_LAST

/*
  ferris sweep on each side: 5 5 5 2
  l1 r1
  l2 r2
  l3 r3
  lt rt
 */

// clang-format off

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
  LAYOUT_wrapper(
                 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
                 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
	               'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
	               'L', 'L', 'R', 'R'
	               );

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [L_BASE] = LAYOUT_wrapper
               (__BASE_L1__, __BASE_R1__,
	              __BASE_L2__, __BASE_R2__,
                __BASE_L3__, __BASE_R3__,
                LT(L_NAV, KC_BSPC), LT(L_SYMR, KC_ENTER), LT(L_SYML, KC_SPACE), LT(L_NUM, KC_TAB)
	              ),
  [L_SYML] = LAYOUT_wrapper
               (__SYML_L1__, __EMPTY5__,
                __SYML_L2__, __HRM_RIGHT__,
                __SYML_L3__, __EMPTY5__,
                KC_DEL,  KC_ESC, __EMPTY2__
	              ),
  [L_SYMR] = LAYOUT_wrapper
               (__EMPTY5__, __SYMR_R1__,
                __HRM_LEFT__, __SYMR_R2__,
                __EMPTY5__, __SYMR_R3__,
                __EMPTY4__
	              ),
  [L_NUM] = LAYOUT_wrapper
              (__NUM_L1__, __EMPTY5__,
               __NUM_L2__, __HRM_RIGHT__,
               __NUM_L3__, __EMPTY5__,
               _______,  LAR, __EMPTY2__
	             ),
  [L_NAV] = LAYOUT_wrapper
              (__EMPTY5__,__NAV_R1__,
               __HRM_LEFT__, __NAV_R2__,
               __EMPTY5__, __NAV_R3__,
               __EMPTY4__
	             ),
  [L_FNMOUSE] = LAYOUT_wrapper
                  (__FNMOUSE_L1__, __FNMOUSE_R1__,
                   __FNMOUSE_L2__, __FNMOUSE_R2__,
                   __FNMOUSE_L3__, __FNMOUSE_R3__,
                   DM_PLY1, DM_PLY2, __EMPTY2__
	                 ),
  [L_SYSMEDIA] = LAYOUT_wrapper
                   (__SYSMEDIA_L1__, __SYSMEDIA_R1__,
                    __SYSMEDIA_L2__, __SYSMEDIA_R2__,
                    __SYSMEDIA_L3__, __SYSMEDIA_R3__,
                    KC_CAPS, QK_BOOT, QK_BOOT, KC_SYRQ
	                  ),
  /* [L_NUMBERS] = LAYOUT_wrapper */
  /*                 (__NUMBERS_L1__, __NUMBERS_R1__, */
  /*                  __NUMBERS_L2__, __NUMBERS_R2__, */
  /*                  __NUMBERS_L3__, __NUMBERS_R3__, */
  /*                  __EMPTY4__ */
	/*                  ), */
  [L_ONEHAND] = LAYOUT_wrapper
                  (__ONEHAND_L1__, __ONEHAND_R1__,
                   __ONEHAND_L2__, __ONEHAND_R2__,
                   __ONEHAND_L3__, __ONEHAND_R3__,
                   _______, KC_NO, __EMPTY2__
	                 ),
};
