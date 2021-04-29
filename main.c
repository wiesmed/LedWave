/* 
 * File:   main.c
 * Author: wieslaw
 *
 * Created on 23 kwietnia 2021, 17:49
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shifter.h"
#include "display.h"

/*
 * 
 */
int main(int argc, char **argv)
{
    uint cd[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    pShifterData sd = initShifer(cd, 9,CYCLE, 0);
    LedSet ls =  {9, pins, 0};

    startWiringPi(&ls);

    for (size_t i = 0; i < 1000; i++)
    {
        display(sd, &ls);
        runShifter(sd);
        usleep(50000);
    }

    closeWiringPi(&ls);
    freeShifter(sd);

    return (EXIT_SUCCESS);
}
