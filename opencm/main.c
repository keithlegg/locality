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



static void rgb_led_setup(void)
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


//static void east_port_setup(void)

//static void west_port_setup(void)

static void north_port_setup(void)
{
    // Enable GPIOA clock. 
    rcc_periph_clock_enable(RCC_GPIOA);

    //gpio_set_mode(GPIOA, GPIO_MODE_INPUT,
    //          GPIO_CNF_INPUT_PULL_UPDOWN, GPIO0);

    gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_2_MHZ,
              GPIO_CNF_OUTPUT_PUSHPULL, GPIO0); 

    gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_2_MHZ,
              GPIO_CNF_OUTPUT_PUSHPULL, GPIO1);    

    gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_2_MHZ,
              GPIO_CNF_OUTPUT_PUSHPULL, GPIO2);  

    gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_2_MHZ,
              GPIO_CNF_OUTPUT_PUSHPULL, GPIO3);  

    gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_2_MHZ,
              GPIO_CNF_OUTPUT_PUSHPULL, GPIO4); 

    //set the pull up ON (default is OFF)
    /*
    gpio_set(GPIOA, GPIO0);
    gpio_set(GPIOA, GPIO1);
    gpio_set(GPIOA, GPIO2);
    gpio_set(GPIOA, GPIO3);
    gpio_set(GPIOA, GPIO4);
    */

    //set the pull ups OFF    
    /*
    gpio_clear(GPIOA, GPIO0);
    gpio_clear(GPIOA, GPIO1);
    gpio_clear(GPIOA, GPIO2);
    gpio_clear(GPIOA, GPIO3);
    gpio_clear(GPIOA, GPIO4);
    */

}

static void south_port_setup(void)
{

    rcc_periph_clock_enable(RCC_GPIOB);

    gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ,
              GPIO_CNF_OUTPUT_PUSHPULL, GPIO10); 

    gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ,
              GPIO_CNF_OUTPUT_PUSHPULL, GPIO11);    

    gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ,
              GPIO_CNF_OUTPUT_PUSHPULL, GPIO12);  

    gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ,
              GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);  

    gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ,
              GPIO_CNF_OUTPUT_PUSHPULL, GPIO14); 

    //set the pull up ON (default is OFF)
    /*
    gpio_set(GPIOB, GPIO5);
    gpio_set(GPIOB, GPIO6);
    gpio_set(GPIOB, GPIO7);
    gpio_set(GPIOB, GPIO8);
    gpio_set(GPIOB, GPIO9);
    */

    //set the pull ups OFF    
    /*
    gpio_clear(GPIOB, GPIO5);
    gpio_clear(GPIOB, GPIO6);
    gpio_clear(GPIOB, GPIO7);
    gpio_clear(GPIOB, GPIO8);
    gpio_clear(GPIOB, GPIO9);
    */

}



static void blinkwait(int dval, uint32_t port, uint32_t pin){
    gpio_set(port, pin); 
    for (int i = 0; i < dval; ++i) __asm__("nop");
    gpio_clear(port, pin); 
    for (int i = 0; i < dval; ++i) __asm__("nop");
}

static void test_north_port(void)
{
    int dv = 100000;

    blinkwait(dv, GPIOA, GPIO0); 
    blinkwait(dv, GPIOA, GPIO1); 
    blinkwait(dv, GPIOA, GPIO2);     
    blinkwait(dv, GPIOA, GPIO3); 
    blinkwait(dv, GPIOA, GPIO4); 
}

static void test_south_port(void)
{
    int dv = 100000;

    blinkwait(dv, GPIOB, GPIO10); 
    blinkwait(dv, GPIOB, GPIO11); 
    blinkwait(dv, GPIOB, GPIO12);     
    blinkwait(dv, GPIOB, GPIO13); 
    blinkwait(dv, GPIOB, GPIO14); 
}


static void test_leds(void)
{
    int dv = 100000;

    blinkwait(dv, GPIOB, GPIO7); 
    blinkwait(dv, GPIOB, GPIO8); 
    blinkwait(dv, GPIOB, GPIO9);     
}


int main(void) 
{
    north_port_setup();
    south_port_setup();
    rgb_led_setup();

    while(1) {
        //poll_button_state();

        test_north_port();
        test_south_port();
        test_leds();
    }

}


















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


