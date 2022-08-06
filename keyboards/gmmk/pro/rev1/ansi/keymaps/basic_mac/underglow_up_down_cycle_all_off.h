#ifdef RGB_SIDEBAR_OFF

// #define RGB_MATRIX_CUSTOM_EFFECT_IMPLS
RGB_MATRIX_EFFECT(INDICATOR_RGB_OFF)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
static HSV INDICATOR_RGB_OFF_math(HSV hsv, uint8_t i, uint8_t time) {
    if (g_led_config.flags[i] == LED_FLAG_UNDERGLOW) {
        hsv.h = g_led_config.point[i].y - time;
        hsv.s = 255;
    } else {
        hsv.v = 0;
    }
    return hsv;
}

bool INDICATOR_RGB_OFF(effect_params_t* params) {
    return effect_runner_i(params, &INDICATOR_RGB_OFF_math);
}
#endif
#endif
