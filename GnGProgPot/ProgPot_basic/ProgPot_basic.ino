#include "GnGProgPot.h"

/*
 * This is an example code of the wrapper class of Adafruit Industrie's DS3502 library. The 
 * original library codes for a programmable potentiometer that can act as a voltage divider.
 * Our GnGProgPot library wraps this class so less #defines are necessary and so that you can
 * control which pin you read the "wiper value" from and the maximum voltage you can expect.
 */

int WVP= A0; //pin you analog read the potentiometer wiper from
GnGProgPot *  prog_pot = new GnGProgPot (WVP); //pointer for programmable potentiometer

void setup() 
{
  Serial.begin(115200);
  prog_pot->Setup();//Setup the device after Serial.begin(----); command

}

void loop() {
  int winput = 42;
  Serial.print("Wiper Input set to: "); Serial.print(winput); Serial.println(" out of 127");
  prog_pot->setWiper(winput);  
  float wipervalinV = prog_pot->getWiperValueinVolts();
  Serial.print("Wiper Voltage Read (V): "); Serial.println (wipervalinV);
  Serial.println();
  delay(1000);

}
