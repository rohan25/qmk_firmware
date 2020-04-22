#include QMK_KEYBOARD_H

#define _______ KC_TRNS

enum custom_keycodes {
  D3NUM_4 = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  RGB_TOG,  KC_MUTE,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   MO(1),    KC_BSPC,  KC_INS,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_DEL,
    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                      KC_ENT,   D3NUM_4,//KC_MNXT (next track)
    KC_LSFT,  MO(1),    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    MO(1),
    KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,   KC_SPC,   KC_SPC,                       KC_RALT,  MO(1),    KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [1] = LAYOUT(
    KC_PWR,   RGB_MOD,  RGB_HUI,  RGB_VAI,  RGB_SAI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PAUS,  KC_MSTP,  KC_MPLY,
    _______,  RGB_RMOD, RGB_HUD,  RGB_VAD,  RGB_SAD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    KC_VOLU,
    KC_NLCK,  KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_KP_4,  KC_KP_5,  KC_KP_6,  KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_KP_0,  _______,  _______,  _______,            KC_VOLD,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  KC_MNXT,//KC_MPRV (prev track)
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGUI(KC_P),         KC_PGUP,  _______,
    _______,  _______,  _______,                      _______,  _______,  _______,                      _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_END
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case D3NUM_4:
      if (record->event.pressed) {
        // when keycode D3NUM_4 is pressed
        register_code(KC_KP_4);
        register_code(KC_NLCK);        
      } else {
        // when keycode D3NUM_4 is released
        unregister_code(KC_KP_4);
        unregister_code(KC_NLCK);
      }
      break;
  }
  return true;
}