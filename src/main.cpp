#include <Arduino.h>
#include "A02YYUW.h"
#include <SoftwareSerial.h>

SoftwareSerial mySerial(11,10);
A02YYUW sensor(&mySerial);

void setup()
{
    Serial.begin(57600);
    sensor.start();
    Serial.println("A02YYUW Sensor Initialized");
}

void loop()
{
    sensor.run();
    float distance = sensor.getDistance();
    if (distance > 30)
    {
        Serial.print("Jarak: ");
        Serial.print(distance);
        Serial.println(" mm");
    }
    else
    {
        Serial.println("Jarak terlalu dekat");
    }
    delay(100);
}
