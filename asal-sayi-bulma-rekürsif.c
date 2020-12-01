/* Melike Sakallioglu
			2016
			Turkish
*/

#include <stdio.h>
#include <stdlib.h>

int asalbul(int sayi) 
{
   int i,asal;
   if (sayi==0 || sayi==1) return 1;
   else {
      for(i=2; i<(sayi/2)+1; i++) 
	  {
         if(sayi%i==0) 
		 {
		 	asal=0;
		 	break;
		 }
      }
	  if(asal!=0) return sayi;
	  return asalbul(sayi-1);
   }
  

} 
int main() {
   int sayi;
   printf("sayi giriniz:"); 
   scanf("%d",&sayi);
   printf("Asal sayi: %d",asalbul(sayi-1));
   return 0;
}
