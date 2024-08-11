// Copyright 2022 ZyBeR (@ZyberSE)
// SPDX-License-Identifier: GPL-2.0
// This keymap is intended for macOS and works for both Ansi and ISO

#include "zyber.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_all(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,         KC_F5,   KC_F6,   KC_F7,   KC_F8,         KC_F9,   KC_F10,    KC_F11,  KC_F12,       KC_PSCR, KC_SCRL, KC_PAUS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    TD(SSHT),TD(MONO),KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,     KC_BSPC, KC_BSPC,      KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     TD(LBRC), KC_RBRC,    KC_BSLS,               KC_DEL,  KC_END,  KC_PGDN,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TD(SCLN), TD(QUOT), KC_NUHS,    KC_ENT,
        KC_LSFT, KC_GRV,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,    KC_TRNS,                       KC_UP,
        KC_LOPT, _______, KC_LCMD,                                   KC_SPC,                                    _______, RO_SPTL, _______, L1_EXPL,      KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT_all(
        QK_BOOT,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS,     KC_TRNS, KC_F15,  KC_VOLU,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,              KC_TRNS, KC_F14,  KC_VOLD,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, P_CBLK,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,                       KC_TRNS,
        KC_TRNS, _______, KC_TRNS,                                   KC_TRNS,                                   _______, KC_TRNS,  _______, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
    ),

};
