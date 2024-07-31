#ifndef __HCSR04_H
#define __HCSR04_H

//��һ��������
#define Trig_Port 		GPIOA
#define Trig_Pin 		GPIO_Pin_0
#define Trig_RCC		RCC_APB2Periph_GPIOA

#define Echo_Port 		GPIOA
#define Echo_Pin 		GPIO_Pin_1
#define Echo_RCC		RCC_APB2Periph_GPIOA

//�ڶ���������
#define Trig_Port 		GPIOA
#define Trig_Pin_2 		GPIO_Pin_2

#define Echo_Port 		GPIOA
#define Echo_Pin_2 		GPIO_Pin_3

//������������
#define Trig_Port 		GPIOA
#define Trig_Pin_3 		GPIO_Pin_4

#define Echo_Port 		GPIOA
#define Echo_Pin_3 		GPIO_Pin_5

//���ĸ�������
#define Trig_Port 		GPIOA
#define Trig_Pin_4 		GPIO_Pin_6

#define Echo_Port 		GPIOA
#define Echo_Pin_4 		GPIO_Pin_7


void HCSR04_Init(void);
uint16_t HCSR04_GetValue();//������1
uint16_t HCSR04_GetValue_2();//������2
uint16_t HCSR04_GetValue_3();//������3
uint16_t HCSR04_GetValue_4();//������4

#endif 
