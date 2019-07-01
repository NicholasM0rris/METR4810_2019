/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI4_15_IRQn
#define RCC_OSC32_IN_Pin GPIO_PIN_14
#define RCC_OSC32_IN_GPIO_Port GPIOC
#define RCC_OSC32_OUT_Pin GPIO_PIN_15
#define RCC_OSC32_OUT_GPIO_Port GPIOC
#define RCC_OSC_IN_Pin GPIO_PIN_0
#define RCC_OSC_IN_GPIO_Port GPIOF
#define RCC_OSC_OUT_Pin GPIO_PIN_1
#define RCC_OSC_OUT_GPIO_Port GPIOF
#define DIR2_Pin GPIO_PIN_0
#define DIR2_GPIO_Port GPIOC
#define STEP2_Pin GPIO_PIN_1
#define STEP2_GPIO_Port GPIOC
#define STEP_Pin GPIO_PIN_0
#define STEP_GPIO_Port GPIOA
#define DIR_Pin GPIO_PIN_1
#define DIR_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define BTN_Pin GPIO_PIN_4
#define BTN_GPIO_Port GPIOA
#define BTN_EXTI_IRQn EXTI4_15_IRQn
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define LEDA_Pin GPIO_PIN_6
#define LEDA_GPIO_Port GPIOA
#define STEPH_Pin GPIO_PIN_7
#define STEPH_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_0
#define LED_GPIO_Port GPIOB
#define ENDSTOP_Pin GPIO_PIN_7
#define ENDSTOP_GPIO_Port GPIOC
#define ENDSTOP_EXTI_IRQn EXTI4_15_IRQn
#define LEDG_Pin GPIO_PIN_9
#define LEDG_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define VSWITCH_Pin GPIO_PIN_2
#define VSWITCH_GPIO_Port GPIOD
#define HSWITCH_Pin GPIO_PIN_3
#define HSWITCH_GPIO_Port GPIOB
#define DIRV_Pin GPIO_PIN_4
#define DIRV_GPIO_Port GPIOB
#define STEPV_Pin GPIO_PIN_5
#define STEPV_GPIO_Port GPIOB
#define DIRH_Pin GPIO_PIN_6
#define DIRH_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
