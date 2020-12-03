/* Melike Sakallioglu
			2016
*/

//find the prime number before the entered number

#include <stdio.h>
#include <stdlib.h>

int find_prime_number(int number) 
{
   int i,prime;
   if (number==0 || number==1) return 1;
   else {
      for(i=2; i<(number/2)+1; i++) 
	  {
         if(number%i==0) 
		 {
		 	prime=0;
		 	break;
		 }
      }
	  if(prime!=0) return number;
	  return find_prime_number(number-1);
   }
  

} 
int main() {
   int number;
   printf("enter a number"); 
   scanf("%d",&number);
   printf("Prime Number: %d",find_prime_number(number-1));
   return 0;
}
