/*
LED 7 segment with common Anode
*/
#include <bcm2835.h>
#define PINA RPI_V2_GPIO_P1_11
#define PINB RPI_V2_GPIO_P1_12
#define PINC RPI_V2_GPIO_P1_13
#define PIND RPI_V2_GPIO_P1_15
#define PINE RPI_V2_GPIO_P1_16
#define PINF RPI_V2_GPIO_P1_18
#define PING RPI_V2_GPIO_P1_22
#define PINH RPI_V2_GPIO_P1_29
//prototype define
int ledmapping(int number);
void led7seg(int number);

int main(int argc, uint8_t **argv)
{
uint8_t i;
if (!bcm2835_init())
return 1;
// Set the pin to be an output
bcm2835_gpio_fsel(PINA, BCM2835_GPIO_FSEL_OUTP);
bcm2835_gpio_fsel(PINB, BCM2835_GPIO_FSEL_OUTP);
bcm2835_gpio_fsel(PINC, BCM2835_GPIO_FSEL_OUTP);
bcm2835_gpio_fsel(PIND, BCM2835_GPIO_FSEL_OUTP);
bcm2835_gpio_fsel(PINE, BCM2835_GPIO_FSEL_OUTP);
bcm2835_gpio_fsel(PINF, BCM2835_GPIO_FSEL_OUTP);
bcm2835_gpio_fsel(PING, BCM2835_GPIO_FSEL_OUTP);
bcm2835_gpio_fsel(PINH, BCM2835_GPIO_FSEL_OUTP);
// Display to LED 7 segment
while (1)
{
for (i=0;i<10;i++)
{
led7seg(i);
bcm2835_delay(1000);
}
}
bcm2835_close();
return 0;
}

void led7seg(int number)
{
int display;
display=ledmapping(number);
//HIGH and LOW respectively defined 0x01 and 0x00 in bcm2835.h
bcm2835_gpio_write(PINA, 0x01 & display>>6);
bcm2835_gpio_write(PINB, 0x01 & display>>5);
bcm2835_gpio_write(PINC, 0x01 & display>>4);
bcm2835_gpio_write(PIND, 0x01 & display>>3);
bcm2835_gpio_write(PINE, 0x01 & display>>2);
bcm2835_gpio_write(PINF, 0x01 & display>>1);
bcm2835_gpio_write(PING, 0x01 & display);
}

int ledmapping(int x)
{
switch (x){
    case 1: return 0x30;//0b0110000;
    break;
    case 2: return 0x6D;  //0b1101101;
    break;
    case 3: return 0x79;//0b1111001;
    break;
    case 4: return 0x33;//0b0110011;
    break;
    case 5: return 0x5B;//0b1011011;
    break;
    case 6: return 0x5F;//b1011111;
    break;
    case 7: return 0x70;//0b1110000;
    break;
    case 8: return 0x7F;//b1111111;
    break;
    case 9: return 0x73;//0b1110011;
    break;
    default: // return 0
    return 0x7E;
}
}