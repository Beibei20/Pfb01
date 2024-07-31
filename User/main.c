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
	OLED_ShowString(1, 1, "HC:");//超声波
	OLED_ShowString(2, 1, "TB:");//对射传感器
	OLED_ShowString(3, 1, "T:");//温度
	OLED_ShowString(3, 10, "S:");//湿度

	
	while (1)
	{
			OLED_ShowNum(1, 4, HCSR04_GetValue(), 2);//超声波1，返回距离cm
			OLED_ShowNum(1, 7, HCSR04_GetValue_2(), 2);//超声波2
			OLED_ShowNum(1, 10, HCSR04_GetValue_3(), 2);//超声波3
			OLED_ShowNum(1, 13, HCSR04_GetValue_4(), 2);//超声波4

			OLED_ShowNum(2, 4, TB_GetNum(), 2);//对射传感器,亮灯为0（无遮挡物），灭灯为1（有遮挡物），返回0，1	
	   
			OLED_ShowNum(3, 3, DHT11_GetTemperature(), 2);//温度，返回温度数据
		  OLED_ShowNum(3, 13, DHT11_GetHumidity(), 2);//湿度，返回湿度数据

		
//黄LED灯模拟风扇，红LED灯模拟照明		
		if(DHT11_GetHumidity() > 65)//湿度阈值
		{
			 GPIO_SetBits(GPIOB, GPIO_Pin_6);  // 启动通风系统(给高电平驱动继电器)
		}
		else
			GPIO_ResetBits(GPIOB,GPIO_Pin_6);// 关闭通风系统（给高电平关闭继电器）
		
		if(TB_GetNum() == 1)//开门启动照明
		{
			GPIO_SetBits(GPIOB, GPIO_Pin_7);  // 启动照明系统(给高电平驱动继电器)
		}
		else
			GPIO_ResetBits(GPIOB,GPIO_Pin_7);// 关闭照明系统（给高电平关闭继电器）
		
	}
}

