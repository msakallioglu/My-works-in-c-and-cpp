/* Melike Sakallioglu
			2016
*/


#include <stdio.h>

void number_of_digits(int number){
	int count=0;
	int result;
	do {
        result=number%10;
        printf("\t %d",result);
        number=number/10;
        count++;
    }while(number>0);
	  
    printf("\n number of digits= %d",count);
}
	
int main() {
	
	int result,number;
    printf("Enter a number = ");
    scanf("%d",&number);
	number_of_digits(number);
	return 0;
}
