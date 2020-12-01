/* Melike Sakallioglu
			2016
			Turkish
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h> 
#include<cstdlib>
#include<iostream>

int  menu2()
{
	int secim2;
	printf("\n --------- M E N U --------- \n");
	printf(" 1 -  Kitap Arama\n");
	printf(" 2 -  Kitap Sira - Raf Güncelleme \n");
	printf(" 3 -  Kitap Silme \n");
	printf(" 4 -  Kitap ekleme \n");
	printf(" 5 -  Kitap kiralama \n");
	printf(" 0 -  Cikis \n");
	printf("Yapmak Istediginiz Islemi Seciniz =....");
	scanf("%d",&secim2);
	printf("\n\n\n");
	return secim2;
}

int  menu()
{
	int secim;
	printf("\n --------- M E N U --------- \n");
	printf(" 1 -  Personel Girisi\n");
	printf(" 2 -  Ogrenci Girisi \n");
	printf(" 0 -  Cikis \n");
	printf("Yapmak Istediginiz Islemi Seciniz =....");
	scanf("%d",&secim);
	printf("\n\n\n");
	return secim;
}

int  menu3()
{
	int secim3;
	printf("\n --------- Kitap Kiralama Durumu --------- \n");
	printf(" 1 -  Kitap Kiralama\n");
	printf(" 2 -  Kitap Iade \n");
	printf(" 0 -  Cikis \n");
	printf("Yapmak Istediginiz Islemi Seciniz =....");
	scanf("%d",&secim3);
	printf("\n\n\n");
	return secim3;
}
int  menu4()
{
	int secim4;
	printf("\n --------- Ogrenci --------- \n");
	printf(" 1 -  Kitap Arama\n");
	printf(" 0 -  Cikis \n");
	printf("Yapmak Istediginiz Islemi Seciniz =....");
	scanf("%d",&secim4);
	printf("\n\n\n");
	return secim4;
}
void arama()
{	
   system("CLS");
	FILE* D = fopen("kitap.txt", "r");
	char kitap[50],yad[20],ysoy[20];
	char kitapd[50],ad[20],soyad[20];
	char yayinevi[20];
	int raf,sira,tarih,kod;
	printf("Kitap aramak icin yazar ad-soyad veya kitap isminden birinin girilmesi yeterlidir.\n Bos birakmak icin 0 degerini giriniz \n\n");
	printf("Aranacak kitap ismi \n");
	scanf("%s",&kitap);
	printf("\n\n");
	printf("Yazar Ad-Soyad \n");
	scanf("%s %s",&yad,&ysoy);
	printf("\n\n");
	while(feof(D)==0)
	{
		fscanf(D,"%d %d %s %s %s %s %d %d",&raf,&sira,kitapd,ad,soyad,yayinevi,&tarih,&kod);
		if(strcmp(kitap,kitapd)==0 || strcmp(yad,ad)==0 || strcmp(ysoy,soyad) == 0)
		{
			printf("sira = %d\nraf = %d\nkitap adi = %s\nyazar adi = %s\nyazar soyad = %s\nyayinevi = %s\nbasim tarih = %d\nkitap kodu=%d\n\n\n",raf,sira,kitapd,ad,soyad,yayinevi,tarih,kod);
			break;
		}
	}
	fclose(D);
	return;
}
void guncelleme()
{
	FILE* D = fopen("kitap.txt", "r");
	FILE* D2 = fopen("yedek.txt","w");
	char kitap[50];
	char kitapd[50],ad[20],soyad[20];
	char yayinevi[20];
	int raf,sira,tarih,kod;
	int rafa,siraa;
	printf("Guncelemek istediginiz kitap ismini giriniz\n");
	
	scanf("%s",&kitap);
	printf("Sira numarasi=\n");
	scanf("%d",&siraa);
	printf("Raf sýrasi=\n");
	scanf("%d",&rafa);
	
	while(feof(D)==0)
	{
		fscanf(D,"%d %d %s %s %s %s %d %d ",&raf,&sira,kitapd,ad,soyad,yayinevi,&tarih,&kod);
		if(strcmp(kitap,kitapd)!=0)
		{	
			fprintf(D2,"%d %d %s %s %s %s %d %d\n",raf,sira,kitapd,ad,soyad,yayinevi,tarih,kod);
			
		}
		else 
			fprintf(D2,"%d %d %s %s %s %s %d %d\n",rafa,siraa,kitapd,ad,soyad,yayinevi,tarih,kod);
		
	}
	
	printf("Guncelleme yapýldý.");
	
	fclose(D);
	fclose(D2);
	remove("kitap.txt");
	rename("yedek.txt", "kitap.txt");
	
	return;
	
}

void silme()
{
	FILE* D = fopen("kitap.txt", "r");
	FILE* D2 = fopen("yedek.txt","w");
	char kitap[50];
	char kitapd[50],ad[20],soyad[20];
	char yayinevi[20];
	int raf,sira,tarih,kod;
	
	printf("Silinecek kitap ismini giriniz\n");
	scanf("%s",&kitap);
	
	while(feof(D)==0)
	{
		fscanf(D,"%d %d %s %s %s %s %d %d ",&raf,&sira,kitapd,ad,soyad,yayinevi,&tarih,&kod);
		if(strcmp(kitap,kitapd)!=0)
			fprintf(D2,"%d %d %s %s %s %s %d %d\n",raf,sira,kitapd,ad,soyad,yayinevi,tarih,kod);
		
	}
	printf("Kitap silindi.");
	
	fclose(D);
	fclose(D2);
	remove("kitap.txt");
	rename("yedek.txt", "kitap.txt");
	
	return;
}


void alma()
{
	FILE* D = fopen("kitap.txt", "r");
	FILE* D2 = fopen("kiralama.txt","a");
	int kodd,gun,ay,yil,no;
	char kitapd[50],ad[20],soyad[20];
	char yayinevi[20];
	int raf,sira,tarih,kod;
	char ad1[20],soyad1[20];
	
	printf("kiralanacak kitap kodunu giriniz \n ");
	scanf("%d",&kodd);
	
	printf("kiralanacak ogrenci ad-soyad \n ");
	scanf("%s",&ad1);
	scanf("%s",&soyad1);
	printf("kiralanacak ogrenci NO \n ");
	scanf("%d",&no);
	printf("Gün = ");
	scanf("%d",&gun);
	printf("\nay = ");
	scanf("%d",&ay);
	printf("\nyil = ");
	scanf("%d",&yil);
	
	while(feof(D)==0)
	{
		fscanf(D,"%d %d %s %s %s %s %d %d",&raf,&sira,kitapd,ad,soyad,yayinevi,&tarih,&kod);
		if(kod==kodd)
		{
			break;
		}
			
	}
	fprintf(D2,"%d %s %d %s %s %d %d %d",kod,kitapd,no,ad1,soyad1,gun,ay,yil);
	printf("Kitap kiralandi.");
	fclose(D);
	fclose(D2);
	
	
	return;
}
	
void teslim()
{
	FILE* D = fopen("kiralama.txt", "r");
	FILE* D2 = fopen("yedek.txt","w");
	int kodd;
	int kod,gun2,ay2,yil2,no;
	int gun1,ay1,yil1;
	int gun,ay,yil;
	double ceza;
	char ad[20],soyad[20],kitapd[50];
	
	printf("Teslim edilecek kitap kodunu giriniz= ");
	scanf("%d",&kodd);
	
	printf("Teslim edildiði tarih= ");
	printf("\nGün = ");
	scanf("%d",&gun1);
	printf("\nay = ");
	scanf("%d",&ay1);
	printf("\nyil = ");
	scanf("%d",&yil1);
	
	while(feof(D)==0)
	{
		fscanf(D,"\n %d %s %d %s %s %d %d %d\n",&kod,kitapd,&no,ad,soyad,&gun2,&ay2,&yil2);
		if(kod==kodd)
		{
		    if (gun1<gun2)
    		{
        		ay1=ay1-1;
        		gun1=gun1+30;
    		}
        	if (ay1<ay2)
    		{
        		yil1=yil1-1;
        		ay1=ay1+12;
    		}
   		 	gun=gun1-gun2; 
			ay=ay1-ay2; 
			yil=yil1-yil2;
			if(gun>15 && ay==0)
			{
				gun-=15;
				ceza=gun*0.5;
				printf("geciken gun= %d - ceza= %.2f\n",gun,ceza);
			}
			else if(gun>15 && ay>0)
			{
				gun-=15;
				ceza=(gun*0.5)+(ay*15);
				printf("geciken gun= %d, geciken ay = %d - ceza= %.2f\n",gun,ay,ceza);
			}
    		else 
    			printf("ceza durumu yok.");
		}
		else
		{
			fprintf(D2,"%d %s %d %s %s %d %d %d\n",kod,kitapd,no,ad,soyad,gun2,ay2,yil2);
		}
		
	}
	
	fclose(D);
	fclose(D2);
	remove("kiralama.txt");
	rename("yedek.txt", "kiralama.txt");
	return;	
}
void kiralama()
{
	int secim3;
	do{	
		secim3=menu3();
	switch(secim3)
     {
		case 1:
			printf("Kitap Kiralama.. \n");
			alma();
			break;
		case 2: 
			printf("kitap teslim ... \n\n");
			teslim();
		    break;
		case 0:
			printf("cikis yapildi hoscakalin..\n \n");
			printf("\n \n");
			break;
		default:
			printf("hatali giris... \n\n");
		}
}while(secim3!=0);
	return;
}

void ekleme()
{
	FILE* D = fopen("kitap.txt", "a");;

	char kitap[50],ad[20],soyad[20];
	char yayinevi[20];
	int raf,sira,tarih,kod;
	
	printf("Eklenecek kitap ismi");
	scanf("%s",&kitap);
	printf("\nYazar AD= ");
	scanf("%s",&ad);
	printf("\nYazar SOYAD= ");
	scanf("%s",&soyad);
	printf("\nYayýnevi= ");
	scanf("%s",&yayinevi);
	printf("\nBasim Tarihi= ");
	scanf("%d",&tarih);
	printf("\nSira numarasi= ");
	scanf("%d",&sira);
	printf("\nRaf sirasi= ");
	scanf("%d",&raf);
	printf("\n Kod= ");
	scanf("%d",&kod);
	
	fprintf(D,"%d %d %s %s %s %s %d %d\n",raf,sira,kitap,ad,soyad,yayinevi,tarih,kod);
	printf("Kitap eklendi.");
	fclose(D);
	return;
}

void personelgiris()
{
	FILE* dosya = fopen("personel.txt","r");
	char isim[20],soyisim[20];
	int tc,sifre,tcno,sifred;
	int sayac=0;
	int basamak;
	
	printf("T.C kimlik numaranizi giriniz = ");
	scanf("%d",&tc);
	
		while(feof(dosya)==0)
		{
			fscanf(dosya,"%d %s %s %d",&tcno,isim,soyisim,&sifred);
			if(tc==tcno)
			{
				sayac=1;
				break;
			}
		}
		system("CLS");
		if(sayac==1)
		{
			printf("Hosgeldiniz %s %s \n",isim,soyisim);
				printf("Lutfen Sifre Giriniz=\n");
				scanf("%d",&sifre);
				if(sifre==sifred)
				{
					printf("Sifre Dogru");
					system("CLS");
					int secim2;
			    	do{	
		                secim2=menu2();
	                      switch(secim2)
                         {
		                    case 1:
						    printf("Kitap Arama.. \n");
						    arama();
						    break;
						    case 2:
						    printf("Kitap Guncelleme.. \n");
						    guncelleme();
						    break;
						    case 3:
						    printf("Kitap Silme.. \n");
						    silme();
						    break;
						    case 4:
						    printf("Kitap ekleme.. \n");
						    ekleme();
						    break;
						    case 5:
						    printf("Kitap kiralama.. \n");
						    kiralama();
						    break;
		                    case 0:
			                printf("cikis yapildi hoscakalin..\n \n");
							printf("\n \n");
							break;
							default:
			                printf("hatali giris... \n\n");
			                
		                }
                   }while(secim2!=0);	      
					
				} 
				else
				{
					printf("Sifre yanlis.");
					return;
				}
		}
		else
		{
			printf("Kisi Bulunamadi. \n");
			return;	
		}
		
		fclose(dosya);	
}

void ogrencigiris()
{
	int secim4;
	do{	
        secim4=menu4();
	    switch(secim4)
        {
		case 1:
		printf("Kitap Arama.. \n");
		arama();
		break;
		case 0:
		printf("cikis yapildi hoscakalin..\n \n");
		printf("\n \n");
		break;
		default:
		printf("hatali giris... \n\n");
		}
	}while(secim4!=0);	      
					
}
		


int main()
{
	
	int secim;
	do{	
		secim=menu();
	switch(secim)
     {
		case 1:
			printf("Personel Girisi.. \n");
			personelgiris();
			break;
		case 2: 
			printf("Ogrenci Girisi ... \n\n");
			ogrencigiris();
		    break;
		case 0:
			printf("cikis yapildi hoscakalin..\n \n");
			printf("\n \n");
			break;
		default:
			printf("hatali giris... \n\n");
		}
}while(secim!=0);
		
return 0;
}
