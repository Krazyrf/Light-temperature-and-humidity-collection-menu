/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  */
#include <string.h>
#include "board.h"
#include "hal_key.h"
#include "tim-board.h"
#include "timer_handles.h"
#include "adc_reader.h"
#include "flash.h"

/**********************************************************************************************
*函数：void Init( void )
*功能：平台初始化
*输入：无
*输出：无
*特殊说明：无
**********************************************************************************************/
void Init() {
    // 开发板平台初始化
    BoardInitMcu();
    BoardInitPeriph();
    keys_init();//按键初始化
    setTimer2Callback(Time2Handler);
    Tim2McuInit(1);//定时器初始化，设置定时中断1ms中断一次
	 
}

/**********************************************************************************************
*函数：void KeyDownHandler( void )
*功能：按钮事件监听
*输入：无
*输出：无
*特殊说明：无
**********************************************************************************************/
void KeyDownHandler(void) {
	
}

/**********************************************************************************************
*函数：void handlerPre10Ms( void )
*功能：10毫秒循环
*输入：无
*输出：无
*特殊说明：循环处理总时长300ms
**********************************************************************************************/
void handlerPre10Ms(void) {
    for (int delay = 0; delay < 30; delay++) {
        HAL_Delay(10);
        
    }
}

uint8_t temp[64];
/**
 * Main application entry point.
 */
int main( void )
{
		char null[32];
		uint32_t mm=0;
		
		uint32_t low;
		mm=PrintFlashTest(0x08000800);
		OLED_Init();  
		OLED_Clear();
		Init();
		uint16_t value;
		ADCS_Init();
  	
unsigned char bmp[]={
0xFF,0xFF,0xFF,0xFF,0xFF,0xDF,0xBF,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC1,
0xC1,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0xBF,0xDF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0x7F,0x7F,0x7F,0x7F,0x7F,0xFF,0xFF,0x7E,0x0F,0xE7,0xF3,0xF9,0xFD,0xFD,0xFC,
0xFC,0xFD,0xFD,0xF9,0xF3,0xE7,0x0F,0x7E,0xFF,0xFF,0x7F,0x7F,0x7F,0x7F,0x7F,0xFF,
0xFF,0xFE,0xFE,0xFE,0xFE,0xFE,0xFF,0xFF,0x7E,0xF0,0xE7,0xCF,0x9F,0xBF,0xBF,0x3F,
0x3F,0xBF,0xBF,0x9F,0xCF,0xE7,0xF0,0x7E,0xFF,0xFF,0xFE,0xFE,0xFE,0xFE,0xFE,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFB,0xFD,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x83,
0x83,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFD,0xFB,0xFF,0xFF,0xFF,0xFF,0xFF,};
	
	char zhu[]={0x00,0x08,0x08,0x08,0x08,0x08,0x09,0xFA,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00,
0x40,0x40,0x41,0x41,0x41,0x41,0x41,0x7F,0x41,0x41,0x41,0x41,0x41,0x40,0x40,0x00,};
	char cai[]={0x04,0x04,0x44,0xC4,0x4F,0x44,0x44,0xC4,0x24,0x24,0x2F,0xB4,0x24,0x04,0x04,0x00,
0x40,0x44,0x24,0x24,0x15,0x0C,0x04,0xFE,0x04,0x0C,0x15,0x24,0x24,0x44,0x40,0x00,};
	char dan[]={0x00,0x00,0xF8,0x49,0x4A,0x4C,0x48,0xF8,0x48,0x4C,0x4A,0x49,0xF8,0x00,0x00,0x00,
0x10,0x10,0x13,0x12,0x12,0x12,0x12,0xFF,0x12,0x12,0x12,0x12,0x13,0x10,0x10,0x00
,};
char guang[]={
0x40,0x40,0x42,0x44,0x58,0xC0,0x40,0x7F,0x40,0xC0,0x50,0x48,0x46,0x40,0x40,0x00,
0x80,0x80,0x40,0x20,0x18,0x07,0x00,0x00,0x00,0x3F,0x40,0x40,0x40,0x40,0x78,0x00,};
	char zhao[] = {0x00,0xFE,0x42,0x42,0x42,0xFE,0x00,0x42,0xA2,0x9E,0x82,0xA2,0xC2,0xBE,0x00,0x00,
0x80,0x6F,0x08,0x08,0x28,0xCF,0x00,0x00,0x2F,0xC8,0x08,0x08,0x28,0xCF,0x00,0x00
,};
char wen[]={0x10,0x60,0x02,0x8C,0x00,0x00,0xFE,0x92,0x92,0x92,0x92,0x92,0xFE,0x00,0x00,0x00,
0x04,0x04,0x7E,0x01,0x40,0x7E,0x42,0x42,0x7E,0x42,0x7E,0x42,0x42,0x7E,0x40,0x00
,};
char du[]={0x00,0x00,0xFC,0x24,0x24,0x24,0xFC,0x25,0x26,0x24,0xFC,0x24,0x24,0x24,0x04,0x00,
0x40,0x30,0x8F,0x80,0x84,0x4C,0x55,0x25,0x25,0x25,0x55,0x4C,0x80,0x80,0x80,0x00,};
char shi[]={0x10,0x60,0x02,0x8C,0x00,0xFE,0x92,0x92,0x92,0x92,0x92,0x92,0xFE,0x00,0x00,0x00,
0x04,0x04,0x7E,0x01,0x44,0x48,0x50,0x7F,0x40,0x40,0x7F,0x50,0x48,0x44,0x40,0x00,};
char dang[]={0x00,0x40,0x42,0x44,0x58,0x40,0x40,0x7F,0x40,0x40,0x50,0x48,0xC6,0x00,0x00,0x00,
0x00,0x40,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0xFF,0x00,0x00,0x00,};
char qian[]={0x08,0x08,0xE8,0x29,0x2E,0x28,0xE8,0x08,0x08,0xC8,0x0C,0x0B,0xE8,0x08,0x08,0x00,
0x00,0x00,0xFF,0x09,0x49,0x89,0x7F,0x00,0x00,0x0F,0x40,0x80,0x7F,0x00,0x00,0x00,};

	OLED_ShowCHineseArray(32,0,zhu);OLED_ShowCHineseArray(48,0,cai);OLED_ShowCHineseArray(64,0,dan);
	OLED_ShowString(0,2,(uint8_t*)"K2. ");
	OLED_ShowString(0,4,(uint8_t*)"K3. ");
	OLED_ShowString(0,6,(uint8_t*)"K4. ");
	OLED_ShowCHineseArray(18,2,guang);
	OLED_ShowCHineseArray(34,2,zhao);
	OLED_ShowCHineseArray(18,4,wen);
	OLED_ShowCHineseArray(34,4,du);
	OLED_ShowCHineseArray(18,6,shi);
	OLED_ShowCHineseArray(34,6,du);
	OLED_ShowString(50,2,(uint8_t*)"Light");
	OLED_ShowString(50,4,(uint8_t*)"Temp");
	OLED_ShowString(50,6,(uint8_t*)"Humi");
	//OLED_ShowCHineseArray(53,6,);
	//OLED_ShowCHineseArray(69,6,);
char a;
    while(1)
    {
				AdcScanChannel();
				if(isKey3Pressed()==1){OLED_Clear();mm=2;resetKey3();}
					if(mm==2){
					OLED_ShowCHineseArray(16,0,dang);OLED_ShowCHineseArray(32,0,qian);
					OLED_ShowCHineseArray(48,0,wen);OLED_ShowCHineseArray(64,0,du);
						while(mm==2){
		
			value = m_AdcScanChannel0();
			sprintf((char *)temp,"%.2f",(5/2.0)*((value*3300/(4096-1.0))/40.0));
			OLED_ShowString(24,2,temp);
			HAL_Delay(100);
						if(mm==1&&mm==3)resetKey3();break;
					}
				}
				
			
		
				if(isKey4Pressed()==1){OLED_Clear();mm=3;resetKey4();}
					if(mm==3){
					
					OLED_ShowCHineseArray(16,0,dang);OLED_ShowCHineseArray(32,0,qian);
					OLED_ShowCHineseArray(48,0,shi);OLED_ShowCHineseArray(64,0,du);
					while(mm==3){
		
			value = m_AdcScanChannel0();
			
			a=sprintf((char *)temp,"%.2f",(5/2.0)*((value*3300/(4096-1.0))/25.0));
			OLED_ShowString(24,2,temp);
			HAL_Delay(100);
						if(mm==1&&mm==2)resetKey4();break;
					}
				}
				
				if(isKey2Pressed()==1){OLED_Clear();mm=1;resetKey2();}
				if(mm==1){
				
					OLED_ShowString(16,0,(uint8_t*)"Light");
					OLED_ShowString(0,2,(uint8_t*)"L:");
					OLED_ShowString(64,2,(uint8_t*)"(LUX)");
					OLED_DrawBMP(95,4,127,7,bmp);
					while(mm==1){
		
			value = m_AdcScanChannel0();
			sprintf((char *)temp,"%.2f",(5/2.0)*((value*3300/(4096-1.0))/10.0));
			OLED_ShowString(24,2,temp);
			HAL_Delay(100);
						if(temp[0]<55){
							GpioWrite(&Led1,0);
						}else{GpioWrite(&Led1,1);}
					
						
						if(mm==2&&mm==3)resetKey2();break;
					}
				}
			
			
//for(int i=6;i>=0;i--){
		//OLED_ShowCHinese(i*16+8,4,37);
				//HAL_Delay(100);
			}}