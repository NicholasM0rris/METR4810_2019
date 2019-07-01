//HEADER FILE
/*****************************************************************
 * rotate.h                                                      *
 * Created: 4/27/2019 3:56:25 PM                                 *
 * Author : Nick Morris!                                         *
 * s44373388 - Team 8 - METR4810                                 *
 * rotate to desired face and spin the z axis                    *
 *****************************************************************/


#ifndef ROTATION_FUNCTIONS_
#define ROTATION_FUNCTIONS_

#define FACE_ONE 1
#define FACE_TWO 2
#define FACE_THREE 3
#define FACE_FOUR 4
#define FACE_FIVE 5

void rotate_face_one(int *current_face, int *current_z_face); 
void rotate_face_two(int *current_face, int *current_z_face);

/***********************************************************************
************************************************************************
** rotate_face_three(int*, int*)                                      **
** Inputs: two int pointers - current face, current_z_face            **
** Outputs: rotate to face one                                        **
** Updates value of current_face and current_z_face                   **
** E.g rotate_face_three(&current_face, &current_z_face;              **
************************************************************************
************************************************************************/
void rotate_face_three(int *current_face, int *current_z_face);

/***********************************************************************
************************************************************************
** rotate_face_four(int*, int*)                                       **
** Inputs: two int pointers - current face, current_z_face            **
** Outputs: rotate to face one                                        **
** Updates value of current_face and current_z_face                   **
** E.g rotate_face_four(&current_face, &current_z_face;               **
************************************************************************
************************************************************************/
void rotate_face_four(int *current_face, int *current_z_face);

/***********************************************************************
************************************************************************
** rotate_face_five(int*)                                             **
** Inputs: one int pointers - current face                            **
** Outputs: rotate to face one                                        **
** Updates value of current_face                                      **
** E.g rotate_face_five(&current_face)                                **
************************************************************************
************************************************************************/
void rotate_face_five(int *current_face);

/***********************************************************************
************************************************************************
** void lathe_time(void)                                              **
** Inputs: void                                                       **
** Outputs: rotates z axis 150rpm                                     **
** E.g lathe_time()                                                   **
************************************************************************
************************************************************************/
void lathe_time(void);

/***********************************************************************
** void rotate_face(int face, int current_face, int current_z_face)   **
** Rotate to chosen face through int input and face inputs to         **
** track face position                                                **
** e.g rotate_face(FACE_FOUR, current_face, current_z_face            **
***********************************************************************/
void rotate_face(int face, int current_face, int current_z_face);


#endif // ROTATION_FUNCTIONS_
