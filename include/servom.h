#ifndef SERVOM_H
#define SERVOM_H

#include <Arduino.h>
#include <ESP32Servo.h>

class servom

{
private:
    boolean counter;
    Servo servoMotor;

public:
    servom(uint8_t pin);
    void mov();
};

servom::servom(uint8_t pin)
{
    this->counter = 0;
    servoMotor.attach(pin);
}

void servom::mov()
{
    servoMotor.write(95);
    delay(300);

    if (this-> counter == 1)
    {
        servoMotor.write(120);
        delay(1000);
        servoMotor.write(95);
        this-> counter = 0;
    }
    else
    {
        servoMotor.write(63);
        delay(1000);
        servoMotor.write(95);
        this-> counter = 1;
    }
    

}


#endif