/*****************************************************************
 * initialise_drivers.c                                          *
 * Created: 4/27/2019 3:56:25 PM                                 *
 * Author : Nick Morris                                          *
 * s44373388 - Team 8 - METR4810                                 *
 * Rotate the handler's face                                     *
 *****************************************************************/
#include "rotation.h"
#include "rotate.h"
#include "main.h"

/***********************************************************************
** void rotate_face(int face, int current_face, int current_z_face)   **
** Rotate to chosen face through int input                            **
***********************************************************************/
void rotate_face(int face, int current_face, int current_z_face)
{
	switch(face){
		
		case FACE_FIVE:
			rotate_face_five(current_face);
			break;
		case: FACE_FOUR:
			rotate_face_four(current_face, current_z_face);
			break;
		case FACE_THREE:
			rotate_face_three(current_face, current_z_face);
			break;
		case FACE_TWO:
			rotate_face_two(current_face, current_z_face);
			break;
		case FACE_ONE:
			rotate_face_one(current_face, current_z_face);
			break;
		default:
			break;
			
	}
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