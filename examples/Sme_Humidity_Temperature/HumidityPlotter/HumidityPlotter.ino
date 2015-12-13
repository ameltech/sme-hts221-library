/*
   This example is designed to be used with the Arduino 1.6.6+ IDE Serial Plotter.
   Blow on the sensor and you will see the humidity change in real time.

   From http://www.st.com/web/en/resource/technical/document/datasheet/DM00116291.pdf
   The HTS221 is an ultra compact sensor for relative humidity and temperature. It includes a
   sensing element and a mixed signal ASIC to provide the measurement information through
   digital serial interfaces.
   The sensing element consists of a polymer dielectric planar capacitor structure capable of
   detecting relative humidity variations.
*/
#include <Wire.h>
#include <HTS221.h>
#include <Arduino.h>

int humidity;
unsigned int pollingInterval = 100; // in milliseconds

// The setup function runs once when you press reset or power the board
void setup() {
  Wire.begin();
  if (!smeHumidity.begin()) { // Flash red light if there is an error initializing the sensor
    flashRGBLed(PIN_LED_RED, 1000);
  }
  else {
    flashRGBLed(PIN_LED_GREEN, 1000);
  }
  SerialUSB.begin(115200);
}

// The loop function runs over and over again forever
void loop() {
  // The value is returned as a percentage of humidity (0 = dry desert, 100 = rain forest)
  humidity = smeHumidity.readHumidity();
  SerialUSB.println(humidity);
  delay(pollingInterval);
}

