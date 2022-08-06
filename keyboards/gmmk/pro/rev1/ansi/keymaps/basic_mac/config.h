// Pixel fractal crashes the board for some reason. Remove the specific rgb effect.
#ifdef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
    #undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#endif

// Disable unused settings
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT
#define NO_ACTION_FUNCTION
#define NO_ACTION_MACRO
#define NO_ACTION_ONESHOT
#define DISABLE_LEADER


// Emulate Apple Keyboard vendor and product IDs
// #define VENDOR_ID 0x0267
// #define PRODUCT_ID 0x05AC
#ifdef DEBOUNCE
    #undef DEBOUNCE
#endif
#define DEBOUNCE 7

// Tap dance timeout of 175 milliseconds
#define TAPPING_TERM 300
#define TAPPING_TOGGLE 2

// Disable RGB lighting after some time
#define RGB_DISABLE_TIMEOUT 300000 // milliseconds
#define RGB_DISABLE_WHEN_USB_SUSPENDED 1

// Enable lighting effects
#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS // Heatmap, Rain
    #define RGB_MATRIX_KEYPRESSES // REACTIVE, SPLASH modes
    
    // Custom LED Effects
    #define ONLY_CAPS_INDICATOR
    #define RGB_SIDEBAR_OFF
    #define RGB_SIDEBAR
    #define INDICATOR_GRADIENT_UP_DOWN

#endif

// Enable Caps Word feature
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

