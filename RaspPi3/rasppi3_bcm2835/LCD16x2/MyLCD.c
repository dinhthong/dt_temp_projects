/*
compile with following command:
gcc -o lcd_txt.c MyLCD.c myLCD
execute:
./myLCD
*/
#include <bcm2835.h>
#include "lcd_txt.h"

char buffer[20];
int var=0;

int main(int argc, char **argv)
{
  if (!bcm2835_init())
  return 1;

    // Set the pins to be outputs
  bcm2835_gpio_fsel(RS_PIN, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_fsel(EN_PIN, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_fsel(D7_PIN, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_fsel(D6_PIN, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_fsel(D5_PIN, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_fsel(D4_PIN, BCM2835_GPIO_FSEL_OUTP);

  lcd_init();
  lcd_puts(0,0,(int8_t*)"Have a nice day!");
  lcd_puts(3,3,(int8_t*)"Hello World!");
  bcm2835_delay(2000);//delay(2000);
  lcd_clear();
  while (1)
  {

  }
  bcm2835_close();
  return 0;
}