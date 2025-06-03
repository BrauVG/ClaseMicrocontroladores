/*
 * Intituto Politecnico Nacional
 * Escuela Superior de Ingenieria Mecanica y Electrica
 * Ingenieria en comunicaciones y electronica
 * Microcontroladores
 * 
 * File:   FFFFDis7x4.c
 * Author: Braulio Alberto Vargas Garcia
 * Co-Author: Aldo Flores Vega
 *
 * Created on 19 de diciembre de 2022, 12:49 PM
 */


#define F_CPU 1000000UL
#include <XC.h>
#include <util/delay.h>
#include <stdint.h>

int main(void) {
    DDRD=0xFF;
    DDRC=15;
    DDRA=15;
    uint8_t Dato[16];
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
        for(int m=15;m>0;m--){
            for(int c=15;c>0;c--){
                for(int d=15;d>0;d--){
                    for(int u=15;u>0;u--){
                        for(int r=50;r>0;r--){
                            
                            PORTD=Dato[m];
                            PORTA=1;
                            _delay_ms(1);
                            PORTA=0;
                            
                            PORTD=Dato[c];
                            PORTA=2;
                            _delay_ms(1);
                            PORTA=0;
                            
                            PORTD=Dato[d];
                            PORTA=4;
                            _delay_ms(1);
                            PORTA=0;
                            
                            PORTD=Dato[u];
                            PORTA=8;
                            _delay_ms(1);
                            PORTA=0;
                        }
                    }
                }
            }
        }
    }
}
