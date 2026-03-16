#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define Decrese_botton 3
#define Increse_botton 4
#define LED_A 5
#define LED_B 6
#define LED_C 7
#define LED_D 8
#define LED_E 9
#define LED_F 10
#define LED_G 11
#define Source 11


static inline bool btn_pressed(gpio_num_t pin) {
    if(gpio_get_level(pin) == 0) {
        return true;
    }
    else {
        return false;
    }
}


void app_main() {

    gpio_config_t out_cfg = {
        .pin_bit_mask = (1ULL << LED_A) | (1ULL << LED_B) | (1ULL << LED_C)| (1ULL << LED_D)| (1ULL << LED_E)| (1ULL << LED_F)| (1ULL << LED_G),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };

    gpio_config(&out_cfg);
    gpio_set_level(LED_A, 0);
    gpio_set_level(LED_B, 0);
    gpio_set_level(LED_C, 0);
    gpio_set_level(LED_D, 0);
    gpio_set_level(LED_E, 0);
    gpio_set_level(LED_F, 0);
    gpio_set_level(LED_G, 0);

    gpio_config_t in_cfg = {
        .pin_bit_mask = (1ULL << Decrese_botton) | (1ULL << Increse_botton),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };

    gpio_config(&in_cfg);
    int counter = 0;

    while(1) {
        bool up = btn_pressed(Decrese_botton);
        bool down = btn_pressed(Increse_botton);
       if(up) {
            counter++;
        }
        else if(down) {
            counter--;
        }
        if(counter==0){
            gpio_set_level(LED_A, 0);
            gpio_set_level(LED_B, 1);
            gpio_set_level(LED_C, 1);
            gpio_set_level(LED_D, 1);
            gpio_set_level(LED_E, 1);
            gpio_set_level(LED_F, 1);
            gpio_set_level(LED_G, 0);;
        }
        if (counter==1){
            gpio_set_level(LED_A, 0);
            gpio_set_level(LED_B, 1);
            gpio_set_level(LED_C, 1);
            gpio_set_level(LED_D, 0);
            gpio_set_level(LED_E, 0);
            gpio_set_level(LED_F, 0);
            gpio_set_level(LED_G, 0);
        }
        if (counter==2){
            gpio_set_level(LED_A, 1);
            gpio_set_level(LED_B, 1);
            gpio_set_level(LED_C, 0);
            gpio_set_level(LED_D, 1);
            gpio_set_level(LED_E, 1);
            gpio_set_level(LED_F, 0);
            gpio_set_level(LED_G, 1);
        }
        if (counter==3){
            gpio_set_level(LED_A, 1);
            gpio_set_level(LED_B, 1);
            gpio_set_level(LED_C, 1);
            gpio_set_level(LED_D, 1);
            gpio_set_level(LED_E, 0);
            gpio_set_level(LED_F, 0);
            gpio_set_level(LED_G, 1);
        }
        if (counter==4){
            gpio_set_level(LED_A, 0);
            gpio_set_level(LED_B, 1);
            gpio_set_level(LED_C, 1);
            gpio_set_level(LED_D, 0);
            gpio_set_level(LED_E, 0);
            gpio_set_level(LED_F, 1);
            gpio_set_level(LED_G, 1);
        }
        if (counter==5){
            gpio_set_level(LED_A, 1);
            gpio_set_level(LED_B, 0);
            gpio_set_level(LED_C, 1);
            gpio_set_level(LED_D, 1);
            gpio_set_level(LED_E, 0);
            gpio_set_level(LED_F, 1);
            gpio_set_level(LED_G, 1);
        }
        if (counter==6){
            gpio_set_level(LED_A, 1);
            gpio_set_level(LED_B, 0);
            gpio_set_level(LED_C, 1);
            gpio_set_level(LED_D, 1);
            gpio_set_level(LED_E, 1);
            gpio_set_level(LED_F, 1);
            gpio_set_level(LED_G, 1);
        }
        if (counter==7){
            gpio_set_level(LED_A, 1);
            gpio_set_level(LED_B, 1);
            gpio_set_level(LED_C, 1);
            gpio_set_level(LED_D, 0);
            gpio_set_level(LED_E, 0);
            gpio_set_level(LED_F, 0);
            gpio_set_level(LED_G, 0);
        }
        if (counter==8){
            gpio_set_level(LED_A, 1);
            gpio_set_level(LED_B, 1);
            gpio_set_level(LED_C, 1);
            gpio_set_level(LED_D, 1);
            gpio_set_level(LED_E, 1);
            gpio_set_level(LED_F, 1);
            gpio_set_level(LED_G, 1);
        }
        if (counter==9){
            LED_A=1;
            LED_B=1;
            LED_C=1;
            LED_D=1;
            LED_E=0;
            LED_F=1;
            LED_G=1;
        }



        vTaskDelay(pdMS_TO_TICKS(100));
    }
}