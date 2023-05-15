#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    bool getAlarmSystemState();
    bool getCountdownAlarmSetState();
    bool getCountdownOngoingAlarmSetState();

    void activateAlarmSystem();
    void activateOngoingAlarm();
    void stopCountdownAlarmSet();
    int countdownAlarmSetTick();
    int countdownOngoingAlarmSetTick();

    void clickButton1();
    void clickButton2();
    void clickButton3();
    void clickButton4();
    void clickButton5();
    void clickButton6();
    void clickButton7();
    void clickButton8();
    void clickButton9();
    void updatePinNumber();

    void sendStartSensingCommPacket();
    void sendStopSensingCommPacket();

    void turnBuzzerOn();
    void turnBuzzerOff();

protected:
    ModelListener* modelListener;

    char RData[257];
    char TData[257];

    bool buttonState;
    bool alarmSystemState;
    bool invalidPinWarningState;
    bool ongoingAlarmState;
    bool countdownAlarmSetState;
    bool countdownOngoingAlarmSetState;

    int countPinDigits;
    int pinNumber[4];
    int ADMIN_PASSWORD;

    int countdownAlarmSetSeconds;
    int countdownOngoingAlarmSetSeconds;
};

#endif // MODEL_HPP
