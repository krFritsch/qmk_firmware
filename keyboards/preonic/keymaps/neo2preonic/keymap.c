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

bool leading_success;

enum preonic_layers {
  BASE,
  LeftM3,
  RightM3,
  LeftM4,
  RightM4,
  MOUSE,
  EMPTY
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
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |  L3   |   U  |   I  |   A  |   E  |   O  |   S  |   N  |   R  |   T  |   D  | L3/Y  |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * | LShift|   Ü  |   Ö  |   Ä  |   P  |   Z  |   B  |   M  |   ,  |   .  |   J  |RShift |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |   L4  | +#S  | GUI  | LALT |CtlBsp| MOUS | LEAD |  SPC | L4  | GUI  | App  | Enter  |
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
 * |       |      |      |      |      |      |      |  EUR |      |      |      |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      |      |      |      |      |   !  |   <  |   >  |   =  |   &  |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      |      |      |      |      |   ?  |   (  |   )  |   -  |   :  |   @   |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      |      |      |      |      |   +  |   %  |   "  |   '  |   ;  |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      |      |      |      |      |      |      |      |      |      |       |
 * `-------------------------------------------------------------------------------------'
 */
[LeftM3] = LAYOUT_preonic_grid( \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_EURO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_EXLM, DE_LABK, DE_RABK, DE_EQL , DE_AMPR, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_AT  , \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
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
 * |       |      |      |      |      |      |      |  EUR |      |      |      |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      |   _  |   [  |   ]  |   ^  |      |      |      |      |      |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |   \  |   /  |   {  |   }  |   *  |      |      |      |      |      |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |   #  |   $  |   |  |   ~  |   `  |      |      |      |      |      |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      |      |      |      |      |      |      |      |      |      |       |
 * `-------------------------------------------------------------------------------------'
 */
[RightM3] = LAYOUT_preonic_grid( \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_EURO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, DE_HASH, DE_DLR , DE_PIPE, DE_TILD, DE_GRV , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
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
 * |       |      |      |      |      |      |      |  TAB |   /  |   *  |   -  |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      |      |      |      |      |      |   7  |   8  |   9  |   +  |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      |      |      |      |      |      |   4  |   5  |   6  |   ,  |   .   |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      |      |      |      |      |   :  |   1  |   2  |   3  |   ;  |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      |      |      |      |      |      |   0  |      |      |      |       |
 * `-------------------------------------------------------------------------------------'
 */
[LeftM4] = LAYOUT_preonic_grid( \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB , KC_PSLS, KC_PAST, KC_PMNS , KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P7  , KC_P8  , KC_P9  , KC_PPLS , KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P4  , KC_P5  , KC_P6  , KC_COMMA, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P1  , KC_P2  , KC_P3  , DE_SCLN , KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0  , KC_TRNS, KC_TRNS, KC_TRNS , KC_TRNS \
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
 * |       |      |      |      |      |      |      |      |      |      |      |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       | PgUp | BSPC |  up  |  del | PgDn |      |      |      |      |      |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       | home | left |  dwn | right|  end |      |      |      |      |      |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |  ESC |  TAB | INS  | ENTR | undo |      |      |      |      |      |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      |      |      |      |slct< |slct> |      |      |      |      |       |
 * `-------------------------------------------------------------------------------------'
 */
[RightM4] = LAYOUT_preonic_grid( \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS      , KC_TRNS      , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_PGUP, KC_BSPC, KC_UP  , KC_DEL , KC_PGDN      , KC_TRNS      , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END       , KC_TRNS      , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_ESC , KC_TAB , KC_INS , KC_ENT , C(DE_Z)      , KC_TRNS      , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S(C(KC_LEFT)), S(C(KC_RGHT)), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
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
 * |       |      |      |      |      |      |      |      |      |      |      |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      |      | MsUp |      |      | Vol+ | But4 | WhUp | But5 |      |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      | MsLe | MsDn | MsRi |      | Vol- | WhLe | WhDn | WhRi |      |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      |      |      |      |      | mute |      |      |      |      |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      |      |      |      |      | LClk | RClk | MClk |      |      |       |
 * `-------------------------------------------------------------------------------------'
 */
[MOUSE] = LAYOUT_preonic_grid( \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS       , KC_TRNS      , KC_TRNS       , KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_VOLU, KC_BTN4       , KC_MS_WH_UP  , KC_BTN5       , KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_VOLD, KC_MS_WH_LEFT , KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_TRNS       , KC_TRNS      , KC_TRNS       , KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2       , KC_MS_BTN3   , KC_TRNS       , KC_TRNS, KC_TRNS \
),

/* Keymap 00: default layer
 * Ascii-art generator: http://patorjk.com/software/taag/#p=display&f=Big&t=Mouse 
 * 
 * ,-------------------------------------------------------------------------------------.
 * |       |      |      |      |      |      |      |      |      |      |      |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      |      |      |      |      |      |      |      |      |      |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      |      |      |      |      |      |      |      |      |      |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      |      |      |      |      |      |      |      |      |      |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      |      |      |      |      |      |      |      |      |      |       |
 * `-------------------------------------------------------------------------------------'
 */
[EMPTY] = LAYOUT_preonic_grid( \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
)



};
/*
 * Define leader key sequences here
 *
 *  _                      _                   _                         
 * | |                    | |                 | |                        
 * | |   ___    __ _    __| |   ___   _ __    | | __   ___   _   _   ___ 
 * | |  / _ \  / _` |  / _` |  / _ \ | '__|   | |/ /  / _ \ | | | | / __|
 * | | |  __/ | (_| | | (_| | |  __/ | |      |   <  |  __/ | |_| | \__ \
 * |_|  \___|  \__,_|  \__,_|  \___| |_|      |_|\_\  \___|  \__, | |___/
 *                                                            __/ |      
 *                                                           |___/       
 */
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
	leading_success = false;
	SEQ_FIVE_KEYS(KC_R, KC_E, KC_S, KC_E, KC_T) {
      // LEAD + R E S E T
	  leading_success = true;
      reset_keyboard();
    }
	leader_end();
  }
}
