#include "super16.h"

enum custom_keycodes {
  UP_URL = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_ortho_4x4(
        RGB_TOG,    KC_1,    KC_U,    KC_P, 
        RGB_MOD,    KC_1,    KC_U,    KC_P,
        RGB_TOG,    KC_1,    KC_U,    KC_P,
        RGB_MOD,    KC_1,    KC_U,    KC_P
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case UP_URL:
            if (record->event.pressed) {
                SEND_STRING("http://1upkeyboads.com");
            }
            return false;
            break;
    }
    return true;
}

void led_set_user(uint8_t usb_led) {

  /* Map RXLED to USB_LED_NUM_LOCK */
	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		DDRB |= (1 << 0); PORTB &= ~(1 << 0);
	} else {
		DDRB &= ~(1 << 0); PORTB &= ~(1 << 0);
	}

  /* Map TXLED to USB_LED_CAPS_LOCK */
	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		DDRD |= (1 << 5); PORTD &= ~(1 << 5);
	} else {
		DDRD &= ~(1 << 5); PORTD &= ~(1 << 5);
	}
}
