/*------------- Define LCD Use -----------------*/
#include <bcm2835.h>
#define LCD16xN //For lcd16x2 or lcd16x4
//#define LCD20xN //For lcd20x4

/*------------- Define For Connection -----------------*/

#define RS_PIN		RPI_GPIO_P1_26
#define EN_PIN		RPI_GPIO_P1_19
#define D7_PIN		RPI_GPIO_P1_13
#define D6_PIN		RPI_GPIO_P1_16
#define D5_PIN		RPI_GPIO_P1_18
#define D4_PIN		RPI_GPIO_P1_11

/*------------ Declaring Private Macro -----------------*/

#define PIN_LOW(PIN)	bcm2835_gpio_write(PIN, LOW)
#define PIN_HIGH(PIN)	bcm2835_gpio_write(PIN, HIGH)

/*------------ Declaring Function Prototype -------------*/
void lcd_init(void);
void lcd_write(uint8_t type,uint8_t data);
void lcd_puts(uint8_t x, uint8_t y, int8_t *string);
void lcd_clear(void);

