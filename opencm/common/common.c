
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#include "common.h"


void rgb_led_setup(void)
{
    // Enable GPIOA clock. 
    rcc_periph_clock_enable(RCC_GPIOB);

    gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ,
              GPIO_CNF_OUTPUT_PUSHPULL, GPIO7); 

    gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ,
              GPIO_CNF_OUTPUT_PUSHPULL, GPIO8);    

    gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ,
              GPIO_CNF_OUTPUT_PUSHPULL, GPIO9);  

}



void blinkwait(int dval, uint32_t port, uint32_t pin){
    gpio_set(port, pin); 
    for (int i = 0; i < dval; ++i) __asm__("nop");
    gpio_clear(port, pin); 
    for (int i = 0; i < dval; ++i) __asm__("nop");
}

















