// Copyright 2022 ZyBeR (@ZyberSE)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H
#include "zyber.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

enum short_keycodes {
    SFT = MOD_LSFT,
    UP  = KC_UP,
    DEL = KC_DEL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_alice_split_bs(
        KC_ESC,      KC_TILD,   KC_1,    KC_2,    KC_3,    TD(SSHT),TD(MONO),KC_6,            KC_7,    KC_8,    KC_9,    KC_0,       KC_MINS,   KC_EQL,     KC_BSLS,    KC_DEL,
        KC_PGUP,     KC_TAB,             KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,       KC_P,      TD(LBRC),   KC_RBRC,    KC_BSPC,
        KC_PGDN,     CTRL_C_UP,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,    KC_K,    KC_L,       TD(SCLN),  TD(QUOT),               KC_ENT,
        TD(END_HOME),KC_LSFT,            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_B,    KC_N,    KC_M,    KC_COMM,    KC_DOT,    KC_SLSH,    MT(SFT,UP), KC_RSFT,
                     KC_LCTL,   KC_LOPT,                          KC_LCMD, KC_SPC,          KC_SPC,  LT(_FN, KC_SPC),                           KC_LEFT,    KC_DOWN,    KC_RGHT),
    [_FN] = LAYOUT_alice_split_bs(
        QK_BOOT,   KC_TRNS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,       KC_F8,   KC_F9,   KC_F10,  KC_F11,     KC_F12,                KC_TRNS,    KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,   RGB_RMOD,   RGB_MOD,    RGB_TOG,
        KC_TRNS,   KC_CAPS,   KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    RGB_VAD,   RGB_VAI,                KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, P_CBLK, KC_TRNS,                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    RGB_SAD,   RGB_SAI,    KC_TRNS,    RGB_HUI,
                   KC_TRNS,   KC_TRNS,                   KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS,                                 KC_TRNS,    KC_TRNS,    KC_TRNS),
};
