/* USER CODE BEGIN Header */
/*****************************************************************
 * main.c                                        								 *
 * Created: 15/05/2019                                           *
 * Author : Madison B, Nicholas M                                *
 * s4393944 - Team 8 - METR4810                                  *
 * Drill, Mill and Lathe main code 															 *
 *****************************************************************/

/********************************************************************************
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
#include "status.h"
#include "vertical_actuation.h"
#include "initialise_drivers.h"
#include "lathe_actuation.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//#define DRILL_BOARD
//#define MILL_BOARD
//#define LATHE_BOARD
#define BASICFUNC_DRILL
//#define BASICFUNC_MILL
//#define BASICFUNC_LATHE

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
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
	int current_vertical_position = 140;
	//uint8_t buffTX[10] = "Hello!!!\n\r"; 
	//uint8_t drillTX[10] = "Drill!!!\n\r";
	
	
	//reset buff and allocate to memory
	uint8_t coords[50]; 
	memset(&coords[0], 0, sizeof(coords));

	uint8_t drill_coords[sizeof(coords)]; 
	float mill_coords[sizeof(coords)]; 
	float lathe_coords[sizeof(coords)]; 

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
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

#ifdef DRILL_BOARD
initialise_drivers(); 
HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
while (1) {
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET); 

	//Initializes buff, resets position in memory
	char buff[50]; 
	memset(&buff[0], 0, sizeof(buff));
	HAL_UART_Receive(&huart1, buff, sizeof(buff), 1000);	

	//if buff is received
	if (strcmp(buff, "hi\n\r") == 0) { 
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET); 
		char buff[50]; 
		memset(&buff[0], 0, sizeof(buff));
		
		//Reset function 
		home_horizontal();
		home_vertical(); 
		//No. of drill holes
		int repeat = drill_coords[0];  
		for (int j = -1; j < repeat; j++) {
			int y_coord = 3+4*j; 
			//CHECK THIS LATER
			int z_coord = 4+4*j; 
			//If message received from handler then do this
			current_vertical_position = move_to_vertical(current_vertical_position, 100); 
			
			spindle_on(); 
			
			current_position = move_to(current_position, 160); //(210 - (80 - drill_coords[z_coord]))); 
			current_position = move_to(current_position, 70);			
			spindle_off(); 		
			home_horizontal(); 
			//MAYBE RESET HER
		}			
		uint8_t brkpt[10] = "BREAKNEW\n\r"; 		
		uint8_t drill_done[11] = "DRILLDONE\n\r";	
		//Transmit back to handler
		HAL_UART_Transmit(&huart1, drill_done, sizeof(drill_done), 3000);

	}			
}
#endif

#ifdef MILL_BOARD
initialise_drivers(); 
while (1) {
	char buff[50];
	memset(&buff[0], 0, sizeof(buff));
	//ISMILLREADY?
	uint8_t mill_ready[13] = "MILLREADY\n\r";
	
	//while the mill is not ready, on board LED is set
	while (strcmp(buff, "MILLREADY\n\r") != 0) { 
		HAL_UART_Receive(&huart1, buff, sizeof(buff), 1000);
		
	}
	//If the mill is ready, this function runs
	if (strcmp(buff, "MILLREADY\n\r") == 0){
		
		//No. of mill sections
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
		
		home_horizontal(); 
		//home_vertical(); 
		
		int repeat = mill_coords[0];  
		for (int j = -1; j < 0; j++) {
			int y_coord = 3+4*j; 
			int z_coord = 4+4*j;
			
			//align vertically
			current_vertical_position = move_to_vertical(current_vertical_position, 100); 
			for(int i = 0; i<30; i++){
				current_position = move_to_lathe(current_position, current_position+1);//mill_coords[z_coord]); 
				current_position = move_to_vertical_lathe(current_vertical_position, current_vertical_position+1);
			}
			//reset
			
			current_vertical_position = move_to_vertical_lathe(current_vertical_position, 110); 
			home_horizontal(); 
		}
		uint8_t mill_done[11] = "MILLDONE\n\r";	
		//Transmit back to handler
		HAL_UART_Transmit(&huart1, mill_done, sizeof(mill_done), 3000);
	}			
}		
#endif 

#ifdef LATHE_BOARD
initialise_drivers(); 
while (1) {
	char buff[50]; 
	memset(&buff[0], 0, sizeof(buff));
	uint8_t lathe_ready[9] = "LATHEGO\n\r";
	
	//while the lathe is not ready, on board LED is set
	while (strcmp(buff, "LATHEGO\n\r") != 0) { 
		HAL_UART_Receive(&huart1, buff, sizeof(buff), 1000);
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
	}	 

	//If handler is ready for lathe, this function runs
	if (strcmp(buff, "LATHEGO\n\r") == 0){		
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);	
		home_vertical(); 
		home_horizontal(); 
		//No. of mill sections
		int repeat = lathe_coords[0];  
		for (int j = 0; j <= 0; j++) {
			int y1_coord = 1+3*j; 
			int y2_coord = 2+3*j; 			
			int z_coord = 3+3*j; 
			
			//align vertically
			current_vertical_position = move_to_vertical(current_vertical_position, 60); 
		
			//lathe to depth			
			current_position = move_to(current_position, 50); 
			HAL_Delay(2000); 
			
			//lathe upward
			current_vertical_position = move_to_vertical(current_vertical_position, 10); 
			
			//reset horizontally
			current_position = move_to(current_position, 0); 
		}
		uint8_t lathe_done[11] = "LATHEDONE\n\r";	
		//Transmit back to handler
		HAL_UART_Transmit(&huart1, lathe_done, sizeof(lathe_done), 1000);		
	}
}			
#endif

#ifdef BASICFUNC_DRILL
initialise_drivers(); 
while(1){
	led_on(RED);
	if(HAL_GPIO_ReadPin(DEMO_GPIO_Port, DEMO_Pin) != 0){
		home_vertical(); 
		home_horizontal();
		current_vertical_position = move_to_vertical(current_vertical_position, 100); 
		spindle_on(); 
		current_position = move_to(current_position, 160); 
		current_position = move_to(current_position, 70);			
		spindle_off(); 		
		home_horizontal();
		led_on(GREEN); 
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET); 		 
	} else { 
		led_on(AMBER); 
	}
}
#endif	


#ifdef BASICFUNC_MILL
initialise_drivers(); 
while(1){
	led_on(RED);
	if(HAL_GPIO_ReadPin(DEMO_GPIO_Port, DEMO_Pin) != 0){
		home_vertical(); 
		home_horizontal();
		current_vertical_position = move_to_vertical(current_vertical_position, (current_vertical_position-10));  
		spindle_on(); 
		current_position = move_to(current_position, 140); 
		current_position = move_to(current_position, 70);			
		spindle_off(); 		
		home_horizontal();
		led_on(GREEN); 
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET); 		 
	} else { 
		led_on(AMBER); 
	}
}
#endif

#ifdef BASICFUNC_LATHE
initialise_drivers(); 
while(1){
	led_on(RED);
	if(HAL_GPIO_ReadPin(DEMO_GPIO_Port, DEMO_Pin) != 0){
		home_vertical(); 
		home_horizontal();
		current_vertical_position = move_to_vertical(current_vertical_position, 100);
		current_position = move_to(current_position, 70);
			for(int i = 0; i<30; i++){
				current_position = move_to_lathe(current_position, current_position+1);//mill_coords[z_coord]); 
				current_position = move_to_vertical_lathe(current_vertical_position, current_vertical_position+1);
			}		 
	} else { 
		led_on(AMBER); 
	}
}
#endif

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
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
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, SPIN1_Pin|STEP2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GREEN_Pin|YELLOW_Pin|RED_Pin|DIR1_Pin 
                          |STEP1_Pin|DIR2_Pin|ENB2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_Pin|ENB1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : SPIN1_Pin STEP2_Pin */
  GPIO_InitStruct.Pin = SPIN1_Pin|STEP2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : GREEN_Pin YELLOW_Pin RED_Pin DIR1_Pin 
                           STEP1_Pin DIR2_Pin ENB2_Pin */
  GPIO_InitStruct.Pin = GREEN_Pin|YELLOW_Pin|RED_Pin|DIR1_Pin 
                          |STEP1_Pin|DIR2_Pin|ENB2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : DEMO_Pin HOR_SWITCH_Pin VERT_SWITCH_Pin */
  GPIO_InitStruct.Pin = DEMO_Pin|HOR_SWITCH_Pin|VERT_SWITCH_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_Pin ENB1_Pin */
  GPIO_InitStruct.Pin = LED_Pin|ENB1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
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
