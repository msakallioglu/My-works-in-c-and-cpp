/* Melike Sakallioglu
			2016
			*/

#include <stdio.h>

int main() {	
    int secim; int karakter;
    printf("Lutfen metni giriniz----->");
	char kelime[100000]=" ";
	scanf("%[^\n]s",&kelime);
	printf("Sifrelemek icin-->1\nSifre cozmek icin-->2\nLutfen islem turunu seciniz");
	scanf("%d",&secim);
	if (secim==1)
	{
		printf("Kac karaktere gore sifrelensin");
		scanf("%d",&karakter);
		char c=kelime[0]; 
	    int i=0;
    	while(c!='\0')
    	{
		    if(c==32)
	     	{ 
		       printf(" ");
		    }
		    if(c>=65&&c<=90)
		    {
			   kelime[i]=(kelime[i]+karakter);
			   if(kelime[i]>90) kelime[i]= (kelime[i]%90)+64; 
	     	}
		    if(c>=97&&c<=122)
		    {
		     	kelime[i]=(kelime[i]+karakter);
                if(kelime[i]>122) kelime[i]= (kelime[i]%122)+96;
		    }
		   i++;
           c=kelime[i];
        }
        printf("%s",kelime);
    }
    else 
	{
		printf("Kac karaktere gore cozulsun");
		scanf("%d",&karakter);
	    char c=kelime[0];
	int i=0;
	while(c!='\0')
	{
		if(c==32)
		{ 
		   printf(" ");
		}
		if(c>=65&&c<=90)
		{
			kelime[i]=(kelime[i]-karakter);
			if(kelime[i]<65) kelime[i]= (91-(65%kelime[i]));
		}
		if(c>=97&&c<=122)
		{
			kelime[i]=(kelime[i]-karakter);
            if(kelime[i]<97) kelime[i]= (123-(97%kelime[i]));
		}
		i++;
        c=kelime[i];
    }

		printf("%s",kelime);
	}



  	return 0;
}
	


