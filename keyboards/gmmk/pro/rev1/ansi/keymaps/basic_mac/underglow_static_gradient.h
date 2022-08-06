#ifdef INDICATOR_GRADIENT_UP_DOWN
RGB_MATRIX_EFFECT(INDICATOR_STATIC_GRADIENT)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool INDICATOR_STATIC_GRADIENT(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV     hsv   = rgb_matrix_config.hsv;
    uint8_t scale = scale8(64, rgb_matrix_config.speed);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        if (g_led_config.flags[i] == LED_FLAG_UNDERGLOW) {
        // The y range will be 0..64, map this to 0..4
        // Relies on hue being 8-bit and wrapping
            hsv.h   = rgb_matrix_config.hsv.h + scale * (g_led_config.point[i].y >> 4);
            RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        } else {
            rgb_matrix_set_color(i, 60, 60, 60);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#    endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif     // ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
