/*****************************************************************
 * status.c                                                      *
 * Created: 4/27/2019 3:56:25 PM                                 *
 * Author : Nick Morris                                          *
 * s44373388 - Team 8 - METR4810                                 *
 * Toggle the status LEDs                                        *
 *****************************************************************/

#include "main.h"
#include "stdlib.h"
#include "status.h"

/*************************************************
* void led_off(int LED)                          *
* toggle the status leds                         *
*************************************************/
void led_off(int LED){
	
	switch(LED){
	case RED:
		HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, GPIO_PIN_RESET);	
 		break;
	
	case AMBER:
		HAL_GPIO_WritePin(YELLOW_GPIO_Port, YELLOW_Pin, GPIO_PIN_RESET);	
 		break;
	
	case GREEN:
		HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, GPIO_PIN_RESET);	
 		break;
	
	default:
		break;
	}
}
	
/*************************************************
* void led_on(int LED)                           *
* toggle the status leds on                      *
*************************************************/
void led_on(int LED){
	switch(LED){
	case RED:
		HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, GPIO_PIN_SET);	
 		break;
	
	case AMBER:
		HAL_GPIO_WritePin(YELLOW_GPIO_Port, YELLOW_Pin, GPIO_PIN_SET);	
 		break;
	
	case GREEN:
		HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, GPIO_PIN_SET);	
 		break;
	
	default:
		break;
	}	
}