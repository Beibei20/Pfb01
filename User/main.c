#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "HCSR04.h"
#include "Thru-Beam.h"
#include "bsp_dht11.h"

int main(void)
{
	OLED_Init();
	HCSR04_Init();
	TB_Init();	
	OLED_ShowString(1, 1, "HC:");//������
	OLED_ShowString(2, 1, "TB:");//���䴫����
	OLED_ShowString(3, 1, "T:");//�¶�
	OLED_ShowString(3, 10, "S:");//ʪ��

	
	while (1)
	{
			OLED_ShowNum(1, 4, HCSR04_GetValue(), 2);//������1�����ؾ���cm
			OLED_ShowNum(1, 7, HCSR04_GetValue_2(), 2);//������2
			OLED_ShowNum(1, 10, HCSR04_GetValue_3(), 2);//������3
			OLED_ShowNum(1, 13, HCSR04_GetValue_4(), 2);//������4

			OLED_ShowNum(2, 4, TB_GetNum(), 2);//���䴫����,����Ϊ0�����ڵ�������Ϊ1�����ڵ��������0��1	
	   
			OLED_ShowNum(3, 3, DHT11_GetTemperature(), 2);//�¶ȣ������¶�����
		  OLED_ShowNum(3, 13, DHT11_GetHumidity(), 2);//ʪ�ȣ�����ʪ������

		
//��LED��ģ����ȣ���LED��ģ������		
		if(DHT11_GetHumidity() > 65)//ʪ����ֵ
		{
			 GPIO_SetBits(GPIOB, GPIO_Pin_6);  // ����ͨ��ϵͳ(���ߵ�ƽ�����̵���)
		}
		else
			GPIO_ResetBits(GPIOB,GPIO_Pin_6);// �ر�ͨ��ϵͳ�����ߵ�ƽ�رռ̵�����
		
		if(TB_GetNum() == 1)//������������
		{
			GPIO_SetBits(GPIOB, GPIO_Pin_7);  // ��������ϵͳ(���ߵ�ƽ�����̵���)
		}
		else
			GPIO_ResetBits(GPIOB,GPIO_Pin_7);// �ر�����ϵͳ�����ߵ�ƽ�رռ̵�����
		
	}
}

