//HEADER FILE
/*****************************************************************
 * vertical_actuation.h                                          *
 * Created: 4/27/2019 3:56:25 PM                                 *
 * Author : Nick Morris         *
 * s44373388 - Team 8 - METR4810                                 *
 * Vertical Linear Actuation given a desired and current position*
 *****************************************************************/

#ifndef VERTICALLINEARACTUATION_FUNCTIONS_
#define VERTICALLINEARACTUATION_FUNCTIONS_


/*************************************************
* void test_function(void)                       *
* Test function to test actuator functionality   *
* Rotate the steppers back and forth 4 rotations *
*************************************************/
void test_vertical_function(void);

/***********************************************************************
************************************************************************
** move_to(float, float)                                              **
** Inputs: two floats - current_position and desired_position in mm   **
** Outputs: Linear actuation to desired_position                      **
** Returns desired position which is the new position after operation **
** E.g current_vertical_position = move_to_vertical(current_position, LATHE);           **
************************************************************************
************************************************************************/
int move_to_vertical(float desired_position, float current_position);


/***********************************************************************
** void spindle_on(void)                                              **
** Turns the spindle motor on                                         **
***********************************************************************/
void spindle_on(void);

/***********************************************************************
** void spindle_off(void)                                             **
** Turns the spindle motor off                                        **
***********************************************************************/
void spindle_off(void);

/*************************************************
* void home_vertical(void)                       *
* Move the vertical axis until limit             *
* limit switch is trigger                        *
*************************************************/
void home_vertical(void);


#endif // VERTICALLINEARACTUATION_FUNCTIONS_
