#pragma once
#include "gpio_regs.h"
class Gpio
{
public:
  enum class AlternateFunction
  { AF1, AF2, AF3, AF4,NO};

  enum class Function
  {INPUT, OUTPUT, ALTERNATE};

  enum class Pull
  {NO, UP, DOWN};

  struct Pin{
    mxc_gpio_regs_t * port;
    uint8_t number;
  };

  Gpio(Pin pin, Function f = Function::OUTPUT, Pull p = Pull::NO, AlternateFunction a = AlternateFunction::NO);
  void set(bool value);
  void toggle();
  bool get();

  void configuration(Function f, Pull p, AlternateFunction alternateFunction);
  void setAlternate(AlternateFunction alternateFunction);

private:
  Pin pin;
};
