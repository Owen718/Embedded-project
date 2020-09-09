#ifndef __LED_H
#define __LED_H
#include "sys.h"
#define LED0 PAout(15)  //PA15
#define LED1 PCout(5) //PC5

void LED_Init(void);  //the startup of the LED_Init()

#endif  //the end if
