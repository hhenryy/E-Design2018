#include "variables.h"


// UART Variables

uint8_t rx_flag = 0;
uint8_t rx_buffer;
uint8_t* uart_command = NULL;
uint8_t* uart_command_copy = NULL;
uint8_t uart_counter = 0;
uint8_t rx_val = 0;
char studentnumber1[] = {'1', '9','2','3','1','8','6','5'};
unsigned char* studentnumber;
char endSimbol[] = {'\r', '\n'};
char comma[] = {','};
uint8_t* return_value = NULL;


uint8_t auto_heating = 0;


// Timer variables
uint8_t pump_flag = 0;
uint32_t tim3_now = 0;
uint32_t tim3_prev = 0;
uint8_t systick_flag = 0;
uint8_t valve_timer = 0;
uint8_t rtc_flag2 = 0;
uint8_t i2c_flag2 = 0;

// Heater On Off Variables
char heater_ON[] = {'O','N','\0'};
char heater_OFF[] = {'O','F','F'};
char loggingIdentifier[] = {'$','L'};
char noLoggingData[] = "$L,0,0,0,0,0,0,0,0,OFF,CLOSED\r\n";
char* heater_state = NULL;

// Unknown parameters:
uint8_t send_unk_val = 48 ;

// Water Accumulated
uint32_t water_acc = 0;
char* total_water = NULL;
uint8_t valve_trig = 0;

// Water Flow Variables
char valve_OPEN[4] = {'O','P','E','N'};
char valve_CLOSE[6] = {'C','L','O','S','E','D'};
char* valve_state = NULL;

// Temperature Variables
uint8_t* set_temp = NULL;
uint8_t sizeOfTemp = 0;
//uint8_t* geyser_temp = NULL;
//uint8_t* ambient_temp = NULL;

// Seven Segment Variables
uint8_t segment_counter = 0;
char* segment_val = NULL;
uint8_t display_set_temp = 0;
char* temp_val = NULL;

// ADC Variables
uint8_t adc_flag = 0;
uint32_t adc_raw_voltage = 0;
uint32_t adc_raw_current = 0;
uint32_t raw_ambient_temp = 0;
uint32_t raw_geyser_temp = 0;
uint8_t geyser_temp_int = 0;
uint64_t adc_buffer_voltage = 0;
uint64_t adc_buffer_current = 0;
uint16_t adc_counter = 0;
char* voltage_rms = NULL;
char* current_rms = NULL;

// interger value of voltage and current RMS
uint32_t* voltage_int_rms = NULL;
uint32_t* current_int_rms = NULL;

char* ambient_temp = NULL;
char* geyser_temp = NULL;

// Logging to flash memory;
uint8_t enableFlashLogging = 0;

// Heating Schedule
char* heating_schedule_info[3];
char* heat_schedule1 = NULL;
char* heat_schedule2 = NULL;
char* heat_schedule3 = NULL;
char* heating_info = NULL;
size_t heating_time_size;

// Time Variables & RTC
RTC_TimeTypeDef* timeOfRTC = NULL;
RTC_TimeTypeDef* new_time = NULL;
RTC_DateTypeDef* date = NULL;
char* temp_time_var = NULL;
uint8_t rtcSecFlag = 0;


// Heating Schedule
RTC_TimeTypeDef heating_schedule[6];
uint16_t fake_RTC_timer = 0;
uint8_t RTC_timer_flag = 0;


// Flash memorry varibales
//uint32_t* memoryStartLoc = 0x0800 0000;
uint32_t flash_counter = 0 ;
uint8_t* flash_stored = NULL;
uint8_t log_counter = 0;
uint8_t* log_receiced_num = NULL;
uint8_t log_empty = 1;
uint8_t* flash_mem_start = (uint8_t*)0x08009000;
uint8_t flash_flag = 0;

unsigned char sliderCoords;                     // variable identified with a Slide event
unsigned char data_buffer[30];
unsigned char events = 0;                       // variable identified with all events

 // Touch Toggle
uint8_t touch_flag = 1;
uint32_t i2c_counter = 0;


uint32_t* ADC1_buffer = NULL;
uint32_t* ADC2_buffer = NULL;

FLASH_EraseInitTypeDef *pEraseInit = NULL;
uint32_t* flash_error = NULL;

uint8_t sizeoflogging = 0;
uint8_t recv_buffer[16];
uint8_t touch_bytes_buffer[2] = {0x03, 0x0};

// TIME
uint32_t time_intervals[6];
uint32_t RTC_in_seconds = 0;
