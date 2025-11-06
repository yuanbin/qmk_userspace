#include "custom_process.h"

#if 1
const uint16_t PROGMEM combo_df[] = {HRM_D, HRM_F, COMBO_END};
const uint16_t PROGMEM combo_jk[] = {HRM_J, HRM_K, COMBO_END};
const uint16_t PROGMEM combo_cv[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_mc[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo_qw[] = {KC_Q, LSA_T(KC_W), COMBO_END};

combo_t key_combos[COMBO_LENGTH] = {
  [DF] = COMBO(combo_df, 0),
  [JK] = COMBO(combo_jk, 0),
  [CV] = COMBO(combo_cv, CW_TOGG),
  [MC] = COMBO(combo_mc, 0),
  [QW] = COMBO(combo_qw, KC_ESC),
};
#endif

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

bool process_combo_swapper(uint16_t keycode, keyrecord_t *record) {
  if (sw_app_active) {
    if (record->event.pressed) {
      switch (keycode) {
      case HRM_F:
        tap_code(KC_TAB);
        return false; // don't send "f"
      case HRM_D:
        register_code(KC_LSFT);
        tap_code(KC_TAB);
        unregister_code(KC_LSFT);
        return false;
      default:
        unregister_code(KC_LGUI);
        sw_app_active = false;
        return false;
      }
    }
  }
  if (sw_win_active) {
    if (record->event.pressed) {
      switch (keycode) {
      case HRM_K:
        tap_code(KC_TAB);
        return false;
      case HRM_J:
        register_code(KC_LSFT);
        tap_code(KC_TAB);
        unregister_code(KC_LSFT);
        return false;
      default:
        unregister_code(KC_LALT);
        sw_win_active = false;
        return false;
      }
    }
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_combo_swapper(keycode, record)) return false;
    /* if (!update_swapper(&sw_app_active, KC_LGUI, KC_TAB, SW_APP, keycode, record)) return false; // has update, stop process */
    /* if (!update_swapper(&sw_win_active, KC_LALT, KC_TAB, SW_WIN, keycode, record)) return false; // has update, stop process */
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

#if 1
void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case DF:
            if (pressed) {
                sw_app_active = true;
                register_code(KC_LGUI);
                tap_code(KC_TAB);
            }
            break;
        case JK:
            if (pressed) {
                sw_win_active = true;
                register_code(KC_LALT);
                tap_code(KC_TAB);
            }
            break;
        default:
            break;
    }
}
#endif
