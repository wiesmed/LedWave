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
    pShifterData sd = initShifer(cd, 9,BOUNCE, 1);

    for (size_t i = 0; i < 1000; i++)
    {
        display(sd, 1);
        runShifter(sd);
        usleep(50000);
    }

    freeShifter(sd);

    return (EXIT_SUCCESS);
}
