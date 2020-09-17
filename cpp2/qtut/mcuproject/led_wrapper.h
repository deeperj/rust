#ifndef LED_WRAPPER_H
#define LED_WRAPPER_H

#include <qul/singleton.h>
#include "led.h"

struct LED : public Qul::Singleton<LED>
{
    void setEnabled(bool enabled)
    {
        if (enabled)
            green_led_switch_on();
        else
            green_led_switch_off();
    }
};

#endif // LED_WRAPPER_H
