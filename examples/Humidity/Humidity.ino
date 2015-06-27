/*
 * humidity.cpp
 *
 * Example on SmartEverything humidity sensor reading
 *
 * Created: 4/27/2015 10:32:11 PM
 *  Author: speirano
 */

#include <Wire.h>
#include <Arduino.h>

#include <HTS221.h>

// the setup function runs once when you press reset or power the board
void setup() {
    smeHumidity.begin();
    SerialUSB.begin(115200);
}

// the loop function runs over and over again forever
void loop() {

    int data = 0;

    data = smeHumidity.readHumidity();
    SerialUSB.print("Humidity   : ");
    SerialUSB.print(data);
    SerialUSB.println(" %");

    data = smeHumidity.readTemperature();
    SerialUSB.print("Temperature: ");
    SerialUSB.print(data);
    SerialUSB.println(" celsius");

    ledRedLight(LOW);
    delay(100);

    ledRedLight(HIGH);       // turn the LED on
    delay(500);              // wait for a second

}