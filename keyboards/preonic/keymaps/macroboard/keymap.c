/* Copyright 2015-2017 Jack Humbert
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

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _MACRO
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* MACRO
 * ,-----------------------------------------------------------------------------------.
 * |   A  |   B  |   C  |   D  |   E  |   F  |   G  |   H  |   I  |   J  |   K  |   L  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  M   |   N  |   O  |   P  |   Q  |   R  |   S  |   T  |   U  |   V  |   W  |   X  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Y   |   Z  |   0  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |  9   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  N0  |  N1  |  N2  |  N3  |  N4  |  N5  |  N6  |  N7  |  N8  |  N9  |  N+  |  N-  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * `-----------------------------------------------------------------------------------' b & j gehen nicht
 */
[_MACRO] = LAYOUT_preonic_grid( \
  KC_A,     KC_B,     KC_C,     KC_D,     KC_E,     KC_F,     KC_G,     KC_H,     KC_I,     KC_J,     KC_K,        KC_L, \
  KC_M,     KC_N,     KC_O,     KC_P,     KC_Q,     KC_R,     KC_S,     KC_T,     KC_U,     KC_V,     KC_W,        KC_X, \
  KC_Y,     KC_Z,     KC_0,     KC_1,     KC_2,     KC_3,     KC_7,     KC_5,     KC_6,     KC_7,     KC_8,        KC_9, \
  KC_KP_0,  KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_KP_4,  KC_KP_5,  KC_KP_6,  KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_KP_PLUS,  KC_KP_MINUS,  \
  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,      KC_F12  \
)
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint8_t f20_tracker;
    switch (keycode) {
    case KC_A ... KC_F19: //notice how it skips over F22
    case KC_F21 ... KC_EXSEL: //exsel is the last one before the modifier keys
        if (record->event.pressed) {
            register_code(KC_F20); //this means to send F22 down
            f20_tracker++;
            register_code(keycode);
        } else {
            unregister_code(keycode);
            f20_tracker--;
            if (!f20_tracker) {
                unregister_code(KC_F20); //this means to send F22 up
            }
            //real key is released HERE. i wish it would happen BEFORE F22 up occurs.
        }
        return false;
        break;
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}