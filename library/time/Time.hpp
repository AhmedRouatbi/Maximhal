#pragma once
#include "max32670.h"

extern "C" {
void SysTick_Handler(void);
}

class Time {
private:
    Time();

    void init();

public:
    static Time &getTimeInstance();

    void sleep(uint32_t time_ms);

    uint32_t millis();

};

Time &time();