/*****************************************************************
 * rotate.c                                                      *
 * Created: 4/27/2019 3:56:25 PM                                 *
 * Author : Nick Morris!                                         *
 * s44373388 - Team 8 - METR4810                                 *
 * rotate to desired face and spin the z axis                    *
 *****************************************************************/




//#include <avr/io.h> For prototyping in atmel studio
#include "main.h"
#include "rotate.h"

#define FACE_ONE 1
#define FACE_TWO 2
#define FACE_THREE 3
#define FACE_FOUR 4
#define FACE_FIVE 5


/*
int current_face = FACE_FOUR;
int current_z_face = FACE_FOUR;
*/

/***********************************************************************
************************************************************************
** rotate_face_one(int*, int*)                                        **
** Inputs: two int pointers - current face, current_z_face            **
** Outputs: rotate to face one                                        **
** Updates value of current_face and current_z_face                   **
** E.g rotate_face_one(&current_face, &current_z_face;                **
************************************************************************
************************************************************************/
void rotate_face_one(int *current_face, int *current_z_face){
	switch(*current_face){
		//Face 1
		case 1:
		//printf("Face 1 to Face 1...");
		*current_face = FACE_ONE;
		*current_z_face = FACE_ONE;
		//printf("Operation complete captain!");
		
		break;
		
		//Face 2
		case 2:
			//printf("Face 2 to Face 1");
			//Set rotation to clockwise
			HAL_GPIO_WritePin(DIR3_GPIO_Port, DIR3_Pin, GPIO_PIN_SET);
			//Rotation in Z direction clockwise 90 degrees (50 steps)
			for(int i = 0; i < 50; i++){
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET);
				HAL_Delay(5);
			}
			*current_face = FACE_ONE;
			*current_z_face = FACE_ONE;
			//printf("Operation complete captain!");		
			break;
			
		//Face 3
		case 3:
			//printf("Face 3 to Face 1");
			//Set rotation to anti-clockwise (Does not matter here)
			HAL_GPIO_WritePin(DIR3_GPIO_Port, DIR3_Pin, GPIO_PIN_RESET);
			//Rotation in Z direction anti-clockwise 180 degrees (100 steps)
			for(int i = 0; i < 100; i++){
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET);
				HAL_Delay(5);
			}
			*current_face = FACE_ONE;
			*current_z_face = FACE_ONE;
			//printf("Operation complete captain!");
			break;
		
		//Face 4
		case 4:
		//printf("Face 4 to Face 1");
			//Set rotation to anti-clockwise 
			HAL_GPIO_WritePin(DIR3_GPIO_Port, DIR3_Pin, GPIO_PIN_RESET);
			//Rotation in Z direction anti-clockwise 90 degrees (50 steps)
			for(int i = 0; i < 50; i++){
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET);
				HAL_Delay(5);
			}
			*current_face = FACE_ONE;
			*current_z_face = FACE_ONE;
			//printf("Operation complete captain!");
			break;
		
		//Face 5
		case 5:
			//printf("Face 5 to Face 1");
			//Set rotation to anti-clockwise
			HAL_GPIO_WritePin(DIR2_GPIO_Port, DIR2_Pin, GPIO_PIN_RESET);
			//Rotation towards submachines of 90 degrees
			for(int i = 0; i < 50; i++){
				HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_RESET);
				HAL_Delay(5);
			}
			rotate_face_one(current_z_face, current_face);
			
			//printf("Operation complete captain!");
			break;
		//Something has gone wrong here
		default:
			//printf("Error 11: You tried to rotate to face one but something went wrong.");
		break;
	}
	
}
/***********************************************************************
************************************************************************
** rotate_face_one(int*, int*)                                        **
** Inputs: two int pointers - current face, current_z_face            **
** Outputs: rotate to face two                                        **
** Updates value of current_face and current_z_face                   **
** E.g rotate_face_two(&current_face, &current_z_face);                **
************************************************************************
************************************************************************/
void rotate_face_two(int *current_face, int *current_z_face){
	switch(*current_face){
		//Face 1
		case 1:
			//printf("Face 1 to Face 2");
			//Set rotation to anti-clockwise
			HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_RESET);
			//Rotation in Z direction anti-clockwise 90 degrees (50 steps)
			for(int i = 0; i < 50; i++){
				HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP3_Pin, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET);
				HAL_Delay(5);
			}
			*current_face = FACE_TWO;
			*current_z_face = FACE_TWO;
			//printf("Operation complete captain!");		
			break;
		
		//Face 2
		case 2:
			//printf("Face 2 to Face 2...");
			*current_face = FACE_TWO;
			*current_z_face = FACE_TWO;
			//printf("Operation complete captain!");
			break;
		
		//Face 3
		case 3:
			//printf("Face 3 to Face 2");
			//Set rotation to clockwise 
			HAL_GPIO_WritePin(DIR3_GPIO_Port, DIR3_Pin, GPIO_PIN_SET);
			//Rotation in Z direction clockwise 90 degrees (50 steps)
			for(int i = 0; i < 50; i++){
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET);
				HAL_Delay(5);
			}
			*current_face = FACE_TWO;
			*current_z_face = FACE_TWO;
			//printf("Operation complete captain!");
			break;
		
		//Face 4
		case 4:
			//printf("Face 4 to Face 2");
			//Set rotation to anti-clockwise
			HAL_GPIO_WritePin(DIR3_GPIO_Port, DIR3_Pin, GPIO_PIN_RESET);
			//Rotation in Z direction anti-clockwise 180 degrees (100 steps)
			for(int i = 0; i < 100; i++){
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET);
				HAL_Delay(5);
			}
			*current_face = FACE_TWO;
			*current_z_face = FACE_TWO;
			//printf("Operation complete captain!");
			break;
		
		//Face 5
		case 5:
			//printf("Face 5 to Face 2");
			//Set rotation to anti-clockwise
			HAL_GPIO_WritePin(DIR2_GPIO_Port, DIR2_Pin, GPIO_PIN_RESET);
			//Rotation towards submachines of 90 degrees
			for(int i = 0; i < 50; i++){
				HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_RESET);
				HAL_Delay(5);
			}
			//Correct z axis face after rotation
			rotate_face_two(current_z_face, current_face);
			//printf("Operation complete captain!");
			break;
			
		//Something has gone wrong here
		default:
		//printf("Error 12: You tried to rotate to face two but something went wrong.");
		break;
	}
	
}

/***********************************************************************
************************************************************************
** rotate_face_three(int*, int*)                                      **
** Inputs: two int pointers - current face, current_z_face            **
** Outputs: rotate to face one                                        **
** Updates value of current_face and current_z_face                   **
** E.g rotate_face_three(&current_face, &current_z_face;              **
************************************************************************
************************************************************************/
void rotate_face_three(int *current_face,int *current_z_face){
	switch(*current_face){
		//Face 1
		case 1:
			//printf("Face 3 to Face 1");
			//Set rotation to anti-clockwise
			HAL_GPIO_WritePin(DIR3_GPIO_Port, DIR3_Pin, GPIO_PIN_RESET);
			//Rotation in Z direction anti-clockwise 180 degrees (100 steps)
			for(int i = 0; i < 100; i++){
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET);
				HAL_Delay(5);
			}
			*current_face = FACE_THREE;
			*current_z_face = FACE_THREE;
			//printf("Operation complete captain!");
			break;
		
		//Face 2
		case 2:
			//printf("Face 2 to Face 3");
			//Set rotation to anti-clockwise
			HAL_GPIO_WritePin(DIR3_GPIO_Port, DIR3_Pin, GPIO_PIN_RESET);
			//Rotation in Z direction anti-clockwise 90 degrees (50 steps)
			for(int i = 0; i < 50; i++){
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET);
				HAL_Delay(5);
			}
			*current_face = FACE_THREE;
			*current_z_face = FACE_THREE;
			//printf("Operation complete captain!");
			break;
		
		//Face 3
		case 3:
		//printf("Face 3 to Face 3...");
			*current_face = FACE_THREE;
			*current_z_face = FACE_THREE;
			//printf("Operation complete captain!");
			break;
		
		//Face 4
		case 4:
			//printf("Face 4 to Face 3");
			//Set rotation to anti-clockwise
			HAL_GPIO_WritePin(DIR3_GPIO_Port, DIR3_Pin, GPIO_PIN_SET);
			//Rotation in Z direction anti-clockwise 90 degrees (50 steps)
			for(int i = 0; i < 50; i++){
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET);
				HAL_Delay(5);
			}
			*current_face = FACE_THREE;
			*current_z_face = FACE_THREE;
			//printf("Operation complete captain!");
			break;
		
		//Face 5
		case 5:
		//printf("Face 5 to Face 3");
		//Set rotation to anti-clockwise
		HAL_GPIO_WritePin(DIR2_GPIO_Port, DIR2_Pin, GPIO_PIN_RESET);
		//Rotation towards submachines of 90 degrees
		for(int i = 0; i < 50; i++){
			HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_SET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_RESET);
			HAL_Delay(5);
		}
		rotate_face_three(current_z_face, current_face);
		//printf("Operation complete captain!");
		break;
		
		//Something has gone wrong here
		default:
		//printf("Error 13: You tried to rotate to face three but something went wrong.");
		break;
	}
	
}

/***********************************************************************
************************************************************************
** rotate_face_four(int*, int*)                                       **
** Inputs: two int pointers - current face, current_z_face            **
** Outputs: rotate to face one                                        **
** Updates value of current_face and current_z_face                   **
** E.g rotate_face_four(&current_face, &current_z_face;               **
************************************************************************
************************************************************************/
void rotate_face_four(int *current_face,int *current_z_face){
	switch(*current_face){
		//Face 1
		case 1:
			//printf("Face 1 to Face 4");
			//Set rotation to clockwise
			HAL_GPIO_WritePin(DIR3_GPIO_Port, DIR3_Pin, GPIO_PIN_SET);
			//Rotation in Z direction clockwise 90 degrees (50 steps)
			for(int i = 0; i < 50; i++){
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET);
				HAL_Delay(5);
			}
			*current_face = FACE_FOUR;
			*current_z_face = FACE_FOUR;
			//printf("Operation complete captain!");
			break;
		
		//Face 2
		case 2:
			//printf("Face 2 to Face 4");
			//Set rotation to clockwise
			HAL_GPIO_WritePin(DIR3_GPIO_Port, DIR3_Pin, GPIO_PIN_SET);
			//Rotation in Z direction clockwise 180 degrees (100 steps)
			for(int i = 0; i < 100; i++){
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET);
				HAL_Delay(5);
			}
			*current_face = FACE_FOUR;
			*current_z_face = FACE_FOUR;
			//printf("Operation complete captain!");
			break;
		
		//Face 3
		case 3:
			//printf("Face 3 to Face 4");
			//Set rotation to clockwise
			HAL_GPIO_WritePin(DIR3_GPIO_Port, DIR3_Pin, GPIO_PIN_RESET);
			//Rotation in Z direction anti-clockwise 90 degrees (50 steps)
			for(int i = 0; i < 50; i++){
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET);
				HAL_Delay(5);
			}
			*current_face = FACE_FOUR;
			*current_z_face = FACE_FOUR;
			//printf("Operation complete captain!");
			break;
		
		//Face 4
		case 4:
			//printf("Face 4 to Face 4...");
			*current_face = FACE_FOUR;
			*current_z_face = FACE_FOUR;
			//printf("Operation complete captain!");
			break;
			
		//Face 5
		case 5:
			//printf("Face 5 to Face 4");
			//Set rotation to anti-clockwise
			HAL_GPIO_WritePin(DIR2_GPIO_Port, DIR2_Pin, GPIO_PIN_RESET);
			//Rotation towards submachines of 90 degrees
			for(int i = 0; i < 50; i++){
				HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_RESET);
				HAL_Delay(5);
			}
			rotate_face_four(current_z_face, current_face);
			//printf("Operation complete captain!");
			break;
		
		//Something has gone wrong here
		default:
		//printf("Error 14: You tried to rotate to face four but something went wrong.");
		break;
	}

}
/***********************************************************************
************************************************************************
** rotate_face_five(int*)                                              **
** Inputs: one int pointers - current face                            **
** Outputs: rotate to face one                                        **
** Updates value of current_face                                      **
** E.g rotate_face_five(&current_face)                                **
************************************************************************
************************************************************************/
void rotate_face_five(int *current_face){
	
			
		//Set rotation to clockwise
		HAL_GPIO_WritePin(DIR2_GPIO_Port, DIR2_Pin, GPIO_PIN_SET);
		//Rotation in Z direction anti-clockwise 90 degrees (50 steps)
		for(int i = 0; i < 50; i++){
			HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_SET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_RESET);
			HAL_Delay(5);
		}
		*current_face = FACE_FIVE;
			
			////printf("Operation complete captain!");			
}

/***********************************************************************
************************************************************************
** void lathe_time(void)                                              **
** Inputs: void                                                       **
** Outputs: rotates z axis 150rpm                                     **
** E.g lathe_time()                                                   **
************************************************************************
************************************************************************/
void lathe_time(void){
	////printf("It's lathe time!");
	
	//Set rotation to clockwise
	HAL_GPIO_WritePin(DIR3_GPIO_Port, DIR3_Pin, GPIO_PIN_SET);
	//Rotate 150rpm for 10 rotations
	//Speed up function
	for(int i = 0; i < 50; i++){
		HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_SET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET);
		HAL_Delay(5);
	}
	for(int i = 0; i < 50; i++){
		HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_SET);
		HAL_Delay(4);
		HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET);
		HAL_Delay(4);
	}
	for(int i = 0; i < 50; i++){
		HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_SET);
		HAL_Delay(3);
		HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET);
		HAL_Delay(3);
	}
	for(int i = 0; i < 50; i++){
		HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_SET);
		HAL_Delay(2);
		HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET);
		HAL_Delay(2);
	}
	//Rotate at 150rpm now.
	for(int i = 0; i < 1600; i++){
		HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET);
		HAL_Delay(1);
	}
	for(int i = 0; i < 200; i++){
		HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_SET);
		HAL_Delay(3);
		HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET);
		HAL_Delay(3);
	}
	////printf("Back to work... lathe time over...");
}

/***********************************************************************
************************************************************************
** void rotate_home(void)                                             **
** Inputs: void                                                       **
** Outputs: homes the z axis rotation                                 **
** E.g rotate_home();                                                 **
************************************************************************
************************************************************************/
//void rotate_home(void){
//	//Read the endstop
//	while(HAL_GPIO_ReadPin(ENDSTOP_GPIO_Port, ENDSTOP_Pin) == 1){
//		//rotate one step
//		HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_SET);
//		HAL_Delay(5);
//		HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET);
//		HAL_Delay(5);
//	}
//	
//}
