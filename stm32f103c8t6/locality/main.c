


#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>



#include "common.h"
//#include "stm32_sw_i2c.h"
#include "blocknet.h"


//#include "north_port.h"
//#include "south_port.h"
//#include "pass_east_west.h"
//#include "pass_north_south.h"


extern bool south_is_connected;
extern bool north_is_connected;
extern bool west_is_connected;
extern bool east_is_connected;


/*
int main(void)
{

    //setup_bnet_read();
    setup_bnet_write();

    while(1){
        BNET_SET_SCL
        BNET_SET_SDA
        BNET_CLEAR_SDA
        BNET_CLEAR_SCL
        for (int i = 0; i < 1000; ++i) __asm__("nop");

        BNET_SET_SCL
        BNET_CLEAR_SDA
        BNET_SET_SDA
        BNET_CLEAR_SCL
        for (int i = 0; i < 1000; ++i) __asm__("nop");


    }

    return 1;
} 
*/




/*
//RX TEST  
int main(void)
{
    rgb_led_setup();

    setup_bnet_read();
    while(1){
        uint8_t rb = bnet_receive_byte(0xff);
        if (rb==0x04){
            gpio_set(GPIOB, GPIO7);
        }else{
            gpio_clear(GPIOB, GPIO7);
            // blinkwait(dv, GPIOB, GPIO7); 
            // blinkwait(dv, GPIOB, GPIO8); 
            // blinkwait(dv, GPIOB, GPIO9);   

        }
    }

    return 1;
} 
*/


/*
//TX TEST 
int main(void)
{
    setup_bnet_write();
    while(1){
        //setup_bnet_write();
       
        bnet_send_byte(0xff, 0x02);
        for (int i = 0; i < 1000; ++i) __asm__("nop");
    }

    return 1;
} 
*/

////////////////////////////////////////////////////


/* 
int main(void)
{
    //setup_i2c_read();
    setup_i2c_write();
    //I2C_init();
    //I2C_start_cond

    while(1){
        //setup_bnet_write();

        I2C_send_byte(0xff, 0xaa);
        for (int i = 0; i < 1000; ++i) __asm__("nop");
        
        I2C_send_byte(0xff, 0xbb);
        for (int i = 0; i < 1000; ++i) __asm__("nop");
        
        I2C_send_byte(0xff, 0xcc);
        for (int i = 0; i < 1000; ++i) __asm__("nop");

    }

    return 1;
}
*/ 
 

////////////////////////////////////////////////////


 
int main(void) 
{
    //rgb_led_setup();
        
    //north_port_setup_in();
    //north_port_setup_out();

    //south_port_setup_in();
    south_port_setup_out();

    while(1) {
        //test_north_port();
        //test_south_port();
        
        //test_leds();

        blinkwait(100000, GPIOA, GPIO4); 
        //blinkwait(100000, GPIOA, GPIO3); 


        //show_connection_state();
        
        //pass_south_to_north();
        //pass_north_to_south();

    }

}
 






