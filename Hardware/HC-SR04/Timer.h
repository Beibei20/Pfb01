#ifndef __TIMER_H
#define __TIMER_H

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

void Timer_Init(void);

#endif
