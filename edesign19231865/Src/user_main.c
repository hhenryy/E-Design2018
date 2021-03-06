#include "main.h"
#include "stm32f3xx_hal.h"

/* USER CODE BEGIN Includes */
//#include <stdlib.h>
//#include "functions.h"
#include "functions.h"
#include "variables.h"
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc2;
DMA_HandleTypeDef hdma_adc2;

I2C_HandleTypeDef hi2c1;

RTC_HandleTypeDef hrtc;

//TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
ADC_ChannelConfTypeDef Channel_1;
ADC_ChannelConfTypeDef Channel_2;
ADC_ChannelConfTypeDef Channel_3;
ADC_ChannelConfTypeDef Channel_4;
extern uint32_t uwTick;



void mainLoop(){
	  if(rx_flag == 1 ){ 	// UART Comms
		  rx_flag = 0;
		  uart_comms();
	  }

	  // Seven Segment
	  if(systick_flag == 1 && uwTick%10){
		  systick_flag = 0;
		  i2c_counter += 1;
		  seven_segment();
//		  HAL_I2C_Mem_Read_IT( &hi2c1, IQS263_ADD, 0x03, I2C_MEMADD_SIZE_8BIT,  &recv_buffer[2],1);


	  }
	  if(uwTick%30 == 0 && i2c_flag2){
		  HAL_I2C_Mem_Read_IT( &hi2c1, IQS263_ADD, 0x03, I2C_MEMADD_SIZE_8BIT,  &recv_buffer[2],1);
		  i2c_flag2 = 0;
	  }

	  if(i2c_counter == 250){
		  i2c_counter = 0;
		  touch_flag = 0;
		  handleEvents();
	  }
	  if(uwTick%500 == 0 && rtc_flag2 ){
		  rtc_flag2 = 0;
		  HAL_RTC_GetTime(&hrtc,timeOfRTC,RTC_FORMAT_BIN);
		  HAL_RTC_GetDate(&hrtc,date,RTC_FORMAT_BIN);
	  }

	  // ADC conversion
	  if(adc_flag == 1){
		  adc_flag = 0;
		  adc_comms();
	  }
	  // Nothing at the moment
	  if(touch_flag == 1 ){
		  touch_flag = 0;
	  }
	  // scheduling of heating and RTC
	  if(RTC_timer_flag == 1){
		  fake_RTC_timer += 1;
		  RTC_timer_flag = 0;
		  if(fake_RTC_timer == 500){
			  fake_RTC_timer = 0;
			  heating_scheduling();
		  }
	  }

	  // Writing to FLASH
	  if(flash_flag){
		  flash_flag = 0;
		  flash_counter += 1;
		  if(flash_counter == 10000){
			  flash_counter = 0;
			  if(enableFlashLogging){
			  write2Flash();
		  	  }
		  }
	  }
	  // Pumping is occurring
	  if(pump_flag == 1){
		  liters_pumped();
	  }



}

