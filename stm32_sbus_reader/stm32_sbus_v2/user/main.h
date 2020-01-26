#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#if defined (USE_STM324xG_EVAL)
  #define DAC_DHR12R2_ADDRESS    0x40007414
  #define DAC_DHR8R1_ADDRESS     0x40007410

#else /* defined (USE_STM324x7I_EVAL)*/ 
  #define DAC_DHR12R2_ADDRESS    0x40007414
  #define DAC_DHR8R1_ADDRESS     0x40007410

#endif
/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
