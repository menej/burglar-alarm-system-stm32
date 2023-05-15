#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <unistd.h>
#include <cstring>

#ifndef SIMULATOR
#include "main.h"
#include "cmsis_os2.h"
#include <cstring>
extern "C"
{
	extern UART_HandleTypeDef huart1;
	extern osMessageQueueId_t uartQueueHandle;
	uartData_t *uartData_r;
}
#endif

Model::Model() :
	modelListener(0),
	buttonState(false),
	ongoingAlarmState(false),
	alarmSystemState(false),
	invalidPinWarningState(false),
	countdownAlarmSetState(false),
	countPinDigits(0),
	ADMIN_PASSWORD(1234)  // Perhaps not the best practice to hard-code the password
{
#ifndef SIMULATOR
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
#endif
}

void Model::tick()
{
#ifndef SIMULATOR
	if (osMessageQueueGetCount(uartQueueHandle) > 0)
	{
		if (osMessageQueueGet(uartQueueHandle, &uartData_r, 0, 0) == osOK)
		{
			strncpy(RData, uartData_r->Data, uartData_r->size);
			modelListener->uart_Data(RData);
			// Check if movement on first sensor
			if (strcmp(RData, "1111110") == 0 && alarmSystemState)
			{
				buttonState = true;
			}
			// Check if movement on second sensor
			else if (strcmp(RData, "1111101") == 0 && alarmSystemState)
			{
				buttonState = true;
			}
			else
			{
				buttonState = false;
			}
		}
	}
	else
	{
		buttonState = false;
	}

#endif
	// modelListener->setPolice(buttonState)
	// If alarm system is set and sensor is activated then initiate alarm
	if (alarmSystemState && buttonState && !ongoingAlarmState && !countdownOngoingAlarmSetState)
	{
		Model::activateOngoingAlarm();
	}
	// Countdown is ticking down
}

/********** SIMULATOR METHODS **********/

// Send a START SENSING COMM PACKET
void Model::sendStartSensingCommPacket()
{
#ifndef SIMULATOR
	strcpy(TData, "0000001");
	HAL_UART_Transmit(&huart1, (uint8_t *) TData, strlen(TData), 1000);
#endif
}

// Send a STOP SENSING COMM PACKET
void Model::sendStopSensingCommPacket()
{
#ifndef SIMULATOR
	strcpy(TData, "0000010");
	HAL_UART_Transmit(&huart1, (uint8_t *) TData, strlen(TData), 1000);
#endif
}

// Send a SENSOR ONE CHECK packet

/********** BUZZER METHODS **********/
void Model::turnBuzzerOn()
{
#ifndef SIMULATOR
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
#endif
}

void Model::turnBuzzerOff()
{
#ifndef SIMULATOR
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
#endif
}

/********** GETTERS AND SETTERS **********/

bool Model::getAlarmSystemState()
{
	return alarmSystemState;
}

bool Model::getCountdownAlarmSetState()
{
	return countdownAlarmSetState;
}

bool Model::getCountdownOngoingAlarmSetState()
{
	return countdownOngoingAlarmSetState;
}

/********** FUNCTION TO PROCESS ACTIVATION OF ALARM **********/

void Model::activateAlarmSystem()
{
	// After this, the countdown function continues inside the view under handleTickEvent() function.
	// This is the better way of implementing delay or timing functions, as it does not waste processor time.
	countdownAlarmSetState = true;
	countdownAlarmSetSeconds = 30;
}

void Model::activateOngoingAlarm()
{
	// After this, the countdown function continues inside the view under handleTickEvent() function.
	countdownOngoingAlarmSetState = true;
	countdownOngoingAlarmSetSeconds = 30;
	modelListener->activateOngoingAlarm();
}

int Model::countdownAlarmSetTick()
{
	countdownAlarmSetSeconds--;
	if (countdownAlarmSetSeconds <= 0)
	{
		countdownAlarmSetState = false;
		alarmSystemState = true;
		Model::sendStartSensingCommPacket();
	}
	return countdownAlarmSetSeconds;
}

int Model::countdownOngoingAlarmSetTick()
{
	countdownOngoingAlarmSetSeconds--;
	if (countdownOngoingAlarmSetSeconds <= 0)
	{
		countdownOngoingAlarmSetState = false;
		ongoingAlarmState = true;
		modelListener->setPolice(true);  // START THE ALARM SOUNDS AND NOTIFICATIONS (in other function)
		Model::turnBuzzerOn();
	}
	return countdownOngoingAlarmSetSeconds;
}


void Model::stopCountdownAlarmSet()
{
	countdownAlarmSetState = false;
	// To be sure of the countdown ongoing alarm state is not initated reset it
	countdownOngoingAlarmSetState = false;

	alarmSystemState = false;
	ongoingAlarmState = false;
}

/********** KEYPAD BUTTONS FUNCTIONS **********/

void Model::updatePinNumber()
{
	int pin = 0;
	for (int i = 0; i < countPinDigits; i++)
	{
		pin = pin * 10 + pinNumber[i];
	}

	// Reached full PIN length
	if (countPinDigits == 4)
	{
		// Correct ADMIN_PASSWORD
		if (pin == ADMIN_PASSWORD) {
			// CALL A FUNCTION HERE THAT WILL TAKE CARE OF THIS + NOTIFICATION

			// To be sure of the countdown ongoing alarm state is not initated reset it
			Model::sendStopSensingCommPacket();
			Model::turnBuzzerOff();


			countdownOngoingAlarmSetState = false;

			alarmSystemState = false;
			ongoingAlarmState = false;
			modelListener->deactivateAlarmSystem();
		}
		// Wrong ADMIN_PASSWORD
		else
		{
			modelListener->updateInvalidPinNumber();
			//modelListener->updatePinNumber(pin);
		}
		countPinDigits = 0;
		int newPinNumber[4];
		std::memcpy(newPinNumber, pinNumber, sizeof(pinNumber));
	}
	// Have not reached full PIN length yet
	else
	{
		modelListener->updatePinNumber(pin);

		//modelListener->updatePinNumber(pinNumber, countPinDigits);
	}

}

void Model::clickButton1() { pinNumber[countPinDigits++] = 1; Model::updatePinNumber(); }

void Model::clickButton2() { pinNumber[countPinDigits++] = 2; Model::updatePinNumber(); }

void Model::clickButton3() { pinNumber[countPinDigits++] = 3; Model::updatePinNumber(); }

void Model::clickButton4() { pinNumber[countPinDigits++] = 4; Model::updatePinNumber(); }

void Model::clickButton5() { pinNumber[countPinDigits++] = 5; Model::updatePinNumber(); }

void Model::clickButton6() { pinNumber[countPinDigits++] = 6; Model::updatePinNumber(); }

void Model::clickButton7() { pinNumber[countPinDigits++] = 7; Model::updatePinNumber(); }

void Model::clickButton8() { pinNumber[countPinDigits++] = 8; Model::updatePinNumber(); }

void Model::clickButton9() { pinNumber[countPinDigits++] = 9; Model::updatePinNumber(); }






