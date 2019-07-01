/*****************************************************************
 * vertical_actuation.c                                          *
 * Created: 4/27/2019 3:56:25 PM                                 *
 * Author : Nick Morris          *
 * s44373388 - Team 8 - METR4810                                 *
 * Linear Actuation given a desired and current position         *
 *****************************************************************/

#include "main.h"
#include "math.h"
#include "stdlib.h"
#include "vertical_actuation.h"

//Variable to keep track of vertical position
int current_vertical_position = 0;

/*************************************************
* void test_function(void)                       *
* Test function to test actuator functionality   *
* Rotate the steppers back and forth 4 rotations *
*************************************************/
void test_vertical_function(void){
	HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_SET);

	for(int i = 0; i < 800; i++){
		HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_RESET);
		HAL_Delay(1);
	}
	HAL_Delay(1000);
	HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_RESET);
	
	for(int i = 0; i < 800; i++){
		HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_RESET);
		HAL_Delay(1);
	}
	HAL_Delay(1000);
}
/*****************************************************************************
******************************************************************************
** move_to(float, float)                                                    **
** Inputs: two floats - current_position and desired_position in mm         **
** Outputs: Linear actuation to desired_position                            **
** Returns desired position which is the new position after operation       **
** E.g current__vertical_position = move_to(current_vertical_position, 100);**
** NOTE: WILL MOVE TO CLOSEST POSITION (STEP) WITHIN 0.04mm                 **
******************************************************************************
******************************************************************************/
int move_to_vertical(float current_position, float desired_position){
	
	//Set enable one to off to power motor
		HAL_GPIO_WritePin(ENB1_GPIO_Port, ENB1_Pin, GPIO_PIN_RESET);

	//Each step does 0.04mm
	int steps_taken = 0;
	//Multiply by 25 to convert steps to mm
	int steps_total = (desired_position - current_vertical_position)*25;
	//If the handler must move backwards, set rotation to anticlockwise
	
	if(steps_total < 0){
		HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_SET);
	}
	//Move forward, set direction to clockwise
	else{
		HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_RESET);
	}
	
	
	//Move forward until destination reached 
	//printf("Moving along the horizontal axis captain");
	for(steps_taken = 0; steps_taken<abs(steps_total); steps_taken++){
		HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_RESET);
		HAL_Delay(1);
	}
	HAL_Delay(1000);
	//printf("Vertical actuation complete!");
	
	//Set enable one to on to power motor
	HAL_GPIO_WritePin(ENB1_GPIO_Port, ENB1_Pin, GPIO_PIN_SET);
	//The new vertical position
	return desired_position;
}

/***********************************************************************
** void spindle_on(void)                                              **
** Turns the spindle motor on                                         **
***********************************************************************/
void spindle_on(void)
{
	HAL_GPIO_WritePin(SPIN1_GPIO_Port, SPIN1_Pin, GPIO_PIN_SET);
}
/***********************************************************************
** void spindle_off(void)                                             **
** Turns the spindle motor off                                        **
***********************************************************************/
void spindle_off(void)
{
	HAL_GPIO_WritePin(SPIN1_GPIO_Port, SPIN1_Pin, GPIO_PIN_RESET);
}


/*************************************************
* void home_vertical(void)                     *
* Move the vertical axis until limit           *
* limit switch is trigger                        *
*************************************************/
void home_vertical(void){
	//Set enable one to on to power motor
	HAL_GPIO_WritePin(ENB1_GPIO_Port, ENB1_Pin, GPIO_PIN_RESET);
	//While the limit switch is not pressed
	while(HAL_GPIO_ReadPin(VERT_SWITCH_GPIO_Port, VERT_SWITCH_Pin) == 0)
	{
		//Set direction to move backwards
		HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_RESET);	
		//Rotate 90 degrees before checking loop condition again
		for(int i = 0; i < 5; i++){
			HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_SET);
			HAL_Delay(1);
			HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_RESET);
			HAL_Delay(1);
		}
	}
	//Set enable one to off to power motor
	HAL_GPIO_WritePin(ENB1_GPIO_Port, ENB1_Pin, GPIO_PIN_SET);
}
