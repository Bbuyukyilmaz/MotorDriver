/*
 * MotorDriver.c
 *
 *  Created on: Sep 4, 2023
 *      Author: baris
 */

#include "main.h"
#include "MotorDriver.h"
#include "PCListener.h"

TaskHandle_t motorTaskHandle;

/* USER CODE BEGIN Header_MotorTask */
/**
* @brief Function implementing the motorTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_MotorTask */
void MotorTaskFunction(void const * argument)
{

	uint32_t hand_position = FIST;

	set_all_motor_speed(90);

	/* Infinite loop */

	for(;;)
	{

		xSemaphoreTake(handFlexHandle, portMAX_DELAY);

//		set_hand_position(hand_position);

		xSemaphoreTake(handReleaseHandle, portMAX_DELAY);

//		set_hand_position(OPEN);

	}

}

void MotorTaskInit(void)
{
	  TaskFunction_t MotorTask = MotorTaskFunction;
	  xTaskCreate(	MotorTask,
					"Motor Task",
					128,
					0,
					tskIDLE_PRIORITY,
	  				motorTaskHandle );
}


void set_motor_position(uint8_t channel, uint16_t position){

	uint32_t target = 4 * position;
	uint8_t tx_buffer[MESSAGE_SIZE];
	tx_buffer[0] = SET_TARGET;
	tx_buffer[1] = channel;
	tx_buffer[2] = target & 0x7F;
	tx_buffer[3] = (target >> 7) & 0x7F;
	HAL_UART_Transmit(&huart6, (uint8_t*)tx_buffer, 4, HAL_MAX_DELAY);

}

void set_motor_speed(uint8_t channel, uint32_t speed){

	uint8_t tx_buffer[MESSAGE_SIZE];
	tx_buffer[0] = SET_SPEED;
	tx_buffer[1] = channel;
	tx_buffer[2] = speed & 0x7F;
	tx_buffer[3] = (speed >> 7) & 0x7F;
	HAL_UART_Transmit(&huart6, (uint8_t*)tx_buffer, 4, HAL_MAX_DELAY);

}
void set_all_motor_speed(uint32_t speed){

	set_motor_speed(THUMB_FINGER, speed);
	set_motor_speed(LITTLE_FINGER, speed);
	set_motor_speed(RING_FINGER, speed);
	set_motor_speed(MIDDLE_FINGER, speed);
	set_motor_speed(INDEX_FINGER, speed);
	set_motor_speed(WRIST, speed);
}

void set_motor_acceleration(uint8_t channel, uint32_t acceleration){

	uint8_t tx_buffer[MESSAGE_SIZE];
	tx_buffer[0] = SET_ACCELERATION;
	tx_buffer[1] = channel;
	tx_buffer[2] = acceleration & 0x7F;
	tx_buffer[3] = (acceleration >> 7) & 0x7F;
	HAL_UART_Transmit(&huart6, (uint8_t*)tx_buffer, 4, HAL_MAX_DELAY);
}

void set_all_motor_acceleration(uint32_t acceleration){

	set_motor_acceleration(THUMB_FINGER, acceleration);
	set_motor_acceleration(LITTLE_FINGER, acceleration);
	set_motor_acceleration(RING_FINGER, acceleration);
	set_motor_acceleration(MIDDLE_FINGER, acceleration);
	set_motor_acceleration(INDEX_FINGER, acceleration);
	set_motor_acceleration(WRIST, acceleration);
}

void set_hand_position(const uint32_t position){

	switch(position){
		case POINTING:
			set_motor_position(THUMB_FINGER, FINGER_OPEN_POSITION_THUMB);
			set_motor_position(LITTLE_FINGER, FINGER_CLOSE_POSITION_LITTLE);
			set_motor_position(RING_FINGER, FINGER_OPEN_POSITION_RING);
			set_motor_position(MIDDLE_FINGER, FINGER_OPEN_POSITION_MIDDLE);
			set_motor_position(INDEX_FINGER, FINGER_OPEN_POSITION_INDEX);
			HAL_Delay(1000);
			set_motor_position(THUMB_FINGER, FINGER_CLOSE_POSITION_THUMB);
			set_motor_position(LITTLE_FINGER, FINGER_OPEN_POSITION_LITTLE);
			set_motor_position(RING_FINGER, FINGER_CLOSE_POSITION_RING);
			set_motor_position(MIDDLE_FINGER, FINGER_CLOSE_POSITION_MIDDLE);
			set_motor_position(INDEX_FINGER, FINGER_OPEN_POSITION_INDEX);
			break;
		case FIST:
			set_motor_position(THUMB_FINGER, FINGER_OPEN_POSITION_THUMB);
			set_motor_position(LITTLE_FINGER, FINGER_CLOSE_POSITION_LITTLE);
			set_motor_position(RING_FINGER, FINGER_OPEN_POSITION_RING);
			set_motor_position(MIDDLE_FINGER, FINGER_OPEN_POSITION_MIDDLE);
			set_motor_position(INDEX_FINGER, FINGER_OPEN_POSITION_INDEX);
			HAL_Delay(1000);
			set_motor_position(THUMB_FINGER, FINGER_CLOSE_POSITION_THUMB);
			set_motor_position(LITTLE_FINGER, FINGER_OPEN_POSITION_LITTLE);
			set_motor_position(RING_FINGER, FINGER_CLOSE_POSITION_RING);
			set_motor_position(MIDDLE_FINGER, FINGER_CLOSE_POSITION_MIDDLE);
			set_motor_position(INDEX_FINGER, FINGER_CLOSE_POSITION_INDEX);
				break;
		case ROCK:
			set_motor_position(THUMB_FINGER, FINGER_OPEN_POSITION_THUMB);
			set_motor_position(LITTLE_FINGER, FINGER_CLOSE_POSITION_LITTLE);
			set_motor_position(RING_FINGER, FINGER_OPEN_POSITION_RING);
			set_motor_position(MIDDLE_FINGER, FINGER_OPEN_POSITION_MIDDLE);
			set_motor_position(INDEX_FINGER, FINGER_OPEN_POSITION_INDEX);
			HAL_Delay(1000);
			set_motor_position(THUMB_FINGER, FINGER_CLOSE_POSITION_THUMB);
			set_motor_position(LITTLE_FINGER, FINGER_CLOSE_POSITION_LITTLE);
			set_motor_position(RING_FINGER, FINGER_CLOSE_POSITION_RING);
			set_motor_position(MIDDLE_FINGER, FINGER_CLOSE_POSITION_MIDDLE);
			set_motor_position(INDEX_FINGER, FINGER_OPEN_POSITION_INDEX);
				break;
		case FUCK:
			set_motor_position(THUMB_FINGER, FINGER_OPEN_POSITION_THUMB);
			set_motor_position(LITTLE_FINGER, FINGER_CLOSE_POSITION_LITTLE);
			set_motor_position(RING_FINGER, FINGER_OPEN_POSITION_RING);
			set_motor_position(MIDDLE_FINGER, FINGER_OPEN_POSITION_MIDDLE);
			set_motor_position(INDEX_FINGER, FINGER_OPEN_POSITION_INDEX);
			HAL_Delay(1000);
			set_motor_position(THUMB_FINGER, FINGER_CLOSE_POSITION_THUMB);
			set_motor_position(LITTLE_FINGER, FINGER_OPEN_POSITION_LITTLE);
			set_motor_position(RING_FINGER, FINGER_CLOSE_POSITION_RING);
			set_motor_position(MIDDLE_FINGER, FINGER_OPEN_POSITION_MIDDLE);
			set_motor_position(INDEX_FINGER, FINGER_CLOSE_POSITION_INDEX);
				break;
		case THUMB:
			set_motor_position(THUMB_FINGER, FINGER_OPEN_POSITION_THUMB);
			set_motor_position(LITTLE_FINGER, FINGER_CLOSE_POSITION_LITTLE);
			set_motor_position(RING_FINGER, FINGER_OPEN_POSITION_RING);
			set_motor_position(MIDDLE_FINGER, FINGER_OPEN_POSITION_MIDDLE);
			set_motor_position(INDEX_FINGER, FINGER_OPEN_POSITION_INDEX);
			HAL_Delay(1000);
			set_motor_position(THUMB_FINGER, FINGER_OPEN_POSITION_THUMB);
			set_motor_position(LITTLE_FINGER, FINGER_OPEN_POSITION_LITTLE);
			set_motor_position(RING_FINGER, FINGER_CLOSE_POSITION_RING);
			set_motor_position(MIDDLE_FINGER, FINGER_CLOSE_POSITION_MIDDLE);
			set_motor_position(INDEX_FINGER, FINGER_CLOSE_POSITION_INDEX);
				break;
		case OPEN:
			set_motor_position(THUMB_FINGER, FINGER_OPEN_POSITION_THUMB);
			set_motor_position(LITTLE_FINGER, FINGER_CLOSE_POSITION_LITTLE);
			set_motor_position(RING_FINGER, FINGER_OPEN_POSITION_RING);
			set_motor_position(MIDDLE_FINGER, FINGER_OPEN_POSITION_MIDDLE);
			set_motor_position(INDEX_FINGER, FINGER_OPEN_POSITION_INDEX);
				break;
		default:
			break;
	}

}



