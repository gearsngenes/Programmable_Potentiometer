#include "GnGProgPot.h"

GnGProgPot::GnGProgPot(uint8_t i2c_addr, float VH_Value) : Adafruit_DS3502()
{
  i2c_Address = i2c_addr;
  vH = VH_Value;
}
void GnGProgPot:: Setup()
{
  Serial.println("Adafruit DS3502 Test");

  if (!(begin(i2c_Address ))) {
    Serial.println("Couldn't find DS3502 chip");
    while (1);
  }
  Serial.println("Found DS3502 chip");

}
void GnGProgPot::  setVH (float newVH)
{
  vH = newVH;
}
