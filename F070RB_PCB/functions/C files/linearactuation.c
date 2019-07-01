/*****************************************************************
 * LinearActuation.c                                             *
 * Created: 4/27/2019 3:56:25 PM                                 *
 * Author : Nick Morris                                          *
 * s44373388 - Team 8 - METR4810                                 *
 * Linear Actuation given a desired and current position         *
 *****************************************************************/

#include "main.h"
#include "math.h"
#include "stdlib.h"
#include "linearactuation.h"

/*
#define MILL 0
#define DRILL 10
#define LATHE 20
#define LENGTH 20
*/

//int current_position = 0;

/*************************************************
* void test_function(void)                       *
* Test function to test actuator functionality   *
* Rotate the steppers back and forth 4 rotations *
*************************************************/
void test_function(void){
	HAL_GPIO_WritePin(ENB1_GPIO_Port, ENB1_Pin, GPIO_PIN_SET); 
	HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_RESET);

	for(int i = 0; i < 200; i++){
		HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_RESET);
		HAL_Delay(1);
	}
	HAL_Delay(1000);
	HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_SET);
	
	for(int i = 0; i < 200; i++){
		HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_RESET);
		HAL_Delay(1);
	}
	HAL_Delay(1000);
}
/***********************************************************************
************************************************************************
** move_to(float, float)                                              **
** Inputs: two floats - current_position and desired_position in mm   **
** Outputs: Linear actuation to desired_position                      **
** Returns desired position which is the new position after operation **
** E.g current_position = move_to(current_position, LATHE);           **
** NOTE: WILL MOVE TO CLOSEST POSITION (STEP) WITHIN 0.04mm           **
************************************************************************
************************************************************************/
int move_to(float current_position, float desired_position){
	//Each step does 0.04mm
	int steps_taken = 0;
	//Multiply by 25 to convert steps to mm
	int steps_total = (desired_position - current_position)*25;
	//If the handler must move backwards, set rotation to anticlockwise
	//Set enable one to on to power motor
	HAL_GPIO_WritePin(ENB1_GPIO_Port, ENB1_Pin, GPIO_PIN_RESET);
	
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
	//printf("Horizontal actuation complete captain!");
	//Set enable one to on to power motor
	HAL_GPIO_WritePin(ENB1_GPIO_Port, ENB1_Pin, GPIO_PIN_SET);
	
	return desired_position;
}

/*************************************************
* void home_horizontal(void)                     *
* Move the horizontal axis until limit           *
* limit switch is trigger                        *
*************************************************/
void home_horizontal(void){
	//Set enable one to on to power motor	
	HAL_GPIO_WritePin(ENB1_GPIO_Port, ENB1_Pin, GPIO_PIN_RESET);
	//While the limit switch is not pressed
	while(HAL_GPIO_ReadPin(HOR_SWITCH_GPIO_Port, HOR_SWITCH_Pin) == 0)
	{
		//Set direction to move backwards
		HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_SET);	
		//Rotate 90 degrees before checking loop condition again
		for(int i = 0; i < 25; i++){
			HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_SET);
			HAL_Delay(1);
			HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_RESET);
			HAL_Delay(1);
		}
	}
	//Set enable one to off to power motor
	HAL_GPIO_WritePin(ENB1_GPIO_Port, ENB1_Pin, GPIO_PIN_SET);
}


