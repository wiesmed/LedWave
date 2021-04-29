/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   display.c
 * Author: wieslaw
 * 
 * Created on 25 kwietnia 2021, 19:42
 */

#include "display.h"
#include "shifter.h"
#include <stdio.h>
#include <wiringPi.h>

void display(pShifterData hndShifter, pLedSet leds)
{
    puint ptr = hndShifter->_arrBuffer + hndShifter->_currPosCar;

    printf("\033[33;40m");
    putchar(0xD);

    for (int i = 0; i < hndShifter->_lenCarier; i++)
    {
        if (ptr[i] != 0)
        {
            putchar('O');

            if(leds != NULL && leds->wPiStarted){
                pinMode(pins[i], OUTPUT);
                digitalWrite(pins[i], 1);
            }
        }
        else
        {
            putchar(' ');
            if(leds != NULL && leds->wPiStarted){
                pinMode(pins[i], OUTPUT);
                digitalWrite(pins[i], 0);
            }
        }
    }
    fflush(stdout);
}

int startWiringPi(pLedSet leds)
{
    if (wiringPiSetupGpio())
    {
        return 0;
    }

    for (size_t i = 0; i < 9; i++)
    {
        pinMode(pins[i], OUTPUT);
    }

    leds->wPiStarted = 1;
    return 0;
}

void closeWiringPi(pLedSet leds)
{
    for (size_t i = 0; i < 9; i++)
    {
        pinMode(pins[i], INPUT);
        digitalWrite(pins[i], 0);
    }
}