


#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>



#include "common.h"

//#include "north_port.h"
//#include "south_port.h"
//#include "pass_east_west.h"
//#include "pass_north_south.h"




extern bool south_is_connected;
extern bool north_is_connected;
extern bool west_is_connected;
extern bool east_is_connected;


int main(void) 
{
    rgb_led_setup();
        
    north_port_setup_in();
    //north_port_setup_out();

    //south_port_setup_in();
    south_port_setup_out();
    


    while(1) {
        //test_north_port();
        test_south_port();
        // test_leds();

        //show_connection_state();
        
        //pass_south_to_north();
        //pass_north_to_south();

    }

}







