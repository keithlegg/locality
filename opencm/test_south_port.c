#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>


static void south_port_setup(void)
{

    rcc_periph_clock_enable(RCC_GPIOB);

    gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ,
              GPIO_CNF_OUTPUT_PUSHPULL, GPIO5); 

    gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ,
              GPIO_CNF_OUTPUT_PUSHPULL, GPIO6);    

    gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ,
              GPIO_CNF_OUTPUT_PUSHPULL, GPIO7);  

    gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ,
              GPIO_CNF_OUTPUT_PUSHPULL, GPIO8);  

    gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ,
              GPIO_CNF_OUTPUT_PUSHPULL, GPIO9); 

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


static void test_south_port(void)
{
    int dv = 100000;

    blinkwait(dv, GPIOB, GPIO5); 
    blinkwait(dv, GPIOB, GPIO6); 
    blinkwait(dv, GPIOB, GPIO7);     
    blinkwait(dv, GPIOB, GPIO8); 
    blinkwait(dv, GPIOB, GPIO9); 
}


int main(void) 
{
    //north_port_setup();
    south_port_setup();

    while(1) {

        test_south_port();
    }

}













