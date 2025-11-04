#pragma once

#include QMK_KEYBOARD_H

#include "36key.h"
#include "swapper.h"
#include "num_word.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record);

#if 1
void process_combo_event(uint16_t combo_index, bool pressed);
#endif
