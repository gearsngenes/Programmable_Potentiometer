#include "GnGProgPot.h"

uint8_t tempi2Address = 0x29; //I2C address of our potentiometer
int readPin = A1; //pin we read potentiometer wiper value from
GnGProgPot *  prog_pot = new GnGProgPot (tempi2Address); //pointer for programmable potentiometer

void setup()
{
  Serial.begin(115200);
  pinMode(readPin, INPUT);
  prog_pot->Setup();//Setup the device after Serial.begin(----)
}

void loop() {
  for (int i = 0; i < 121; i += 20)
  {
    Serial.print("Wiper="); Serial.print(i); Serial.print(", ratio: "); Serial.println((i * 1.0) / 127 * 1.0);
    
    prog_pot->setWiper(i); //set wiper value
    
    Serial.print("AnalogRead("); Serial.print(readPin); Serial.print(")="); Serial.println(analogRead(readPin));
    
    float vpin = 3.3 * analogRead(readPin) / 1023.0;
    float expected = ((i * 1.0) / 127 * 1.0 * 3.3);
    
    Serial.print("Computed Voltage (V): "); Serial.print (vpin);
    Serial.print(" Expected voltage: "); Serial.print(expected);
    Serial.print(" %diff: "); Serial.print(((vpin - expected) / vpin) * 100.0); Serial.println (" %");
    Serial.println("....");
    
  }

  Serial.println("-------------");
  delay(1000);

}
