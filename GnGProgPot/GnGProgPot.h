#ifndef GnGProgPot_h
#define GnGProgPot_h
#include "Arduino.h"
#include "Adafruit_DS3502.h"


class GnGProgPot : public Adafruit_DS3502
{
  public:
    GnGProgPot(int wiper_rec_pin, float VH_Value = 3.3);
    int wiperRecPin;
    void Setup();
    float getWiperValueinVolts();
    void setVH (float newVH);
  protected:
    float vH;
};

#endif
