#pragma once

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "version.h"

#define MACRO_DELAY 20

enum custom_keycodes {
    SW_APP = SAFE_RANGE,  // Switch to next window         (alt-tab)
    SW_WIN,
    NUMWORD,
    ST_MACRO_HOME_DIR,
    ST_MACRO_PAREN_DIR,
    STICKY_SHIFT_L_NUM,
    STICKY_SHIFT_L_NAV,
};

enum layers {
    L_BASE = 0,
    L_SYML,
    L_SYMR,
    L_NUM,
    L_NAV,
    L_FNMOUSE,
    L_SYSMEDIA,
    L_NUMBERS,
    L_LAST
};

#if 1
enum combos_events {
    CV_SW_APP = 0,
    MC_SW_WIN,
    COMBO_LENGTH,
};
extern combo_t key_combos[COMBO_LENGTH];
#endif

//clang-format off

#define ZOOM_IN RCS(KC_EQUAL)
#define ZOOM_OUT RCTL(KC_MINUS)
#define ZOOM_RESET RCTL(KC_0)
#define LAR LALT(KC_R)

#define __EMPTY2__ _______, _______
#define __EMPTY3__ __EMPTY2__, _______
#define __EMPTY4__ __EMPTY3__, _______
#define __EMPTY5__ __EMPTY4__, _______
#define __EMPTY6__ __EMPTY5__, _______
#define __EMPTY7__ __EMPTY6__, _______
#define __EMPTY8__ __EMPTY7__, _______
#define __EMPTY9__ __EMPTY8__, _______
#define __EMPTY10__ __EMPTY5__, __EMPTY5__
#define __EMPTY12__ __EMPTY10__, _______, _______
#define __EMPTY14__ __EMPTY12__, _______, _______

#define __HRM_LEFT__ KC_LSFT, KC_LALT, KC_LCTL, LALT(LCTL(KC_NO)), KC_LGUI
#define __HRM_RIGHT__ KC_RGUI, RALT(RCTL(KC_NO)), KC_RCTL, KC_RALT, KC_RSFT

// naming: layer_side_row. e.g. BASE_L1
#define __BASE_L1__ KC_Q,               LSA_T(KC_W),          LT(L_FNMOUSE, KC_E), MT(MOD_LCTL|MOD_LSFT, KC_R), LT(L_SYSMEDIA, KC_T)
#define __BASE_L2__ MT(MOD_LSFT, KC_A), MT(MOD_LALT, KC_S),   MT(MOD_LCTL, KC_D),  LCA_T(KC_F),                 MT(MOD_LGUI,KC_G)
#define __BASE_L3__ KC_Z,               KC_X,                 KC_C,                KC_V,                        KC_B
#define __BASE_LT__ LT(L_NAV, KC_BSPC), LT(L_SYMR, KC_ENTER), KC_BSPC

#define __BASE_R1__ LT(L_SYSMEDIA, KC_Y), RCS_T(KC_U),                LT(L_FNMOUSE, KC_I),       RSA_T(KC_O),        KC_P
#define __BASE_R2__ MT(MOD_RGUI, KC_H),   MT(MOD_RCTL|MOD_RALT,KC_J), MT(MOD_RCTL, KC_K),        MT(MOD_RALT, KC_L), MT(MOD_RSFT, KC_SCLN)
#define __BASE_R3__ KC_N,                 KC_M,                       KC_COMMA,                  KC_DOT,             KC_SLASH
#define __BASE_RT__ KC_TAB,               LT(L_SYML, KC_SPACE),       LT(L_NUM, KC_TAB)

#define __TO_LAST__ _______, _______, TO(L_LAST), _______, _______

#define __SYML_L1__ KC_AT,             KC_LABK,        KC_RABK,        KC_HASH,        KC_PERC
#define __SYML_L2__ KC_EXLM,           KC_MINUS,       KC_PLUS,        KC_EQUAL,       KC_DQUO
#define __SYML_L3__ ST_MACRO_HOME_DIR, KC_BSLS,        KC_ASTR,        KC_QUOTE,       KC_QUES
#define __SYML_LT__ KC_DEL,            CW_TOGG,        KC_DEL

#define __SYMR_R1__ KC_PIPE,           KC_COLN,        KC_LCBR,        KC_RCBR,        KC_GRAVE
#define __SYMR_R2__ KC_AMPR,           KC_UNDS,        KC_LPRN,        KC_RPRN,        KC_CIRC
#define __SYMR_R3__ KC_TILD,           KC_DLR,         KC_LBRC,        KC_RBRC,        ST_MACRO_PAREN_DIR
#define __SYMR_RT__ _______,           KC_ESCAPE,      _______

#define __NUM_L1__ KC_ASTR,  KC_9, KC_8, KC_7, KC_PLUS
#define __NUM_L2__ KC_DOT,   KC_6, KC_5, KC_4, KC_MINUS
#define __NUM_L3__ KC_SLASH, KC_3, KC_2, KC_1, KC_0
#define __NUM_LT__ NUMWORD,  LAR,  _______

#define __NAV_R1__ ZOOM_OUT,   ZOOM_IN,     KC_END, KC_HOME,        KC_WWW_FORWARD
#define __NAV_R2__ KC_LEFT,    KC_DOWN,     KC_UP,  KC_RIGHT,       KC_WWW_BACK
#define __NAV_R3__ __EMPTY4__, KC_WWW_HOME
#define __NAV_RT__ _______,    KC_PGDN,     KC_PGUP

#define __FNMOUSE_L1__ DM_RSTP, KC_F9,   KC_F8,  KC_F7, KC_F12
#define __FNMOUSE_L2__ DM_REC2, KC_F6,   KC_F5,  KC_F4, KC_F11
#define __FNMOUSE_L3__ DM_REC1, KC_F3,   KC_F2,  KC_F1, KC_F10
#define __FNMOUSE_LT__ DM_PLY1, DM_PLY2, _______

#define __FNMOUSE_R1__ _______,       KC_MS_BTN2,    KC_MS_BTN1,  KC_MS_BTN3,     _______
#define __FNMOUSE_R2__ KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_UP,    KC_MS_RIGHT,    _______
#define __FNMOUSE_R3__ KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, _______
#define __FNMOUSE_RT__ __EMPTY3__

#define __SYSMEDIA_L1__ __EMPTY5__
#define __SYSMEDIA_L2__ __EMPTY5__
#define __SYSMEDIA_L3__ __EMPTY5__
#define __SYSMEDIA_LT__ _______, KC_CAPS, QK_BOOT

#define __SYSMEDIA_R1__ KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_STOP,   KC_MEDIA_NEXT_TRACK, _______
#define __SYSMEDIA_R2__ _______,             KC_AUDIO_VOL_DOWN,   KC_AUDIO_VOL_UP, KC_AUDIO_MUTE,       _______
#define __SYSMEDIA_R3__ _______,             _______,             KC_SYSTEM_SLEEP, KC_PWR,              _______
#define __SYSMEDIA_RT__ QK_BOOT, KC_SYRQ, _______

#define __NUMBERS_L1__ __NUM_L1__
#define __NUMBERS_L2__ __NUM_L2__
#define __NUMBERS_L3__ __NUM_L3__
#define __NUMBERS_LT__ __EMPTY3__

#define __NUMBERS_R1__ __EMPTY5__
#define __NUMBERS_R2__ __EMPTY5__
#define __NUMBERS_R3__ __EMPTY5__
#define __NUMBERS_RT__ __EMPTY3__

#define __ONEHAND_L1__ KC_WWW_FORWARD, KC_PGUP, KC_WH_U, KC_PGDN,  ZOOM_RESET
#define __ONEHAND_L2__ KC_WWW_BACK,    KC_BTN3, KC_BTN2, KC_BTN1, ZOOM_IN
#define __ONEHAND_L3__ KC_WWW_HOME,    KC_HOME, KC_WH_D, KC_END, ZOOM_OUT
#define __ONEHAND_LT__ TO(L_BASE),     _______, _______

#define __ONEHAND_R1__ __EMPTY5__
#define __ONEHAND_R2__ __EMPTY5__
#define __ONEHAND_R3__ __EMPTY5__
#define __ONEHAND_RT__ __EMPTY3__

#define __AUTOMOUSE_L1__ KC_WWW_FORWARD, KC_NO,      KC_NO,      KC_NO,      KC_NO
#define __AUTOMOUSE_L2__ KC_WWW_BACK,    KC_MS_BTN2, SCRL_MO,    KC_MS_BTN1, ZOOM_IN
#define __AUTOMOUSE_L3__ ZOOM_RESET,     KC_HOME,    KC_MS_BTN3, KC_END,     ZOOM_OUT
#define __AUTOMOUSE_LT__ TO(L_BASE),     KC_NO,      KC_NO

#define __AUTOMOUSE_R1__ KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_WWW_FORWARD
#define __AUTOMOUSE_R2__ ZOOM_IN,        KC_MS_BTN1, SCRL_MO,    KC_MS_BTN2, KC_WWW_BACK
#define __AUTOMOUSE_R3__ ZOOM_OUT,       KC_END,     KC_MS_BTN3, KC_HOME,    ZOOM_RESET
#define __AUTOMOUSE_RT__ KC_NO,          KC_NO,      KC_NO

// clang-format on
