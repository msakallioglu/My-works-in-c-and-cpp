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
	printf("Welcome to the Stone Collecting Game... \n");
	printf("How many stones will be used??:");
	scanf("%d",&tt);
	printf("How many stones can be collected in each move?:");
	scanf("%d",&maxt);
	printf("Who will start the game (Computer (C) / User (U))?");
	while(1)
	{
		scanf(" %c",&secim);
		if(secim=='C' || secim=='U') break;
		else if(secim=='c' || secim=='u') break;
		else
		{
			printf("entered wrong !! Re-enter. \n");
		}
	}
	
	if(secim=='C' || secim=='c')
	{
		hamle=(tt-1)%(maxt+1);
		if(hamle==0)
		{
			hamle=1+rand()%maxt;
					printf("C: %d\n",hamle);
				tt-=hamle;
		}
		else
		{
			printf("C: %d\n",hamle);
			tt-=hamle;
		}
		
		while(1)
		{
			printf("U= ");
			scanf("%d",&khamle);
			while(1)
			{
				if(khamle==0) printf("At least 1 stone should be collected. Enter again. \n");
				else if(khamle>maxt) printf("You have exceeded the maximum sumable number !! Re-enter.\n");
				else if((tt-khamle)<=0) printf(" Re-enter  -  impossible move !!.\n");
				else break;
				printf("U= ");
				scanf("%d",&khamle);
			}
			tt-=khamle;
			if(tt==1)
			{
				printf("Game over. USER wins...");
				return 0;
			}
			
			hamle=(tt-1)%(maxt+1);
			if(hamle==0)
			{
				hamle=1+rand()%maxt;
					printf("C: %d\n",hamle);
				tt-=hamle;
				if(tt==1)
				{
					printf("Game over. Computer won...");
					return 0;
				}	
			}
			else
			{
				hamle=maxt+1-khamle;
				printf("C: %d\n",hamle);
				tt-=hamle;
				if(tt==1)
				{
					printf("Game Over. Computer won...");
					return 0;
				}
			}		
		}
	}
	
	if(secim=='U' || secim=='u')
	{
		
		while(1)
		{
			printf("U: ");
			scanf("%d",&khamle);
			while(1)
			{
				if(khamle==0) printf("At least 1 stone should be collected. Enter again.\n");
				else if(khamle>maxt) printf("You have exceeded the maximum sumable number !! Re-enter.\n");
				else if((tt-khamle)<=0) printf(" Re-enter  -  impossible move !!.\n");
				else break;
				printf("u: ");
				scanf("%d",&khamle);
			}
			tt-=khamle;
			if(tt==1)
			{
				printf("Game Over. USER won... ");
				return 0;
			}
			
			hamle=(tt-1)%(maxt+1);
			if(hamle==0)
			{
				hamle=1+rand()%maxt;
					printf("C: %d\n",hamle);
				tt-=hamle;
				if(tt==1)
				{
					printf("Game Over. Computer won...");
					return 0;
				}	
			}
			else
			{
				hamle=maxt+1-khamle;
				printf("C: %d\n",hamle);
				tt-=hamle;
				if(tt==1)
				{
					printf("Game Over. Computer won...");
					return 0;
				}
			}
		
			
		}
	}
	
	system("pause"); 
	return 0;
}
