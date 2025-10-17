#include "custom_process.h"

bool            sw_app_active = false;
bool            sw_win_active = false;
static uint16_t sticky_timer  = 0;

void sticky_shift_lt(const uint16_t layer, keyrecord_t *record) {
    if (record->event.pressed) {
        sticky_timer = timer_read();
        layer_on(layer); // momentary activate layer while holding
    } else {
        layer_off(layer); // deactivate layer when released
        if (timer_elapsed(sticky_timer) < TAPPING_TERM) {
            set_oneshot_mods(MOD_BIT(KC_LSFT)); // Tap: sticky shift
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!update_swapper(&sw_app_active, KC_LGUI, KC_TAB, SW_APP, keycode, record)) return false; // has update, stop process
    if (!update_swapper(&sw_win_active, KC_LALT, KC_TAB, SW_WIN, keycode, record)) return false; // has update, stop process
    if (!process_record_num_word(NUMWORD, L_NUMBERS, keycode, record)) return false;

    switch (keycode) {
        case ST_MACRO_HOME_DIR:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_GRAVE)) SS_DELAY(MACRO_DELAY) SS_TAP(X_SLASH));
            }
            break;
        case ST_MACRO_PAREN_DIR:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_DOT) SS_DELAY(MACRO_DELAY) SS_TAP(X_DOT) SS_DELAY(MACRO_DELAY) SS_TAP(X_SLASH));
            }
            break;
        case STICKY_SHIFT_L_NUM:
            sticky_shift_lt(L_NUM, record);
            return false; // prevent further processing
        case STICKY_SHIFT_L_NAV:
            sticky_shift_lt(L_NAV, record);
            return false;
    }
    return true;
}
