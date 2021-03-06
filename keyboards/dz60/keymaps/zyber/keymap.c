#include QMK_KEYBOARD_H
#include "zyber.h"

enum keyboard_layers {
  _BL = 0, // Base Layer
  _FL,      // Function Layer
  _CL      // Control Layer
};

// Custom #defined keycodes (shorter macros for readability)
#define KC_CTES CTL_T(KC_ESC)
#define KC_RSUP RSFT_T(KC_UP)
#define KC_FNDN LT(_FL, KC_DOWN)
#define KC_RGLT RCMD_T(KC_LEFT)
#define KC_RCRT RCTL_T(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BL] = LAYOUT_60_tsangan(
		KC_GESC, KC_1,    KC_2,    KC_3,    TD(SSHT), KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,            KC_BSPC,
		KC_TAB,           KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     TD(LBRC), KC_RBRC, KC_BSLS,
		CTRL_C_UP,        KC_A,    KC_S,    KC_D,     KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TD(SCLN), TD(QUOT), KC_ENT,
		KC_LSFT,          KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSUP, MO(_FL),
		KC_LCTL, KC_LALT,          KC_LGUI,                    KC_SPC,                                      KC_RGLT,            KC_FNDN, KC_RCRT
	),
	[_FL] = LAYOUT_60_tsangan(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,           KC_DEL,
		_______,          _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______,  KC_SLCK, KC_PAUS, RESET,
		_______,          KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, KC_INS,  KC_HOME,  KC_PGUP, _______,
		_______,          _______, _______, _______, _______, _______, _______, _______, _______, KC_END,  KC_PGDN,           _______, _______,
		_______, _______,          _______,                   _______,                                     _______,           MO(_CL), _______
	),
	[_CL] = LAYOUT_60_tsangan(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,
		_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______,          _______, _______, _______, _______, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, _______, _______,          _______, _______,
		_______, _______,          _______,                   _______,                                     _______,          _______, _______
	)
};
