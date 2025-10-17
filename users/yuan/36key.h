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
    L_SYMR,
    L_SYML,
    L_NUM,
    L_NAV,
    L_FNMAC,
    L_MOUSE,
    L_SYSMEDIA,
    L_NUMBERS,
    L_LAST
};

//clang-format off

#define ZOOM_IN RCS(KC_EQUAL)
#define ZOOM_OUT RCTL(KC_MINUS)
#define ZOOM_RESET RCTL(KC_0)
#define LAR LALT(KC_R)

#define __EMPTY5__ _______, _______, _______, _______, _______
#define __EMPTY3__ _______, _______, _______
#define __HRM_LEFT__ KC_LGUI, KC_LALT, KC_LCTL, LALT(LCTL(KC_NO)), KC_LSFT
#define __HRM_RIGHT__ KC_RSFT, RALT(RCTL(KC_NO)), KC_RCTL, KC_RALT, KC_RGUI

// naming: layer_side_row. e.g. BASE_L1
#define __BASE_R1__ LT(7,KC_Y),         KC_U,                       RCS_T(KC_I),          RSA_T(KC_O),         KC_P
#define __BASE_R2__ MT(MOD_RSFT, KC_H), MT(MOD_RCTL|MOD_RALT,KC_J), MT(MOD_RCTL, KC_K),   MT(MOD_RALT, KC_L),  MT(MOD_RGUI, KC_SCLN)
#define __BASE_R3__ KC_N,               KC_M,                       MT(MOD_MEH,KC_COMMA), MT(MOD_HYPR,KC_DOT), KC_SLASH
#define __BASE_RT__ LT(6, KC_TAB),      LT(2, KC_SPACE),            STICKY_SHIFT_L_NAV

#define __BASE_L1__ KC_Q,               LSA_T(KC_W),        MT(MOD_LCTL|MOD_LSFT, KC_E), KC_R,        LT(7,KC_T)
#define __BASE_L2__ MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LCTL, KC_D),          LCA_T(KC_F), MT(MOD_LSFT,KC_G)
#define __BASE_L3__ KC_Z,               MT(MOD_HYPR,KC_X),  MT(MOD_MEH,KC_C),            KC_V,        KC_B
#define __BASE_LT__ STICKY_SHIFT_L_NUM, LT(1, KC_ENTER),    LT(5,KC_BSPC)

#define __SYMBOLS_R1__ KC_PIPE,           KC_COLN,        KC_LCBR,        KC_RCBR,        KC_GRAVE
#define __SYMBOLS_R2__ KC_AMPR,           KC_UNDS,        KC_LPRN,        KC_RPRN,        KC_CIRC
#define __SYMBOLS_R3__ KC_TILD,           KC_DLR,         KC_LBRC,        KC_RBRC,        ST_MACRO_PAREN_DIR
#define __SYMBOLS_RT__ KC_ESCAPE,         NUMWORD,        _______

#define __SYMBOLS_L1__ KC_AT,             KC_LABK,        KC_RABK,        KC_HASH,        KC_PERC
#define __SYMBOLS_L2__ KC_EXLM,           KC_MINUS,       KC_PLUS,        KC_EQUAL,       KC_DQUO
#define __SYMBOLS_L3__ ST_MACRO_HOME_DIR, KC_BSLS,        KC_ASTR,        KC_QUOTE,       KC_QUES
#define __SYMBOLS_LT__ _______,           CW_TOGG,        KC_DEL

#define __NUMNAV_R1__ KC_PLUS,            KC_7,           KC_8,           KC_9,           KC_ASTR
#define __NUMNAV_R2__ KC_MINUS,           KC_4,           KC_5,           KC_6,           KC_DOT
#define __NUMNAV_R3__ KC_0,               KC_1,           KC_2,           KC_3,           KC_SLASH
#define __NUMNAV_RT__ KC_EQUAL,           LAR,   _______

#define __NUMNAV_L1__ KC_WWW_FORWARD,     KC_PGUP,        KC_UP,          KC_PGDN,        ZOOM_RESET
#define __NUMNAV_L2__ KC_WWW_BACK,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       ZOOM_IN
#define __NUMNAV_L3__ KC_WWW_HOME,        KC_HOME,        KC_APP,         KC_END,         ZOOM_OUT
#define __NUMNAV_LT__ __EMPTY3__

#define __FNMOUSE_R1__ KC_F12,            KC_F7,          KC_F8,          KC_F9,          DM_RSTP
#define __FNMOUSE_R2__ KC_F11,            KC_F4,          KC_F5,          KC_F6,          DM_REC2
#define __FNMOUSE_R3__ KC_F10,            KC_F1,          KC_F2,          KC_F3,          DM_REC1
#define __FNMOUSE_RT__ DM_PLY1,           DM_PLY2,        _______

#define __FNMOUSE_L1__ _______,           KC_MS_WH_UP,    KC_MS_UP,       KC_MS_WH_DOWN,  _______
#define __FNMOUSE_L2__ KC_MS_WH_LEFT,     KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_RIGHT
#define __FNMOUSE_L3__ _______,           KC_MS_BTN3,     KC_MS_BTN2,     KC_MS_BTN1,     _______
#define __FNMOUSE_LT__ __EMPTY3__

#define __SYSMEDIA_R1__ __EMPTY5__
#define __SYSMEDIA_R2__ __EMPTY5__
#define __SYSMEDIA_R3__ __EMPTY5__
#define __SYSMEDIA_RT__ QK_BOOT, KC_SYRQ, _______

#define __SYSMEDIA_L1__ _______, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_UP,    KC_MEDIA_NEXT_TRACK, KC_SYSTEM_SLEEP
#define __SYSMEDIA_L2__ _______, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_VOL_DOWN,  KC_MEDIA_STOP,       KC_PWR
#define __SYSMEDIA_L3__ _______, KC_WWW_FAVORITES,    KC_AUDIO_MUTE,      KC_MY_COMPUTER,      _______
#define __SYSMEDIA_LT__ _______, KC_CAPS, QK_BOOT

#define __NUMBERS_R1__ __NUMNAV_R1__
#define __NUMBERS_R2__ __NUMNAV_R2__
#define __NUMBERS_R3__ __NUMNAV_R3__
#define __NUMBERS_RT__ KC_EQUAL, _______, _______

#define __NUMBERS_L1__ __EMPTY5__
#define __NUMBERS_L2__ __EMPTY5__
#define __NUMBERS_L3__ __EMPTY5__
#define __NUMBERS_LT__ __EMPTY3__

#define __ONEHAND_R1__ __EMPTY5__
#define __ONEHAND_R2__ __EMPTY5__
#define __ONEHAND_R3__ __EMPTY5__
#define __ONEHAND_RT__ __EMPTY3__

#define __ONEHAND_L1__ KC_WWW_FORWARD, KC_HOME, KC_WH_U, KC_END,  ZOOM_OUT
#define __ONEHAND_L2__ KC_WWW_BACK,    KC_BTN3, KC_BTN2, KC_BTN1, ZOOM_IN
#define __ONEHAND_L3__ KC_WWW_HOME,    KC_PGUP, KC_WH_D, KC_PGDN, ZOOM_RESET
#define __ONEHAND_LT__ __EMPTY3__

#define __AUTOMOUSE_R1__ KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_WWW_FORWARD
#define __AUTOMOUSE_R2__ ZOOM_IN,        KC_MS_BTN1, SCRL_MO,    KC_MS_BTN2, KC_WWW_BACK
#define __AUTOMOUSE_R3__ ZOOM_OUT,       KC_END,     KC_MS_BTN3, KC_HOME,    ZOOM_RESET
#define __AUTOMOUSE_RT__ KC_NO,          KC_NO,      KC_NO

#define __AUTOMOUSE_L1__ KC_WWW_FORWARD, KC_NO,      KC_NO,      KC_NO,      KC_NO
#define __AUTOMOUSE_L2__ KC_WWW_BACK,    KC_MS_BTN2, SCRL_MO,    KC_MS_BTN1, ZOOM_IN
#define __AUTOMOUSE_L3__ ZOOM_RESET,     KC_HOME,    KC_MS_BTN3, KC_END,     ZOOM_OUT
#define __AUTOMOUSE_LT__ KC_NO,          KC_NO,      KC_NO

// 3*5+3
#define __BASE_1__ __BASE_L1__, __BASE_R1__
#define __BASE_2__ __BASE_L2__, __BASE_R2__
#define __BASE_3__ __BASE_L3__, __BASE_R3__
#define __BASE_T__ __BASE_LT__, __BASE_RT__

#define __SYMR_1__ __EMPTY5__,   __SYMBOLS_R1__
#define __SYMR_2__ __HRM_LEFT__, __SYMBOLS_R2__
#define __SYMR_3__ __EMPTY5__,   __SYMBOLS_R3__
#define __SYMR_T__ __EMPTY3__,   __SYMBOLS_RT__

#define __SYML_1__ __SYMBOLS_L1__, __EMPTY5__
#define __SYML_2__ __SYMBOLS_L2__, __HRM_RIGHT__
#define __SYML_3__ __SYMBOLS_L3__, __EMPTY5__
#define __SYML_T__ __SYMBOLS_LT__, __EMPTY3__

#define __NUM_1__ __EMPTY5__,    __NUMNAV_R1__
#define __NUM_2__ __HRM_RIGHT__, __NUMNAV_R2__
#define __NUM_3__ __EMPTY5__,    __NUMNAV_R3__
#define __NUM_T__ __EMPTY3__,    __NUMNAV_RT__

#define __NAV_1__ __NUMNAV_L1__, __EMPTY5__
#define __NAV_2__ __NUMNAV_L2__, __HRM_RIGHT__
#define __NAV_3__ __NUMNAV_L3__, __EMPTY5__
#define __NAV_T__ __NUMNAV_LT__, __EMPTY3__

#define __FNMAC_1__ __EMPTY5__,   __FNMOUSE_R1__
#define __FNMAC_2__ __HRM_LEFT__, __FNMOUSE_R2__
#define __FNMAC_3__ __EMPTY5__,   __FNMOUSE_R3__
#define __FNMAC_T__ __EMPTY3__,   __FNMOUSE_RT__

#define __MOUSE_1__ __FNMOUSE_L1__, __EMPTY5__
#define __MOUSE_2__ __FNMOUSE_L2__, __HRM_LEFT__
#define __MOUSE_3__ __FNMOUSE_L3__, __EMPTY5__
#define __MOUSE_T__ __FNMOUSE_LT__, __EMPTY3__

#define __SYSMEDIA_1__ __SYSMEDIA_L1__, __SYSMEDIA_R1__
#define __SYSMEDIA_2__ __SYSMEDIA_L2__, __SYSMEDIA_R2__
#define __SYSMEDIA_3__ __SYSMEDIA_L3__, __SYSMEDIA_R3__
#define __SYSMEDIA_T__ __SYSMEDIA_LT__, __SYSMEDIA_RT__

#define __NUMBERS_1__ __NUMBERS_L1__, __NUMBERS_R1__
#define __NUMBERS_2__ __NUMBERS_L2__, __NUMBERS_R2__
#define __NUMBERS_3__ __NUMBERS_L3__, __NUMBERS_R3__
#define __NUMBERS_T__ __NUMBERS_LT__, __NUMBERS_RT__

#define __ONEHAND_1__ __ONEHAND_L1__, __ONEHAND_R1__
#define __ONEHAND_2__ __ONEHAND_L2__, __ONEHAND_R2__
#define __ONEHAND_3__ __ONEHAND_L3__, __ONEHAND_R3__
#define __ONEHAND_T__ __ONEHAND_LT__, __ONEHAND_RT__

#define __AUTOMOUSE_1__ __AUTOMOUSE_L1__, __AUTOMOUSE_R1__
#define __AUTOMOUSE_2__ __AUTOMOUSE_L2__, __AUTOMOUSE_R2__
#define __AUTOMOUSE_3__ __AUTOMOUSE_L3__, __AUTOMOUSE_R3__
#define __AUTOMOUSE_T__ __AUTOMOUSE_LT__, __AUTOMOUSE_RT__

// clang-format on
