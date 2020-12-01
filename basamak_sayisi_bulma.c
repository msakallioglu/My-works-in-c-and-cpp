/* Melike Sakallioglu
			2016
			Turkish
*/


#include <stdio.h>

void basamaksayisi(int sayi){
	int sayac=0;
	int sonuc;
	do {
        sonuc=sayi%10;
        printf("\t %d",sonuc);
        sayi=sayi/10;
        sayac++;
    }while(sayi>0);
    
    printf("\nbasamak sayisi= %d",sayac);
}
	
int main(int argc, char** argv) {
	
	int sonuc,sayi;
    printf("sayi giriniz...");
    scanf("%d",&sayi);
	basamaksayisi(sayi);
	return 0;
}
