#include "stm32f10x.h"  
#include "Thru-Beam.h"

//对射红外传感器PB9

//风扇PB6

//灯条模块PB7

void TB_Init(void)
{
	//对射红外传感器部分
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
//——————————————————————————————	
//风扇，灯条模块部分	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		
	GPIO_InitTypeDef GPIO_InitStructure_FD;
	GPIO_InitStructure_FD.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure_FD.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure_FD.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure_FD);
		
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);//拉低电平	（高电平启动，低电平停止）风扇
	GPIO_ResetBits(GPIOB,GPIO_Pin_7);//拉低电平	（高电平启动，低电平停止）照明
	
	
}

uint8_t TB_GetNum(void)//获取对射红外传感器数据
{
	uint8_t TBNum = 0;
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9) == 0)
	{
		
		TBNum = 1;
	
	}
	return TBNum;
}



