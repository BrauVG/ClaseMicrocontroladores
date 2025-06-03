/*
 * File:   NOMBRE COMPLETO.c
 * Author: Aldo Flores Vega
 * Co-Author: Braulio Alberto Vargas García
 * Created on 1 de febrero de 2023, 07:26 PM
 */

#define F_CPU 1000000UL
#include <xc.h>
#include <stdint.h>
#include <util/delay.h>

#define E  PA2

void main(void)
{
   DDRD = 255;
   DDRA = 7;
//RUTINA DE INCIALIZACIÓN DE LA LCD
   
   //RS = 0 COMANDO - RW = 0 ESCRITURA - E = 1
	/*
     Podemos resumir con compuertas lógicas lo solicitado para el modo de datos:
                (((1<<E) | ~(1<<RS)) & ~(1<<RW))
     Un Enable en modo encendido, con RS y RW apagados, todo en una misma función. 
                                JUSTIFICACIÓN
		(1<<E_pin)  -> PA2 1 0B00000100 |
	   ~(1<<RW_pin) -> PA1 1 0B11111101   (Ya que se niegan con la fución NOT los valores de RW.)
                             ------------
							 0B11111101 & (Resultado de la función O256 entre E y RW.)   (1)
     Entonces:
       ~(1<<RS_pin) -> PA0 1 0B11111110   (Ya que se niegan con la fución NOT los valores de RS.)
                             ------------
							 0B11111100   (Resultado que entrará a PORTA) (252 decimal)
	*/ 
   _delay_ms(15);
   PORTD = 48;
   PORTA =252;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   _delay_ms(1);
   PORTD = 48;
   PORTA =252;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   _delay_ms(1);
   PORTD = 48;
   PORTA =252;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   _delay_ms(1);
   PORTD = 56;
   PORTA =252;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   _delay_ms(1);
   PORTD = 12;
   PORTA =252;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   _delay_ms(1);
   PORTD = 1;
   PORTA =252;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   _delay_ms(1);
   PORTD = 6;
   PORTA =252;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   _delay_ms(1);
   
   //ESCRITURA DE NOMBRE CAMBIANDO RS DE 0 A 1

   
   //RS = 1 CARACTER - RW = 0 ESCRITURA - E = 1
	/*
     Podemos resumir con compuertas lógicas lo solicitado para el modo de escritura:
              (((1<<E) | (1<<RS)) & ~(1<<RW))
     Un Enable y un RS encendidos, con un valor de RW apagado.
                        JUSTIFICACIÓN
		(1<<E_pin)  ->  1 0B00000100 |
	    (1<<RS_pin) ->  1 0B00000001   (En este caso no hay NOT RS, por lo que la función OR solamente suma.)
                          ------------
						  0B00000101   (Resultado de la función OR.)    (1)
     Entonces:
	   ~(1<<RW_pin) ->  1 0B11111101 & (Aquí sí existe una NOT RW, se le aplica la función AND con (1).)
                          ------------
						  0B00000101   (Resultado  final que entrará a PORTA) (5 decimal)
	*/ 
   //BRAULIO
   PORTD = 66; //B
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD = 114; //r
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD =97; //a
   PORTA =5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD =117; //u
   PORTA =5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD =108; //l
   PORTA =5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD = 105; //i
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD = 111; //o
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD = 32; //espacio
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   
   //Alberto
   PORTD = 65; //A
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD =108; //l
   PORTA =5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD = 98; //b
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD = 101; //e
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD = 114; //r
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD = 116; //t
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD = 111; //o
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD = 32; //ESPACIO
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   
   //Vargas
   PORTD =86; //V
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD =97; //a
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD = 114; //r
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD =103; //g
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD =97; //a
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD =115; //s
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD =32; //espacio
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   
   PORTD =71; //G
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD =97; //a
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD = 114; //r
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD =99; //c
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD = 105; //i
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD =97; //a
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
   PORTD =32; //espacio
   PORTA = 5;
   _delay_ms(1);
   PORTA &= ~(1<<E);
   _delay_ms(50);
}