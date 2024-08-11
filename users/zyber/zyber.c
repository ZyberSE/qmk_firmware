// Copyright 2022 ZyBeR (@ZyberSE)
// SPDX-License-Identifier: GPL-2.0

#include "zyber.h"


__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

uint16_t key_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	//const uint8_t mods = get_mods();

	if (record->event.pressed) {
		key_timer = timer_read();
	}

	if (!process_caps_word(keycode, record)) {
		return false;
	}

	switch(keycode) {
		// PHPStorm fold methods (Expand All to Level 1)
		case PS_FOLD:
			if (record->event.pressed) {
				SEND_STRING(SS_LALT(SS_LCMD(SS_TAP(X_PAST) SS_TAP(X_KP_1))));
			}
			return false;

		// Paste code block in Slack
		case P_CBLK:
			if (record->event.pressed) {
				send_string("```" SS_DELAY(80) SS_LCMD("v") SS_DELAY(80) "```");
			}
			break;

		// Left Ctrl / macOS Explode
		case CTRL_C_UP:
			if (record->event.pressed) {
				register_mods(MOD_BIT(KC_LEFT_CTRL));
			} else {
				unregister_mods(MOD_BIT(KC_LEFT_CTRL));
				if (timer_elapsed(key_timer) < TAPPING_TERM) {
					tap_code16(C(KC_UP));
				}
			}
			return false;

		// Layer 1 / macOS Explode
		case L1_EXPL:
			if (record->event.pressed) {
				layer_on(1);
				update_tri_layer(1, 2, 3);
			} else {
				layer_off(1);
				update_tri_layer(1, 2, 3);
				if (timer_elapsed(key_timer) < TAPPING_TERM) {
					tap_code16(C(KC_UP));
				}
			}
			return false;

		// Right Option / macOS Spotlight
		case RO_SPTL:
			if (record->event.pressed) {
				register_mods(MOD_BIT(KC_ROPT));
			} else {
				unregister_mods(MOD_BIT(KC_ROPT));
				if (timer_elapsed(key_timer) < TAPPING_TERM) {
					tap_code16(G(KC_SPC));
				}
			}
			return false;

		// FN_MO23 / macOS Spotlight (for Zephyr)
		case L2_SPTL:
			if (record->event.pressed) {
				layer_on(2);
				update_tri_layer(1, 2, 3);
			} else {
				layer_off(2);
				update_tri_layer(1, 2, 3);
				if (timer_elapsed(key_timer) < TAPPING_TERM) {
					tap_code16(G(KC_SPC));
				}
			}
			return false;
	}

	return process_record_keymap(keycode, record);
}

// Screenshot macOS
void dance_SSHT_finished(tap_dance_state_t *state, void *user_data) {
	if (state->count == 2) {
		tap_code16(C(S(G(KC_4))));
	} else {
		tap_code(KC_4);
	}
}
void dance_SSHT_reset(tap_dance_state_t *state, void *user_data) {
	if (state->count == 2) {
		unregister_code16(C(S(G(KC_4))));
	} else {
		unregister_code(KC_4);
	}
}

// Screenshot Mono
void dance_MONO_finished(tap_dance_state_t *state, void *user_data) {
	if (state->count == 2) {
		tap_code16(A(G(KC_5)));
	} else {
		tap_code(KC_5);
	}
}
void dance_MONO_reset(tap_dance_state_t *state, void *user_data) {
	if (state->count == 2) {
		unregister_code16(A(G(KC_5)));
	} else {
		unregister_code(KC_5);
	}
}

// Use with macOS and Swansi layout to get Å on double-tap
void dance_LBRC_finished(tap_dance_state_t *state, void *user_data) {
	if (state->count == 2) {
		tap_code16(A(KC_LBRC));
	} else {
		tap_code(KC_LBRC);
	}
}
void dance_LBRC_reset(tap_dance_state_t *state, void *user_data) {
	if (state->count == 2) {
		unregister_code16(A(KC_LBRC));
	} else {
		unregister_code(KC_LBRC);
	}
}

// Use with macOS and Swansi layout to get Ö on double-tap
void dance_SCLN_finished(tap_dance_state_t *state, void *user_data) {
	if (state->count == 2) {
		tap_code16(A(KC_SCLN));
	} else {
		tap_code(KC_SCLN);
	}
}
void dance_SCLN_reset(tap_dance_state_t *state, void *user_data) {
	if (state->count == 2) {
		unregister_code16(A(KC_SCLN));
	} else {
		unregister_code(KC_SCLN);
	}
}

// Use with macOS and Swansi layout to get Ä on double-tap
void dance_QUOT_finished(tap_dance_state_t *state, void *user_data) {
	if (state->count == 2) {
		tap_code16(A(KC_QUOT));
	} else {
		tap_code(KC_QUOT);
	}
}
void dance_QUOT_reset(tap_dance_state_t *state, void *user_data) {
	if (state->count == 2) {
		unregister_code16(A(KC_QUOT));
	} else {
		unregister_code(KC_QUOT);
	}
}

tap_dance_action_t tap_dance_actions[] = {
	[SSHT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_SSHT_finished, dance_SSHT_reset),
	[MONO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_MONO_finished, dance_MONO_reset),
	[LBRC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_LBRC_finished, dance_LBRC_reset),
	[SCLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_SCLN_finished, dance_SCLN_reset),
	[QUOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_QUOT_finished, dance_QUOT_reset),
	[END_HOME] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_RIGHT), LGUI(KC_LEFT))
};
