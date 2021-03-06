#include "drivers_sonar_low.h"
#include "drivers_sonar_user.h"

#include "stdint.h"
#include "gpio.h"
#include "cmsis_os.h"
#include "utilities_tim.h"
#include "utilities_debug.h"

NaiveIOPoolDefine(SonarIOPool, {0});

float sonar_distance_f = 0.0, sonar_distance_l = 0.0, sonar_distance_b = 0.0, sonar_distance_r = 0.0;
float sonar_distance_fl = 0.0, sonar_distance_fr = 0.0, sonar_distance_bl = 0.0, sonar_distance_br = 0.0;
uint8_t sonar_measuring_flag_f = 0, sonar_measuring_flag_l = 0, sonar_measuring_flag_b = 0, sonar_measuring_flag_r = 0;
uint8_t sonar_measuring_flag_fl = 0, sonar_measuring_flag_fr = 0, sonar_measuring_flag_bl = 0, sonar_measuring_flag_br = 0;
void SonarCallbask(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == GPIO_PIN_1)
	{
		//fw_printfln("GPIO_Pin == GPIO_PIN_1");
		static uint64_t initial1;
		//sonar_echo
		//jump from low to high
		if(HAL_GPIO_ReadPin(GPIOF,GPIO_Pin)==GPIO_PIN_SET)
		{
			initial1 = fw_getTimeMicros();
		}
		//jump from high to low
		else if(HAL_GPIO_ReadPin(GPIOF,GPIO_Pin)==GPIO_PIN_RESET)
		{
			uint32_t tmp= fw_getTimeMicros()-initial1;
			float tmp_dis=(double)tmp/10000*170;
			
			if(tmp_dis<300)
			{
				sonar_distance_f=tmp_dis;
			}
			//release flag
			sonar_measuring_flag_f=0;
		}
	}
	
//	if(GPIO_Pin == GPIO_PIN_5)
//	{
//		//fw_printfln("GPIO_Pin == GPIO_PIN_5");
//		static uint64_t initial1;
//		//sonar_echo
//		//jump from low to high
//		if(HAL_GPIO_ReadPin(GPIOE,GPIO_Pin)==GPIO_PIN_SET)
//		{
//			initial1 = fw_getTimeMicros();
//		}
//		//jump from high to low
//		else if(HAL_GPIO_ReadPin(GPIOE,GPIO_Pin)==GPIO_PIN_RESET)
//		{
//			uint32_t tmp= fw_getTimeMicros()-initial1;
//			float tmp_dis=(double)tmp/10000*170;
//			
//			if(tmp_dis<300)
//			{
//				sonar_distance_l=tmp_dis;
//			}
//			//release flag
//			sonar_measuring_flag_l=0;
//		}
//	}
	
	if(GPIO_Pin == GPIO_PIN_6)//E6
	{
		//fw_printfln("GPIO_Pin == GPIO_PIN_6");
		static uint64_t initial1;
		//sonar_echo
		//jump from low to high
		if(HAL_GPIO_ReadPin(GPIOE,GPIO_Pin)==GPIO_PIN_SET)
		{
			initial1 = fw_getTimeMicros();
		}
		//jump from high to low
		else if(HAL_GPIO_ReadPin(GPIOE,GPIO_Pin)==GPIO_PIN_RESET)
		{
			uint32_t tmp= fw_getTimeMicros()-initial1;
			float tmp_dis=(double)tmp/10000*170;
			
			if(tmp_dis<300)
			{
				sonar_distance_b=tmp_dis;
			}
			//release flag
			sonar_measuring_flag_b=0;
		}
	}
	
	if(GPIO_Pin == GPIO_PIN_10)//GPIO_PIN_2
	{
		//fw_printfln("GPIO_Pin == GPIO_PIN_2");//c2
		static uint64_t initial1;
		//sonar_echo
		//jump from low to high
		if(HAL_GPIO_ReadPin(GPIOF,GPIO_Pin)==GPIO_PIN_SET)
		{
			initial1 = fw_getTimeMicros();
		}
		//jump from high to low
		else if(HAL_GPIO_ReadPin(GPIOF,GPIO_Pin)==GPIO_PIN_RESET)
		{
			uint32_t tmp= fw_getTimeMicros()-initial1;
			float tmp_dis=(double)tmp/10000*170;
			
			if(tmp_dis<300)
			{
				sonar_distance_r=tmp_dis;
			}
			//release flag
			sonar_measuring_flag_r=0;
		}
	}
	
	if(GPIO_Pin == GPIO_PIN_2)//GPIO_PIN_2
	{
		//fw_printfln("GPIO_Pin == GPIO_PIN_2");//c2
		static uint64_t initial1;
		//sonar_echo
		//jump from low to high
		if(HAL_GPIO_ReadPin(GPIOC,GPIO_Pin)==GPIO_PIN_SET)
		{
			initial1 = fw_getTimeMicros();
		}
		//jump from high to low
		else if(HAL_GPIO_ReadPin(GPIOC,GPIO_Pin)==GPIO_PIN_RESET)
		{
			uint32_t tmp= fw_getTimeMicros()-initial1;
			float tmp_dis=(double)tmp/10000*170;
			
			if(tmp_dis<300)
			{
				sonar_distance_fl=tmp_dis;
			}
			//release flag
			sonar_measuring_flag_fl=0;
		}
	}
	
	if(GPIO_Pin == GPIO_PIN_3)//GPIO_PIN_2
	{
		//fw_printfln("GPIO_Pin == GPIO_PIN_2");//c2
		static uint64_t initial1;
		//sonar_echo
		//jump from low to high
		if(HAL_GPIO_ReadPin(GPIOC,GPIO_Pin)==GPIO_PIN_SET)
		{
			initial1 = fw_getTimeMicros();
		}
		//jump from high to low
		else if(HAL_GPIO_ReadPin(GPIOC,GPIO_Pin)==GPIO_PIN_RESET)
		{
			uint32_t tmp= fw_getTimeMicros()-initial1;
			float tmp_dis=(double)tmp/10000*170;
			
			if(tmp_dis<300)
			{
				sonar_distance_fr=tmp_dis;
			}
			//release flag
			sonar_measuring_flag_fr=0;
		}
	}
	
	if(GPIO_Pin == GPIO_PIN_4)//GPIO_PIN_2
	{
		//fw_printfln("GPIO_Pin == GPIO_PIN_2");//c2
		static uint64_t initial1;
		//sonar_echo
		//jump from low to high
		if(HAL_GPIO_ReadPin(GPIOC,GPIO_Pin)==GPIO_PIN_SET)
		{
			initial1 = fw_getTimeMicros();
		}
		//jump from high to low
		else if(HAL_GPIO_ReadPin(GPIOC,GPIO_Pin)==GPIO_PIN_RESET)
		{
			uint32_t tmp= fw_getTimeMicros()-initial1;
			float tmp_dis=(double)tmp/10000*170;
			
			if(tmp_dis<300)
			{
				sonar_distance_bl=tmp_dis;
			}
			//release flag
			sonar_measuring_flag_bl=0;
		}
	}
	
	if(GPIO_Pin == GPIO_PIN_9)//GPIO_PIN_2
	{
		//fw_printfln("GPIO_Pin == GPIO_PIN_2");//c2
		static uint64_t initial1;
		//sonar_echo
		//jump from low to high
		if(HAL_GPIO_ReadPin(GPIOI,GPIO_Pin)==GPIO_PIN_SET)
		{
			initial1 = fw_getTimeMicros();
		}
		//jump from high to low
		else if(HAL_GPIO_ReadPin(GPIOI,GPIO_Pin)==GPIO_PIN_RESET)
		{
			uint32_t tmp= fw_getTimeMicros()-initial1;
			float tmp_dis=(double)tmp/10000*170;
			
			if(tmp_dis<300)
			{
				sonar_distance_br=tmp_dis;
			}
			//release flag
			sonar_measuring_flag_br=0;
		}
	}
	
	if(GPIO_Pin == GPIO_PIN_5)
	{
		//fw_printfln("GPIO_Pin == GPIO_PIN_5");
		static uint64_t initial1;
		//sonar_echo
		//jump from low to high
		if(HAL_GPIO_ReadPin(GPIOE,GPIO_Pin)==GPIO_PIN_SET)
		{
			initial1 = fw_getTimeMicros();
		}
		//jump from high to low
		else if(HAL_GPIO_ReadPin(GPIOE,GPIO_Pin)==GPIO_PIN_RESET)
		{
			uint32_t tmp= fw_getTimeMicros()-initial1;
			float tmp_dis=(double)tmp/10000*170;
			
			if(tmp_dis<300)
			{
				sonar_distance_l=tmp_dis;
			}
			//release flag
			sonar_measuring_flag_l=0;
		}
	}
}

uint8_t SonarPrint=0;
void sonarTask(void const * argument){
	while(1){
		static uint32_t cnt=0;
		if(sonar_measuring_flag_f==0){
				//ready for next measure
				uint32_t i=42*15;
				HAL_GPIO_WritePin(GPIOF,GPIO_PIN_0,GPIO_PIN_SET);
				while(i--);
				HAL_GPIO_WritePin(GPIOF,GPIO_PIN_0,GPIO_PIN_RESET);
				sonar_measuring_flag_f=1;
		}
		
		osDelay(2);
		
		if(sonar_measuring_flag_l==0){
				//ready for next measure
				uint32_t i=42*15;
				HAL_GPIO_WritePin(GPIOE,GPIO_PIN_4,GPIO_PIN_SET);
				while(i--);
				HAL_GPIO_WritePin(GPIOE,GPIO_PIN_4,GPIO_PIN_RESET);
				sonar_measuring_flag_l=1;
		}
		//fw_printf("l = %3f\t", sonar_distance_l);
		osDelay(2);
		
		if(sonar_measuring_flag_b==0){//e12
				//ready for next measure
				uint32_t i=42*15;
				HAL_GPIO_WritePin(GPIOE,GPIO_PIN_12,GPIO_PIN_SET);
				while(i--);
				HAL_GPIO_WritePin(GPIOE,GPIO_PIN_12,GPIO_PIN_RESET);
				sonar_measuring_flag_b=1;
		}
		//fw_printf("b = %3f\t", sonar_distance_b);
		osDelay(2);
	
		if(sonar_measuring_flag_r==0){//b8
				//ready for next measure
				uint32_t i=42*15;
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
				while(i--);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
				sonar_measuring_flag_r=1;
		}
		osDelay(2);
		//fw_printfln("r = %3f\t", sonar_distance_r);
		
		if(sonar_measuring_flag_fl==0){//b8
				//ready for next measure
				uint32_t i=42*15;
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);
				while(i--);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_RESET);
				sonar_measuring_flag_fl=1;
		}
		osDelay(2);
		
		if(sonar_measuring_flag_fr==0){//b8
				//ready for next measure
				uint32_t i=42*15;
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
				while(i--);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
				sonar_measuring_flag_fr=1;
		}
		osDelay(2);
		
		if(sonar_measuring_flag_bl==0){//b8
				//ready for next measure
				uint32_t i=42*15;
				HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_SET);
				while(i--);
				HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_RESET);
				sonar_measuring_flag_bl=1;
		}
		osDelay(2);
		
		if(sonar_measuring_flag_br==0){//b8
				//ready for next measure
				uint32_t i=42*15;
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
				while(i--);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
				sonar_measuring_flag_br=1;
		}
		osDelay(2);
		
		IOPool_pGetWriteData(SonarIOPool)->sonarValue[0] = sonar_distance_f;
		IOPool_pGetWriteData(SonarIOPool)->sonarValue[1] = sonar_distance_l;
		IOPool_pGetWriteData(SonarIOPool)->sonarValue[2] = sonar_distance_b;
		IOPool_pGetWriteData(SonarIOPool)->sonarValue[3] = sonar_distance_r;
		IOPool_pGetWriteData(SonarIOPool)->sonarValue[4] = sonar_distance_fl;
		IOPool_pGetWriteData(SonarIOPool)->sonarValue[5] = sonar_distance_fr;
		IOPool_pGetWriteData(SonarIOPool)->sonarValue[6] = sonar_distance_bl;
		IOPool_pGetWriteData(SonarIOPool)->sonarValue[7] = sonar_distance_br;
		if(SonarPrint)
		{
			if(cnt%20==0)
			{
					fw_printf("df =%f | dl= %f | db=%f | dr=%f | dfl=%f | dfr=%f dbl=%f dbr=%f\r\n",sonar_distance_f,sonar_distance_l,sonar_distance_b,sonar_distance_r,sonar_distance_fl,sonar_distance_fr,sonar_distance_bl,sonar_distance_br);
			}
		}
		IOPool_getNextWrite(SonarIOPool);
		cnt++;
		osDelay(60);
		//fw_printf("f = %3f\t", sonar_distance_f);
	}
}


