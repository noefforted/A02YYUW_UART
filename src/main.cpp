#include <Arduino.h>
#include "A02YYUW.h"

A02YYUW sensor(&Serial);

void setup()
{
    Serial.begin(57600);
    Serial.begin(9600);
    sensor.begin();
    Serial.println("A02YYUW Sensor Initialized");
}

void loop()
{
    sensor.run();
    float distance = sensor.getDistance();
    Serial.println(distance);
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
    delay(500);
}
