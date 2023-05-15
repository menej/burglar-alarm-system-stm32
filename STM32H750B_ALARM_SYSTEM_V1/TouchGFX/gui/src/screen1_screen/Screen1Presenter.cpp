#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}

bool Screen1Presenter::getAlarmSystemState() { return model->getAlarmSystemState(); }

bool Screen1Presenter::getCountdownAlarmSetState() { return model->getCountdownAlarmSetState(); }

bool Screen1Presenter::getCountdownOngoingAlarmSetState() { return model->getCountdownOngoingAlarmSetState(); }

void Screen1Presenter::setPolice(bool state) { view.setPolice(state); }

int Screen1Presenter::countdownAlarmSetTick() { return model->countdownAlarmSetTick(); }

int Screen1Presenter::countdownOngoingAlarmSetTick() { return model->countdownOngoingAlarmSetTick(); }

void Screen1Presenter::activateAlarmSystem() { model->activateAlarmSystem(); }

void Screen1Presenter::activateOngoingAlarm() { view.activateOngoingAlarm(); }

void Screen1Presenter::deactivateAlarmSystem() { view.deactivateAlarmSystem(); }

void Screen1Presenter::stopCountdownAlarmSet() { model->stopCountdownAlarmSet(); }

void Screen1Presenter::updatePinNumber(int pin) { view.updatePinNumber(pin); }

void Screen1Presenter::updateInvalidPinNumber() { view.updateInvalidPinNumber(); }

void Screen1Presenter::clickButton1() { model->clickButton1(); }

void Screen1Presenter::clickButton2() { model->clickButton2(); }

void Screen1Presenter::clickButton3() { model->clickButton3(); }

void Screen1Presenter::clickButton4() { model->clickButton4(); }

void Screen1Presenter::clickButton5() { model->clickButton5(); }

void Screen1Presenter::clickButton6() { model->clickButton6(); }

void Screen1Presenter::clickButton7() { model->clickButton7(); }

void Screen1Presenter::clickButton8() { model->clickButton8(); }

void Screen1Presenter::clickButton9() { model->clickButton9(); }


void Screen1Presenter::uart_Data(char *data)
{
	view.uart_Data(data);
}
