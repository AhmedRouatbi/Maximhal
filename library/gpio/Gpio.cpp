#include "Gpio.hpp"

//----------------------------------------------------------------------------------------------------

Gpio::Gpio(Pin pin, Function f, Pull p, AlternateFunction a) :
    pin(pin) {

  configuration(f, p, a);
}

//----------------------------------------------------------------------------------------------------

void Gpio::configuration(const Function f, const Pull p, const AlternateFunction alternateFunction) {
  const uint32_t reset_mask_pull = ~(1 << (pin.number));

  pin.port->padctrl0 &= reset_mask_pull;
  pin.port->ps &= reset_mask_pull;
  switch (f)
  {
    case Function::INPUT:
      pin.port->inen |= (1 << (pin.number));
      break;
    case Function::OUTPUT:
      pin.port->outen |= (1 << (pin.number));
      break;
    case Function::ALTERNATE:

      break;
  }

  switch (p)
  {
    case Pull::NO: pin.port->padctrl0 &= 0 << (pin.number);
      break;
    case Pull::UP:pin.port->padctrl0 |= 1 << (pin.number);
      pin.port->ps |= 1 << (pin.number);
      break;
    case Pull::DOWN:pin.port->padctrl0 |= 1 << (pin.number);
      pin.port->ps &= 0 << (pin.number);
      break;
  }

  const uint32_t reset_mask_function_e0   = (1 << (pin.number));
  const uint32_t reset_mask_function_e1_2 = ~(1 << (pin.number));
  pin.port->en0 |= reset_mask_function_e0;  // on power on  all IO configured as High impedance inputs
  pin.port->en1 &= reset_mask_function_e1_2;
  pin.port->en2 &= reset_mask_function_e1_2;

  setAlternate(alternateFunction);
}

//----------------------------------------------------------------------------------------------------

bool Gpio::get()
{
    return this->pin.port->in & (1 << pin.number);
}

//----------------------------------------------------------------------------------------------------

void Gpio::set(const bool value)
{
  if(value)
  {
    this->pin.port->out |=1 << (this->pin.number );
  }
  else
  {
    this->pin.port->out &=  ~(1 << (pin.number));
  }

}

//----------------------------------------------------------------------------------------------------

void Gpio::setAlternate(AlternateFunction alternateFunction) {
  switch (alternateFunction)
  {

    case AlternateFunction::AF1:
      pin.port->en0 &= ~(1 << (pin.number));
      pin.port->en1 &= ~(1 << (pin.number));
      pin.port->en2 &= ~(1 << (pin.number));
      break;
    case AlternateFunction::AF2:
      pin.port->en0 &= ~(1 << (pin.number));
      pin.port->en1 |= (1 << (pin.number));
      pin.port->en2 &= ~(1 << (pin.number));
      break;
    case AlternateFunction::AF3:
      pin.port->en0 |= (1 << (pin.number));
      pin.port->en1 |= (1 << (pin.number));
      pin.port->en2 &= ~(1 << (pin.number));
      break;
    case AlternateFunction::AF4:
      pin.port->en0 &= ~(1 << (pin.number));
      pin.port->en1 &= ~(1 << (pin.number));
      pin.port->en2 |= (1 << (pin.number));
      break;
    case AlternateFunction::NO:
      break;
  }
}

//----------------------------------------------------------------------------------------------------

void Gpio::toggle()
{
    this->pin.port->out ^= 1 << this->pin.number;
}

