
#include "main.h"
#include "mxc_delay.h"
#include "gpio.h"
#include "Time.hpp"
#define MXC_GPIO_PORT_OUT               MXC_GPIO0
#define MXC_GPIO_PIN_OUT                MXC_GPIO_PIN_23


int main(void) {

  mxc_gpio_cfg_t gpio_out;
  gpio_out.port = MXC_GPIO_PORT_OUT;
  gpio_out.mask = MXC_GPIO_PIN_OUT;
  gpio_out.pad = MXC_GPIO_PAD_NONE;
  gpio_out.func = MXC_GPIO_FUNC_OUT;
  MXC_GPIO_Config(&gpio_out);
  while (1)
  {
    MXC_GPIO_OutToggle(gpio_out.port, gpio_out.mask);
    time().sleep(1000);

  }
  return 0;
}

void Error_Handler(void) {

  while (1)
  {
  }

}

