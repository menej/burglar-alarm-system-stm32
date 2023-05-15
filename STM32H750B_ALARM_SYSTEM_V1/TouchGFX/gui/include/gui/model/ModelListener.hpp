#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void uart_Data(char *data);

    virtual void setPolice(bool state) {};
    virtual void deactivateAlarmSystem();
    virtual void updatePinNumber(int pin);
    virtual void activateOngoingAlarm();
    virtual void updateInvalidPinNumber();


protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
