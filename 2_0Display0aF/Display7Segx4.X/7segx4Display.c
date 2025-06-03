/*
 * Intituto Politecnico Nacional
 * Escuela Superior de Ingenieria Mecanica y Electrica
 * Ingenieria en comunicaciones y electronica
 * Microcontroladores
 * 
 * File:   7segx4Display.c
 * Author: Braulio Alberto Vargas Garcia
 * Co-Author: Aldo Flores Vega
 *
 * Created on 10 de diciembre de 2022, 03:03 PM
 */


#define F_CPU 1000000UL
#include <XC.h>
#include <util/delay.h>
#include <stdint.h>

int main(void) {
    DDRD=0xFF;
    DDRA=15;
    PORTA=1;
    uint8_t Dato[16],n;
    Dato[0]=63;
    Dato[1]=6;
    Dato[2]=91;
    Dato[3]=79;
    Dato[4]=102;
    Dato[5]=109;
    Dato[6]=125;
    Dato[7]=7;
    Dato[8]=127;
    Dato[9]=103;
    Dato[10]=119;
    Dato[11]=124;
    Dato[12]=57;
    Dato[13]=94;
    Dato[14]=121;
    Dato[15]=113;
    while (1) {
        n=0;
        while (!(n>15))
        {
           PORTD=Dato[n];
           _delay_ms(500);
           n =n+1;
        }
    }
}
