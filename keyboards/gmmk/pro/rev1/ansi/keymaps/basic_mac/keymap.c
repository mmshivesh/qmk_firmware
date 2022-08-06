/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum custom_keycodes {
  KC_MISSION_CONTROL = SAFE_RANGE,  // Mission Control
  KC_LAUNCHPAD, // Launchpad
  RGB_E_H,  // Change Hue of the Lighting with the Encoder
  RGB_E_S,  // Change Saturation of the Lighting with the Encoder
  RGB_E_V   // Change Value of the Lighting with the Encoder
//   KC_TAUNTXT
};

enum {
    TD_F1_BRID,
    TD_F2_BRIU,
    TD_F3_MCTL,
    TD_F4_LPAD,
    TD_F7_PREV,
    TD_F8_PPAU,
    TD_F9_NEXT,
    TD_F10_MUTE,
    TD_F11_VOLD,
    TD_F12_VOLU
};


// Use Cleanshot X shortcuts instead
// #define KC_SCRCPY LGUI(LSFT(LCTL(KC_4)))
#define KC_SCRCPY LGUI(LSFT(KC_2))

#define KC_SCR LGUI(LSFT(KC_3))
#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD


qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_F1_BRID] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_BRID),
    [TD_F2_BRIU] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_BRIU),
    [TD_F3_MCTL] = ACTION_TAP_DANCE_DOUBLE(KC_F3, KC_MCTL),
    [TD_F4_LPAD] = ACTION_TAP_DANCE_DOUBLE(KC_F4, KC_LPAD),
    [TD_F7_PREV] = ACTION_TAP_DANCE_DOUBLE(KC_F7, KC_MPRV),
    [TD_F8_PPAU] = ACTION_TAP_DANCE_DOUBLE(KC_F8, KC_MPLY),
    [TD_F9_NEXT] = ACTION_TAP_DANCE_DOUBLE(KC_F9, KC_MNXT),
    [TD_F10_MUTE] = ACTION_TAP_DANCE_DOUBLE(KC_F10, KC_MUTE),
    [TD_F11_VOLD] = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_VOLD),
    [TD_F12_VOLU] = ACTION_TAP_DANCE_DOUBLE(KC_F12, KC_VOLU)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// RGB LED layout

// led number, function of the key

//  67, Side led 01    0, ESC      6, F1       12, F2       18, F3       23, F4       28, F5       34, F6       39, F7       44, F8       50, F9       56, F10      61, F11      66, F12      69, Prt       Rotary(Mute)   68, Side led 12
//  70, Side led 02    1, ~        7, 1        13, 2        19, 3        24, 4        29, 5        35, 6        40, 7        45, 8        51, 9        57, 0        62, -_       78, (=+)     85, BackSpc   72, Del        71, Side led 13
//  73, Side led 03    2, Tab      8, Q        14, W        20. E        25, R        30, T        36, Y        41, U        46, I        52, O        58, P        63, [{       89, ]}       93, \|        75, PgUp       74, Side led 14
//  76, Side led 04    3, Caps     9, A        15, S        21, D        26, F        31, G        37, H        42, J        47, K        53, L        59, ;:       64, '"                    96, Enter     86, PgDn       77, Side led 15
//  80, Side led 05    4, Sh_L     10, Z       16, X        22, C        27, V        32, B        38, N        43, M        48, ,<       54, .<       60, /?                    90, Sh_R     94, Up        82, End        81, Side led 16
//  83, Side led 06    5, Ct_L     11,Win_L    17, Alt_L                              33, SPACE                              49, Alt_R    55, FN                    65, Ct_R     95, Left     97, Down      79, Right      84, Side led 17
//  87, Side led 07                                                                                                                                                                                                        88, Side led 18
//  91, Side led 08       

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.

    [0] = LAYOUT(
        KC_ESC,  TD(TD_F1_BRID),   TD(TD_F2_BRIU),   TD(TD_F3_MCTL),   TD(TD_F4_LPAD),   KC_F5,   KC_F6,   TD(TD_F7_PREV),   TD(TD_F8_PPAU),   TD(TD_F9_NEXT),   TD(TD_F10_MUTE),  TD(TD_F11_VOLD),  TD(TD_F12_VOLU),  KC_SCRCPY,  KC_SYSTEM_SLEEP,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_HOME,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LALT, KC_LGUI,                             KC_SPC,                            KC_RGUI, KC_RALT, TT(1) ,  KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, KC_SCR,           _______,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,           _______,
        _______, RGB_E_H, RGB_E_S, RGB_E_V, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),
};


void set_side_leds(int r, int g, int b) {
    int side_leds[16] = {67, 70, 73, 76, 80, 83, 87, 91, 68, 71, 74, 77, 81, 84, 88, 92};
    for (int i = 0; i < 16; i++) {
        rgb_matrix_set_color(side_leds[i], r,g,b);
    }
}


static bool hue_pressed = false;
static bool sat_pressed = false;
static bool val_pressed = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // static bool tAuNtTeXt = false;

    // if (tAuNtTeXt) {
    //     if (record->event.pressed) {
    //         if (keycode != KC_SPC) {
    //             register_code(KC_CAPS);
    //             unregister_code(KC_CAPS);
    //         }
    //     }
    // }
    switch (keycode) {
        case RGB_E_H:
            if (record->event.pressed) hue_pressed = true;
            else hue_pressed = false;
            return false;
        case RGB_E_S:
            if (record->event.pressed) sat_pressed = true;
            else sat_pressed = false;
            return false;
        case RGB_E_V:
            if (record->event.pressed) val_pressed = true;
            else val_pressed = false;
            return false;
        // case KC_TAUNTXT:
        //     if (record->event.pressed) {
        //         tAuNtTeXt = !tAuNtTeXt;
        //         // when it's turned on, toggle caps lock (makes first letter lowercase)
        //         if (tAuNtTeXt) {
        //             register_code(KC_CAPS);
        //             unregister_code(KC_CAPS);
        //         } 
        //     }
        //     return false;
        // Custom keycodes for Mission Control and Launchpad
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}


static bool tabbing = false;
static uint16_t tabtimer;
#define TABBING_TIMER 750

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (biton32(layer_state)) {
            case 1:
                if (clockwise) {
                    if (hue_pressed) rgblight_increase_hue_noeeprom();
                    else if (sat_pressed) rgblight_increase_sat_noeeprom();
                    else if (val_pressed) rgblight_increase_val_noeeprom();
                    else tap_code16(KC_VOLU);
                } else {
                    if (hue_pressed) rgblight_decrease_hue_noeeprom();
                    else if (sat_pressed) rgblight_decrease_sat_noeeprom();
                    else if (val_pressed) rgblight_decrease_val_noeeprom();
                    else tap_code16(KC_VOLD);
                }
                return false;
            default:
                if ((get_mods() & MOD_BIT(KC_LGUI)) || (get_mods() & MOD_BIT(KC_RGUI))) {
                    if (clockwise) {
                        // MOVE FORWARD, COMMAND+TAB
                        tabtimer = timer_read();
                        if(!tabbing) {
                            register_code(KC_LGUI);
                            tabbing = true;
                        }
                        tap_code(KC_TAB);
                    }
                    else {
                        // MOVE BACKWARDS, COMMAND+TAB, THEN TILDE
                        tabtimer = timer_read();
                        if(!tabbing) {
                            register_code(KC_LGUI);
                            // Open ⌘+tab window, moves ahead one app
                            tap_code(KC_TAB);
                            // Move one app behind, i.e. back to the current app.
                            tap_code(KC_GRV);
                            tabbing = true;
                        }
                        // Move behind applications.
                        tap_code(KC_GRV);
                    }
                    break;
                }
                else {
                    if (clockwise) {
                        // tap_code16(LSFT(LALT(KC_VOLU)));
                        tap_code16(KC_VOLU);
                    } else {
                        // tap_code16(LSFT(LALT(KC_VOLD)));
                        tap_code16(KC_VOLD);
                    }
                }
                break;
        }
    }
    // returning false so that the inbuilt encoder function doesn't do anything
    return false;
}


void matrix_scan_user(void) {
  if(tabbing) {
    if (timer_elapsed(tabtimer) > TABBING_TIMER) {
      unregister_code(KC_LGUI);
      tabbing = false;
    }
  }
}

void rgb_matrix_indicators_user() {
    if (IS_LAYER_ON(1)) {
        rgb_matrix_set_color(8, RGB_RED);
        rgb_matrix_set_color(14, RGB_RED);
        rgb_matrix_set_color(20, RGB_RED);
    }
    if (host_keyboard_led_state().caps_lock) {
        set_side_leds(255,255,255);
    }
}
