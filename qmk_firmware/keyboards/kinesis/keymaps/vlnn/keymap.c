#include QMK_KEYBOARD_H

enum { TD_SPC_TAB = 0, TD_OPENBRACE, TD_CLOSEBRACE };

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum { HOLD = 1, SINGLE_TAP = 2, DOUBLE_TAP = 3, TRIPLE_TAP = 4, QUAD_TAP = 5 };

int cur_dance(qk_tap_dance_state_t *state) {
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

void space_cadet_open_finished(qk_tap_dance_state_t *state, void *user_data) {
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

void space_cadet_open_reset(qk_tap_dance_state_t *state, void *user_data) {
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

void space_cadet_close_finished(qk_tap_dance_state_t *state, void *user_data) {
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

void space_cadet_close_reset(qk_tap_dance_state_t *state, void *user_data) {
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

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SPC_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_SPACE, KC_TAB),
    [TD_OPENBRACE] = ACTION_TAP_DANCE_FN_ADVANCED(
        NULL, space_cadet_open_finished, space_cadet_open_reset),
    [TD_CLOSEBRACE] = ACTION_TAP_DANCE_FN_ADVANCED(
        NULL, space_cadet_close_finished, space_cadet_close_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC, LWIN(KC_1), LWIN(KC_2), LWIN(KC_3), LWIN(KC_4), LWIN(KC_5),
        LWIN(KC_6), LWIN(KC_7), LWIN(KC_8), KC_EQL, KC_1, KC_2, KC_3, KC_4,
        KC_5, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_ESC, ALT_T(KC_A),
        WIN_T(KC_S), CTL_T(KC_D), SFT_T(KC_F), LT(1, KC_G), TD(TD_OPENBRACE),
        KC_Z, KC_X, KC_C, KC_V, KC_B, KC_GRV, KC_NO, KC_LALT, KC_LGUI,

        MO(1), KC_LCTL, LSFT(KC_INSERT), KC_BSPC, KC_LSFT, LCTL(KC_INSERT),

        LCTL(KC_S), KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SLCK, KC_PAUS, KC_FN0,
        KC_1, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_Y, KC_U, KC_I, KC_O,
        KC_P, KC_BSLS, LT(1, KC_H), SFT_T(KC_J), CTL_T(KC_K), WIN_T(KC_L),
        ALT_T(KC_SCLN), KC_QUOT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
        TD(TD_CLOSEBRACE), KC_RGUI, KC_RALT, TD(TD_OPENBRACE),
        TD(TD_CLOSEBRACE),

        KC_RCTL, MO(1), KC_PGUP, KC_PGDN, KC_SFTENT, TD(TD_SPC_TAB)),

    [1] = LAYOUT(
        RESET, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

        KC_NO, KC_NO, LCTL(KC_Y), KC_DELETE, KC_TRNS, LCTL(KC_Z),

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TAB, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
        LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP), LCTL(KC_RGHT), KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,

        LCTL(LSFT(KC_T)), KC_TRNS, LCTL(KC_T), LCTL(KC_W), KC_NO, KC_NO),

    [2] = LAYOUT(
        RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
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
