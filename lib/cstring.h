void reverse(char str[], int length) 
{ 
	int start=0; 
	int end=length-1; 
	while(start<end) 
	{ 
		int temp=str[start];
		str[start]=str[end];
		str[end]=temp;		
		start++; 
		end--; 
	} 
} 
char* tostring(int num,char *str)
{
	int i=0;
	if(num==0)
	{
		str[i++]='0';
		str[i]='\0';
		return str;
	}
	while(num!=0)
	{
		str[i++]=num%10+'0';
		num=num/10;
	}
	str[i]='\0';
	reverse(str,i);
	return str;
}