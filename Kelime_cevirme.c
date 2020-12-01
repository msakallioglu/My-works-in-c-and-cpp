/*Melike Sakallioglu
			2016
			Turkish
*/

#include<stdio.h>
#include <string.h>
int main(){
	
	char kelime[100], x[100];
	printf("Cumle giriniz : "); 
	scanf("%[^\n]s", &kelime);
	int uzunluk=strlen(kelime);
	int xinuzunluk = 0;
	for(int i = 0; i <=uzunluk; i++)
	{
		if(kelime[i] != ' ')
		{
			x[i] = kelime[i];
		}
		else if(kelime[i] == ' '){
			for(int j = strlen(x) - 1; j >= xinuzunluk ; j--)
			{
				printf("%c", x[j]);
			}
			x[i] = kelime[i];
			printf("%c", x[i]);
			xinuzunluk = strlen(x);
		}
	}
	for(int i = uzunluk - 1; i >= xinuzunluk; i--)
		printf("%c", kelime[i]);
	return 0;
}
