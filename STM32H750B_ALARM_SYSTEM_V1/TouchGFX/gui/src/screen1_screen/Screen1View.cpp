#include <gui/screen1_screen/Screen1View.hpp>
#include <string>


/********** CONSTRUCTOR **********/
Screen1View::Screen1View(): tickCount(0), seconds(0), MINUTE(60), TEST_TIME(10)
{

}

/********** SCREEN FUNCTIONS **********/
void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
    Screen1View::setSceneInit();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::handleTickEvent()
{
	bool countdownAlarmSetState = presenter->getCountdownAlarmSetState();
	bool countdownOngoingAlarmSetState = presenter->getCountdownOngoingAlarmSetState();


	// Countdown for activating the alarm system
	if (countdownAlarmSetState && tickCount == TEST_TIME)
	{
		// Asking for seconds (each second)
		int seconds = presenter->countdownAlarmSetTick();  // Get number of seconds

		Unicode::snprintf(textAreaCountdownAlarmSetBuffer, TEXTAREACOUNTDOWNALARMSET_SIZE, "%d", seconds);
	    textAreaCountdownAlarmSet.invalidate();

	    // IT HAS CONCLUDED
	    if (seconds == 0)
	    {
	    	textAreaCountdownAlarmSet.setVisible(false);
	    	Unicode::snprintf(textAreaCountdownAlarmSetBuffer, TEXTAREACOUNTDOWNALARMSET_SIZE, "%d", 30);

	    	textAreaPreventActivation.setVisible(false);
	    	buttonPreventActivation.setVisible(false);

	    	textAreaPreventActivation.invalidate();
	    	buttonPreventActivation.invalidate();

	    	Screen1View::sceneShowKeypad();

	    	// Reset the value in text area, so on the next run the count starts form 30 not 0.

	    	textAreaCountdownAlarmSet.invalidate();
	    }

	    tickCount = 0;
	}
	// Countdown for activating ongoing alarm (detected movement or sensors)
	else if (countdownOngoingAlarmSetState && tickCount == TEST_TIME)
	{
		int seconds = presenter->countdownOngoingAlarmSetTick();  // Get number of seconds

		// TODO: textAreaCountdownAlarmSet is a horrible name, change it
		Unicode::snprintf(textAreaCountdownOngoingAlarmSetBuffer, TEXTAREACOUNTDOWNONGOINGALARMSET_SIZE, "%d", seconds);
	    textAreaCountdownOngoingAlarmSet.invalidate();

	    if (seconds == 0)
	    {
	    	textAreaCountdownOngoingAlarmSet.setVisible(false);
	    	Unicode::snprintf(textAreaCountdownOngoingAlarmSetBuffer, TEXTAREACOUNTDOWNONGOINGALARMSET_SIZE, "%d", 30);
	    	// Reset the value in text area, so on the next run the count starts form 30 not 0.

	    	textAreaCountdownOngoingAlarmSet.invalidate();
	    }

	    tickCount = 0;
	}
	else if (countdownAlarmSetState || countdownOngoingAlarmSetState)
	{
		tickCount++;  // TODO: error in accuracy of the first second is at question here
	}
}

void Screen1View::setSceneInit()
{
	Screen1View::sceneHideKeypad();

	buttonActivate.setVisible(true); buttonActivate.invalidate();
	textAreaActivate.setVisible(true); textAreaActivate.invalidate();

}

void Screen1View::sceneShowKeypad()
{
	button1.setVisible(true); button1.invalidate();
	button2.setVisible(true); button2.invalidate();
	button3.setVisible(true); button3.invalidate();
	button4.setVisible(true); button4.invalidate();
	button5.setVisible(true); button5.invalidate();
	button6.setVisible(true); button6.invalidate();
	button7.setVisible(true); button7.invalidate();
	button8.setVisible(true); button8.invalidate();
	button9.setVisible(true); button9.invalidate();
	textArea1.setVisible(true); textArea1.invalidate();
	textArea2.setVisible(true); textArea2.invalidate();
	textArea3.setVisible(true); textArea3.invalidate();
	textArea4.setVisible(true); textArea4.invalidate();
	textArea5.setVisible(true); textArea5.invalidate();
	textArea6.setVisible(true); textArea6.invalidate();
	textArea7.setVisible(true); textArea7.invalidate();
	textArea8.setVisible(true); textArea8.invalidate();
	textArea9.setVisible(true); textArea9.invalidate();
	textAreaPin.setVisible(true); textAreaPin.invalidate();
	scalableImagePin.setVisible(true); scalableImagePin.invalidate();
}
void Screen1View::sceneHideKeypad()
{
	button1.setVisible(false); button1.invalidate();
	button2.setVisible(false); button2.invalidate();
	button3.setVisible(false); button3.invalidate();
	button4.setVisible(false); button4.invalidate();
	button5.setVisible(false); button5.invalidate();
	button6.setVisible(false); button6.invalidate();
	button7.setVisible(false); button7.invalidate();
	button8.setVisible(false); button8.invalidate();
	button9.setVisible(false); button9.invalidate();
	textArea1.setVisible(false); textArea1.invalidate();
	textArea2.setVisible(false); textArea2.invalidate();
	textArea3.setVisible(false); textArea3.invalidate();
	textArea4.setVisible(false); textArea4.invalidate();
	textArea5.setVisible(false); textArea5.invalidate();
	textArea6.setVisible(false); textArea6.invalidate();
	textArea7.setVisible(false); textArea7.invalidate();
	textArea8.setVisible(false); textArea8.invalidate();
	textArea9.setVisible(false); textArea9.invalidate();
	textAreaPin.setVisible(false); textAreaPin.invalidate();
	scalableImagePin.setVisible(false); scalableImagePin.invalidate();
}

/********** ALARM SYSTEM FUNCTIONS **********/
void Screen1View::setPolice(bool state)
{
	imagePolice.setVisible(state);
	imagePolice.invalidate();
}

// CALLED FROM FRONTEND (GUI)
void Screen1View::activateAlarmSystem()
{
	textAreaActivate.setVisible(false);
	buttonActivate.setVisible(false);
	textAreaCountdownAlarmSet.setVisible(true);
	textAreaPreventActivation.setVisible(true);
	buttonPreventActivation.setVisible(true);

	textAreaActivate.invalidate();
	buttonActivate.invalidate();
	textAreaCountdownAlarmSet.invalidate();
	textAreaPreventActivation.invalidate();
	buttonPreventActivation.invalidate();

	tickCount = 0;

	// Passing back data to the presenter and the model
	presenter->activateAlarmSystem();
}

// CALLED FROM BACKEND (MODEL)
void Screen1View::activateOngoingAlarm()
{
	textAreaCountdownOngoingAlarmSet.setVisible(true);

	textAreaCountdownAlarmSet.invalidate();

	tickCount = 0;
}

void Screen1View::preventActivationAlarmSystem()
{
	presenter->stopCountdownAlarmSet();

	textAreaPreventActivation.setVisible(false);
	buttonPreventActivation.setVisible(false);
	textAreaPreventActivation.invalidate();
	buttonPreventActivation.invalidate();

	Screen1View::deactivateAlarmSystem();
}

void Screen1View::deactivateAlarmSystem()
{
	imagePolice.setVisible(false);
	buttonActivate.setVisible(true);
	textAreaActivate.setVisible(true);
    Unicode::snprintf(textAreaPinBuffer, TEXTAREAPIN_SIZE, "%s", "");

    textAreaCountdownAlarmSet.setVisible(false);
	Unicode::snprintf(textAreaCountdownAlarmSetBuffer, TEXTAREACOUNTDOWNALARMSET_SIZE, "%d", 30);

    textAreaCountdownOngoingAlarmSet.setVisible(false);
	Unicode::snprintf(textAreaCountdownOngoingAlarmSetBuffer, TEXTAREACOUNTDOWNONGOINGALARMSET_SIZE, "%d", 30);

	imagePolice.invalidate();
	textAreaActivate.invalidate();
	buttonActivate.invalidate();
	textAreaPin.invalidate();
	textAreaCountdownAlarmSet.invalidate();
	textAreaCountdownOngoingAlarmSet.invalidate();

	Screen1View::sceneHideKeypad();

}


/********** KEYPAD BUTTONS FUNCTIONS **********/

void Screen1View::updatePinNumber(int pin)
{
	int length = std::to_string(pin).length();

	char asterisks[length + 1];
	for	(int i = 0; i < length; i++)
	{
		asterisks[i] = '*';
	}
	asterisks[length] = '\0';

	Unicode::strncpy(textAreaPinBuffer, asterisks, length + 1);
	textAreaPin.invalidate();

	// Hide error image in case it was shown in previous querry
	imageError.setVisible(false);
	imageError.invalidate();
}

void Screen1View::updateInvalidPinNumber()
{
    Unicode::snprintf(textAreaPinBuffer, TEXTAREAPIN_SIZE, "%s", "");
	imageError.setVisible(true);

    textAreaPin.invalidate();
	imageError.invalidate();
}

void Screen1View::clickButton1() { if (presenter->getAlarmSystemState()) presenter->clickButton1(); }

void Screen1View::clickButton2() { if (presenter->getAlarmSystemState()) presenter->clickButton2(); }

void Screen1View::clickButton3() { if (presenter->getAlarmSystemState()) presenter->clickButton3(); }

void Screen1View::clickButton4() { if (presenter->getAlarmSystemState()) presenter->clickButton4(); }

void Screen1View::clickButton5() { if (presenter->getAlarmSystemState()) presenter->clickButton5(); }

void Screen1View::clickButton6() { if (presenter->getAlarmSystemState()) presenter->clickButton6(); }

void Screen1View::clickButton7() { if (presenter->getAlarmSystemState()) presenter->clickButton7(); }

void Screen1View::clickButton8() { if (presenter->getAlarmSystemState()) presenter->clickButton8(); }

void Screen1View::clickButton9() { if (presenter->getAlarmSystemState()) presenter->clickButton9(); }

void Screen1View::uart_Data(char *data)
{
	//textArea1.setWideTextAction(touchgfx::WIDE_TEXT_WORDWRAP);
	//Unicode::strncpy(textArea1Buffer, data, TEXTAREA1_SIZE);
	//textArea1.invalidate();
}
