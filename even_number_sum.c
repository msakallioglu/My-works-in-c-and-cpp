/* Melike Sakallioglu
			2016
*/
		
#include<stdio.h>

// Recursive function that finds the sum of even numbers up to the number entered.

int sum (int a)
{	
	if(a>0 && a%2==0) return a + sum(a-1);
	else if(a>0)
		return sum(a-1);
	else
		return 0;
	
}

int main()
{
	int a;
	printf("Enter a number = ");
	scanf("%d",&a);
	if(a%2!=0) printf("result %d",sum(a));
	else printf("result %d",sum(a-1));
	
	return 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
}
