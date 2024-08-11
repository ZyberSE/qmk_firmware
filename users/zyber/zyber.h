// Copyright 2022 ZyBeR (@ZyberSE)
// SPDX-License-Identifier: GPL-2.0

#pragma once

#include QMK_KEYBOARD_H
#include "quantum.h"

enum custom_keycodes {
	CTRL_C_UP = SAFE_RANGE,
	L1_EXPL,
	L2_SPTL,
	RO_SPTL,
	P_CBLK,
	PS_FOLD
};

enum tap_dances {
	SSHT = 0,
	MONO,
	LBRC,
	SCLN,
	QUOT,
	END_HOME
};

bool process_record_user(uint16_t keycode, keyrecord_t *record);

void dance_SSHT_finished(tap_dance_state_t *state, void *user_data);
void dance_SSHT_reset(tap_dance_state_t *state, void *user_data);
void dance_MONO_finished(tap_dance_state_t *state, void *user_data);
void dance_MONO_reset(tap_dance_state_t *state, void *user_data);
void dance_LBRC_finished(tap_dance_state_t *state, void *user_data);
void dance_LBRC_reset(tap_dance_state_t *state, void *user_data);
void dance_SCLN_finished(tap_dance_state_t *state, void *user_data);
void dance_SCLN_reset(tap_dance_state_t *state, void *user_data);
void dance_QUOT_finished(tap_dance_state_t *state, void *user_data);
void dance_QUOT_reset(tap_dance_state_t *state, void *user_data);
