/*
 * SpaceFN layout
 * http://geekhack.org/index.php?topic=51069.0
 */
#include "keymap_common.h"
#include "command.h"
#include "bootloader.h"
#include <util/delay.h>

#define QWERTY_LAYER 0
#define F1_LAYER 1
#define F2_LAYER 2
#define MEDIA_LAYER 3
#define F4_LAYER 4
#define F5_LAYER 5

// Fillers to make layering more clear
#define _______ KC_TRNS
#define oo KC_TRNS
#define XXXXXXX KC_NO

// My macros
#define S_6 FN6
#define S_GRV FN7
#define S_1 FN8
#define S_2 FN9
#define S_3 FN10
#define S_4 FN11
#define S_5 FN12
#define S_7 FN13
#define S_8 FN14
#define S_9 FN15
#define S_0 FN16
#define S_LBRC FN17
#define S_RBRC FN18
#define S_QUOT FN19
#define S_MINS FN20
#define S_EQL FN21

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: default
     * ,---.   ,---------------. ,---------------. ,---------------. ,-----------.     ,-----------.
     * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|     |Pwr|Slp|Wak|
     * `---'   `---------------' `---------------' `---------------' `-----------'     `-----------'
     * ,-----------------------------------------------------------. ,-----------. ,---------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|Bks| |Ins|Hom|PgU| |NmL|  /|  *|  -|
     * |-----------------------------------------------------------| |-----------| |---------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \| |Del|End|PgD| |  7|  8|  9|   |
     * |-----------------------------------------------------------| `-----------' |-----------|  +|
     * |CapsLo|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |               |  4|  5|  6|   |
     * |-----------------------------------------------------------|     ,---.     |---------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|RO|Shift  |     |Up |     |  1|  2|  3|   |
     * |-----------------------------------------------------------| ,-----------. |-----------|Ent|
     * |Ctrl |    |Alt |         Space         |Alt |    |    |Ctrl| |Lef|Dow|Rig| |      0|  .|   |
     * `-----------------------------------------------------------' `-----------' `---------------'
     */
    [QWERTY_LAYER] = KEYMAP_MODELM(
    ESC,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,               oo, oo, oo,

    ESC,  1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, GRV,BSLS,     oo, oo, oo,    oo,  oo,  oo,  oo,
    TAB,  Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,    BSPC,     oo, oo, oo,    oo,  oo,  oo,
    FN2,  A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,          ENT,                    oo,  oo,  oo,  oo,
    LSFT,LGUI,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, FN5, FN22,      FN1,         oo,        oo,  oo,  oo,
    FN4,      LALT,             FN0,                       RALT,           FN3,     oo, oo, oo,    oo,       oo,  oo
    ),

    [F1_LAYER] = KEYMAP_MODELM(
    TRNS,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,             oo, oo, oo,

    GRV,   F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,TRNS,   oo, oo, oo,    oo,  oo,  oo,  oo,
    TRNS,  TRNS,TRNS,TRNS,TRNS,GRV, TRNS,HOME,TRNS,MINS,EQL, GRV, TRNS,     TRNS,   oo, oo, oo,    oo,  oo,  oo,
    TRNS,  TRNS,TRNS,TRNS,TRNS,S_GRV, LEFT,DOWN,UP,  RGHT,BSPC,TRNS,        TRNS,                  oo,  oo,  oo,  oo,
    TRNS,LGUI,TRNS,TRNS,TRNS,TRNS,S_6, END, DEL, INS, PGUP,PGDN,TRNS,       TRNS,       oo,        oo,  oo,  oo,
    TRNS,     TRNS,             TRNS,                 TRNS,                 TRNS,   oo, oo, oo,    oo,       oo,  oo
    ),

    [F2_LAYER] = KEYMAP_MODELM(
    TRNS,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,                   oo, oo, oo,

    TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS, TRNS, TRNS, TRNS,TRNS,  TRNS, TRNS,TRNS,   oo, oo, oo,    oo,  oo,  oo,  oo,
    TRNS,  S_1, S_2, S_3, S_4, S_5, S_6, S_7, S_8, S_9, S_0, TRNS,     TRNS,      TRNS,   oo, oo, oo,    oo,  oo,  oo,
    TRNS,  S_9, S_0,S_LBRC, S_RBRC, NO,  NO, QUOT, S_QUOT, S_MINS, S_EQL, TRNS,   TRNS,                  oo,  oo,  oo,  oo,
    TRNS,LGUI,LBRC, RBRC, TRNS,TRNS,  NO, TRNS, TRNS,TRNS,TRNS,TRNS, TRNS,        TRNS,       oo,        oo,  oo,  oo,
    TRNS,     TRNS,               TRNS,                    TRNS,                  TRNS,   oo, oo, oo,    oo,       oo,  oo
    ),

    [MEDIA_LAYER] = KEYMAP_MODELM(
    TRNS,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,             oo, oo, oo,

    PWR, TRNS, TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   oo, oo, oo,    oo,  oo,  oo,  oo,
    SLEP,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS, TRNS,TRNS,TRNS,    TRNS,   oo, oo, oo,    oo,  oo,  oo,
    TRNS,  TRNS,MPRV,MNXT,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,                  oo,  oo,  oo,  oo,
    TRNS,TRNS,VOLU,VOLD,MUTE,MPLY,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,       TRNS,       oo,        oo,  oo,  oo,
    TRNS,     TRNS,             TRNS,                 TRNS,                 TRNS,   oo, oo, oo,    oo,       oo,  oo
    )

    // Template
    // [EXAMPLE_LAYER] = KEYMAP_MODELM(
    // TRNS,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,             oo, oo, oo,
    //
    // TRNS,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   oo, oo, oo,    oo,  oo,  oo,  oo,
    // TRNS,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,   oo, oo, oo,    oo,  oo,  oo,
    // TRNS,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,                  oo,  oo,  oo,  oo,
    // TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,       TRNS,       oo,        oo,  oo,  oo,
    // TRNS,     TRNS,             TRNS,                 TRNS,                 TRNS,   oo, oo, oo,    oo,       oo,  oo
    // ),
};

const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_KEY(F1_LAYER,    KC_SPACE),
    [1] = ACTION_LAYER_TAP_KEY(F2_LAYER,    KC_APP),
    [2] = ACTION_MODS_TAP_KEY(MOD_LCTL,     KC_TAB),
    [3] = ACTION_LAYER_TAP_KEY(F2_LAYER,    KC_PSCR),
    [4] = ACTION_LAYER_TAP_TOGGLE(F1_LAYER),
    [5] = ACTION_LAYER_TAP_KEY(MEDIA_LAYER, KC_SLSH),
    [6] = ACTION_KEY(MOD_LSFT | KC_6),      // S_6
    [7] = ACTION_KEY(MOD_LSFT | KC_GRV),    // S_GRV
    [8] = ACTION_KEY(MOD_LSFT | KC_1),      // S_1
    [9] = ACTION_KEY(MOD_LSFT | KC_2),      // S_2
    [10] = ACTION_KEY(MOD_LSFT | KC_3),     // S_3
    [11] = ACTION_KEY(MOD_LSFT | KC_4),     // S_4
    [12] = ACTION_KEY(MOD_LSFT | KC_5),     // S_5
    [13] = ACTION_KEY(MOD_LSFT | KC_7),     // S_7
    [14] = ACTION_KEY(MOD_LSFT | KC_8),     // S_8
    [15] = ACTION_KEY(MOD_LSFT | KC_9),     // S_9
    [16] = ACTION_KEY(MOD_LSFT | KC_0),     // S_0
    [17] = ACTION_KEY(MOD_LSFT | KC_LBRC),  // S_LBRC
    [18] = ACTION_KEY(MOD_LSFT | KC_RBRC),  // S_RBRC
    [19] = ACTION_KEY(MOD_LSFT | KC_QUOT),  // S_QUOT
    [20] = ACTION_KEY(MOD_LSFT | KC_MINS),  // S_MINS
    [21] = ACTION_KEY(MOD_LSFT | KC_EQL),   // S_EQL
    [22] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_DEL),
};

bool command_extra(uint8_t code)
{
    switch (code) {
        case KC_B:
            clear_keyboard();
            print("\n\nJump to bootloader... ");
            _delay_ms(1000);
            bootloader_jump(); // not return
            print("not supported.\n");
            break;
    }
    return false;
}
