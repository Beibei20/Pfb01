#include "stm32f10x.h"                  // Device header
#include "Timer.h"

extern uint16_t Time;
extern uint16_t Time_2;
extern uint16_t Time_3;
extern uint16_t Time_4;

void Timer_Init()
{
	//计数器清零
	Time = 0;
	Time_2 = 0;
	Time_3 = 0;
	Time_4 = 0;
	
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	//选择APB1总线下的定时器Timer2
	
	TIM_InternalClockConfig(TIM2);		//TIM2使用内部时钟
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;		//计数模式，此处为向上计数
	TIM_TimeBaseInitStructure.TIM_Period = 7199;		//ARR 1 = 0.0001S
	TIM_TimeBaseInitStructure.TIM_Prescaler = 0;		//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;		//高级计时器特有，重复计数
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);		//使能中断
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;		//中断通道选择
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		//优先级，同上
	
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM2, ENABLE);		//打开定时器
}

void TIM2_IRQHandler()		//定时器2的中断函数，不懂直接套用
{
	if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{

		if (GPIO_ReadInputDataBit(Echo_Port, Echo_Pin) == 1)//超声波1
		{
			Time ++;
		}
		
		if (GPIO_ReadInputDataBit(Echo_Port, Echo_Pin_2) == 1)//超声波2
		{
			Time_2 ++;
		}

		if (GPIO_ReadInputDataBit(Echo_Port, Echo_Pin_3) == 1)//超声波3
		{
			Time_3 ++;
		}

		if (GPIO_ReadInputDataBit(Echo_Port, Echo_Pin_4) == 1)//超声波4
		{
			Time_4 ++;
		}
		
		
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);		//清空标志位
	}
	
}
