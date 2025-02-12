#include QMK_KEYBOARD_H

void keyboard_pre_init_user() {
    gpio_write_pin(LED1, true);
    gpio_write_pin(LED2, true);
}

void keyboard_post_init_user() {
    gpio_write_pin(LED1, false);
    gpio_write_pin(LED2, false);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    gpio_write_pin(LED1, record->event.pressed);

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    gpio_write_pin(LED2, state);

    return state;
}