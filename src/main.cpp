#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(11, 10);

void setup()
{
    Serial.begin(57600);
    mySerial.begin(9600);
}

void loop()
{
    if (mySerial.read() == 0xFF)
    {
        delay(10);
        uint8_t dataPayloadMsb = mySerial.read();
        uint8_t dataPayloadLsb = mySerial.read();
        uint8_t dataCrc = mySerial.read();

        uint8_t checkSum = (0xff + dataPayloadMsb + dataPayloadLsb);
        if (checkSum == dataCrc)
        {
            uint16_t result = ((uint16_t)dataPayloadMsb << 8) | dataPayloadLsb;
            // Serial.println(dataPayloadMsb);
            // Serial.println(dataPayloadLsb);
            // Serial.println(dataCrc);
            Serial.println(result);
        }
    }
}
// #include <Arduino.h>
// #include "A02YYUW.h"
// #include <SoftwareSerial.h>

// SoftwareSerial mySerial(11,10);
// A02YYUW sensor(&mySerial);

// void setup()
// {
//     Serial.begin(57600);
//     sensor.start();
//     Serial.println("A02YYUW Sensor Initialized");
// }

// void loop()
// {
//     sensor.run();
//     float distance = sensor.getDistance();
//     if (distance > 30)
//     {
//         Serial.print("Jarak: ");
//         Serial.print(distance);
//         Serial.println(" mm");
//     }
//     else
//     {
//         Serial.println("Jarak terlalu dekat");
//     }
//     delay(100);
// }