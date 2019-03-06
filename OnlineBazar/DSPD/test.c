#include<stdio.h>
void main()
{
	int a=7;
	int b=6;
	b=a+b-(a=b);
	printf("%d %d",b,a);
	
}
