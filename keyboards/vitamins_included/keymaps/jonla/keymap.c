#include QMK_KEYBOARD_H

#define TG_NKRO MAGIC_TOGGLE_NKRO


// Layer names

enum layer_names {
    _QWERTY,
    _COLEMAK,
    _DVORAK,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FN
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
  FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | FN   |  Alt | GUI  |Lower |Space |Space |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
    KC_TAB,        KC_Q,     KC_W,     KC_E,     KC_R,   KC_T,    KC_Y,    KC_U,   KC_I,     KC_O,    KC_P,     KC_BSPC,
    CTL_T(KC_ESC), KC_A,     KC_S,     KC_D,     KC_F,   KC_G,    KC_H,    KC_J,   KC_K,     KC_L,    KC_SCLN,  KC_ENT,
    KC_LSFT,       KC_Z,     KC_X,     KC_C,     KC_V,   KC_B,    KC_N,    KC_M,   KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
    KC_NO,         FN,       KC_LALT,  KC_LGUI,  LOWER,  KC_SPC,  KC_SPC,  RAISE,  KC_NO,    KC_NO,   KC_NO,    KC_NO
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | FN   |  Alt | GUI  |Lower |Space |Space |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12( \
  KC_TAB,        KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  CTL_T(KC_ESC), KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
  KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_NO,         FN,      KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_NO,   KC_NO,   KC_NO,   KC_NO        
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | FN   |  Alt | GUI  |Lower |Space |Space |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
  KC_NO,   FN,      KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_NO,   KC_NO,   KC_NO,   KC_NO        
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |GUI(1)|GUI(2)|GUI(3)|GUI(4)|GUI(5)|      |   -  |   +  |   [  |   ]  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |GUI(6)|GUI(7)|GUI(8)|GUI(9)|GUI(0)|      |   _  |   =  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
    KC_TILD,  KC_EXLM,     KC_AT,       KC_HASH,     KC_DLR,      KC_PERC,     KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
    KC_DEL,   LGUI(KC_1),  LGUI(KC_2),  LGUI(KC_3),  LGUI(KC_4),  LGUI(KC_5),  KC_NO,    KC_MINS,  KC_PLUS,  KC_LBRC,  KC_RBRC,  KC_DQUO,
    _______,  LGUI(KC_6),  LGUI(KC_7),  LGUI(KC_8),  LGUI(KC_9),  LGUI(KC_0),  KC_NO,    KC_UNDS,  KC_EQL,   KC_LCBR,  KC_RCBR,  KC_PIPE,
    _______,  _______,     _______,     _______,     _______,     _______,     _______,  _______,  _______,  _______,  _______,  _______
),

/* Raise 
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | C(1) | C(2) | C(3) | C(4) | C(5) | Left |  Up  | Down |Right |      |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | C(6) | C(7) | C(8) | C(9) | C(0) | Mute | Vol- | Vol+ | GUI  |      |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
    KC_GRV,   KC_1,        KC_2,        KC_3,        KC_4,        KC_5,        KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
    _______,  LCTL(KC_1),  LCTL(KC_2),  LCTL(KC_3),  LCTL(KC_4),  LCTL(KC_5),  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_NO,    KC_QUOT,
    _______,  LCTL(KC_6),  LCTL(KC_7),  LCTL(KC_8),  LCTL(KC_9),  LCTL(KC_0),  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_LGUI,  KC_NO,    KC_BSLS,
    _______,  _______,     _______,     _______,     _______,     _______,     _______,  _______,  _______,  _______,  _______,  _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |Qwerty|Colemk|Dvorak|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |Audoff Audon |      |      |      |      |RGBMOD|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, QWERTY,  COLEMAK, DVORAK,  _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, QWERTY,  COLEMAK, DVORAK,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, AU_OFF,  AU_ON,   _______, _______, _______, _______, RGB_MOD \
),

/* FN
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |      |      |      |   [  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Home | PgDn | PgUp | End  |  ;   |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_ortho_4x12(
    KC_F1,  KC_F2,    KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_LBRC,
    KC_F7,  KC_F8,    KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,  KC_SCLN,  KC_QUOT,
    KC_NO,  KC_NO,    KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO,
    KC_NO,  _______,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO
)

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case FN:
      if (record->event.pressed) {
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      return false;
      break;
  }
  return true;
}
