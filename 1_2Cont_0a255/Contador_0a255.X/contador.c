/*
 * Intituto Politecnico Nacional
 * Escuela Superior de Ingenieria Mecanica y Electrica
 * Ingenieria en comunicaciones y electronica
 * Microcontroladores
 * 
 * File:   contador.c
 * Author: Braulio Alberto Vargas Garcia
 * Co-Author: Aldo Flores Vega
 *
 * Created on 1 de febrero de 2023, 11:44 PM
 */

#define F_CPU 1000000UL
#include <XC.h>
#include <util/delay.h>

int main(void) {
    DDRB=255;
    while (1) 
    {
        for(int i=0;i<=255;i++)
        {
            PORTB=i;
            _delay_ms(250);
        }
    }
}
