//HEADER FILE
/*****************************************************************
 * status.h                                                      *
 * Created: 4/27/2019 3:56:25 PM                                 *
 * Author : Nick Morris                                          *
 * s44373388 - Team 8 - METR4810                                 *
 * Linear Actuation given a desired and current position         *
 *****************************************************************/

#define RED 0
#define AMBER 1
#define GREEN 2

/*************************************************
* void led_on(int LED)                           *
* toggle the status leds on                      *
*************************************************/
void led_on(int LED);

/*************************************************
* void led_off(int LED)                          *
* toggle the status leds                         *
*************************************************/
void led_off(int LED);
