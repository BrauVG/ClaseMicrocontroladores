/*
 * File:   TEXTO REVERSO.c
 * Author: Aldo Flores Vega
 * Co-Author: Braulio Alberto Vargas García
 * Created on 4 de febrero de 2023, 10:44 PM
 */

#define F_CPU 1000000UL
#include <xc.h>
#include <stdint.h>
#include <util/delay.h>
#include <math.h>
#include <avr/io.h>

#define LCD_Data_Dir DDRD	/* Define LCD data port direction */
#define LCD_Command_Dir DDRA	/* Define LCD command port direction register */
#define LCD_Data_Port PORTD	/* Define LCD data port */
#define LCD_Command_Port PORTA	/* Define LCD data port */
#define RS PA0			/* Define Register Select signal pin */
#define RW PA1			/* Define Read/Write signal pin */
#define EN PA2			/* Define Enable signal pin */

int main(){
    
    //LETRAS INVERSAS
	unsigned char Character1[8] = { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x1F }; //L
	unsigned char Character2[8] = { 0x0F, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0F }; //D
	unsigned char Character3[8] = { 0x1F, 0x01, 0x01, 0x0F, 0x01, 0x01, 0x01 }; //F
	unsigned char Character4[8] = { 0x0F, 0x11, 0x11, 0x0F, 0x05, 0x09, 0x11 }; //R
	unsigned char Character5[8] = { 0x1F, 0x01, 0x01, 0x0F, 0x01, 0x01, 0x1F }; //E
	unsigned char Character6[8] = { 0xFE, 0x01, 0x01, 0x0E, 0x10, 0x10, 0x0F }; //S
	unsigned char Character7[8] = { 0x0E, 0x11, 0x01, 0x1D, 0x11, 0x11, 0x0E }; //G
	unsigned char Character8[8] = { 0x0F, 0x11, 0x11, 0x0F, 0x11, 0x11, 0x0F }; //B

	LCD_Init();
	
	LCD_Custom_Char(0, Character1);  /* Build Character1 at position 0 */
	LCD_Custom_Char(1, Character2);  /* Build Character2 at position 1 */
	LCD_Custom_Char(2, Character3);  /* Build Character3 at position 2 */
	LCD_Custom_Char(3, Character4);  /* Build Character4 at position 3 */
	LCD_Custom_Char(4, Character5);  /* Build Character5 at position 4 */
	LCD_Custom_Char(5, Character6);  /* Build Character6 at position 5 */
	LCD_Custom_Char(6, Character7);  /* Build Character6 at position 6 */
	LCD_Custom_Char(7, Character8);  /* Build Character6 at position 7 */
    
    LCD_Command(0X80);
	LCD_Char('A');
    LCD_Char(6);
    LCD_Char(4);
    LCD_Char('V');
    LCD_Char(' ');
    LCD_Char(5);
    LCD_Char(4);
    LCD_Char(3);
    LCD_Char('O');
    LCD_Char(0);
    LCD_Char(2);
    LCD_Char(' ');
    LCD_Char('O');
    LCD_Char(1);
    LCD_Char(0);
    LCD_Char('A');
    LCD_Command(0XC0);
    LCD_Char('.');
    LCD_Char(5);
    LCD_Char('A');
    LCD_Char(6);
    LCD_Char(3);
    LCD_Char('A');
    LCD_Char('V');
    LCD_Char(' ');
    LCD_Char('O');
    LCD_Char('I');
    LCD_Char(0);
    LCD_Char('U');
    LCD_Char('A');
    LCD_Char(3);
    LCD_Char(7);
}

void LCD_Command(unsigned char cmnd){
	LCD_Data_Port = cmnd; //El valor que el Puerto D recibirá puede ser = 0x30 | 0X0C | 0X01 | 0X06
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
    LCD_Command_Port = 0b11111100;
	_delay_ms(1);
	LCD_Command_Port &= ~(1<<EN);
	_delay_ms(5);
}

void LCD_Char (unsigned char char_data){
	LCD_Data_Port = char_data; //El valor que el Puerto D recibirá como caracter para imprimir.
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
    LCD_Command_Port = 0b00000101; 
	_delay_ms(1);
	LCD_Command_Port &= ~(1<<EN);
	_delay_ms(5);
}

void LCD_Init (void){
	DDRD = 0xFF;// PUERTO C = SALIDA
	DDRA = 0x07;// PA0 PA1 PA2 = SALIDA
	_delay_ms(15);
	LCD_Command(0X30);
	_delay_ms(1);
	LCD_Command(0X30);
	_delay_ms(1);
	LCD_Command(0X30);
	_delay_ms(1);
	LCD_Command(0X38); // Dos líneas de la  LCD con caracteres de 5x8.
	_delay_ms(1);
	LCD_Command(0X0C); // Encencido del display.
	_delay_ms(1);
	LCD_Command(0X01); // LCD Clear.
	_delay_ms(1);
	LCD_Command(0X06); // Habilitar la DDRAM.
	_delay_ms(1);
}

void LCD_String (char *str){		/* Send string to LCD function */
	for(int i=0;str[i]!=0;i++)		/* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);
	}
}

void LCD_Custom_Char (int loc, unsigned char *msg){
	if(loc<8)
	{
		LCD_Command (0x40 + (loc*8));	/* Command 0x40 and onwards forces the device to point CGRAM address */
		for(int i=0;i<8;i++)	/* Write 8 byte for generation of 1 character */
		LCD_Char(msg[i]);
	}
}