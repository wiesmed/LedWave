/* 
 * File:   main.c
 * Author: wieslaw
 *
 * Created on 23 kwietnia 2021, 17:49
 */

#include <stdio.h>
#include <stdlib.h>
#include "shifter.h"
#include "display.h"

/*
 * 
 */
int main(int argc, char** argv) {
    uint cd[4] = {1, 1, 1, 1};
    pShifterData sd = initShifer(cd, 4, CYCLE, 1);

    for (size_t i = 0; i < 100; i++) {
        display(sd, 1);
        runShifter(sd);
    }

    freeShifter(sd);
    
    return (EXIT_SUCCESS);
}

