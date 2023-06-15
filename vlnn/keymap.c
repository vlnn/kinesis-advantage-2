#include QMK_KEYBOARD_H
#include "features/achordion.h"

enum { TD_SPC_TAB = 0, TD_OPENBRACE, TD_CLOSEBRACE };

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum { HOLD = 1, SINGLE_TAP = 2, DOUBLE_TAP = 3, TRIPLE_TAP = 4, QUAD_TAP = 5 };

int cur_dance(tap_dance_state_t *state) {
  if (state->pressed)
    return HOLD;

  if (state->count == 1)
    return SINGLE_TAP;

  if (state->count == 2)
    return DOUBLE_TAP;

  if (state->count == 3)
    return TRIPLE_TAP;

  if (state->count == 4)
    return QUAD_TAP;

  return -1;
}

static int spl_o_tap_state = 0;
static int spl_c_tap_state = 0;

void space_cadet_open_finished(tap_dance_state_t *state, void *user_data) {
  spl_o_tap_state = cur_dance(state);
  switch (spl_o_tap_state) {
  case SINGLE_TAP:
    register_mods(MOD_BIT(KC_LSFT));
    register_code(KC_9); // (
    break;
  case DOUBLE_TAP:
    register_mods(MOD_BIT(KC_LSFT));
    register_code(KC_LBRC); // {
    break;
  case TRIPLE_TAP:
    register_code(KC_LBRC); // [
    break;
  case QUAD_TAP:
    register_mods(MOD_BIT(KC_LSFT));
    register_code(KC_COMMA); // <
    break;
  case HOLD:
    register_mods(MOD_BIT(KC_LSFT));
  }
}

void space_cadet_open_reset(tap_dance_state_t *state, void *user_data) {
  switch (spl_o_tap_state) {
  case SINGLE_TAP:
    unregister_code(KC_9);
    unregister_mods(MOD_BIT(KC_LSFT));
    break;
  case DOUBLE_TAP:
    unregister_code(KC_LBRC); // [
    unregister_mods(MOD_BIT(KC_LSFT));
    break;
  case TRIPLE_TAP:
    unregister_code(KC_LBRC); // {
    break;
  case QUAD_TAP:
    unregister_code(KC_COMMA); // <
    unregister_mods(MOD_BIT(KC_LSFT));
    break;
  case HOLD:
    unregister_mods(MOD_BIT(KC_LSFT));
    break;
  }
  spl_o_tap_state = 0;
}

void space_cadet_close_finished(tap_dance_state_t *state, void *user_data) {
  spl_c_tap_state = cur_dance(state);
  switch (spl_c_tap_state) {
  case SINGLE_TAP:
    register_mods(MOD_BIT(KC_RSFT));
    register_code(KC_0); // )
    break;
  case DOUBLE_TAP:
    register_mods(MOD_BIT(KC_RSFT));
    register_code(KC_RBRC); // }
    break;
  case TRIPLE_TAP:
    register_code(KC_RBRC); // ]
    break;
  case QUAD_TAP:
    register_mods(MOD_BIT(KC_RSFT));
    register_code(KC_DOT); // >
    break;
  case HOLD:
    register_mods(MOD_BIT(KC_RSFT));
  }
}

void space_cadet_close_reset(tap_dance_state_t *state, void *user_data) {
  switch (spl_c_tap_state) {
  case SINGLE_TAP:
    unregister_code(KC_0); // )
    unregister_mods(MOD_BIT(KC_RSFT));
    break;
  case DOUBLE_TAP:
    unregister_code(KC_RBRC); // }
    unregister_mods(MOD_BIT(KC_RSFT));
    break;
  case TRIPLE_TAP:
    unregister_code(KC_RBRC); // ]
    break;
  case QUAD_TAP:
    unregister_code(KC_DOT); // >
    unregister_mods(MOD_BIT(KC_RSFT));
    break;
  case HOLD:
    unregister_mods(MOD_BIT(KC_RSFT));
    break;
  }
  spl_c_tap_state = 0;
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_SPC_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_SPACE, KC_TAB),
    [TD_OPENBRACE] = ACTION_TAP_DANCE_FN_ADVANCED(
        NULL, space_cadet_open_finished, space_cadet_open_reset),
    [TD_CLOSEBRACE] = ACTION_TAP_DANCE_FN_ADVANCED(
        NULL, space_cadet_close_finished, space_cadet_close_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC, LSFT(KC_F1), LSFT(KC_F2), LSFT(KC_F3), LSFT(KC_F4), KC_F5, KC_F6, KC_F7, KC_F8,
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
        HYPR_T(KC_ESC), ALT_T(KC_A), CTL_T(KC_S), WIN_T(KC_D), SFT_T(KC_F), LT(1, KC_G),
        TD(TD_OPENBRACE), KC_Z, KC_X, KC_C, KC_V, KC_B,
        KC_EQL, KC_NO, KC_LBRC, KC_RBRC,

        MO(1), CTL_T(KC_F14), LWIN(KC_V),
        KC_BSPC, KC_LSFT, LWIN(KC_C),

        MO(2), KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SCRL, KC_PAUS, KC_F13, KC_F14,
        KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
        LT(1, KC_H), RSFT_T(KC_J), RWIN_T(KC_K), RCTL_T(KC_L), RALT_T(KC_SCLN), KC_QUOT,
        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TD(TD_CLOSEBRACE),
        LSFT(KC_LBRC), LSFT(KC_RBRC), TD(TD_OPENBRACE), TD(TD_CLOSEBRACE),

        CTL_T(KC_F13), MO(1), KC_PGUP,
        KC_PGDN, SFT_T(KC_ENT), LT(1, KC_SPC)),

    [1] = LAYOUT(
        QK_REBOOT, DB_TOGG, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,

        KC_NO, KC_NO, LCTL(KC_Y),
        KC_BSPC, KC_TRNS, LCTL(KC_Z),

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        TD_OPENBRACE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_MINUS, TD(TD_OPENBRACE), TD(TD_CLOSEBRACE), KC_NO, KC_NO, KC_NO,
        KC_PLUS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO,
        KC_NO, LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP), LCTL(KC_RGHT), KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,

        LCTL(LSFT(KC_T)), KC_TRNS, LCTL(KC_T),
        LWIN(KC_W), KC_NO, KC_NO),

    [2] = LAYOUT(
        QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

        KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO,

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TAB, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

        KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }

#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}

void matrix_scan_user(void) {
  achordion_task();
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    case LT(1, KC_SPC):
      return 0;  // Bypass Achordion for these keys.
  }

  return 600;  // Otherwise use a timeout of 800 ms.
}
