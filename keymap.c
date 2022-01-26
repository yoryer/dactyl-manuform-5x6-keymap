#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _DEV 1
#define _MOVE 2

// Layouts
#define L_DEV MO(_DEV)
#define L_MOVE MO(_MOVE)

// Macros 
enum custom_keycodes {
  M_LSPC,
  M_RSPC
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M_LSPC:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)));
      }
      break;

    case M_RSPC:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_RGHT)));
      }
      break;
  }
  return true;
};

// Layouts
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6(
        KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
        L_DEV  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                   KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                   KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                          KC_LCTL, KC_LALT,                                                       KC_RALT, KC_RCTL,
                                            KC_LGUI, KC_BSPC,                   KC_SPC , KC_RGUI, 
                                            L_MOVE , KC_DEL ,                   KC_ENT , _______,
                                            M_LSPC , M_RSPC,                    _______, _______
    ),


    [_DEV] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   KC_LT  , KC_AT  , KC_LPRN, KC_RPRN, _______, _______,
        _______, _______, _______, _______, _______, _______,                   KC_GT  , KC_EQL , KC_LCBR, KC_RCBR, _______, KC_GRV ,
        _______, _______, _______, _______, _______, _______,                   KC_TILD, KC_SLSH, KC_LBRC, KC_RBRC, KC_PIPE, _______,
                          _______, _______,                                                       _______, _______,
                                            _______, _______,                   _______, _______,
                                            _______, _______,                   _______, _______,
                                            _______, _______,                   _______, _______
    ),

    [_MOVE] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______,
        _______, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP  , KC_RGTH, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
                          _______, _______,                                                       _______, _______,
                                            _______, _______,                   _______, _______,
                                            _______, _______,                   _______, _______,
                                            _______, _______,                   _______, _______
    )

//    [EMPTY] = LAYOUT_5x6(
//        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//                          _______, _______,                                                       _______, _______,
//                                            _______, _______,                   _______, _______,
//                                            _______, _______,                   _______, _______,
//                                            _______, _______,                   _______, _______
//    )

};
