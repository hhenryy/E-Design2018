#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "variables.h"


// I2C DEFAULT SLAVE ADDRESS
#define IQS263_ADD             0x44<<1

/*********************** IQS263 REGISTERS *************************************/

#define DEVICE_INFO             0x00
#define SYS_FLAGS               0x01
#define COORDINATES             0x02
#define TOUCH_BYTES             0x03
#define COUNTS                  0x04
#define LTA                     0x05
#define DELTAS                  0x06
#define MULTIPLIERS             0x07
#define COMPENSATION            0x08
#define PROX_SETTINGS           0x09
#define THRESHOLDS              0x0A
#define TIMINGS_AND_TARGETS     0x0B
#define GESTURE_TIMERS          0x0C
#define ACTIVE_CHANNELS         0x0D

/* Used to switch Projected mode & set Global Filter Halt (0x01 Byte1) */
#define SYSTEM_FLAGS_VAL					0x00

/* Enable / Disable system events (0x01 Byte2)*/
#define SYSTEM_EVENTS_VAL					0x00

/* Change the Multipliers & Base value (0x07 in this order) */
#define MULTIPLIERS_CH0						0x08	//0x19 - default
#define MULTIPLIERS_CH1						0x08	//0x08 - default
#define MULTIPLIERS_CH2						0x08	//0x08 - default
#define MULTIPLIERS_CH3						0x08	//0x08 - default
#define BASE_VAL							0x08	//0x44 - default

/* Change the Compensation for each channel (0x08 in this order) */
#define COMPENSATION_CH0					0x51
#define COMPENSATION_CH1					0x49
#define COMPENSATION_CH2					0x4A
#define COMPENSATION_CH3					0x49

/* Change the Prox Settings or setup of the IQS263 (0x09 in this order) */
#define PROXSETTINGS0_VAL					0x00
#define PROXSETTINGS1_VAL					0x1D
#define PROXSETTINGS2_VAL					0x04
#define PROXSETTINGS3_VAL					0x00
#define EVENT_MASK_VAL						0x00

/* Change the Thresholds for each channel (0x0A in this order) */

#define PROX_THRESHOLD					0x08
#define TOUCH_THRESHOLD_CH1				0x20
#define TOUCH_THRESHOLD_CH2				0x20
#define TOUCH_THRESHOLD_CH3				0x20
#define MOVEMENT_THRESHOLD				0x03
#define RESEED_BLOCK					0x00
#define HALT_TIME						0x14 //0x14 -> orig
#define I2C_TIMEOUT						0x04

/* Change the Timing settings (0x0B in this order) */
#define LOW_POWER						0x00
#define ATI_TARGET_TOUCH					0x30
#define ATI_TARGET_PROX						0x40
#define TAP_TIMER						0x05
#define FLICK_TIMER						0x51
#define FLICK_THRESHOLD						0x33

/* Set Active Channels (0x0D) */
#define ACTIVE_CHS						0x0F

void handleEvents(void);
int init_iqs263();
void uart_comms();
void seven_segment();
void init_peripherals();
void adc_comms();
void seven_segment_display(uint8_t num);
void convert_adc_raw();
void liters_pumped();
void heating_scheduling();
void write2Flash();
void logPosition();
void heating_control();
void mainLoop();

#endif
