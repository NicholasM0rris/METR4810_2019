/* USER CODE BEGIN Header */
/*****************************************************************
 * main.c                                        								 *
 * Created: 15/05/2019                                           *
 * Author : Madison B, Nicholas M                                *
 * s4393944 - Team 8 - METR4810                                  *
 * Handler main code 																						 *
 *****************************************************************/
/**
******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2019 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "linearactuation.h"
#include "rotate.h"
#include "status.h"
#include "vertical_actuation.h"
#include "initialise_drivers.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/*****************************************
*DRILL COORDS:                           *
*{no. of times, face, x, y, z, ...}      *
*                                        *
*MILL COODS:                             *
*{no. of times, face, x, y, z, ...}      *
*                                        *
*LATHE COORDS:                           *
*{no. of times, y_1, y_2, z...}          *
*                                        *
******************************************/
uint8_t drill[] = {1, 2, 20, 100, 30}; 

uint8_t mill[] = {1, 3, 40, 4, 39, 35, 111, 8}; 

uint8_t lathe[] = {1, 40, 50, 10}; 

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//COMMENT OUT ALL BUT THE ONE YOU ARE UPLOADING TO
#define HANDLER_BOARD
//#define LATHE_BOARD
//#define MILL_BOARD
//#define DRILL_BOARD
//#define ORIGINAL

uint8_t buffTX[10] = "Hello!!!\n\r"; 
uint8_t drillTX[10] = "Drill!!!\n\r"; 

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim14;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;
UART_HandleTypeDef huart4;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_USART3_UART_Init(void);
static void MX_USART4_UART_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_TIM14_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
int current_position = 0;
int current_face = FACE_FOUR;
int current_z_face = FACE_FOUR;

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  MX_USART4_UART_Init();
  MX_USART1_UART_Init();
  MX_TIM14_Init();
  /* USER CODE BEGIN 2 */

led_on(GREEN);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
		
#ifdef HANDLER_BOARD
//Sets all enable pins - turns all motor drivers off
initialise_handler_drivers(); 
home_horizontal(); 
//current_position = move_to(current_position, 412); 

while (1) {
	//Transmits through an initial buffer to computer
	HAL_UART_Transmit(&huart2, buffTX, 10, 1000);
	uint8_t print[4] = "hi\n\r"; 
	uint8_t bye[5] = "bye\n\r";
	uint8_t trans[10] = "transmit\n\r"; 
	
	//Initial tranmit of co-ordinates
	//for(int i = 0; i<5; i++){
		HAL_UART_Transmit(&huart1, drill, sizeof(drill), 1000); 
		HAL_UART_Transmit(&huart3, mill, sizeof(mill), 1000); 
		HAL_UART_Transmit(&huart4, lathe, sizeof(lathe), 1000); 
	//}
	//initialises flag and buffer - assigns buffer to memory location
	int flag = 0;
	char buff[50]; 
	memset(&buff[0], 0, sizeof(buff));
	//get from serial
	//HAL_UART_Receive(&huart2, buff, 10, 5000);
	while(1){
		if (HAL_GPIO_ReadPin(DEMO_GPIO_Port, DEMO_Pin) == 0) {
			break;
		}
	}
	//if(strcmp(buff, "on") == 0) {
		//start the timer
	led_off(GREEN);
	uint8_t test[10]; 
	//memset(&test[0], 0, sizeof(test)); 
	HAL_UART_Receive(&huart1, test, sizeof(test), 1000); 
	HAL_UART_Transmit(&huart2, test, sizeof(test), 1000); 


	//flag = 1;
	//'Hi' transmitted through to serial 
	HAL_UART_Transmit(&huart2, print, sizeof(print), 100);
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	HAL_TIM_Base_Start_IT(&htim14);
		
	//Horizontal moves to DRILL STATION
	current_position = move_to(current_position, 20);
	
	//aligns to correct x co-ordinate
	int repeat = drill[0]; 
	for (int j = -1; j <= -1; j++) {
		int x_coord = 3*j;
		int des_face = 3*j; 

		//align horizontally
		//current_position = move_to(current_position, drill[x_coord]); 
	
		//Rotation to correct face
	//	rotate_face_five(&current_face); 
		//HAL_Delay(1000); 
		//rotate_face_one(&current_face, &current_z_face); 
	}
	//TRANSMISSIONS
	uint8_t brkpt1[16] = "BREAKafterspin\n\r"; 
	//transmits to terminal
	HAL_UART_Transmit(&huart2, brkpt1, sizeof(brkpt1), 100); 
		
	//UART_1 Transmits to next board
	HAL_UART_Transmit(&huart1, print, sizeof(print), 1000);
	//UART_2 prints to terminal
	HAL_UART_Transmit(&huart2, trans, sizeof(trans), 100);
	
	//Sets memory and receives back from UART_1 ("Drill")
	memset(&buff[0], 0, sizeof(buff));
	//if(flag == 1){		
	uint8_t here[10] = "IAMHERE1\n\r";
	HAL_UART_Transmit(&huart2, here, sizeof(here), 3000);
		
		while (strcmp(buff, "DRILLDONE\n\r") != 0) { 
			HAL_UART_Receive(&huart1, buff, 50, 1000);
		}
	//}

	uint8_t here1[9] = "IAMHERE\n\r";
	HAL_UART_Transmit(&huart2, here1, sizeof(here1), 1000);			
	uint8_t handler_rec[12] = "HANDLERREC\n\r";


	//Recieve from UART_1 to see if the drill is done
	if (strcmp(buff, "DRILLDONE\n\r") == 0) {
		//Transmits a message that the handler has received message back from drill
		HAL_UART_Transmit(&huart2, handler_rec ,sizeof(handler_rec), 1000);
		
		//Horizontal moves to MILL STATION
		current_position = move_to(current_position, 140); 
		
		
		//current_position = move_to(current_position, 170);
		
		//aligns to correct x co-ordinate
		int repeat = mill[0]; 
		for (int j = -1; j < 0; j++) {
			int x_coord = 3*j;
			int des_face = 3*j; 

			//align horizontally
		//current_position = move_to(current_position, mill[x_coord]); 
		
			//Rotation to correct face
			//rotate_face_five(&current_face); 
			////HAL_Delay(1000); 
			rotate_face_one(&current_face, &current_z_face); 
		}
	}
	//Transmit to next board through UART3
	uint8_t mill_ready[12] = "MILLREADY\n\r";
	HAL_UART_Transmit(&huart3, mill_ready, sizeof(mill_ready), 3000);
	
		lathe_time();
	//char buff[50]; 
	memset(&buff[0], 0, sizeof(buff));
	while (strcmp(buff, "MILLDONE\n\r") != 0) { 
		HAL_UART_Receive(&huart3, buff, 50, 1000);
	}

	//Recieve from UART_3 to see if the mill is done
	if (strcmp(buff, "MILLDONE\n\r") == 0) {
		
		//Horizontal moves to LATHE STATION
		current_position = move_to(current_position, 280);
		uint8_t lathe_ready[15] = "LATHEGO\n\r"; 
		//Transmit to next board through UART4
		HAL_UART_Transmit(&huart4, lathe_ready, sizeof(lathe_ready), 3000);
		//Spins motor for lathe functionality 
		lathe_time(); 
	}
	
} 	 
#endif
	
#ifdef LATHE_BOARD
	while (1) {
}
#endif

#ifdef DRILL_BOARD
  while (1) {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		//Initialise specific distances
		int req_vert_dist = 20; 
		int req_vert_rot = req_vert_dist/8;
		int req_vert_steps = req_vert_rot*200;
		
		int req_hor_distance = 50; 
		int req_hor_rot = req_hor_distance/8; 
		int req_hor_steps = req_hor_rot*200; 
		char buff[50]; 
		memset(&buff[0], 0, sizeof(buff));
		
		//Reveice message from handler
		HAL_UART_Receive(&huart1, buff, 50, 500);
			if(strcmp(buff, "hi\n\r") == 0) {	
				HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET); 
				
				//If message received from handler then do this
				HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_SET);	
				HAL_Delay(500); 
									
				while(1) {
					for (int i = 1; i <= req_vert_steps; i++) {
						HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_SET); 
						HAL_Delay(1); 
						HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_RESET); 
						HAL_Delay(1);
						}
					
					HAL_GPIO_WritePin(SPIN1_GPIO_Port, SPIN1_Pin, GPIO_PIN_SET); 
					HAL_Delay(500); 
					
					HAL_GPIO_WritePin(DIR2_GPIO_Port, DIR2_Pin, GPIO_PIN_RESET);	
					for (int i = 1; i <= req_hor_steps; i++) {
						HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_SET); 
						HAL_Delay(1); 
						HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_RESET); 
						HAL_Delay(1);
						}			
						
					HAL_GPIO_WritePin(DIR2_GPIO_Port, DIR2_Pin, GPIO_PIN_SET);	
					for (int i = 1; i <= req_hor_steps; i++) {
						HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_SET); 
						HAL_Delay(1); 
						HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_RESET); 
						HAL_Delay(1);
						}
						
					HAL_GPIO_WritePin(SPIN1_GPIO_Port, SPIN1_Pin, GPIO_PIN_RESET); 											
					uint8_t brkpt[10] = "BREAKNEW\n\r"; 
					HAL_UART_Transmit(&huart2, brkpt, sizeof(brkpt), 100); 
					break;
				}		
				
				uint8_t drill_done[11] = "DRILLDONE\n\r";
				//Transmit back to handler
				HAL_UART_Transmit(&huart1, drill_done, sizeof(drill_done), 100);
				HAL_UART_Transmit(&huart2, drill_done, sizeof(drill_done), 100);
				
				
		} else if (strcmp(buff, "off") == 0) { 
			uint8_t bye[5] = "bye\n\r";
			HAL_UART_Transmit(&huart2, bye, sizeof(bye), 100);  
			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET); 
		}
	}

#endif

#ifdef MILL_BOARD
		char buff[50]; 
		memset(&buff[0], 0, sizeof(buff));
		
		HAL_UART_Receive(&huart3, buff, 50, 500);
			if(strcmp(buff, "hi\n\r") == 0) {	
				HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET); 

				int req_vert_dist = 20; 
				int req_vert_rot = req_vert_dist/8;
				int req_vert_steps = req_vert_rot*200;
				
				int req_hor_distance = 50; 
				int req_hor_rot = req_hor_distance/8; 
				int req_hor_steps = req_hor_rot*200; 
				
			
				HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_SET);	
				HAL_Delay(500); 
				
					
				while(1) {
					for (int i = 1; i <= req_vert_steps; i++) {
						HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_SET); 
						HAL_Delay(1); 
						HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_RESET); 
						HAL_Delay(1);
						}
					
					HAL_GPIO_WritePin(SPIN1_GPIO_Port, SPIN1_Pin, GPIO_PIN_SET); 
					HAL_Delay(500); 
					
					HAL_GPIO_WritePin(DIR2_GPIO_Port, DIR2_Pin, GPIO_PIN_SET);	
					for (int i = 1; i <= req_hor_steps; i++) {
						HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_SET); 
						HAL_Delay(1); 
						HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_RESET); 
						HAL_Delay(1);
						}			
						
					HAL_GPIO_WritePin(DIR2_GPIO_Port, DIR2_Pin, GPIO_PIN_RESET);	
					for (int i = 1; i <= req_hor_steps; i++) {
						HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_SET); 
						HAL_Delay(1); 
						HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_RESET); 
						HAL_Delay(1);
						}
						
					HAL_GPIO_WritePin(SPIN1_GPIO_Port, SPIN1_Pin, GPIO_PIN_RESET); 	
									
					
					uint8_t brkpt[8] = "BREAK3\n\r"; 
					HAL_UART_Transmit(&huart2, brkpt, sizeof(brkpt), 100);
					break;
				}		
				
				uint8_t mill_done[10] = "MILLDONE\n\r";
				//Transmit to next board
				HAL_UART_Transmit(&huart3, mill_done, sizeof(mill_done), 100);
				
		} else if (strcmp(buff, "off") == 0) { 
			uint8_t bye[5] = "bye\n\r";
			HAL_UART_Transmit(&huart2, bye, sizeof(bye), 100);  
			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET); 
		}
	
#endif 

#ifdef ORIGINAL
HAL_GPIO_WritePin(ENB1_GPIO_Port, ENB1_Pin, GPIO_PIN_SET); 
HAL_GPIO_WritePin(ENB2_GPIO_Port, ENB2_Pin, GPIO_PIN_SET); 
HAL_GPIO_WritePin(ENB3_GPIO_Port, ENB3_Pin, GPIO_PIN_SET); 
  while (1) {
    /* USER CODE END WHILE */
	    /* USER CODE BEGIN 3 */
		while(1) {
			//When switch is pressed, comes in here and breaks
			if (HAL_GPIO_ReadPin(DEMO_GPIO_Port, DEMO_Pin)) {
				break;
			} else {	
				while(1) {
					int req_vert_dist = 20; 
					int req_vert_rot = req_vert_dist/8;
					int req_vert_steps = req_vert_rot*200;
					
					int req_hor_distance = 50; 
					int req_hor_rot = req_hor_distance/8; 
					int req_hor_steps = req_hor_rot*200;
					
					HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_RESET); 
					for (int i = 1; i <= 200; i++) {
						HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_SET); 
						HAL_Delay(1); 
						HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_RESET); 
						HAL_Delay(1);
						}
					break; 
					
//					HAL_GPIO_WritePin(SPIN1_GPIO_Port, SPIN1_Pin, GPIO_PIN_SET); 
//					HAL_Delay(500); 
//					
//					HAL_GPIO_WritePin(DIR2_GPIO_Port, DIR2_Pin, GPIO_PIN_SET);	
//					for (int i = 1; i <= req_hor_steps; i++) {
//						HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_SET); 
//						HAL_Delay(1); 
//						HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_RESET); 
//						HAL_Delay(1);
//						}			
//						
//					HAL_GPIO_WritePin(DIR2_GPIO_Port, DIR2_Pin, GPIO_PIN_RESET);	
//					for (int i = 1; i <= req_hor_steps; i++) {
//						HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_SET); 
//						HAL_Delay(1); 
//						HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_RESET); 
//						HAL_Delay(1);
//						}
//						
//					HAL_GPIO_WritePin(SPIN1_GPIO_Port, SPIN1_Pin, GPIO_PIN_RESET); 	
//					break;
					}
				}
			}
		}	
#endif
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM14 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM14_Init(void)
{

  /* USER CODE BEGIN TIM14_Init 0 */

  /* USER CODE END TIM14_Init 0 */

  /* USER CODE BEGIN TIM14_Init 1 */

  /* USER CODE END TIM14_Init 1 */
  htim14.Instance = TIM14;
  htim14.Init.Prescaler = 1000;
  htim14.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim14.Init.Period = 60;
  htim14.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim14.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim14) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM14_Init 2 */

  /* USER CODE END TIM14_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 38400;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 38400;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 38400;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief USART4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART4_UART_Init(void)
{

  /* USER CODE BEGIN USART4_Init 0 */

  /* USER CODE END USART4_Init 0 */

  /* USER CODE BEGIN USART4_Init 1 */

  /* USER CODE END USART4_Init 1 */
  huart4.Instance = USART4;
  huart4.Init.BaudRate = 38400;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_1;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_TX_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  huart4.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart4.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART4_Init 2 */

  /* USER CODE END USART4_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, DIR1_Pin|STEP1_Pin|YELLOW_Pin|RED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, DIR3_Pin|STEP3_Pin|STEP2_Pin|LD2_Pin 
                          |ENB1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, DIR2_Pin|GREEN_Pin|ENB2_Pin|ENB3_Pin 
                          |SPIN1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : DEMO_Pin GO_Pin */
  GPIO_InitStruct.Pin = DEMO_Pin|GO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : DIR1_Pin STEP1_Pin YELLOW_Pin RED_Pin */
  GPIO_InitStruct.Pin = DIR1_Pin|STEP1_Pin|YELLOW_Pin|RED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : DIR3_Pin STEP3_Pin STEP2_Pin LD2_Pin 
                           ENB1_Pin */
  GPIO_InitStruct.Pin = DIR3_Pin|STEP3_Pin|STEP2_Pin|LD2_Pin 
                          |ENB1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : DIR2_Pin GREEN_Pin ENB2_Pin ENB3_Pin 
                           SPIN1_Pin */
  GPIO_InitStruct.Pin = DIR2_Pin|GREEN_Pin|ENB2_Pin|ENB3_Pin 
                          |SPIN1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : HOR_SWITCH_Pin VERT_SWITCH_Pin */
  GPIO_InitStruct.Pin = HOR_SWITCH_Pin|VERT_SWITCH_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
