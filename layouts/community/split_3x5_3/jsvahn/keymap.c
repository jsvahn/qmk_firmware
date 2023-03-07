#include QMK_KEYBOARD_H
//#include "keymap_swedish.h"

#define THUMB_TAPPING_TERM TAPPING_TERM + 80
#define INDEX_TAPPING_TERM TAPPING_TERM + 50
#define RING_TAPPING_TERM TAPPING_TERM + 130
#define PINKY_TAPPING_TERM TAPPING_TERM + 200

#define __V__ KC_TRNS
#define _____ KC_NO

#define LSH_A LSFT_T(KC_A)
#define LCT_S LCTL_T(KC_S)
#define LAL_D LALT_T(KC_D)
#define LOS_F LGUI_T(KC_F)
#define ROS_J RGUI_T(KC_J)
#define RAL_K RALT_T(KC_K)
#define RCT_L RCTL_T(KC_L)
#define RSH_SC RSFT_T(KC_SCLN)

/* #define MY_AA XP(UC_SE_LOWER_AA, UC_SE_UPPER_AA) */
/* #define MY_AE XP(UC_SE_LOWER_AE, UC_SE_UPPER_AE) */
/* #define MY_OE XP(UC_SE_LOWER_OE, UC_SE_UPPER_OE) */

#define NP_TAB LT(_NUMPAD, KC_TAB)
#define F_1SH LT(_FUNC, OSM(MOD_LSFT))
enum custom_keycodes {
    EMAIL = SAFE_RANGE,
    MY_AA,
    MY_AE,
    MY_OE
};

/* enum unicode_names { */
/*     UC_SE_LOWER_AA, */
/*     UC_SE_LOWER_AE, */
/*     UC_SE_LOWER_OE, */
/*     UC_SE_UPPER_AA, */
/*     UC_SE_UPPER_AE, */
/*     UC_SE_UPPER_OE, */
/*     THUMBS_UP, */
/* }; */

/* const uint32_t PROGMEM unicode_map[] = { */
/*     [UC_SE_LOWER_AA]  = 0x00E5,  // */
/*     [UC_SE_LOWER_AE]  = 0x00E4,  // */
/*     [UC_SE_LOWER_OE]  = 0x00F6, // 🐍 */
/*     [UC_SE_UPPER_AA]  = 0x00C5,  // */
/*     [UC_SE_UPPER_AE]  = 0x00C4,  // */
/*     [UC_SE_UPPER_OE]  = 0x00D6, // 🐍 */
/*     [THUMBS_UP]       = 0x1F44D, // 🐍 */
/* }; */

enum layers {
    _QWERTY = 0,
    _NUMPAD,
    _MOVE,
    _FUNC,
    _TEXTRA
};

//
// NB: Created to be used with US. International keybord input source, primarily on mac OS
//


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ,-----------------------------------.                 ,------------------------------------.
     * |   Q   |   W  |  E   |  R   |  T   |                 |  Y   |  U   |  I   |  O   |   P    |
     * |-------+------+------+------+------|                 |------+------+------+------+--------|
     * | SH/ A | CTL/S| ALT/D| OS/F |  G   |                 |  H   | OS/J |ALT/K |CTL/L | SH/;:  |
     * |-------+------+------+------+------|                 |-------------+------+------+--------|
     * |   Z   |   X  |  C   |  V   |  B   |------.   ,------|  N   |  M   |  ,   |  .   |  / ?   |
     * `---------------------+------+------| SPC  |   |ENTER |------+------+------+---------------'
     *                       |F/1SH |NP/TAB|      |   |      | MOVE | BSPC |
     *                       `--------------------'   `--------------------'
     */

	[_QWERTY] = LAYOUT_split_3x5_3(
        KC_Q, KC_W, KC_E, KC_R, KC_T,      KC_Y, KC_U, KC_I, KC_O, KC_P,
        LSH_A, LCT_S, LAL_D, LOS_F, KC_G,  KC_H, ROS_J, RAL_K, RCT_L, RSH_SC,
        KC_Z, KC_X, KC_C, KC_V, KC_B,      KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
        F_1SH, NP_TAB, KC_SPC,     KC_ENT, MO(_MOVE), KC_BSPC),

    /*
     * ,-----------------------------------.                 ,-----------------------------------.
     * |  § ±  |      | - _  | " '  | TAB  |                 |  = + | 7 &  | 8 *  | 9    | [ {   |
     * |-------+------+------+------+------|                 |------+------+------+------+-------|
     * | SHIFT | CTL  | ALT  |  OS  | \ |  |                 |   .  | 4 $  | 5 %  | 6 '^'| SHIFT |
     * |-------+------+------+------+------|                 |-------------+------+------+-------|
     * | CAPSL | ` ~  |  (   |   )  | (<R>)|------.   ,------|  DEL | 1 !  | 2 @  | 3 #  | ] }   |
     * `---------------------+------+------|      |   |ENTER |------+------+------+--------------'
     *                       |      |      |      |   |      |TEXTRA|  0   |
     *                       `--------------------'   `--------------------'
     */

	[_NUMPAD] = LAYOUT_split_3x5_3(
        KC_GRV, _____, KC_MINS, KC_QUOT, KC_TAB,        KC_EQL, KC_7, KC_8, KC_P9, KC_LBRC,
        KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_BSLS,    KC_DOT, KC_4, KC_5, KC_6, KC_RSFT,
        KC_CAPS, KC_NUBS, KC_LPRN, KC_RPRN, _____,      KC_DEL, KC_1, KC_2, KC_3, KC_RBRC,
                        _____, __V__, __V__,            KC_ENT, MO(_TEXTRA), KC_P0
                                   ),


   /*
     * ,-----------------------------------.                 ,-----------------------------------.
     * | WH -> | WH ^ | WH v |WH <- | TAB  |                 |      |EJECT | STOP | VOL- | VOL+  |
     * |-------+------+------+------+------|                 |------+------+------+------+-------|
     * |  <-   |   v  |  ^   |  ->  | PG UP|                 | ESC  |  OS  | ALT  | CTL  | SHIFT |
     * |-------+------+------+------+------|                 |-------------+------+------+-------|
     * | MO <- | MO v | MO ^ |MO -> | PG DN|------.   ,------| PREV |  RWD | PLAY |  FF  | NEXT  |
     * `---------------------+------+------| MO 2 |   |ENTER |------+------+------+--------------'
     *                       | MO 1 |TEXTRA|      |   |      |      |      |
     *                       `--------------------'   `--------------------'
     */

	[_MOVE] = LAYOUT_split_3x5_3(
        KC_WH_R, KC_WH_U, KC_WH_D, KC_WH_L, KC_TAB,     _____, KC_EJCT, KC_MSTP, KC_VOLD, KC_VOLU,
        KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_PGUP,      KC_ESC, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT,
        KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_PGDN,    KC_MPRV, KC_MRWD, KC_MPLY, KC_MFFD, KC_MNXT,
                          KC_BTN1, MO(_TEXTRA), KC_BTN2,      KC_ENT, __V__, _____),


   /*
     * ,-----------------------------------.                 ,-----------------------------------.
     * |       |      |      |      | RST  |                 |PG UP |  F7  |  F8  |  F9  | F10   |
     * |-------+------+------+------+------|                 |------+------+------+------+-------|
     * | SHIFT | CTL  | ALT  |  OS  |      |                 |PG DN |  F4  |  F5  |  F6  | F11   |
     * |-------+------+------+------+------|                 |-------------+------+------+-------|
     * |       |      |      |      |      |------.   ,------|      |  F1  |  F2  |  F3  | F12   |
     * `---------------------+------+------|      |   |      |------+------+------+--------------'
     *                       |      |      |      |   |      |      | DEL  |
     *                       `--------------------'   `--------------------'
     */

	[_FUNC] = LAYOUT_split_3x5_3(
        _____, _____, _____, _____, RESET,           KC_PGUP, KC_F7, KC_F8, KC_F9, KC_F10,
        KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _____,   KC_PGDN, KC_F4, KC_F5, KC_F6, KC_F11,
        _____, _____, _____, _____, _____,           _____, KC_F1, KC_F2, KC_F3, KC_F12,
                      __V__, _____, _____,           _____, _____, KC_DEL),
   /*
     * ,-----------------------------------.                 ,-----------------------------------.
     * |       | @mail|      |      |      |                 |      |      |      |      |       |
     * |-------+------+------+------+------|                 |------+------+------+------+-------|
     * | SHIFT |      |      |      |      |                 |      |  Å   |  Ä   |  Ö   |       |
     * |-------+------+------+------+------|                 |-------------+------+------+-------|
     * |       |      |      |      |      |------.   ,------|      |      |      |      |       |
     * `---------------------+------+------|      |   |      |------+------+------+--------------'
     *                       |      |      |      |   |      |      |      |
     *                       `--------------------'   `--------------------'
     */

	[_TEXTRA] = LAYOUT_split_3x5_3(
                                   _____, EMAIL, _____, _____, _____,        _____, _____, _____, _____, _____,
                                   KC_LSFT, _____, _____, _____, _____,          _____, MY_AA, MY_AE, MY_OE, _____,
                                   _____, _____, _____, _____, _____,            _____, _____, _____, _____, _____,
                                   _____, __V__, _____,                          _____, __V__, _____)
   /*
     *x ,-----------------------------------.                 ,-----------------------------------.
     *x |       |      |      |      |      |                 |      |      |      |      |       |
     *x |-------+------+------+------+------|                 |------+------+------+------+-------|
     *x |       |      |      |      |      |                 |      |      |      |      |       |
     *x |-------+------+------+------+------|                 |-------------+------+------+-------|
     *x |       |      |      |      |      |------.   ,------|      |      |      |      |       |
     *x `---------------------+------+------|      |   |      |------+------+------+--------------'
     *x                       |      |      |      |   |      |      |      |
     *x                       `--------------------'   `--------------------'
     */

    // [_R] = LAYOUT_split_3x5_3(
    //      _____, _____, _____, _____, _____,      _____, _____, _____, _____, _____,
    //      _____, _____, _____, _____, _____,      _____, _____, _____, _____, _____,
    //      _____, _____, _____, _____, __V__,    _____, _____, _____, _____, _____,
    //                    _____, __V__, _____,    _____, _____, _____)

    // Layer template
    /*
     *x ,-----------------------------------.                 ,-----------------------------------.
     *x |       |      |      |      |      |                 |      |      |      |      |       |
     *x |-------+------+------+------+------|                 |------+------+------+------+-------|
     *x |       |      |      |      |      |                 |      |      |      |      |       |
     *x |-------+------+------+------+------|                 |-------------+------+------+-------|
     *x |       |      |      |      |      |------.   ,------|      |      |      |      |       |
     *x `---------------------+------+------|      |   |      |------+------+------+--------------'
     *x                       |      |      |      |   |      |      |      |
     *x                       `--------------------'   `--------------------'
     */
        // [_LAYERINDEX] = LAYOUT(
        //    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
        //    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
        //    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
        //                      _______, _______, _______,    _______, _______, _______,
        // ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    //    uint8_t shift_pressed = get_mods() & ((MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)));

    switch (keycode) {
    case EMAIL:
        if (record->event.pressed) {
            SEND_STRING("email@provider.com");
        }
        break;

    case MY_AA:
        if (record->event.pressed) {
            register_code16(A(KC_A));
        } else {
            unregister_code16(A(KC_A));
        }
        break;

    case MY_AE:
        // TODO: handle OSM shift - eaten up by "-tap
        if (record->event.pressed) {
            tap_code16(S(KC_QUOT));
            register_code(KC_A);
        } else {
            unregister_code(KC_A);
        }
        break;

    case MY_OE:
        // TODO: handle OSM shift - eaten up by "-tap
        if (record->event.pressed) {
            tap_code16(S(KC_QUOT));
            register_code(KC_O);
        } else {
            unregister_code(KC_O);
        }
        break;
    }
    return true;
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

    case NP_TAB:
        return THUMB_TAPPING_TERM;

    case LAL_D:
    case RAL_K:
        return INDEX_TAPPING_TERM;

    case LCT_S:
    case RCT_L:
        return RING_TAPPING_TERM;

    case LSH_A:
    case RSH_SC:
        return PINKY_TAPPING_TERM;

    default:
        return TAPPING_TERM;
    }
}
