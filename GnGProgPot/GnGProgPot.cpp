#include "GnGProgPot.h"

GnGProgPot::GnGProgPot(int wiper_rec_pin, float VH_Value) : Adafruit_DS3502()
{
  wiperRecPin = wiper_rec_pin;
  vH = VH_Value;
}
void GnGProgPot:: Setup()
{
  Serial.println("Adafruit DS3502 Test");
  pinMode(wiperRecPin, INPUT);

  if (!(begin())) {
    Serial.println("Couldn't find DS3502 chip");
    while (1);
  }
  Serial.println("Found DS3502 chip");

}
void GnGProgPot::  setVH (float newVH)
{
  vH = newVH;
}
float GnGProgPot::getWiperValueinVolts()
{
  float wiper_value = analogRead(wiperRecPin);
  wiper_value *= vH;
  wiper_value /= 1024;//Res;
  return wiper_value;

}