/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST,
  _FN,
  _GAME
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN MO(_FN)
#define GAME_TG TG(_GAME)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc C|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Fn   | Alt  | GUI  |Lower |    Space    |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,        KC_Q,     KC_W,     KC_E,     KC_R,   KC_T,    KC_Y,    KC_U,   KC_I,     KC_O,    KC_P,     KC_BSPC,
    CTL_T(KC_ESC), KC_A,     KC_S,     KC_D,     KC_F,   KC_G,    KC_H,    KC_J,   KC_K,     KC_L,    KC_SCLN,  KC_ENT,
    KC_LSFT,       KC_Z,     KC_X,     KC_C,     KC_V,   KC_B,    KC_N,    KC_M,   KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
    KC_NO,         FN,       KC_LALT,  KC_LGUI,  LOWER,  KC_SPC,  KC_SPC,  RAISE,  KC_NO,    KC_NO,   KC_NO,    KC_NO
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
[_LOWER] = LAYOUT_planck_grid(
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
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,   KC_1,        KC_2,        KC_3,        KC_4,        KC_5,        KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
    _______,  LCTL(KC_1),  LCTL(KC_2),  LCTL(KC_3),  LCTL(KC_4),  LCTL(KC_5),  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_NO,    KC_QUOT,
    _______,  LCTL(KC_6),  LCTL(KC_7),  LCTL(KC_8),  LCTL(KC_9),  LCTL(KC_0),  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_LGUI,  KC_NO,    KC_BSLS,
    _______,  _______,     _______,     _______,     _______,     _______,     _______,  _______,  _______,  _______,  _______,  _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |NumLck|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    KC_CAPS, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______,  _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, KC_NUMLOCK,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* FN
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |      |      |      |   [  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Home | PgDn | PgUp | End  |  ;   |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |GameTG|      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_ortho_4x12(
    KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_LBRC,
    KC_F7,  KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,  KC_SCLN,  KC_QUOT,
    KC_NO,  KC_NO,    GAME_TG, KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO,
    KC_NO,  _______,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO
),

/* Game mode
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   7  |   8  |   9  |  F6  |  F7  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   4  |   2  |   6  |  F8  |  F9  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   1  |   X  |   3  |  F10 |  F11 |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RotMod| Fn   | Alt  | GUI  |Lower |     F12     |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_planck_grid(
  KC_ESC,    KC_P7,   KC_P8,   KC_P9,   KC_F6,   KC_F7,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_LCTL,   KC_P4,   KC_P2,   KC_P6,   KC_F8,   KC_F9,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT,   KC_P1,   KC_TRNS, KC_P3,   KC_F10,  KC_F11,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_NO,     FN,      KC_LALT, KC_LGUI, LOWER,   KC_F12,  KC_F12,  RAISE,   KC_NO,   KC_NO,   KC_NO,   KC_NO
)
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
