/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"

int nbut1 = 0, nbut2 = 0;

#define LED_GPIO_PORT  (GPIOB)
#define LED_GPIO_PINS  (GPIO_PIN_0)

#define BUT_GPIO_PORT  (GPIOA)
#define BUT1_GPIO_PINS  (GPIO_PIN_3)
#define BUT2_GPIO_PINS  (GPIO_PIN_4)

#define RELAY_GPIO_PORT  (GPIOC)
#define RELAY1_GPIO_PINS  (GPIO_PIN_1)
#define RELAY2_GPIO_PINS  (GPIO_PIN_2)

void clk_config(void);
void Delay(uint32_t nCount);

void main(void)
{
  clk_config();
  GPIO_DeInit(GPIOC);
  /* Initialize LED in Output Mode */
  GPIO_Init(LED_GPIO_PORT, LED_GPIO_PINS, GPIO_MODE_OUT_PP_LOW_FAST);
  /* Initialize RELAY in Output Mode */
  GPIO_Init(RELAY_GPIO_PORT, RELAY1_GPIO_PINS, GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(RELAY_GPIO_PORT, RELAY2_GPIO_PINS, GPIO_MODE_OUT_PP_LOW_FAST);
  /* Initialize BUTTON in Input Mode */
  GPIO_Init(BUT_GPIO_PORT, BUT1_GPIO_PINS, GPIO_MODE_IN_FL_NO_IT);
  
  while (1)
  {
    if(GPIO_ReadInputPin(BUT_GPIO_PORT, BUT1_GPIO_PINS)==0)
       {
         Delay(80000);
         if(GPIO_ReadInputPin(BUT_GPIO_PORT, BUT1_GPIO_PINS)==0)
           nbut1++;
       }
    if(nbut1 == 1)
      GPIO_WriteHigh(RELAY_GPIO_PORT, RELAY1_GPIO_PINS);
    else
    {
      GPIO_WriteLow(RELAY_GPIO_PORT, RELAY1_GPIO_PINS);
      nbut1 = 0;
    }

    if(GPIO_ReadInputPin(BUT_GPIO_PORT, BUT2_GPIO_PINS)==0)
       {
         Delay(80000);
         if(GPIO_ReadInputPin(BUT_GPIO_PORT, BUT2_GPIO_PINS)==0)
           nbut2++;
       }
    if(nbut2 == 1)
      GPIO_WriteHigh(RELAY_GPIO_PORT, RELAY2_GPIO_PINS);
    else
    {
      GPIO_WriteLow(RELAY_GPIO_PORT, RELAY2_GPIO_PINS);
      nbut2 = 0;
    }
  }
}

#ifdef USE_FULL_ASSERT

void clk_config(void)
{
  CLK_DeInit();
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);//cau hinh tan so xung noi HSI/1=16MHZ
  CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);// xung cpu=HSI/1=16MHZ
  while(CLK_GetFlagStatus(CLK_FLAG_HSIRDY)!=SET);
}

void Delay(uint32_t nCount)
{
  /* Decrement nCount value */
  while (nCount != 0)
  {
    nCount--;
  }
}


void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
