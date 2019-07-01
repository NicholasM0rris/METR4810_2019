//HEADER FILE
/*****************************************************************
 * initialise_drivers.h                                             *
 * Created: 4/27/2019 3:56:25 PM                                 *
 * Author : Nick Morris                                          *
 * s44373388 - Team 8 - METR4810                                 *
 * Initialise the drivers by toggling the enable pins         *
 *****************************************************************/

#ifndef INITIALISEDRIVERS_FUNCTIONS_
#define INITIALISEDRIVERS_FUNCTIONS_

/***********************************************************************
** void initialise__handler_drivers(void)                             **
** Initialises the hand;er's stepper drivers                          **
***********************************************************************/
void initialise_handler_drivers(void);

/***********************************************************************
** void initialise_drivers(void)                                      **
** Initialises the stepper drivers to OFF by setting enable to high   **
***********************************************************************/
void initialise_drivers(void);


#endif // INITIALISEDRIVERS_FUNCTIONS_
