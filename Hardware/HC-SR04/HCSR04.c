#include "stm32f10x.h"                  // Device header
#include "HCSR04.h"
#include "Timer.h"
#include "Delay.h"


uint16_t Time;
uint16_t Time_2;
uint16_t Time_3;
uint16_t Time_4;

void HCSR04_Init()
{
	RCC_APB2PeriphClockCmd(Trig_RCC, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = Trig_Pin | Trig_Pin_2 | Trig_Pin_3 | Trig_Pin_4;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(Trig_Port, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStruct.GPIO_Pin = Echo_Pin | Echo_Pin_2 | Echo_Pin_3 | Echo_Pin_4;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(Echo_Port, &GPIO_InitStruct);
	
	GPIO_ResetBits(Trig_Port, Trig_Pin);
	GPIO_ResetBits(Trig_Port, Trig_Pin_2);
	GPIO_ResetBits(Trig_Port, Trig_Pin_3);
	GPIO_ResetBits(Trig_Port, Trig_Pin_4);
	
}

void HCSR04_Start()
{
	GPIO_SetBits(Trig_Port, Trig_Pin);
	Delay_us(45);
	
	GPIO_ResetBits(Trig_Port, Trig_Pin);
	Timer_Init();
}

void HCSR04_Start_2()
{
	GPIO_SetBits(Trig_Port, Trig_Pin_2);
	Delay_us(45);
	
	GPIO_ResetBits(Trig_Port, Trig_Pin_2);
	Timer_Init();
}

void HCSR04_Start_3()
{
	GPIO_SetBits(Trig_Port, Trig_Pin_3);
	Delay_us(45);
	
	GPIO_ResetBits(Trig_Port, Trig_Pin_3);
	Timer_Init();
}

void HCSR04_Start_4()
{
	GPIO_SetBits(Trig_Port, Trig_Pin_4);
	Delay_us(45);
	
	GPIO_ResetBits(Trig_Port, Trig_Pin_4);
	Timer_Init();
}


uint16_t HCSR04_GetValue()
{
	HCSR04_Start();
	Delay_ms(100);
	return ((Time * 0.0001) * 34000) / 2;
}

uint16_t HCSR04_GetValue_2()
{
	HCSR04_Start_2();
	Delay_ms(100);
	return ((Time_2 * 0.0001) * 34000) / 2;
}

uint16_t HCSR04_GetValue_3()
{
	HCSR04_Start_3();
	Delay_ms(100);
	return ((Time_3 * 0.0001) * 34000) / 2;
}

uint16_t HCSR04_GetValue_4()
{
	HCSR04_Start_4();
	Delay_ms(100);
	return ((Time_4 * 0.0001) * 34000) / 2;
}

