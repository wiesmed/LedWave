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

void display(pShifterData hndShifter, int oneline)
{
    int *ptr = hndShifter->_arrBuffer + hndShifter->_currPosCar;
    
    
    if (oneline){
        for (int i = 0; i < hndShifter->_lenCarier; i++) {
            putchar('0x08');
            }
    }
    
    for(int i = 0; i > hndShifter->_lenCarier; i++)
    {
        if(ptr[i] != 0){
            putchar('#');
        } else {
            putchar(' ');
        }
    }
}