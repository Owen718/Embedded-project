#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "SMG.h"
#include "dht11.h"

const unsigned char LED_table[24]={
//01234567
0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,
//89ABCDEF
0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E,
//ʱ��Ч��
0xF9,0xBF,0x99,0xBF,0x82,0xF9,0xC0,0xA4
};

//��������ܶ��롰0123456789AbCdEFϨ��-��
const unsigned char wei_table[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
//��һλ���ڰ�λλ��

int Celsius_show(float celsius)  //���¶���ֵ����ת�����������������ʾ��
{
	
	
	//��λ
	SMG_Display(LED_table[12],wei_table[0]); //��0λ��ʾC,��ʾ���϶�
	
	//�¶������趨
	if (celsius >=50.0)  //���ڲ����¶ȣ���ʾ������Ϣ�� EORO
	{
	SMG_Display(LED_table[0],wei_table[0]);
	SMG_Display(~0x50,wei_table[1]);
	SMG_Display(LED_table[0],wei_table[2]);
	SMG_Display(LED_table[14],wei_table[3]);  
	}
	else if(celsius > 0 )
	{
		int first_num,second_num,third_num;
		first_num = (int)(celsius * 10) % 10 ; //ȡС������һλ
		second_num = (int)celsius % 10; //ȡ�¶ȵĸ�λ
		third_num = (int)(celsius / 10) % 10; //ȡ�¶ȵ�ʮλ

		SMG_Display(LED_table[first_num],wei_table[1]);
		SMG_Display(LED_table[second_num] & 0x7f,wei_table[2]);
		SMG_Display(LED_table[third_num],wei_table[3]);
		
	}
	return 0;

}



int main(void)
{
	  int i;
	  float temperature=0;
	  float dampness=0;
	  int t;
	
	  t=0;
      delay_init();
	  LED_Init();
	  HC595_Init();
	  
	
	  while(1)
	  {
		  t++;  
		 if(t%500==0)
	     {
		  ReadDHT11();
		 }
		  
		  temperature=(float)tdata[2] + ((float)tdata[3])/10;
		 //temperature = tdata[3]; 
		 dampness=tdata[0] +((float)tdata[1])/100;
	     Celsius_show(temperature);
  
	  
	  }
		
 }