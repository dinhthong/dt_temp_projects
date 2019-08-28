#ifndef		__LCDTXT_H
#define		__LCDTXT_H

#include "stm32f10x.h"
//#include "main.c"

/*------------- Define LCD Use -----------------*/


#define LCD16xN //For lcd16x2 or lcd16x4
//#define LCD20xN //For lcd20x4

/*------------- Define For Connection -----------------*/

#define RS_PORT		GPIOB
#define RS_PIN		GPIO_Pin_12

#define EN_PORT		GPIOB
#define EN_PIN		GPIO_Pin_13

#define D7_PORT		GPIOB
#define D7_PIN		GPIO_Pin_7

#define D6_PORT		GPIOB
#define D6_PIN		GPIO_Pin_6

#define D5_PORT		GPIOB
#define D5_PIN		GPIO_Pin_5

#define D4_PORT		GPIOB
#define D4_PIN		GPIO_Pin_4


/*------------ Declaring Private Macro -----------------*/

#define PIN_LOW(PORT,PIN)  GPIO_ResetBits(PORT,PIN);
#define PIN_HIGH(PORT,PIN)  GPIO_SetBits(PORT,PIN);

/*------------ Declaring Function Prototype -------------*/
void lcd_init(void);
void lcd_write(uint8_t type,uint8_t data);
void lcd_puts(uint8_t x, uint8_t y, int8_t *string);
void lcd_clear(void);
#endif

