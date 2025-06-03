/*
 * Intituto Politecnico Nacional
 * Escuela Superior de Ingenieria Mecanica y Electrica
 * Ingenieria en comunicaciones y electronica
 * Microcontroladores
 * 
 * File:   BinarioDisplay.c
 * Author: Braulio Alberto Vargas Garcia
 * Co-Author: Aldo Flores Vega
 *
 * Created on 2 de febrero de 2023, 01:07 AM
 */

#define F_CPU 1000000UL
#include <XC.h>
#include <util/delay.h>
#include <stdint.h>

int main(void){
    
    DDRD=0xFF;
    DDRA=15;
    uint8_t Dato[2];

    Dato[0]=63;//0
    Dato[1]=6;//1 o I
    
    while (1) {
        for(int m=0;m<2;m++){
            for(int c=0;c<2;c++){
                for(int d=0;d<2;d++){
                    for(int u=0;u<2;u++){
                        for(int r=100;r>0;r--){
                            
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