// Pixel fractal crashes the board for some reason. Remove the specific rgb effect.
#ifdef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
    #undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#endif

// Emulate Apple Keyboard vendor and product IDs
// #define VENDOR_ID 0x0267
// #define PRODUCT_ID 0x05AC
#ifdef DEBOUNCE
    #undef DEBOUNCE
#endif
#define DEBOUNCE 7

// Tap dance timeout of 175 milliseconds
#define TAPPING_TERM 175

// Disable RGB lighting after some time
#define RGB_DISABLE_TIMEOUT 120000 // milliseconds
#define RGB_DISABLE_WHEN_USB_SUSPENDED 1

// Disable the default encoder feature, since it duplicates inbuilt volume action
// #undef ENCODER_ENABLE

#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS // Heatmap, Rain
    #define RGB_MATRIX_KEYPRESSES // REACTIVE, SPLASH modes

#endif


// Custom LED Effects

#define ONLY_CAPS_INDICATOR
#define RGB_SIDEBAR
#define INDICATOR_GRADIENT_UP_DOWN
