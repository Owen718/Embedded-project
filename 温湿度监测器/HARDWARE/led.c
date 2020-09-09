#include "led.h"

void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitTypeStruct;    //define a gpio_typedefine struct
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC,ENABLE);  //use the rcc to enable the gpioa and apio d
  
	GPIO_InitTypeStruct.GPIO_Mode = GPIO_Mode_Out_PP;       //the gpio_typedefine 
	GPIO_InitTypeStruct.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitTypeStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitTypeStruct);
	GPIO_SetBits(GPIOA,GPIO_Pin_15);
	
	GPIO_InitTypeStruct.GPIO_Pin = GPIO_Pin_5;
	GPIO_Init(GPIOC,&GPIO_InitTypeStruct);
	GPIO_SetBits(GPIOC,GPIO_Pin_5);

}
