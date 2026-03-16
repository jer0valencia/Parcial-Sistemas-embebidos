void app_main()
{
    gpio_config_t in_cfg = {
        .pin_bit_mask = (1ULL << SIGNAL_IN),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = 0,
        .pull_down_en = 0,
        .intr_type = GPIO_INTR_POSEDGE
    };

    gpio_config(&in_cfg);

    gpio_config_t out_cfg = {
        .pin_bit_mask = (1ULL<<LED1)|(1ULL<<LED2)|(1ULL<<LED3)|(1ULL<<LED4),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = 0,
        .pull_down_en = 0,
        .intr_type = GPIO_INTR_DISABLE
    };

    gpio_config(&out_cfg);

    gpio_install_isr_service(0);
    gpio_isr_handler_add(SIGNAL_IN, pulse_isr, NULL);
