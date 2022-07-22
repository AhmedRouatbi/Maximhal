
#include <cstring>
#include "main.h"
#include "Time.hpp"
#include "Gpio.hpp"
#include "dma.h"

Gpio ledGreen{{MXC_GPIO0, 23}};
Gpio ledRed{{MXC_GPIO0, 22}};
Gpio button{{MXC_GPIO0, 21}, Gpio::Function::INPUT, Gpio::Pull::UP};

int main(void) {

  static uint32_t startTime = 0;
  while (1)
  {

    ledRed.set(button.get());
    if (time().millis() - startTime > 1000)
    {
      startTime = time().millis();
      ledGreen.toggle();
    }

  }
  return 0;
}


