#include "stm32f10x.h"  
#include "Thru-Beam.h"

//������⴫����PB9

//����PB6

//����ģ��PB7

void TB_Init(void)
{
	//������⴫��������
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
//������������������������������������������������������������	
//���ȣ�����ģ�鲿��	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		
	GPIO_InitTypeDef GPIO_InitStructure_FD;
	GPIO_InitStructure_FD.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure_FD.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure_FD.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure_FD);
		
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);//���͵�ƽ	���ߵ�ƽ�������͵�ƽֹͣ������
	GPIO_ResetBits(GPIOB,GPIO_Pin_7);//���͵�ƽ	���ߵ�ƽ�������͵�ƽֹͣ������
	
	
}

uint8_t TB_GetNum(void)//��ȡ������⴫��������
{
	uint8_t TBNum = 0;
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9) == 0)
	{
		
		TBNum = 1;
	
	}
	return TBNum;
}



