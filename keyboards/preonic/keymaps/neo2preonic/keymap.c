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
#include "keymap_german.h"

enum preonic_layers {
  BASE,
  LeftM3,
  RightM3,
  LeftM4,
  RightM4,
  MOUSE
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

/* Keymap 00: default layer
 * Ascii-art generator: http://patorjk.com/software/taag/#p=display&f=Big&t=Mouse
 *      _           __                   _   _       _                               
 *     | |         / _|                 | | | |     | |                              
 *   __| |   ___  | |_    __ _   _   _  | | | |_    | |   __ _   _   _    ___   _ __ 
 *  / _` |  / _ \ |  _|  / _` | | | | | | | | __|   | |  / _` | | | | |  / _ \ | '__|
 * | (_| | |  __/ | |   | (_| | | |_| | | | | |_    | | | (_| | | |_| | |  __/ | |   
 *  \__,_|  \___| |_|    \__,_|  \__,_| |_|  \__|   |_|  \__,_|  \__, |  \___| |_|   
 *                                                                __/ |              
 *                                                               |___/                
 * 
 * ,-------------------------------------------------------------------------------------.
 * |  ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp  |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |CTL/Tab|   X  |   V  |   L  |   C  |   W  |   K  |   H  |   G  |   F  |   Q  | CTL/ß |
 * |-------+------+------+------+------+-------------+------+------+------+------+-------|
 * |  L3   |   U  |   I  |   A  |   E  |   O  |   S  |   N  |   R  |   T  |   D  | L3/Y  |
 * |-------+------+------+------+------+------|------+------+------+------+------+-------|
 * | LShift|   Ü  |   Ö  |   Ä  |   P  |   Z  |   B  |   M  |   ,  |   .  |   J  |RShift |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |   L4  | +#S  | GUI  | LALT |CtlBsp| MOUSE | LEAD |  SPC | L4 | GUI  | App  | Enter  |
 * `-------------------------------------------------------------------------------------'
 */
[BASE] = LAYOUT_preonic_grid( \
  KC_ESC              ,       KC_1,    KC_2,    KC_3,          KC_4,               KC_5,     KC_6,    KC_7,        KC_8,    KC_9,   KC_0,             KC_BSPC, \
  MT(MOD_LCTL, KC_TAB),       DE_X,    DE_V,    DE_L,          DE_C,               DE_W,     DE_K,    DE_H,        DE_G,    DE_F,   DE_Q, MT(MOD_RCTL, DE_SS),  \
  MO(LeftM3)          ,       DE_U,    DE_I,    DE_A,          DE_E,               DE_O,     DE_S,    DE_N,        DE_R,    DE_T,   DE_D,   LT(RightM3, DE_Y), \
  KC_LSFT             ,    DE_UDIA, DE_ODIA, DE_ADIA,          DE_P,               DE_Z,     DE_B,    DE_M,    KC_COMMA,  KC_DOT,   DE_J,             KC_RSFT,  \
  MO(LeftM4)          , G(S(DE_S)), KC_LGUI, KC_LALT, LCTL(KC_BSPC), LT(MOUSE, KC_TRNS), KC_LEAD, KC_SPACE, MO(RightM4), KC_RGUI, KC_APP,              KC_ENT  \
),

/* Keymap 00: default layer
 *  __  __               _   _    __   _                   ____      _        ______   ______   _______ 
 * |  \/  |             | | (_)  / _| (_)                 |___ \    | |      |  ____| |  ____| |__   __|
 * | \  / |   ___     __| |  _  | |_   _    ___   _ __      __) |   | |      | |__    | |__       | |   
 * | |\/| |  / _ \   / _` | | | |  _| | |  / _ \ | '__|    |__ <    | |      |  __|   |  __|      | |   
 * | |  | | | (_) | | (_| | | | | |   | | |  __/ | |       ___) |   | |____  | |____  | |         | |   
 * |_|  |_|  \___/   \__,_| |_| |_|   |_|  \___| |_|      |____/    |______| |______| |_|         |_|                     
 *                                                
 * 
 * ,-------------------------------------------------------------------------------------.
 * |  ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp  |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |CTL/Tab|   X  |   V  |   L  |   C  |   W  |   K  |   H  |   G  |   F  |   Q  | CTL/ß |
 * |-------+------+------+------+------+-------------+------+------+------+------+-------|
 * |  L3   |   U  |   I  |   A  |   E  |   O  |   S  |   N  |   R  |   T  |   D  | L3/Y  |
 * |-------+------+------+------+------+------|------+------+------+------+------+-------|
 * | LShift|   Ü  |   Ö  |   Ä  |   P  |   Z  |   B  |   M  |   ,  |   .  |   J  |RShift |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |   L4  | +#S  | GUI  | LALT |CtlBsp| MOUSE | LEAD |  SPC | L4 | GUI  | App  | Enter  |
 * `-------------------------------------------------------------------------------------'
 */
[LeftM3] = LAYOUT_preonic_grid( \
  KC_ESC              ,       KC_1,    KC_2,    KC_3,          KC_4,               KC_5,     KC_6,    KC_7,        KC_8,    KC_9,   KC_0,             KC_BSPC, \
  MT(MOD_LCTL, KC_TAB),       DE_X,    DE_V,    DE_L,          DE_C,               DE_W,     DE_K,    DE_H,        DE_G,    DE_F,   DE_Q, MT(MOD_RCTL, DE_SS),  \
  MO(LeftM3)          ,       DE_U,    DE_I,    DE_A,          DE_E,               DE_O,     DE_S,    DE_N,        DE_R,    DE_T,   DE_D,   LT(RightM3, DE_Y), \
  KC_LSFT             ,    DE_UDIA, DE_ODIA, DE_ADIA,          DE_P,               DE_Z,     DE_B,    DE_M,    KC_COMMA,  KC_DOT,   DE_J,             KC_RSFT,  \
  MO(LeftM4)          , G(S(DE_S)), KC_LGUI, KC_LALT, LCTL(KC_BSPC), LT(MOUSE, KC_TRNS), KC_LEAD, KC_SPACE, MO(RightM4), KC_RGUI, KC_APP,              KC_ENT  \
),

/* Keymap 00: default layer
 * Ascii-art generator: http://patorjk.com/software/taag/#p=display&f=Big&t=Mouse
 *  __  __               _   _    __   _                   ____      _____    _____    _____   _    _   _______ 
 * |  \/  |             | | (_)  / _| (_)                 |___ \    |  __ \  |_   _|  / ____| | |  | | |__   __|
 * | \  / |   ___     __| |  _  | |_   _    ___   _ __      __) |   | |__) |   | |   | |  __  | |__| |    | |   
 * | |\/| |  / _ \   / _` | | | |  _| | |  / _ \ | '__|    |__ <    |  _  /    | |   | | |_ | |  __  |    | |   
 * | |  | | | (_) | | (_| | | | | |   | | |  __/ | |       ___) |   | | \ \   _| |_  | |__| | | |  | |    | |   
 * |_|  |_|  \___/   \__,_| |_| |_|   |_|  \___| |_|      |____/    |_|  \_\ |_____|  \_____| |_|  |_|    |_|   
 *
 * ,-------------------------------------------------------------------------------------.
 * |  ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp  |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |CTL/Tab|   X  |   V  |   L  |   C  |   W  |   K  |   H  |   G  |   F  |   Q  | CTL/ß |
 * |-------+------+------+------+------+-------------+------+------+------+------+-------|
 * |  L3   |   U  |   I  |   A  |   E  |   O  |   S  |   N  |   R  |   T  |   D  | L3/Y  |
 * |-------+------+------+------+------+------|------+------+------+------+------+-------|
 * | LShift|   Ü  |   Ö  |   Ä  |   P  |   Z  |   B  |   M  |   ,  |   .  |   J  |RShift |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |   L4  | +#S  | GUI  | LALT |CtlBsp| MOUSE | LEAD |  SPC | L4 | GUI  | App  | Enter  |
 * `-------------------------------------------------------------------------------------'
 */
[RightM3] = LAYOUT_preonic_grid( \
  KC_ESC              ,       KC_1,    KC_2,    KC_3,          KC_4,               KC_5,     KC_6,    KC_7,        KC_8,    KC_9,   KC_0,             KC_BSPC, \
  MT(MOD_LCTL, KC_TAB),       DE_X,    DE_V,    DE_L,          DE_C,               DE_W,     DE_K,    DE_H,        DE_G,    DE_F,   DE_Q, MT(MOD_RCTL, DE_SS),  \
  MO(LeftM3)          ,       DE_U,    DE_I,    DE_A,          DE_E,               DE_O,     DE_S,    DE_N,        DE_R,    DE_T,   DE_D,   LT(RightM3, DE_Y), \
  KC_LSFT             ,    DE_UDIA, DE_ODIA, DE_ADIA,          DE_P,               DE_Z,     DE_B,    DE_M,    KC_COMMA,  KC_DOT,   DE_J,             KC_RSFT,  \
  MO(LeftM4)          , G(S(DE_S)), KC_LGUI, KC_LALT, LCTL(KC_BSPC), LT(MOUSE, KC_TRNS), KC_LEAD, KC_SPACE, MO(RightM4), KC_RGUI, KC_APP,              KC_ENT  \
),

/* Keymap 00: default layer
 * Ascii-art generator: http://patorjk.com/software/taag/#p=display&f=Big&t=Mouse
 *  __  __               _   _    __   _                   _  _       _        ______   ______   _______ 
 * |  \/  |             | | (_)  / _| (_)                 | || |     | |      |  ____| |  ____| |__   __|
 * | \  / |   ___     __| |  _  | |_   _    ___   _ __    | || |_    | |      | |__    | |__       | |   
 * | |\/| |  / _ \   / _` | | | |  _| | |  / _ \ | '__|   |__   _|   | |      |  __|   |  __|      | |   
 * | |  | | | (_) | | (_| | | | | |   | | |  __/ | |         | |     | |____  | |____  | |         | |   
 * |_|  |_|  \___/   \__,_| |_| |_|   |_|  \___| |_|         |_|     |______| |______| |_|         |_|   
 *
 * ,-------------------------------------------------------------------------------------.
 * |  ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp  |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |CTL/Tab|   X  |   V  |   L  |   C  |   W  |   K  |   H  |   G  |   F  |   Q  | CTL/ß |
 * |-------+------+------+------+------+-------------+------+------+------+------+-------|
 * |  L3   |   U  |   I  |   A  |   E  |   O  |   S  |   N  |   R  |   T  |   D  | L3/Y  |
 * |-------+------+------+------+------+------|------+------+------+------+------+-------|
 * | LShift|   Ü  |   Ö  |   Ä  |   P  |   Z  |   B  |   M  |   ,  |   .  |   J  |RShift |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |   L4  | +#S  | GUI  | LALT |CtlBsp| MOUSE | LEAD |  SPC | L4 | GUI  | App  | Enter  |
 * `-------------------------------------------------------------------------------------'
 */
[LeftM4] = LAYOUT_preonic_grid( \
  KC_ESC              ,       KC_1,    KC_2,    KC_3,          KC_4,               KC_5,     KC_6,    KC_7,        KC_8,    KC_9,   KC_0,             KC_BSPC, \
  MT(MOD_LCTL, KC_TAB),       DE_X,    DE_V,    DE_L,          DE_C,               DE_W,     DE_K,    DE_H,        DE_G,    DE_F,   DE_Q, MT(MOD_RCTL, DE_SS),  \
  MO(LeftM3)          ,       DE_U,    DE_I,    DE_A,          DE_E,               DE_O,     DE_S,    DE_N,        DE_R,    DE_T,   DE_D,   LT(RightM3, DE_Y), \
  KC_LSFT             ,    DE_UDIA, DE_ODIA, DE_ADIA,          DE_P,               DE_Z,     DE_B,    DE_M,    KC_COMMA,  KC_DOT,   DE_J,             KC_RSFT,  \
  MO(LeftM4)          , G(S(DE_S)), KC_LGUI, KC_LALT, LCTL(KC_BSPC), LT(MOUSE, KC_TRNS), KC_LEAD, KC_SPACE, MO(RightM4), KC_RGUI, KC_APP,              KC_ENT  \
),

/* Keymap 00: default layer
 * Ascii-art generator: http://patorjk.com/software/taag/#p=display&f=Big&t=Mouse
 *  __  __               _   _    __   _                   _  _       _____    _____    _____   _    _   _______ 
 * |  \/  |             | | (_)  / _| (_)                 | || |     |  __ \  |_   _|  / ____| | |  | | |__   __|
 * | \  / |   ___     __| |  _  | |_   _    ___   _ __    | || |_    | |__) |   | |   | |  __  | |__| |    | |   
 * | |\/| |  / _ \   / _` | | | |  _| | |  / _ \ | '__|   |__   _|   |  _  /    | |   | | |_ | |  __  |    | |   
 * | |  | | | (_) | | (_| | | | | |   | | |  __/ | |         | |     | | \ \   _| |_  | |__| | | |  | |    | |   
 * |_|  |_|  \___/   \__,_| |_| |_|   |_|  \___| |_|         |_|     |_|  \_\ |_____|  \_____| |_|  |_|    |_|   
 * 
 * ,-------------------------------------------------------------------------------------.
 * |  ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp  |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |CTL/Tab|   X  |   V  |   L  |   C  |   W  |   K  |   H  |   G  |   F  |   Q  | CTL/ß |
 * |-------+------+------+------+------+-------------+------+------+------+------+-------|
 * |  L3   |   U  |   I  |   A  |   E  |   O  |   S  |   N  |   R  |   T  |   D  | L3/Y  |
 * |-------+------+------+------+------+------|------+------+------+------+------+-------|
 * | LShift|   Ü  |   Ö  |   Ä  |   P  |   Z  |   B  |   M  |   ,  |   .  |   J  |RShift |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |   L4  | +#S  | GUI  | LALT |CtlBsp| MOUSE | LEAD |  SPC | L4 | GUI  | App  | Enter  |
 * `-------------------------------------------------------------------------------------'
 */
[RightM4] = LAYOUT_preonic_grid( \
  KC_ESC              ,       KC_1,    KC_2,    KC_3,          KC_4,               KC_5,     KC_6,    KC_7,        KC_8,    KC_9,   KC_0,             KC_BSPC, \
  MT(MOD_LCTL, KC_TAB),       DE_X,    DE_V,    DE_L,          DE_C,               DE_W,     DE_K,    DE_H,        DE_G,    DE_F,   DE_Q, MT(MOD_RCTL, DE_SS),  \
  MO(LeftM3)          ,       DE_U,    DE_I,    DE_A,          DE_E,               DE_O,     DE_S,    DE_N,        DE_R,    DE_T,   DE_D,   LT(RightM3, DE_Y), \
  KC_LSFT             ,    DE_UDIA, DE_ODIA, DE_ADIA,          DE_P,               DE_Z,     DE_B,    DE_M,    KC_COMMA,  KC_DOT,   DE_J,             KC_RSFT,  \
  MO(LeftM4)          , G(S(DE_S)), KC_LGUI, KC_LALT, LCTL(KC_BSPC), LT(MOUSE, KC_TRNS), KC_LEAD, KC_SPACE, MO(RightM4), KC_RGUI, KC_APP,              KC_ENT  \
),

/* Keymap 00: default layer
 * Ascii-art generator: http://patorjk.com/software/taag/#p=display&f=Big&t=Mouse
 *  __  __                              
 * |  \/  |                             
 * | \  / |   ___    _   _   ___    ___ 
 * | |\/| |  / _ \  | | | | / __|  / _ \
 * | |  | | | (_) | | |_| | \__ \ |  __/
 * |_|  |_|  \___/   \__,_| |___/  \___|
 *
 * ,-------------------------------------------------------------------------------------.
 * |  ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp  |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |CTL/Tab|   X  |   V  |   L  |   C  |   W  |   K  |   H  |   G  |   F  |   Q  | CTL/ß |
 * |-------+------+------+------+------+-------------+------+------+------+------+-------|
 * |  L3   |   U  |   I  |   A  |   E  |   O  |   S  |   N  |   R  |   T  |   D  | L3/Y  |
 * |-------+------+------+------+------+------|------+------+------+------+------+-------|
 * | LShift|   Ü  |   Ö  |   Ä  |   P  |   Z  |   B  |   M  |   ,  |   .  |   J  |RShift |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |   L4  | +#S  | GUI  | LALT |CtlBsp| MOUSE | LEAD |  SPC | L4 | GUI  | App  | Enter  |
 * `-------------------------------------------------------------------------------------'
 */
[MOUSE] = LAYOUT_preonic_grid( \
  KC_ESC              ,       KC_1,    KC_2,    KC_3,          KC_4,               KC_5,     KC_6,    KC_7,        KC_8,    KC_9,   KC_0,             KC_BSPC, \
  MT(MOD_LCTL, KC_TAB),       DE_X,    DE_V,    DE_L,          DE_C,               DE_W,     DE_K,    DE_H,        DE_G,    DE_F,   DE_Q, MT(MOD_RCTL, DE_SS),  \
  MO(LeftM3)          ,       DE_U,    DE_I,    DE_A,          DE_E,               DE_O,     DE_S,    DE_N,        DE_R,    DE_T,   DE_D,   LT(RightM3, DE_Y), \
  KC_LSFT             ,    DE_UDIA, DE_ODIA, DE_ADIA,          DE_P,               DE_Z,     DE_B,    DE_M,    KC_COMMA,  KC_DOT,   DE_J,             KC_RSFT,  \
  MO(LeftM4)          , G(S(DE_S)), KC_LGUI, KC_LALT, LCTL(KC_BSPC), LT(MOUSE, KC_TRNS), KC_LEAD, KC_SPACE, MO(RightM4), KC_RGUI, KC_APP,              KC_ENT  \
)



};

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
}; */

/* bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50; */

/* void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
} */

/* void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}
 */

/* void matrix_scan_user(void) {
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

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
} */
