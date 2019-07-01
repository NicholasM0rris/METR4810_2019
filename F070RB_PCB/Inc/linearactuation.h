//HEADER FILE
/*****************************************************************
 * LinearActuation.h                                             *
 * Created: 4/27/2019 3:56:25 PM                                 *
 * Author : Nick Morris                                          *
 * s44373388 - Team 8 - METR4810                                 *
 * Linear Actuation given a desired and current position         *
 *****************************************************************/

#ifndef LINEARACTUATION_FUNCTIONS_
#define LINEARACTUATION_FUNCTIONS_

#define MILL 0
#define DRILL 10
#define LATHE 20
#define LENGTH 20

/*************************************************
* void test_function(void)                       *
* Test function to test actuator functionality   *
* Rotate the steppers back and forth 4 rotations *
*************************************************/
void test_function(void);

/***********************************************************************
************************************************************************
** move_to(float, float)                                              **
** Inputs: two floats - current_position and desired_position in mm   **
** Outputs: Linear actuation to desired_position                      **
** Returns desired position which is the new position after operation **
** E.g current_position = move_to(current_position, LATHE);           **
************************************************************************
************************************************************************/
int move_to(float desired_position, float current_position);

/*************************************************
* void home_horizontal(void)                     *
* Move the horizontal axis until limit           *
* limit switch is trigger                        *
*************************************************/
void home_horizontal(void);


#endif // LINEARACTUATION_FUNCTIONS_
