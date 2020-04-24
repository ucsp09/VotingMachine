#include"lcd.h"
#include"cstring.h"
sbit s1=P3^2;sbit l1=P1^0;
sbit s2=P3^3;sbit l2=P1^1;
sbit s3=P3^4;sbit l3=P1^2;
sbit s4=P3^5;sbit l4=P1^3;
sbit s5=P3^6;sbit l5=P1^4;
sbit s6=P3^7;
int count[5]={0,0,0,0,0};
char buffer[10];
int* getwinners(int arr[],int *wlist)
{
	int i,max,j;
	max=-1;
	for(i=0;i<5;i++)
		if(arr[i]>max)
			max=arr[i];
	for(j=0;j<5;j++)
		if(arr[j]==max)
			wlist[j]=1;
	return wlist;
}
void load()
{
	lcdinit();
	lcdcmd(0x80);
	lcdstring("Voting Machine");
	lcdcmd(0xC0);
	lcdstring("Press Start/Stop");
	while(1)
	{
		if(!s6)
			break;
	}
}
void end()
{
	int i,j,_max,_count;
	int *winnerslist;
	int _wlist[5]={0,0,0,0,0};
	winnerslist=getwinners(count,_wlist);
	lcdstring("Voting ended");
	delay_ms(800);
	for(i=1;i<=5;i++)
	{
		lcdcmd(0x01);
		lcdstring("Party ");
		lcddata(i+'0');
		lcdstring(" Votes");
		lcdcmd(0xC0);
		lcdstring("are:");
		lcdstring(tostring(count[i-1],buffer));
		delay_ms(3000);
	}
	lcdcmd(0x01);
	lcdstring("{");
	_count=0;
	for(j=0;j<5;j++)
	{
		if(winnerslist[j]==1)
		{
			lcddata(j+1+'0');
			lcddata(' ');
			_max=count[j];
			_count+=1;
		}
	}
	if(_count==1)
	{
		lcdstring("}is");
		lcdcmd(0xC0);
		lcdstring("winner:");
	}
	else
	{
		lcdstring("}are");
		lcdcmd(0xC0);
		lcdstring("winners:");
	}
	lcdstring(tostring(_max,buffer));
	lcdstring(" votes");
	while(1)
	{
		;
	}
}
void checkswitch(int switchnumber)
{
	lcdcmd(0x01);
	if(switchnumber==1||switchnumber==2||switchnumber==3||switchnumber==4||switchnumber==5)
		{
			lcdstring("Voted for");
			lcdcmd(0xC0);
			lcdstring("Party:");
			lcddata(switchnumber+'0');
			delay_ms(500);
		}
	else
		end();	
}
void start()
{
	while(1)
	{
		int flag=0;
		lcdcmd(0x01);
		lcdstring("Click on party");
		lcdcmd(0xC0);
		lcdstring("Switch to vote");
		while(1)
		{
			if(s1==0)
			{
				l1=1;
				count[0]+=1;
				flag=1;
				break;
			}
			else if(s2==0)
			{
				l2=1;
				count[1]+=1;
				flag=2;
				break;
			}
			else if(s3==0)
			{
				l3=1;
				count[2]+=1;
				flag=3;
				break;
			}
			else if(s4==0)
			{
				l4=1;
				count[3]+=1;
				flag=4;
				break;
			}
			else if(s5==0)
			{
				l5=1;
				count[4]+=1;
				flag=5;
				break;
			}
			else if(s6==0)
			{
				flag=6;
				break;
			}
			else
				l1=l2=l3=l4=l5=0;
		}
		checkswitch(flag);
	}
}
void vote()
{
	load();
	start();
}