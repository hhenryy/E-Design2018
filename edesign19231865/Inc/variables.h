#ifndef VARIABLES_H_
#define VARIABLES_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "stm32f3xx_hal.h"

// UART Variables
extern uint8_t rx_flag;
extern uint8_t rx_buffer;
extern uint8_t* uart_command;
extern uint8_t* uart_command_copy;
extern uint8_t uart_counter;
extern uint8_t* studentnumber;
extern char endSimbol[8];
extern char comma[2];
extern uint8_t* return_value;
extern uint32_t i2c_counter;
// Timer Variables
extern uint8_t pump_flag;
extern uint32_t tim3_now;
extern uint32_t tim3_prev;
extern uint8_t valve_timer;
extern uint8_t systick_flag;
extern uint8_t rtc_flag2;
extern uint8_t i2c_flag2;
extern uint8_t sizeOfTemp0;
extern char studentnumber1[];

// Seven Segment Variables
extern uint8_t segment_counter;
extern char* segment_val;
extern uint8_t display_set_temp;
extern char* temp_val;
// Heater Variables
extern char heater_ON[];
extern char heater_OFF[];
extern char loggingIdentifier[];
extern char noLoggingData[];
extern char* heater_state;

// Water Accumulated
extern uint32_t water_acc;
extern char* total_water;
extern uint8_t valve_trig;

// Temperature Variables
//extern uint8_t* geyser_temp;
extern uint8_t sizeOfTemp;
extern uint8_t auto_heating;
extern uint8_t* set_temp;
//extern uint8_t* ambient_temp;

// Unknown Variables at this thime
extern char SAFE[];
extern uint8_t send_unk_val;

//Water Flow Variables
extern char valve_OPEN[];
extern char valve_CLOSE[];
extern char* valve_state;

// ADC Variables
extern uint8_t adc_flag;
extern uint32_t adc_raw_voltage;
extern uint32_t adc_raw_current;

extern uint64_t adc_buffer_voltage;
extern uint64_t adc_buffer_current;
extern uint16_t adc_counter;
extern uint16_t adc_buffer_array[];
extern char* voltage_rms;
extern char* current_rms;

extern uint32_t* voltage_int_rms;
extern uint32_t* current_int_rms;

extern uint32_t raw_ambient_temp;
extern uint32_t raw_geyser_temp;
extern uint8_t geyser_temp_int;

extern char* ambient_temp;
extern char* geyser_temp;

// Logging to flash memory;
extern uint8_t enableFlashLogging;
extern uint32_t flash_counter;
extern uint8_t* flash_stored;
extern uint8_t log_counter;
extern uint8_t* log_receiced_num;
extern uint8_t log_empty;
extern uint8_t* flash_mem_start;
extern uint8_t flash_flag;
// Heating Schedule
extern char* heating_schedule_info[];
extern char* heat_schedule1;
extern char* heat_schedule2;
extern char* heat_schedule3;
extern char* heating_info;
extern size_t heating_time_size;

// TIME
extern RTC_TimeTypeDef* timeOfRTC;
extern RTC_TimeTypeDef* new_time;
extern RTC_DateTypeDef* date;
extern uint8_t rtcSecFlag;
extern char* temp_time_var;
extern uint8_t RTC_timer_flag;

// ADC
extern uint32_t* ADC1_buffer;
extern uint32_t* ADC2_buffer;

// Touch Toggle
extern uint8_t touch_flag;

extern unsigned char sliderCoords;                     // variable identified with a Slide event
extern unsigned char data_buffer[30];
extern unsigned char events;                       // variable identified with all events



extern RTC_TimeTypeDef heating_schedule[6];
extern uint16_t fake_RTC_timer;
extern FLASH_EraseInitTypeDef *pEraseInit;
extern uint32_t* flash_error;
extern uint8_t sizeoflogging;
extern uint8_t recv_buffer[16];
extern uint8_t touch_bytes_buffer[2];
extern uint32_t time_intervals[6];
extern uint32_t RTC_in_seconds;
#endif
