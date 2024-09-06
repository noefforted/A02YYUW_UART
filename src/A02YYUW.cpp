#include "A02YYUW.h"

A02YYUW::A02YYUW(HardwareSerial *serial)
{
    this->serial = serial;
    distance = 0.0;
}

void A02YYUW::begin()
{
    serial->begin(9600);
}

void A02YYUW::run()
{
    if (serial->available() >= 4)
    {
        for (int i = 0; i < 4; i++)
        {
            data[i] = serial->read();
        }
        serial->flush();
        if (data[0] == 0xff)
        {
            int sum = (data[0] + data[1] + data[2]) & 0x00FF;

            if (sum == data[3])
            {
                distance = (data[1] << 8) + data[2];
            }
            else
            {
                Serial.println("Checksum ERROR");
            }
        }
    }
    else
    {
        Serial.println("Data tidak terbaca");
    }
}

float A02YYUW::getDistance()
{
    return distance;
}
