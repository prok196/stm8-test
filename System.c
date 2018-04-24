#include "System.h"

void clk_config_16MHz_HSI(void)
{
	CLK_DeInit();
        /* HSE*/
        //CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);
         //CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSE, DISABLE, CLK_CURRENTCLOCKSTATE_DISABLE);        
         /* HSI*/
        CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);      //f_Master = HSI/1 = 16MHz
        CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);            //f_CPU = f_Master/1 = 16MHz
        CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSI, DISABLE, CLK_CURRENTCLOCKSTATE_DISABLE);
        while(CLK_GetFlagStatus(CLK_FLAG_HSIRDY)!=SET);
}

void delay(uint32_t ncount)
{
  while(--ncount);
}