/* Melike Sakallioglu
			2016
			Turkish
*/

#include<stdio.h>
#include<stdlib.h>   
#include<time.h>    
#include<conio.h>

int main()
{
	srand(time(NULL));
	char secim;
	int tt=0,maxt=0,hamle,khamle;
	printf("TAS TOPLAMA OYUNUNA HOSGELDINIZ... \n");
	printf("Kac tas kullanilacak?:");
	scanf("%d",&tt);
	printf("Her hamlede  kac tane tas toplanabilir?:");
	scanf("%d",&maxt);
	printf("Oyuna kim baslayacak (Bilgisayar (B) / Kullanici (K))?");
	while(1)
	{
		scanf(" %c",&secim);
		if(secim=='B' || secim=='K') break;
		else if(secim=='b' || secim=='k') break;
		else
		{
			printf("yanlis girdi !! Tekrar giriniz. \n");
		}
	}
	
	if(secim=='B' || secim=='b')
	{
		hamle=(tt-1)%(maxt+1);
		if(hamle==0)
		{
			hamle=1+rand()%maxt;
					printf("B: %d\n",hamle);
				tt-=hamle;
		}
		else
		{
			printf("B: %d\n",hamle);
			tt-=hamle;
		}
		
		while(1)
		{
			printf("K= ");
			scanf("%d",&khamle);
			while(1)
			{
				if(khamle==0) printf("En az 1 tas toplanmali. Tekrar girin.\n");
				else if(khamle>maxt) printf("Maksimum toplanabilecek sayiyi astiniz !! Tekrar girin.\n");
				else if((tt-khamle)<=0) printf(" Tekrar girin imkansiz hamle !!.\n");
				else break;
				printf("K= ");
				scanf("%d",&khamle);
			}
			tt-=khamle;
			if(tt==1)
			{
				printf("Oyun bitti. KULLANICI kazandi...");
				return 0;
			}
			
			hamle=(tt-1)%(maxt+1);
			if(hamle==0)
			{
				hamle=1+rand()%maxt;
					printf("B: %d\n",hamle);
				tt-=hamle;
				if(tt==1)
				{
					printf("Oyun bitti. BILGISAYAR kazandi...");
					return 0;
				}	
			}
			else
			{
				hamle=maxt+1-khamle;
				printf("B: %d\n",hamle);
				tt-=hamle;
				if(tt==1)
				{
					printf("Oyun bitti. BILGISAYAR kazandi...");
					return 0;
				}
			}		
		}
	}
	
	if(secim=='K' || secim=='k')
	{
		
		while(1)
		{
			printf("K: ");
			scanf("%d",&khamle);
			while(1)
			{
				if(khamle==0) printf("En az 1 tas toplanmali. Tekrar girin.\n");
				else if(khamle>maxt) printf("Maksimum toplanabilecek sayiyi astiniz !! Tekrar girin.\n");
				else if((tt-khamle)<=0) printf(" Tekrar girin imkansiz hamle olamaz !!.\n");
				else break;
				printf("K: ");
				scanf("%d",&khamle);
			}
			tt-=khamle;
			if(tt==1)
			{
				printf("Oyun bitti. KULLANICI kazandi... ");
				return 0;
			}
			
			hamle=(tt-1)%(maxt+1);
			if(hamle==0)
			{
				hamle=1+rand()%maxt;
					printf("B: %d\n",hamle);
				tt-=hamle;
				if(tt==1)
				{
					printf("Oyun bitti. BILGISAYAR kazandi...");
					return 0;
				}	
			}
			else
			{
				hamle=maxt+1-khamle;
				printf("B: %d\n",hamle);
				tt-=hamle;
				if(tt==1)
				{
					printf("Oyun bitti. BILGISAYAR kazandi...");
					return 0;
				}
			}
		
			
		}
	}
	
	system("pause"); 
	return 0;
}
