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
    ST_MACRO_RAR,
    ST_MACRO_RAR_N,
    ST_MACRO_LANG,
    ST_MACRO_ZOOMIN,
    ST_MACRO_ZOOMOUT,
    ST_MACRO_ZOOM_RESET,
    ST_MACRO_QR,
    ST_MACRO_UNDO,
    ST_MACRO_GOTO,
    ST_MACRO_SAVE_FILE,
    ST_MACRO_JOIN_LINE,
    ST_MACRO_KILL_BUF,
    ST_MACRO_MARK_BUF,
    ST_MACRO_OPEN_FILE,
    ST_MACRO_SWITCH_BUF,
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
#define __NUMNAV_RT__ KC_EQUAL,           ST_MACRO_RAR,   _______

#define __NUMNAV_L1__ KC_WWW_FORWARD,     KC_PGUP,        KC_UP,          KC_PGDN,        ST_MACRO_ZOOM_RESET
#define __NUMNAV_L2__ KC_WWW_BACK,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       ST_MACRO_ZOOMIN
#define __NUMNAV_L3__ KC_WWW_HOME,        KC_HOME,        KC_APP,         KC_END,         ST_MACRO_ZOOMOUT
#define __NUMNAV_LT__ __EMPTY3__

#define __FNMOUSE_R1__ KC_F12,            KC_F7,          KC_F8,          KC_F9,          DM_RSTP
#define __FNMOUSE_R2__ KC_F11,            KC_F4,          KC_F5,          KC_F6,          DM_REC2
#define __FNMOUSE_R3__ KC_F10,            KC_F1,          KC_F2,          KC_F3,          DM_REC1
#define __FNMOUSE_RT__ DM_PLY1,           DM_PLY1,        _______

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

#define __ONEHAND_L1__ KC_WWW_FORWARD, KC_HOME, KC_WH_U, KC_END,  ST_MACRO_ZOOMOUT
#define __ONEHAND_L2__ KC_WWW_BACK,    KC_BTN3, KC_BTN2, KC_BTN1, ST_MACRO_ZOOMIN
#define __ONEHAND_L3__ KC_WWW_HOME,    KC_PGUP, KC_WH_D, KC_PGDN, ST_MACRO_ZOOM_RESET
#define __ONEHAND_LT__ __EMPTY3__

#define __AUTOMOUSE_R1__ KC_NO,                KC_NO,    KC_NO,    KC_NO,    KC_WWW_FORWARD
#define __AUTOMOUSE_R2__ LCTL(LSFT(KC_EQUAL)), KC_MS_BTN1, SCRL_MO,    KC_MS_BTN2, KC_WWW_BACK
#define __AUTOMOUSE_R3__ LCTL(KC_MINUS),       KC_END,     KC_MS_BTN3, KC_HOME,    LCTL(KC_0)
#define __AUTOMOUSE_RT__ KC_NO,                KC_NO,      KC_NO

#define __AUTOMOUSE_L1__ KC_WWW_FORWARD,       KC_NO,    KC_NO,    KC_NO,    KC_NO
#define __AUTOMOUSE_L2__ KC_WWW_BACK,          KC_MS_BTN2, SCRL_MO,    KC_MS_BTN1, LCTL(LSFT(KC_EQUAL))
#define __AUTOMOUSE_L3__ LCTL(KC_0),           KC_HOME,    KC_MS_BTN3, KC_END,     LCTL(KC_MINUS)
#define __AUTOMOUSE_LT__ KC_NO,                KC_NO,      KC_NO

// clang-format on
