#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    // SETTING WIDGETS
    virtual void setSceneInit();
    virtual void sceneShowKeypad();
    virtual void sceneHideKeypad();

    virtual void setPolice(bool state);

    virtual void updatePinNumber(int pin);
    virtual void updateInvalidPinNumber();

    virtual void activateAlarmSystem();
    virtual void deactivateAlarmSystem();
    virtual void preventActivationAlarmSystem();

    virtual void activateOngoingAlarm();

    virtual void handleTickEvent();


    // KEYPAD BUTTONS
    virtual void clickButton1();
    virtual void clickButton2();
    virtual void clickButton3();
    virtual void clickButton4();
    virtual void clickButton5();
    virtual void clickButton6();
    virtual void clickButton7();
    virtual void clickButton8();
    virtual void clickButton9();

    virtual void uart_Data(char *data);

protected:
    int16_t seconds;
    int16_t tickCount;

    int MINUTE;
    int TEST_TIME;
};

#endif // SCREEN1VIEW_HPP
