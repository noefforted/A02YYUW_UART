#include "A02YYUW.h"

A02YYUW::A02YYUW(SoftwareSerial *serial)
{
    this->serial = serial;
}

void A02YYUW::start()
{
    serial->begin(9600);
}

void A02YYUW::run()
{
    do
    {
        for (int i = 0; i < 4; i++)
        {
            data[i] = serial->read();
        }
        Serial.print("HEADER: ");
        Serial.println(data[0]);

        Serial.print("DATA_H: ");
        Serial.println(data[1]);

        Serial.print("DATA_L: ");
        Serial.println(data[2]);

        Serial.print("SUM: ");
        Serial.println(data[3]);
    } while (serial->read() == 0xff);

    serial->flush();
    if (data[0] == 0xff)
    {
        int sum;
        sum = (data[0] + data[1] + data[2]) & 0x00FF;
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

float A02YYUW::getDistance()
{
    return distance;
}
