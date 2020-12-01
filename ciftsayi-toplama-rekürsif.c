/* Melike Sakallioglu
			2016
			Turkish
*/
		
#include<stdio.h>

// 1 den girilen sayiya kadar çift sayilari ekrana yazan rekürsif fonksiyon.

int topla(int a)
{	
	if(a>0 && a%2==0) return a + topla(a-1);
	else if(a>0)
		return topla(a-1);
	else
		return 0;
	
}

int main()
{
	int a;
	scanf("%d",&a);
	if(a%2!=0) printf("sonuc %d",topla(a)); // Çift sayi gönderildiginde gönderilen sayiyi da toplama kattigi için böyle bir çözüm yaptim.
	else printf("sonuc %d",topla(a-1));
	
	return 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
}
