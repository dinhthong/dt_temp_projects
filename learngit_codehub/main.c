#include "stm32f4xx.h"
#include "stm32f4xx_it.h"
#include "stm32f4xx_it.hello"
#hello this in new fuckingline in branch2
/*
Demonstrate how to implement 'C printf() function' to transfer USART
But how about receive?? 
*/
void UARTmain_Init(void);
void UARTmain_Init2(void);
void rcv_USART_handler(void);
int i;
uint16_t USART_rc;
void Delay(int t){
	int i;
	for (i=0; i<t; i++);
}
void delay_us(uint32_t period){
	
  	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  	TIM2->PSC = 83;		// clk = SystemCoreClock /2/(PSC+1) = 1MHz
  	TIM2->ARR = period-1;
  	TIM2->CNT = 0;
  	TIM2->EGR = 1;		// update registers;
  	TIM2->SR  = 0;		// clear overflow flag
  	TIM2->CR1 = 1;		// enable Timer6
  	while (!TIM2->SR);
  	TIM6->CR2 = 0;		// stop Timer6
  	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, DISABLE);
}
//delay 0.1ms
void delay_01ms(uint16_t period){
	
	
	
  	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
  	TIM6->PSC = 8399;		// clk = SystemCoreClock /2 /(PSC+1) = 10KHz
  	TIM6->ARR = period-1;
  	TIM6->CNT = 0;
  	TIM6->EGR = 1;		// update registers;
  	TIM6->SR  = 0;		// clear overflow flag
  	TIM6->CR1 = 1;		// enable Timer6
  	while (!TIM6->SR);
  	TIM6->CR1 = 0;		// stop Timer6
  	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, DISABLE);
}

extern uint32_t tick_count;
	float angle_roll, angle_yaw,angle_pitch;
	float gyro_pitch_input,gyro_roll_input,gyro_yaw_input;
int32_t Ga, esc_1, esc_2, esc_3, esc_4, Ga_hold;
float Kp_roll=0.54, 		Ki_roll=0.004, 		Kd_roll=17.6;
float Kp_pitch=0.54, 		Ki_pitch=0.004, 	Kd_pitch=17.6;
float Kp_yaw=3.3, 				Ki_yaw=0.02, 			Kd_yaw=0;
int32_t countt;
#define BUFFERSIZE 18
char RxBuffer[BUFFERSIZE];
__IO uint8_t RxIndex = 0x00;
int main(void)
{
	
  GPIO_InitTypeDef  GPIO_InitStructure;
	SysTick_Config(168);
  /* GPIOD Peripheral clock enable */
 // RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
  RCC->AHB1ENR |= RCC_AHB1Periph_GPIOD;
  /* Configure PD12, PD13 in output pushpull mode */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
	UARTmain_Init2();
  while (1)
  {
		//case 0. normal test
//		printf("*%d tick_count time:%0.2f\r\n",countt,(float)tick_count*0.000001);
//					  printf("esc1,2,3,4:\r\n%d, %d, %d, %d\r\n",esc_1,esc_2,esc_3,esc_4);
//						printf("gyro_roll_input,gyro_pitch_input,gyro_yaw_input:\r\n%0.2f, %0.2f, %0.2f.\r\n",gyro_roll_input,gyro_pitch_input,gyro_yaw_input);
//						printf("angle_roll,angle_pitch,angle_yaw:\r\n%0.2f, %0.2f, %0.2f.\r\n",angle_roll,angle_pitch,angle_yaw);
		//countt++;	
		//case 1, export directly to Excel
		printf("*%0.2f,%0.2f,%0.2f,%0.2f,%0.2f,%0.2f,%0.2f,%0.2f,%0.2f,%0.2f,%0.2f,\r\n",(float)tick_count*0.000001,esc_1,esc_2,esc_3,esc_4,angle_roll,angle_pitch,angle_yaw,gyro_roll_input,gyro_pitch_input,gyro_yaw_input);

		//case 2,for USART to C#, live view
		delay_01ms(3000);
  }
}
//transfer only!

//2 ways
void UARTmain_Init2()
{
		GPIO_InitTypeDef GPIO_InitStruct;
    USART_InitTypeDef USART_InitStruct;
	  NVIC_InitTypeDef NVIC_InitStructure;
	
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
    GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_Pin=GPIO_Pin_2|GPIO_Pin_3;
    GPIO_InitStruct.GPIO_Speed=GPIO_Speed_100MHz;
    GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_UP;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	  /*PD5 to PL2303 RX*/
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);//UART Tx pins 
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);//UART Rx pins
	
    //USART2 configuration
    USART_InitStruct.USART_BaudRate=38400;
    USART_InitStruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
    USART_InitStruct.USART_Mode=USART_Mode_Tx|USART_Mode_Rx;
    USART_InitStruct.USART_Parity=USART_Parity_No;
    USART_InitStruct.USART_StopBits=USART_StopBits_1;
    USART_InitStruct.USART_WordLength=USART_WordLength_8b;
    USART_Init(USART2, &USART_InitStruct);
		
		NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 10;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_InitStructure);
		USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
		USART_Cmd(USART2, ENABLE);  
}
void USART2_IRQHandler(void)
{
		// Transfer interrupt
    if (USART_GetITStatus(USART2, USART_IT_TXE) != RESET) 
        {
        }
  // Receive interrupt
    if (USART_GetITStatus(USART2, USART_IT_RXNE) != RESET) 
        {
					//read from USART_DR will automatically clear the RNXE bit.
					RxBuffer[RxIndex++] = USART_ReceiveData(USART2);
	  if (RxIndex >= BUFFERSIZE)
    {
			RxIndex=0;
      /* Receive Transaction data */
			rcv_USART_handler();
    }
		
				}
}
void rcv_USART_handler(void)
{
	Kp_roll=(RxBuffer[0]-48)*100+(RxBuffer[1]-48)*10+(RxBuffer[2]-48)+(RxBuffer[4]-48)/10.0+(RxBuffer[5]-48)/100.0;
	Ki_roll=(RxBuffer[6]-48)*100+(RxBuffer[7]-48)*10+(RxBuffer[8]-48)+(RxBuffer[10]-48)/10.0+(RxBuffer[11]-48)/100.0;
	Kd_roll=(RxBuffer[12]-48)*100+(RxBuffer[13]-48)*10+(RxBuffer[14]-48)+(RxBuffer[16]-48)/10.0+(RxBuffer[17]-48)/100.0;
}
