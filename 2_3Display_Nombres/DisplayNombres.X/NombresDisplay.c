/*
 * Intituto Politecnico Nacional
 * Escuela Superior de Ingenieria Mecanica y Electrica
 * Ingenieria en comunicaciones y electronica
 * Microcontroladores
 * 
 * File:   NombresDisplay.c
 * Author: Braulio Alberto Vargas Garcia
 * Co-Author: Aldo Flores Vega
 *
 * Created on 2 de febrero de 2023, 12:22 AM
 */


#define F_CPU 1000000UL
#include <XC.h>
#include <util/delay.h>
#include <stdint.h>

int main(void){
    
    DDRD=0xFF;
    DDRA=15;
    uint8_t Dato[51];
    /*
    Dato[0]=63;//0
    Dato[1]=6;//1 o I
    Dato[2]=91;//2
    Dato[3]=79;//3
    Dato[4]=102;//4
    Dato[5]=109;//5 o S
    Dato[6]=125;//6 o G
    Dato[7]=7;//7
    Dato[8]=127;//8
    Dato[9]=103;//9 o g
    Dato[10]=119;//A
    Dato[11]=124;//B
    Dato[12]=57;//C
    Dato[13]=94;//D
    Dato[14]=121;//E
    Dato[15]=113;//F
    Dato[11]=0b01010000;//r
    Dato[10]=0b00011100;//u
    Dato[10]=0b00111000;//L
    Dato[11]=0b01111000;//t
    Dato[0]=0b000111110;//V
    Dato[15]=113;//F
    */
    Dato[0]=124;//B
    Dato[1]=0b01010000;//r 80
    Dato[2]=119;//A
    Dato[3]=0b00011100;//u 28
    Dato[4]=0b00111000;//L 56
    Dato[5]=6;//1 o I
    Dato[6]=63;//0 o O
    Dato[7]=0;//espacio
    
    Dato[8]=119;//A
    Dato[9]=0b00111000;//L 56
    Dato[10]=124;//B
    Dato[11]=121;//E
    Dato[12]=0b01010000;//r 80
    Dato[12]=0b01111000;//t 120
    Dato[13]=63;//0 o O
    Dato[14]=0;//espacio
    
    Dato[15]=0b00111110;//V 62
    Dato[16]=119;//A
    Dato[17]=0b01010000;//r 80
    Dato[18]=125;//6 o G
    Dato[19]=119;//A
    Dato[20]=109;//5 o S
    Dato[21]=0;//espacio
    
    Dato[22]=125;//6 o G
    Dato[23]=119;//A
    Dato[24]=0b01010000;//r 80
    Dato[25]=57;//C
    Dato[26]=6;//1 o I
    Dato[27]=119;//A
    Dato[28]=0;//espacio 
    Dato[29]=128;//.
    
    
    Dato[30]=119;//A
    Dato[31]=0b00111000;//L 56
    Dato[32]=94;//D
    Dato[33]=63;//0 o O
    Dato[34]=0;//espacio
    
    Dato[35]=113;//F
    Dato[36]=0b00111000;//L 56
    Dato[37]=63;//0 o O
    Dato[38]=0b01010000;//r 80
    Dato[39]=121;//E
    Dato[40]=109;//5 o S
    Dato[41]=0;//espacio
    
    Dato[42]=0b00111110;//V 62
    Dato[43]=121;//E
    Dato[44]=125;//6 o G
    Dato[45]=119;//A
    Dato[46]=0;//espacio
    Dato[47]=0;//espacio
    Dato[48]=0;//espacio
    Dato[49]=0;//espacio
    Dato[50]=0;//espacio
    
    while (1) {
        for(int m=0;m<47;m++){
            for(int r=100;r>0;r--){
                PORTD=Dato[m];
                PORTA=1;
                _delay_ms(1);
                PORTA=0;
                
                PORTD=Dato[m+1];
                PORTA=2;
                _delay_ms(1);
                PORTA=0;
                
                PORTD=Dato[m+2];
                PORTA=4;
                _delay_ms(1);
                PORTA=0;
                
                PORTD=Dato[m+3];
                PORTA=8;
                _delay_ms(1);
                PORTA=0;
            }
        }
    }
}