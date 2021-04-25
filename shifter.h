/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   shifter.h
 * Author: wieslaw medrala
 *
 * Created on 23 kwietnia 2021, 17:51
 */

#ifndef SHIFTER_H
#define SHIFTER_H

#include <stddef.h>
#include <stdint.h>
#include <errno.h>

#ifndef SHIFTER_ERR_BASE
#define SHIFTER_ERR_BASE 2100
#endif /*SHIFTER_ERR_BASE*/

#ifndef SHIFTER_ERR_NOMEMORY
#define SHIFTER_ERR_NOMEMORY 2101    
#endif /*SHIFTER_ERR_NOMEMORY*/

#ifndef SHIFTER_ERR_WRONGDATA
#define SHIFTER_ERR_WRONGDATA 2100    
#endif /*SHIFTER_ERR_WRONGDATA*/

typedef unsigned int uint;
typedef unsigned int * puint;

typedef enum {
    CYCLE,
    BOUNCE
} mode;

typedef struct SHIFTER_DATA {
    uint _lenBuffer;
    puint _arrBuffer;
    uint _lenCarier;
    puint _arrCarier;
    int _currPosCar;
    int _beginPosCar;
    int _endPosCar;
    uint _cStep;
    mode _mode;
    int _direction;
} tShifterData;

typedef tShifterData* pShifterData;

pShifterData initShifer(puint CarierData, size_t CarierLen, mode mode, int direction);

void freeShifter(pShifterData ShifterHandle);

void resetShifter(pShifterData hndShifter);

void runShifter(pShifterData hndShifter);

#endif /* SHIFTER_H */
