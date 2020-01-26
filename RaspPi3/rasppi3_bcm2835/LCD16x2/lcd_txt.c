#include "lcd_txt.h"

/*--------------- Initialize LCD ------------------*/
void lcd_init(void)
{
	
	bcm2835_delay(30);
	PIN_LOW(D4_PIN);
	PIN_HIGH(D5_PIN);
	PIN_LOW(D6_PIN);
	PIN_LOW(D7_PIN);
	PIN_LOW(RS_PIN);

	PIN_HIGH(EN_PIN);
	PIN_LOW(EN_PIN);
	
	lcd_write(0,0x28);
	lcd_write(0,0x0c);
	lcd_write(0,0x06);
	lcd_write(0,0x01);
}

/*--------------- Write To LCD ---------------*/
void lcd_write(uint8_t type,uint8_t data)
{
	bcm2835_delay(5);
	if(type)
	{
		PIN_HIGH(RS_PIN);
	}else
	{
		PIN_LOW(RS_PIN);
	}
	
	//Send High Nibble
	if(data&0x80)
	{
		PIN_HIGH(D7_PIN);
	}else
	{
		PIN_LOW(D7_PIN);
	}
	
	if(data&0x40)
	{
		PIN_HIGH(D6_PIN);
	}else
	{
		PIN_LOW(D6_PIN);
	}
	
	if(data&0x20)
	{
		PIN_HIGH(D5_PIN);
	}else
	{
		PIN_LOW(D5_PIN);
	}
	
	if(data&0x10)
	{
		PIN_HIGH(D4_PIN);
	}else
	{
		PIN_LOW(D4_PIN);
	}
	PIN_HIGH(EN_PIN);
	PIN_LOW(EN_PIN);
	

	//Send Low Nibble
	if(data&0x08)
	{
		PIN_HIGH(D7_PIN);
	}else
	{
		PIN_LOW(D7_PIN);
	}
	
	if(data&0x04)
	{
		PIN_HIGH(D6_PIN);
	}else
	{
		PIN_LOW(D6_PIN);
	}
	
	if(data&0x02)
	{
		PIN_HIGH(D5_PIN);
	}else
	{
		PIN_LOW(D5_PIN);
	}
	
	if(data&0x01)
	{
		PIN_HIGH(D4_PIN);
	}else
	{
		PIN_LOW(D4_PIN);
	}
	PIN_HIGH(EN_PIN);
	PIN_LOW(EN_PIN);
}

void lcd_puts(uint8_t x, uint8_t y, int8_t *string)
{
	//Set Cursor Position
	#ifdef LCD16xN	//For LCD16x2 or LCD16x4
	switch(x)
	{
		case 0: //Row 0
			lcd_write(0,0x80+0x00+y);
			break;
		case 1: //Row 1
			lcd_write(0,0x80+0x40+y);
			break;
		case 2: //Row 2
			lcd_write(0,0x80+0x10+y);
			break;
		case 3: //Row 3
			lcd_write(0,0x80+0x50+y);
			break;
	}
	#endif
	
	#ifdef LCD20xN	//For LCD20x4
	switch(x)
	{
		case 0: //Row 0
			lcd_write(0,0x80+0x00+y);
			break;
		case 1: //Row 1
			lcd_write(0,0x80+0x40+y);
			break;
		case 2: //Row 2
			lcd_write(0,0x80+0x14+y);
			break;
		case 3: //Row 3
			lcd_write(0,0x80+0x54+y);
			break;
	}
	#endif
	
	while(*string)
	{
		lcd_write(1,*string);
		string++;
	}
}
void lcd_clear(void)
{
	//instruction table. : Clear Display page 8/9
	lcd_write(0,0x01);
}



