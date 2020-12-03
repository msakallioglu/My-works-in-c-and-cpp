/* Melike Sakallioglu
			2016
*/

#include<stdio.h>

int rounding(float a)
{
	int x;
	x=a;
	float result1,result2;
	result1=a-(x);
	result2=(x+1)-a;
	
	if(result1>result2) return x+1;
	else if(result2>result1) return x;
	else
		return x+1;
}


int main()
{
	float number;
	scanf("%f",&number);
	printf("rounding= %d",rounding(number));
	return 0;
}
