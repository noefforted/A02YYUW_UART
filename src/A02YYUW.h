#ifndef A02YYUW_H
#define A02YYUW_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class A02YYUW
{
public:
    A02YYUW(SoftwareSerial *serial); 
    void start();                    
    void run();                    
    float getDistance();              

private:
    SoftwareSerial *serial;          
    float distance;                   
    unsigned char data[4];            
};

#endif
