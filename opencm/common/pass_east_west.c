#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>


// Set STM32 to 24 MHz. 
//static void clock_setup(void)
//rcc_clock_setup_pll(&rcc_hse_configs[RCC_CLOCK_HSE8_24MHZ]);


/*
static void gpio_setup(void)
{
    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_GPIOC);

    gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);
    gpio_set_mode(GPIOA, GPIO_MODE_INPUT, GPIO_CNF_INPUT_PULL_UPDOWN, GPIO0);

    // Set GPIO9 (in GPIO port C) to 'output push-pull'. //
    //gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_50_MHZ,
    //          GPIO_CNF_OUTPUT_PUSHPULL, GPIO9);
}
*/




/*
static void poll_button_state(void)
{
    int state = 0;
    state = gpio_get(GPIOA, GPIO0);

    if (state==0x0001){
        gpio_set(GPIOC, GPIO13);            
    }else{
        gpio_clear(GPIOC, GPIO13);            
    }  
}
*/

/*
static void poll_button_state(void)
{
    int pa_reg = 0;
    pa_reg = gpio_port_read(GPIOA);

    if (pa_reg &(1<<1))
    {
        gpio_set(GPIOC, GPIO13);            
    }else{
        gpio_clear(GPIOC, GPIO13);            
    }  
}
*/



