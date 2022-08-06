
#ifdef RGB_SIDEBAR

// #define RGB_MATRIX_CUSTOM_EFFECT_IMPLS
RGB_MATRIX_EFFECT(INDICATOR_RGB)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
static HSV INDICATOR_RGB_math(HSV hsv, uint8_t i, uint8_t time) {
    if (g_led_config.flags[i] == LED_FLAG_UNDERGLOW) {
        hsv.h = g_led_config.point[i].y - time;
        hsv.s = 255;
    }
    return hsv;
}

bool INDICATOR_RGB(effect_params_t* params) {
    return effect_runner_i(params, &INDICATOR_RGB_math);
}
#endif
#endif
