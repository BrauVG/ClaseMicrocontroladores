/*
 * Intituto Politecnico Nacional
 * Escuela Superior de Ingenieria Mecanica y Electrica
 * Ingenieria en comunicaciones y electronica
 * Microcontroladores
 * 
 * File:   Led.c
 * Author: Braulio Alberto Vargas Garcia
 * 
 * Created on 1 de diciembre de 2022, 01:42 AM
 */

#define F_CPU 1000000UL
#include <XC.h>
#include <util/delay.h>

int main()
{
   DDRA =1;
   while (1)
   {
      PORTA =1;
      _delay_ms(500);
      PORTA =0;
      _delay_ms(500);
   }
   return 0;
}