


#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>



#include "common.h"
#include "stm32_sw_i2c.h"


//#include "north_port.h"
//#include "south_port.h"
//#include "pass_east_west.h"
//#include "pass_north_south.h"




extern bool south_is_connected;
extern bool north_is_connected;
extern bool west_is_connected;
extern bool east_is_connected;






/*
void I2C_bus_init(uint8_t scl_pin, uint8_t sda_pin, uint8_t port){
    //Configure GPIO pins : SW_I2C_SCL_Pin SW_I2C_SDA_Pin 
    GPIO_InitStruct.Pin = SW_I2C_SCL_Pin|SW_I2C_SDA_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}
*/


 
int main(void)
{
    //setup_i2c_read();
    setup_i2c_write();

    //north_port_setup_in();

    //I2C_init();

    //I2C_start_cond

    while(1){
        I2C_send_byte(0xff, 0x55);
        for (int i = 0; i < 100; ++i) __asm__("nop");

        //I2C_write_byte(0x33, true, false);

        //#define I2C_CLEAR_SDA gpio_clear(SW_I2C_SDA_GPIO_Port, SW_I2C_SDA_Pin);
        //#define I2C_SET_SDA gpio_set(SW_I2C_SDA_GPIO_Port, SW_I2C_SDA_Pin);
        //#define I2C_CLEAR_SCL gpio_clear(SW_I2C_SCL_GPIO_Port, SW_I2C_SCL_Pin);
        //#define I2C_SET_SCL gpio_set(SW_I2C_SCL_GPIO_Port, SW_I2C_SCL_Pin);
        //#define I2C_DELAY DWT_Delay_us(5); // 5 microsecond delay

        /* 
        I2C_write_bit(0x00);
        for (int i = 0; i < 100; ++i) __asm__("nop");
        I2C_write_bit(0xaa);
        for (int i = 0; i < 100; ++i) __asm__("nop");   
        */  
    }

    return 1;
}

 




/*
int main(void) 
{
    rgb_led_setup();
        
    north_port_setup_in();
    //north_port_setup_out();

    //south_port_setup_in();
    south_port_setup_out();

    while(1) {
        //test_north_port();
        //test_south_port();
        //test_leds();

        //show_connection_state();
        
        //pass_south_to_north();
        pass_north_to_south();

    }

}
*/







