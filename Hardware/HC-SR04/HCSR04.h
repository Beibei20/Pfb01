#ifndef __HCSR04_H
#define __HCSR04_H

//第一个超声波
#define Trig_Port 		GPIOA
#define Trig_Pin 		GPIO_Pin_0
#define Trig_RCC		RCC_APB2Periph_GPIOA

#define Echo_Port 		GPIOA
#define Echo_Pin 		GPIO_Pin_1
#define Echo_RCC		RCC_APB2Periph_GPIOA

//第二个超声波
#define Trig_Port 		GPIOA
#define Trig_Pin_2 		GPIO_Pin_2

#define Echo_Port 		GPIOA
#define Echo_Pin_2 		GPIO_Pin_3

//第三个超声波
#define Trig_Port 		GPIOA
#define Trig_Pin_3 		GPIO_Pin_4

#define Echo_Port 		GPIOA
#define Echo_Pin_3 		GPIO_Pin_5

//第四个超声波
#define Trig_Port 		GPIOA
#define Trig_Pin_4 		GPIO_Pin_6

#define Echo_Port 		GPIOA
#define Echo_Pin_4 		GPIO_Pin_7


void HCSR04_Init(void);
uint16_t HCSR04_GetValue();//超声波1
uint16_t HCSR04_GetValue_2();//超声波2
uint16_t HCSR04_GetValue_3();//超声波3
uint16_t HCSR04_GetValue_4();//超声波4

#endif 
