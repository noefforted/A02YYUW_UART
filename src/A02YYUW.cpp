#include "A02YYUW.h"

A02YYUW::A02YYUW(SoftwareSerial *serial)
{
    this->serial = serial;
    distance = 0.0;
}

void A02YYUW::start()
{
    serial->begin(9600);
}

void A02YYUW::run()
{
    // Membaca data dari sensor
    for (int i = 0; i < 4; i++)
    {
        data[i] = serial->read();
    }

    // Flush untuk membersihkan buffer serial setelah pembacaan
    serial->flush();

    // Deteksi posisi 0xff dan rotasi data jika perlu
    for (int i = 0; i < 4; i++)
    {
        if (data[i] == 0xff)
        {
            // Rotasi array sehingga 0xff selalu di data[0]
            while (i != 0)
            {
                uint8_t temp = data[0];
                for (int j = 0; j < 3; j++)
                {
                    data[j] = data[j + 1];
                }
                data[3] = temp;
                i--;
            }
            break;
        }
    }

    // Menampilkan data
    // Serial.print("HEADER: ");
    // Serial.println(data[0]);

    // Serial.print("DATA_H: ");
    // Serial.println(data[1]);

    // Serial.print("DATA_L: ");
    // Serial.println(data[2]);

    // Serial.print("SUM: ");
    // Serial.println(data[3]);

    // Validasi checksum dan hitung jarak
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
    else
    {
        Serial.println("Invalid Header");
    }
}

float A02YYUW::getDistance()
{
    return distance;
}
