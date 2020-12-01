/* Melike Sakallioglu
			2016
			Turkish
*/

#include<stdio.h>

int yuvarla(float a)
{
	int x;
	x=a;
	float sonuc1,sonuc2;
	sonuc1=a-(x);
	sonuc2=(x+1)-a;
	
	if(sonuc1>sonuc2) return x+1;
	else if(sonuc2>sonuc1) return x;
	else
		return x+1;
}


int main()
{
	float sayi;
	scanf("%f",&sayi);
	printf("yuvarlama= %d",yuvarla(sayi));
	return 0;
}
