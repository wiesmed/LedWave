/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   display.h
 * Author: wieslaw
 *
 * Created on 25 kwietnia 2021, 19:42
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include "shifter.h"

static int pins[] = {18, 23, 24, 25, 12, 16, 20, 21, 26, 0};

typedef struct
{
    int     _contLed;
    int     *_arrPins;
    int     wPiStarted;    
} LedSet;

typedef LedSet *pLedSet;

void display(pShifterData hndShifter, pLedSet leds);

int startWiringPi(pLedSet leds);

void closeWiringPi(pLedSet leds);

#endif /* DISPLAY_H */
