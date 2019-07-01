//HEADER FILE
/*****************************************************************
 * lathe_actuation.h                                             *
 * Created: 4/27/2019 3:56:25 PM                                 *
 * Author : Nick Morris                                          *
 * s44373388 - Team 8 - METR4810                                 *
 * Linear Actuation given a desired and current position         *
 *****************************************************************/

#ifndef LATHEACTUATION_FUNCTIONS_
#define LATHEACTUATION_FUNCTIONS_



/***********************************************************************
************************************************************************
** move_to_lathe(float, float)                                        **
** Inputs: two floats - current_position and desired_position in mm   **
** Outputs: Linear actuation to desired_position                      **
** Returns desired position which is the new position after operation **
** E.g current_position = move_to(current_position, LATHE);           **
** NOTE: WILL MOVE TO CLOSEST POSITION (STEP) WITHIN 0.04mm           **
************************************************************************
************************************************************************/
int move_to_lathe(float current_position, float desired_position);

/*****************************************************************************
******************************************************************************
** move_to_vertical_lathe(float, float)                                                    **
** Inputs: two floats - current_position and desired_position in mm         **
** Outputs: Linear actuation to desired_position                            **
** Returns desired position which is the new position after operation       **
** E.g current__vertical_position = move_to(current_vertical_position, 100);**
** NOTE: WILL MOVE TO CLOSEST POSITION (STEP) WITHIN 0.04mm                 **
******************************************************************************
******************************************************************************/
int move_to_vertical_lathe(float current_vertical_position, float desired_position);


#endif // LINEARACTUATION_FUNCTIONS_
