/*
 * File:   LCD startup seq.c
 * Author: Aldo Flores Vega
 *
 * Created on 8 de enero de 2023, 11:59 AM
 */

#define F_CPU 1000000UL
#include <xc.h>
#include <stdint.h>
#include <util/delay.h>
#include <math.h>
#include <avr/io.h>

#define LCD_DATA PORTB
#define E  PC2
#define RW PC1
#define RS PC0

void LCD_Init(void);
void LCD_Interface(unsigned char val_portb);
void LCD_Caracter(unsigned char	data);

int main(void)
{
	LCD_Init();
    LCD_Caracter('A');
    LCD_Caracter('M');
    LCD_Caracter('O');
    LCD_Caracter('N');
    LCD_Caracter('G');
    LCD_Caracter(' ');
    LCD_Caracter('U');
    LCD_Caracter('S');
}

void LCD_Init(void){
	DDRB = 0xFF;// PUERTO C SALIDA
	DDRC = 0x07;// PA0 PA1 PA2 SALIDA
	_delay_ms(15);
	LCD_Interface(0X30);
	_delay_ms(1);
	LCD_Interface(0X30);
	_delay_ms(1);
	LCD_Interface(0X30);
	_delay_ms(1);
	LCD_Interface(0X38); // Dos líneas de la  LCD con caracteres de 5x8.
	_delay_ms(1);
	LCD_Interface(0X0C); // Encencido del display.
	_delay_ms(1);
	LCD_Interface(0X01); // LCD Clear.
	_delay_ms(1);
	LCD_Interface(0X06); // Habilitar la DDRAM.
	_delay_ms(1);
}

void LCD_Interface(unsigned char val_portb){
	LCD_DATA = val_portb; //El valor que el Puerto B recibirá puede ser = 0x30 | 0X0C | 0X01 | 0X06
	//RS = 0 COMANDO - RW = 0 ESCRITURA - E = 1
	PORTC = 0b11111100;
	/*
     Podemos resumir con compuertas lógicas lo solicitado para el modo de datos:
                (((1<<E) | ~(1<<RS)) & ~(1<<RW))
     Un Enable en modo encendido, con RS y RW apagados, todo en una misma función. 
                                JUSTIFICACIÓN
		(1<<E_pin)  -> PC2 1 0B00000100 |
	   ~(1<<RW_pin) -> PC1 1 0B11111101   (Ya que se niegan con la fución NOT los valores de RW.)
                             ------------
							 0B11111101 & (Resultado de la función OR entre E y RW.)   (1)
     Entonces:
       ~(1<<RS_pin) -> PC0 1 0B11111110   (Ya que se niegan con la fución NOT los valores de RS.)
                             ------------
							 0B11111100   (Resultado que entrará a  PORTC)
	*/ 
	_delay_ms(1);
	PORTC &= ~(1<<E);
	_delay_ms(50);
}

void LCD_Caracter(unsigned char	data){
	LCD_DATA = data; //El valor que el Puerto B recibirá como caracter para imprimir.
	//RS = 1 CARACTER - RW = 0 ESCRITURA - E = 1
	PORTC = 0b00000101; 
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
						  0B00000101   (Resultado  final que entrará a PORTC)
	*/ 
	_delay_ms(1);
	PORTC &= ~(1<<E);
	_delay_ms(50);
}