#include<reg51.h>
sbit rs=P3^0;
sbit en=P3^1;
void delay_ms(unsigned int k)
{
	unsigned int i,j;
	for(i=0;i<=k;i++)
		for(j=0;j<110;j++);
}
void lcdcmd(unsigned char cmd)
{
	rs=0;en=1;
	P2=cmd;
	delay_ms(1);
	en=0;
	delay_ms(100);
}
void lcddata(unsigned char dat)
{
	rs=1;en=1;
	P2=dat;
	delay_ms(1);
	en=0;
}
void lcdinit()
{
	P2=0x00;
	rs=0;en=0;
	lcdcmd(0x38);//use two rows;
	lcdcmd(0x0C);//display on cursor blinking
	lcdcmd(0x01);//clear screen;
}
void lcdstring(char *str)
{
	unsigned int j;
	for(j=0;str[j]!=0;j++)
	{
		lcddata(str[j]);
	}
	delay_ms(2);
}