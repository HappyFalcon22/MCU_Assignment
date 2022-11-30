/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f1xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PEDE_BUTTON_Pin GPIO_PIN_0
#define PEDE_BUTTON_GPIO_Port GPIOA
#define BUTTON1_Pin GPIO_PIN_1
#define BUTTON1_GPIO_Port GPIOA
#define BUTTON2_Pin GPIO_PIN_4
#define BUTTON2_GPIO_Port GPIOA
#define PEDE_BUZZER_Pin GPIO_PIN_6
#define PEDE_BUZZER_GPIO_Port GPIOA
#define BUTTON3_Pin GPIO_PIN_0
#define BUTTON3_GPIO_Port GPIOB
#define PEDE_LIGHT_A_Pin GPIO_PIN_10
#define PEDE_LIGHT_A_GPIO_Port GPIOB
#define PEDE_LIGHT_B_Pin GPIO_PIN_8
#define PEDE_LIGHT_B_GPIO_Port GPIOA
#define LIGHT1_A_Pin GPIO_PIN_10
#define LIGHT1_A_GPIO_Port GPIOA
#define LIGHT1_B_Pin GPIO_PIN_3
#define LIGHT1_B_GPIO_Port GPIOB
#define LIGHT2_B_Pin GPIO_PIN_4
#define LIGHT2_B_GPIO_Port GPIOB
#define LIGHT2_A_Pin GPIO_PIN_5
#define LIGHT2_A_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
