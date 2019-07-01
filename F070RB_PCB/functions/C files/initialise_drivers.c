/*****************************************************************
 * initialise_drivers.c                                          *
 * Created: 4/27/2019 3:56:25 PM                                 *
 * Author : Nick Morris                                          *
 * s44373388 - Team 8 - METR4810                                 *
 * Initialise the drivers by toggling the enable pins            *
 *****************************************************************/
#include "initialise_drivers.h"
#include "main.h"

/***********************************************************************
** Handler enable pins:                                               **
** ENB1 corresponds to linear actuator                                **
** ENB2 corresponds to x axis rotation                                **
** ENB3 corresponds to y axis rotation                                **
**                                                                    **
** Submachine enable pins:                                            **
** ENB1 corresponds to vertical actuation motor                       **
** ENB2 corresponds to horizontal actuation motor                     **
***********************************************************************/

/***********************************************************************
** void initialise__handler_drivers(void)                             **
** Initialises the handler's stepper drivers                          **
***********************************************************************/
void initialise_handler_drivers(void)
{
	//Disable linear actuation stepper motor
	HAL_GPIO_WritePin(ENB1_GPIO_Port, ENB1_Pin, GPIO_PIN_SET); 
	//Enable rotation stepper motors
	HAL_GPIO_WritePin(ENB2_GPIO_Port, ENB1_Pin, GPIO_PIN_RESET); 
	HAL_GPIO_WritePin(ENB3_GPIO_Port, ENB1_Pin, GPIO_PIN_RESET); 
}

/***********************************************************************
** void initialise_drivers(void)                                      **
** Initialises the stepper drivers to OFF by setting enable to high   **
***********************************************************************/
void initialise_drivers(void)
{
	//Disable stepper drivers
	HAL_GPIO_WritePin(ENB1_GPIO_Port, ENB1_Pin, GPIO_PIN_SET); 
	HAL_GPIO_WritePin(ENB2_GPIO_Port, ENB2_Pin, GPIO_PIN_SET);
}
