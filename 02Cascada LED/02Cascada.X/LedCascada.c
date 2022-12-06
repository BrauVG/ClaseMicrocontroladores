/*
 * Intituto Politecnico Nacional
 * Escuela Superior de Ingenieria Mecanica y Electrica
 * Ingenieria en comunicaciones y electronica
 * Microcontroladores
 * 
 * File:   LedCascada.c
 * Author: Braulio Alberto Vargas Garcia
 * Created on 3 de diciembre de 2022, 01:31 PM
 */

#define F_CPU 1000000UL
#include <XC.h>
#include <util/delay.h>
#include <math.h>

int main(void) {
    DDRB=255;
    while(1)
    {
        PORTB=1;
        for(int i=1;i<=8;i++)
        {
            _delay_ms(500);
            PORTB=pow(2,i);
        }
    }
}
