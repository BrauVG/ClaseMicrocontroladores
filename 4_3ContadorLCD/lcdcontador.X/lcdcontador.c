/*
 * Intituto Politecnico Nacional
 * Escuela Superior de Ingenieria Mecanica y Electrica
 * Ingenieria en comunicaciones y electronica
 * Microcontroladores
 * 
 * File:   lcdcontador.c
 * Author: Braulio Alberto Vargas Garcia
 * Co-Author: Aldo Flores Vega
 *
 * Created on 12 de febrero de 2023, 10:19 PM
 */


#define F_CPU 1000000UL
#include <xc.h>
#include <stdint.h>
#include <util/delay.h>
#include <math.h>
#include <avr/io.h>

#define E  PA2
#define RW PA1
#define RS PA0

void LCD_Init(void);
void LCD_Interface(unsigned char val_portd);
void LCD_Caracter(unsigned char	data);

int main(void)
{
    char Numeros[11]={0b00110000,0b00110001,0b00110010,0b00110011,0b00110100,0b00110101,0b00110110,0b00110111,0b00111000,0b00111001,0b00110000};
    int number[10];
    for(int i=0;i<10;i++)
    {
            number[i]=Numeros[i];
    }
    int push=0;
    DDRB &= ~(1 << PB0);
    _delay_ms(200);
	LCD_Init();
    while(1)
    {
        for(int cuatro=0;cuatro<10;cuatro++)
        {
            for(int tres=0;tres<10;tres++)
            {
                for(int dos=0;dos<10;dos++)
                {
                    for(int uno=0;uno<10;uno++)
                    {
                        pintar:
                        LCD_Caracter(number[cuatro]);
                        
                        LCD_Caracter(number[tres]);
                        
                        LCD_Caracter(number[dos]);
                        
                        LCD_Caracter(number[uno]);
                        _delay_ms(100);
                        LCD_Interface(0X02);
                        if (PINB & (1<<PB0)) {goto cont;}
                        else {goto pintar;}
                        cont:
                        push++;
                    }
                }
            }
        }
        LCD_Interface(0X01);
    }
    return 0;
}

void LCD_Init(void){
	DDRD = 0xFF;// PUERTO C = SALIDA
	DDRA = 0x07;// PA0 PA1 PA2 = SALIDA, PA3-7= ENTRADA
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

void LCD_Interface(unsigned char val_portd){
	PORTD = val_portd; //El valor que el Puerto D recibirá puede ser = 0x30 | 0X0C | 0X01 | 0X06
	//RS = 0 COMANDO - RW = 0 ESCRITURA - E = 1
	/*
     Podemos resumir con compuertas lógicas lo solicitado para el modo de datos:
                (((1<<E) | ~(1<<RS)) & ~(1<<RW))
     Un Enable en modo encendido, con RS y RW apagados, todo en una misma función. 
                                JUSTIFICACIÓN
		(1<<E_pin)  -> PA2 1 0B00000100 |
	   ~(1<<RW_pin) -> PA1 1 0B11111101   (Ya que se niegan con la fución NOT los valores de RW.)
                             ------------
							 0B11111101 & (Resultado de la función OR entre E y RW.)   (1)
     Entonces:
       ~(1<<RS_pin) -> PA0 1 0B11111110   (Ya que se niegan con la fución NOT los valores de RS.)
                             ------------
							 0B11111100   (Resultado que entrará a PORTA)
	*/ 
    PORTA = 0b11111100;
	_delay_ms(1);
	PORTA &= ~(1<<E);
	_delay_ms(50);
}

void LCD_Caracter(unsigned char	data){
	PORTD = data; //El valor que el Puerto D recibirá como caracter para imprimir.
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
						  0B00000101   (Resultado  final que entrará a PORTA)
	*/ 
    PORTA = 0b00000101; 
	_delay_ms(1);
	PORTA &= ~(1<<E);
	_delay_ms(50);
}