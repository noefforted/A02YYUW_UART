#ifndef A02YYUW_H
#define A02YYUW_H

#include <Arduino.h>

class A02YYUW
{
public:
    A02YYUW(HardwareSerial *serial); 
    void begin();                    
    void run();                    
    float getDistance();              

private:
    HardwareSerial *serial;          
    float distance;                   
    unsigned char data[4];            
};

#endif
