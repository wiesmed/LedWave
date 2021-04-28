/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   shifter.c
 * Author: wieslaw medrala
 * 
 * Created on 23 kwietnia 2021, 17:51
 */


#include <stdlib.h>
#include <stdio.h>
#include "shifter.h"

pShifterData initShifer(puint CarierData, size_t CarierLen, mode mode, int dir)
{
    pShifterData psd;

    if (CarierData == NULL) {
        fprintf(stderr, "Error no %d \n", SHIFTER_ERR_WRONGDATA);
        return NULL;
    }

    if (CarierLen == 0) {
        fprintf(stderr, "Error no %d \n", SHIFTER_ERR_WRONGDATA);
        return NULL;
    }

    psd = (pShifterData) malloc(sizeof (tShifterData));

    if (psd == NULL) {
        fprintf(stderr, "Error no %d due alocaton for structure\n", SHIFTER_ERR_NOMEMORY);
        return NULL;
    }

    psd->_cStep = 0;
    psd->_mode = mode;
    psd->_direction = dir;
    psd->_lenBuffer = CarierLen * 3;
    psd->_lenCarier = CarierLen;
    psd->_arrBuffer = calloc(psd->_lenBuffer, sizeof (uint));

    if (psd->_arrBuffer == NULL) {
        fprintf(stderr, "Error no %d due allocation for buffer\n", SHIFTER_ERR_NOMEMORY);
        free(psd);
        return NULL;
    }

    psd->_arrCarier = calloc(CarierLen, sizeof (uint));

    if (psd->_arrCarier == NULL) {
        fprintf(stderr, "Error no %d due allocation for carier data\n", SHIFTER_ERR_NOMEMORY);
        free(psd->_arrBuffer);
        free(psd);
        return NULL;
    }

    for (size_t i = 0; i < CarierLen; i++) {
        psd->_arrCarier[i] = CarierData[i];
    }

    if (psd->_direction > 0) {
        psd->_cStep = 1;
        psd->_beginPosCar = 0;
        psd->_endPosCar = psd->_lenCarier * 2;
    } else {
        psd->_cStep = -1;
        psd->_beginPosCar = psd->_lenCarier * 2;
        psd->_endPosCar = 0;
    }
    
    return psd;
}

void freeShifter(pShifterData hndShifter)
{
    if (hndShifter != NULL) {
        free(hndShifter->_arrBuffer);
        free(hndShifter->_arrCarier);
        free(hndShifter);
    }
}

void resetShifter(pShifterData hndShifter)
{
    hndShifter->_cStep = 0;

    for (size_t i = 0; i < hndShifter->_lenBuffer; i++) {
        hndShifter->_arrBuffer[i] = 0;
    }

    uint prefix = hndShifter->_lenCarier;

    for (size_t i = 0; i < hndShifter->_lenCarier; i++) {
        hndShifter->_arrBuffer[prefix + i] = hndShifter->_arrCarier[i];
    }
}

void runShifter(pShifterData hndShifter)
{
    hndShifter->_currPosCar += hndShifter->_cStep;

    if (hndShifter->_currPosCar == hndShifter->_endPosCar) {
        
        switch (hndShifter->_mode) {
            case CYCLE:               
                /*hndShifter->_cStep = hndShifter->_cStep;*/
                hndShifter->_currPosCar = hndShifter->_beginPosCar;
                break;

            case BOUNCE:
                hndShifter->_cStep = -hndShifter->_cStep;                
                hndShifter->_endPosCar = hndShifter->_beginPosCar;
                hndShifter->_beginPosCar = hndShifter->_currPosCar;
                break;
        }        
    }    
}