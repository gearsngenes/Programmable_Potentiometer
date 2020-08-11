#ifndef GnGProgPot_h
#define GnGProgPot_h
#include "Arduino.h"
#include "Adafruit_DS3502.h"


class GnGProgPot : public Adafruit_DS3502
{
  public:
    GnGProgPot(uint8_t i2c_addr=0x28, float VH_Value = 3.3);
    void Setup();
    void setVH (float newVH);
  protected:
    float vH;
    uint8_t i2c_Address;
};

#endif
