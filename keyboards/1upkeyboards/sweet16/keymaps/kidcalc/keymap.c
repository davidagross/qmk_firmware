#include QMK_KEYBOARD_H

#define _TENKEY 0
#define _TKSHFT 1
#define _EMOJI  2

enum custom_keycodes {
    SHRUG = SAFE_RANGE,
    DISFACE,
    FU,
    TFLIP,
    TFLIP2,
    HAPPYFACE,
    HEARTFACE,
    CLOUD,
    BEAR,
    EXCLAIM,
    AT,
    HASH,
    UNDRSCR,
    CARET,
    AMP,
    TUV,
    LPAREN,
    CAPC,
    CAPF,
    PAUSE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Ten-Key Numpad //
    * ,-----------------------------------.
    * |    7   |    8   |    9   |    /   |
    * |--------+--------+--------+--------|
    * |    4   |    5   |    6   |    *   |
    * |--------+--------+--------+--------|
    * |    1   |    2   |    3   |    -   |
    * |--------+--------+--------+--------|
    * |  EMOJI |    0   | ./SHFT |    +   |
    * `-----------------------------------'
    */
    [_TENKEY] = LAYOUT_ortho_4x4(
        KC_7,       KC_8,   KC_9,   KC_SLSH,
        KC_4,       KC_5,   KC_6,   KC_ASTR,
        KC_1,       KC_2,   KC_3,   KC_MINS,
        MO(_EMOJI), KC_0,   LT(_TKSHFT,KC_DOT), KC_PPLS
    ),
    
        /* Shifted Ten-Key Numpad //
    * ,-----------------------------------.
    * |    &   |   TUV  |    (   |  BKSPC |
    * |--------+--------+--------+--------|
    * |    F   |    5   |    ^   | DELETE |
    * |--------+--------+--------+--------|
    * |    !   |    @   |    #   |  SPACE |
    * |--------+--------+--------+--------|
    * |  PAUSE |    C   |<URHERE>|    =   |
    * `-----------------------------------'
    */
    [_TKSHFT] = LAYOUT_ortho_4x4(
        AMP,    TUV,    LPAREN, KC_BSPC,
        CAPF,   KC_5,   CARET,  KC_DEL,
        EXCLAIM,AT,     HASH,   KC_SPC,
        PAUSE,  CAPC,   KC_NO,  KC_EQL
    ),
    
    /* EMOJI Pad
    * ,-----------------------------------.
    * |  TFLIP | TFlIP2 |   FU   |  BKSPC |
    * |--------+--------+--------+--------|
    * |  CLOUD | HRTFAC | DISFACE| DELETE |
    * |--------+--------+--------+--------|
    * |  SHRUG | HAPPYF |  BEAR  |  SPACE |
    * |--------+--------+--------+--------|
    * |<URHERE>| UC_OSX | UC_WINC|  ENTER |
    * `-----------------------------------'
    */
    [_EMOJI] = LAYOUT_ortho_4x4(
        TFLIP,   TFLIP2,   FU,          KC_BSPC, 
        CLOUD,   HEARTFACE,DISFACE,     KC_DEL, 
        SHRUG,   HAPPYFACE,BEAR,       KC_SPC,
        KC_NO,   UC_M_OS,  UC_M_WI,     KC_ENTER
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case CLOUD:     // (っ◕‿◕)っ
                if(record->event.pressed){
                    send_unicode_hex_string("0028 3063 25D5 203F 25D5 0029 3063");
                }
                return false;
                break;
            case FU:        // t(-_-t)
                if(record->event.pressed){
                    SEND_STRING("t(-_-t)");
                }
                return false;
                break;  
            case HAPPYFACE: // ʘ‿ʘ
                if(record->event.pressed){
                     send_unicode_hex_string("0298 203F 0298");
                }
                return false;
                break;  
            case SHRUG:     // ¯\_(ツ)_/¯
                if (record->event.pressed) {
                    send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
                }
                return false; 
                break;
            case HEARTFACE: // ♥‿♥
                if(record->event.pressed){
                    send_unicode_hex_string("2665 203F 2665");
                }
                return false;
                break;  
            case DISFACE:   // ಠ_ಠ 
                if(record->event.pressed){
                    send_unicode_hex_string("0CA0 005F 0CA0");
                }
                return false;
                break;
            case TFLIP:     // (╯°□°)╯ ︵ ┻━┻ 
                if(record->event.pressed){
                    send_unicode_hex_string("0028 256F 00B0 25A1 00B0 0029 256F 0020 FE35 0020 253B 2501 253B");
                }
                return false;
                break;
            case TFLIP2:    // ┻━┻︵ \(°□°)/ ︵ ┻━┻  
                if(record->event.pressed){
                    send_unicode_hex_string("253B 2501 253B FE35 0020 005C 0028 00B0 25A1 00B0 0029 002F 0020 FE35 0020 253B 2501 253B");
                }
                return false;
                break;
            case BEAR:    // ʕ•ᴥ•ʔ
                if(record->event.pressed){
                    send_unicode_hex_string("0295 2022 1D25 2022 0294");
                }
                return false;
                break;    
            case EXCLAIM:
                if(record->event.pressed){
                    SEND_STRING("!");
                }
                return false;
                break;
            case AT:
                if(record->event.pressed){
                    SEND_STRING("@");
                }
                return false;
                break;
            
            case HASH:
                if(record->event.pressed){
                    SEND_STRING("#");
                }
                return false;
                break;
            case UNDRSCR:
                if(record->event.pressed){
                    SEND_STRING("_");
                }
                return false;
                break;
            case CARET:
                if(record->event.pressed){
                    SEND_STRING("^");
                }
                return false;
                break;
            case AMP:
                if(record->event.pressed){
                    SEND_STRING("&");
                }
                return false;
                break;
            case TUV:
                if(record->event.pressed){
                    SEND_STRING("TUV");
                }
                return false;
                break;
            case LPAREN:
                if(record->event.pressed){
                    SEND_STRING("(");
                }
                return false;
                break;
            case CAPC:
                if(record->event.pressed){
                    SEND_STRING("C");
                }
                return false;
                break;
            case CAPF:
                if(record->event.pressed){
                    SEND_STRING("F");
                }
                return false;
                break;
            case PAUSE:
                if(record->event.pressed){
                    SEND_STRING("PAUSE");
                }
                return false;
                break;
        } 
    }
    return true;
}