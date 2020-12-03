/* Melike Sakallioglu
			2016
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
FILE*dosya,*dosya2;
dosya=fopen("text.txt","r");
dosya2=fopen("text2.txt","w");
int sayi;
int ort=0,sayac=0;
int standartsapma=0;
while(feof(dosya)==0)
{
	fscanf(dosya,"%d \n",&sayi);
	sayac++;
	ort=ort+sayi;
}
ort=ort/sayac;
fclose(dosya);
fclose(dosya2);
fopen("text.txt","r");
fopen("text2.txt","a");
int i=0;
int dizi[sayac];
while(feof(dosya)==0)
{
	fscanf(dosya,"%d \n",&sayi);
	dizi[i]=sayi;
	i++;
	standartsapma=standartsapma+pow(ort-sayi,2);
}
	standartsapma=sqrt(standartsapma);
for(int i=0; i<sayac; i++)
	for(int j=i; j<sayac+1; j++) 
	{
			if(dizi[i]>dizi[j])
			{
			int tmp;
			tmp=dizi[i];
			dizi[i]=dizi[j];
			dizi[j]=tmp;		
}
	}
for(int i=0; i<sayac; i++)
{
	fprintf(dosya2,"%d\n",dizi[i]);
}
	fprintf(dosya2,"Avg =  %d \n",ort);
	fprintf(dosya2,"standard deviation= %d\n",standartsapma);
fclose(dosya2);
printf("standard deviation : ->>>>> %d",standartsapma);
return 0;
}

