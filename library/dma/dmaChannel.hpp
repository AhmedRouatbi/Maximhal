#pragma once
class dmaChannel {
  enum class Priority {
    low,
    medium,
    high,
    veryHigh
  };

  enum class Channel {
    Ch0 = 0,
    Ch1,
    Ch2,
    Ch3,
    Ch4,
    Ch5,
    Ch6,
    Ch7
  };

  enum class Size{
    bit8,
    bit16,
    bit32
  };
  enum class Direction{
    readPeripheral,
    writeToPeripheral,
  };



  struct Setup {
    Priority channelPriority;
    Size registerSize;
    Size memorySize;
    bool isCircular;
    bool periphericalAutoIncrement;
    bool memoryAutoIncrement;
  };
};
