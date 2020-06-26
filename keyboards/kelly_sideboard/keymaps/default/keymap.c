/* Copyright 2019
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

#define WRAPPER KC_F23

void send01rst (qk_tap_dance_state_t *state, void *user_data) {
	switch (state-> count) {
		case 1:
			register_code(WRAPPER);
			register_code(KC_0);
			unregister_code(KC_0);
			unregister_code(WRAPPER);		
			break;
		case 2:
			register_code(WRAPPER);
			register_code(KC_1);
			unregister_code(KC_1);
			unregister_code(WRAPPER);		
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			reset_keyboard();
			reset_tap_dance(state);
	}
}

void send23 (qk_tap_dance_state_t *state, void *user_data) {
	switch (state-> count) {
		case 1:
			register_code(WRAPPER);
			register_code(KC_2);
			unregister_code(KC_2);
			unregister_code(WRAPPER);
			break;
		case 2:
			register_code(WRAPPER);
			register_code(KC_3);
			unregister_code(KC_3);
			unregister_code(WRAPPER);
			break;
	}
}

void send45 (qk_tap_dance_state_t *state, void *user_data) {
	switch (state-> count) {
		case 1:
			register_code(WRAPPER);
			register_code(KC_4);
			unregister_code(KC_4);
			unregister_code(WRAPPER);
			break;
		case 2:
			register_code(WRAPPER);
			register_code(KC_5);
			unregister_code(KC_5);
			unregister_code(WRAPPER);
			break;
	}
}

void send67 (qk_tap_dance_state_t *state, void *user_data) {
	switch (state-> count) {
		case 1:
			register_code(WRAPPER);
			register_code(KC_6);
			unregister_code(KC_6);
			unregister_code(WRAPPER);
			break;
		case 2:
			register_code(WRAPPER);
			register_code(KC_7);
			unregister_code(KC_7);
			unregister_code(WRAPPER);
			break;
	}
}

void send89 (qk_tap_dance_state_t *state, void *user_data) {
	switch (state-> count) {
		case 1:
			register_code(WRAPPER);
			register_code(KC_8);
			unregister_code(KC_8);
			unregister_code(WRAPPER);
			break;
		case 2:
			register_code(WRAPPER);
			register_code(KC_9);
			unregister_code(KC_9);
			unregister_code(WRAPPER);
			break;
	}
}

void sendab (qk_tap_dance_state_t *state, void *user_data) {
	switch (state-> count) {
		case 1:
			register_code(WRAPPER);
			register_code(KC_A);
			unregister_code(KC_A);
			unregister_code(WRAPPER);
			break;
		case 2:
			register_code(WRAPPER);
			register_code(KC_B);
			unregister_code(KC_B);
			unregister_code(WRAPPER);
			break;
	}
}

void sendcd (qk_tap_dance_state_t *state, void *user_data) {
	switch (state-> count) {
		case 1:
			register_code(WRAPPER);
			register_code(KC_C);
			unregister_code(KC_C);
			unregister_code(WRAPPER);
			break;
		case 2:
			register_code(WRAPPER);
			register_code(KC_D);
			unregister_code(KC_D);
			unregister_code(WRAPPER);
			break;
	}
}

void sendef (qk_tap_dance_state_t *state, void *user_data) {
	switch (state-> count) {
		case 1:
			register_code(WRAPPER);
			register_code(KC_E);
			unregister_code(KC_E);
			unregister_code(WRAPPER);
			break;
		case 2:
			register_code(WRAPPER);
			register_code(KC_F);
			unregister_code(KC_F);
			unregister_code(WRAPPER);
			break;
	}
}

void sendgh (qk_tap_dance_state_t *state, void *user_data) {
	switch (state-> count) {
		case 1:
			register_code(WRAPPER);
			register_code(KC_G);
			unregister_code(KC_G);
			unregister_code(WRAPPER);
			break;
		case 2:
			register_code(WRAPPER);
			register_code(KC_H);
			unregister_code(KC_H);
			unregister_code(WRAPPER);
			break;
	}
}

void sendij (qk_tap_dance_state_t *state, void *user_data) {
	switch (state-> count) {
		case 1:
			register_code(WRAPPER);
			register_code(KC_I);
			unregister_code(KC_I);
			unregister_code(WRAPPER);
			break;
		case 2:
			register_code(WRAPPER);
			register_code(KC_J);
			unregister_code(KC_J);
			unregister_code(WRAPPER);
			break;
	}
}

void sendkl (qk_tap_dance_state_t *state, void *user_data) {
	switch (state-> count) {
		case 1:
			register_code(WRAPPER);
			register_code(KC_K);
			unregister_code(KC_K);
			unregister_code(WRAPPER);
			break;
		case 2:
			register_code(WRAPPER);
			register_code(KC_L);
			unregister_code(KC_L);
			unregister_code(WRAPPER);
			break;
	}
}

void sendmn (qk_tap_dance_state_t *state, void *user_data) {
	switch (state-> count) {
		case 1:
			register_code(WRAPPER);
			register_code(KC_M);
			unregister_code(KC_M);
			unregister_code(WRAPPER);
			break;
		case 2:
			register_code(WRAPPER);
			register_code(KC_N);
			unregister_code(KC_N);
			unregister_code(WRAPPER);
			break;
	}
}

// Tap Dance Declarations
enum {
	TD_01RST = 0,
	TD_23,
	TD_45,
	TD_67,
	TD_89,
	TD_AB,
	TD_CD,
	TD_EF,
	TD_GH,
	TD_IJ,
	TD_KL,
	TD_MN
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_01RST] = ACTION_TAP_DANCE_FN (send01rst),
	[TD_23] = ACTION_TAP_DANCE_FN (send23),
	[TD_45] = ACTION_TAP_DANCE_FN (send45),
	[TD_67] = ACTION_TAP_DANCE_FN (send67),
	[TD_89] = ACTION_TAP_DANCE_FN (send89),
	[TD_AB] = ACTION_TAP_DANCE_FN (sendab),
	[TD_CD] = ACTION_TAP_DANCE_FN (sendcd),
	[TD_EF] = ACTION_TAP_DANCE_FN (sendef),
	[TD_GH] = ACTION_TAP_DANCE_FN (sendgh),
	[TD_IJ] = ACTION_TAP_DANCE_FN (sendij),
	[TD_KL] = ACTION_TAP_DANCE_FN (sendkl),
	[TD_MN] = ACTION_TAP_DANCE_FN (sendmn)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
				TD(TD_01RST), 	TD(TD_23), TD(TD_45), TD(TD_67), TD(TD_89), TD(TD_AB), \
	KC_MUTE, 	TD(TD_CD), 		TD(TD_EF), TD(TD_GH), TD(TD_IJ), TD(TD_KL), TD(TD_MN) \
  )
};

void encoder_update_user(uint8_t index, bool clockwise) {
	if (clockwise) {
		tap_code(KC_VOLD);
	} else {
		tap_code(KC_VOLU);
	}
}