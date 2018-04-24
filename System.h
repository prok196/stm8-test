#ifndef SYSTEM_H_
#define SYSTEM_H_

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "stdlib.h"
/* Private defines -----------------------------------------------------------*/
void clk_config_16MHz_HSI(void);
void delay(uint32_t ncount);
#endif