//assigning a phone number to the user from the queue structure

#include<stdio.h>
#include<string.h>
#define SIZE 2000
#define SIZE_TEL 2000
#define SIZE_HUMAN 2000

int i=0;  
char temp[50];
int check=0;
 
typedef struct{
	int tel[SIZE_TEL];  
	int top;
 }stack_tel;
 stack_tel tel;
 
typedef struct{
 	char name[100]; 
 	char address[100];
 	char date[15];
 	int tel;  
 }stack_i;  
 stack_i x[SIZE_HUMAN];
 
typedef struct { 
 	char name[100]; 
 	char address[100];
 	char date[15];  
 } person_t ; 
 
typedef struct { 
 	int front, rear; 
 	person_t data[SIZE]; 
 }queue;
 
 queue initialize_q(queue q) { 
 	q.front = 0; 
 	q.rear = -1; 
 return q;
 }
 
 int is_empty_q(queue q) { 
 	if (q.front > q.rear) 
 		return 1; 
 	return 0; 
 }
 
 int is_full_q(queue q) { 
 	if (q.rear == SIZE - 1) 
 		return 1; 
 	return 0; 
 }
 
stack_tel initialize_s1(stack_tel s)  
{ 
    s.top = -1; 
	return s; 
}

int is_empty_s1(stack_tel s)  
{   
	if (s.top==-1)  
    	return 1;   
  return 0;  
}

int is_full_s1(stack_tel s)  
{   
	if(s.top == SIZE_TEL)     
		return 1;  
 	return 0;  
 } 

stack_tel push1(stack_tel s,int item)  
 {   
 
 	if (is_full_s1(s))
	 {
	 	printf("Error: Stack is full!\n"); 
	 	return s;
	}        
   	else     
	{     
   		(s.top)++;     
  		s.tel[s.top] = item;  
		  return s;
  	}  
} 
stack_tel pop1(stack_tel s)  
{    
	if (is_empty_s1(s))     
	{    
	 printf("Error: Stack is empty!\n");    
  	    
		return s;    
  	}    
	else    
   	{   
	   x[i].tel=s.tel[s.top];  
    	(s.top)--; 
		return s;    
	}            
	
}
 
queue insert(queue q,person_t item) { 
 	
	if (is_full_q(q)) 
	{
		printf("Error : Queue is full!\n"); 
		return q;
	}
 	else 
	{ 
		 q.rear = q.rear + 1; 
		 q.data[q.rear] = item; 
		 return q;
 	} 
 }
 
queue remove(queue q) { 
 
 	strcpy(x[i].name,q.data[q.front].name);
 	strcpy(x[i].address,q.data[q.front].address);
	strcpy(x[i].date,q.data[q.front].date);
 	q.front = q.front + 1; 	
 	return q;
 
 }

void moving()
{
	int j;
	int check;
	for(j=0;j<i;j++)
	{
		if(strcmp(x[j].name,temp)==0)
		{
			tel=push1(tel,x[j].tel);
			check=j;
		}	
	
	}
	int s;
	for(s=0;s<j;s++){	
		if(s>=check){
			strcpy(x[s].name,x[s+1].name);
			strcpy(x[s].address,x[s+1].address);
			strcpy(x[s].name,x[s+1].name);
 			x[s].tel=x[s+1].tel;
		}
	}	
	i--;
}
 
 int menu()
{
	int a;
	printf("\n\n");
	printf("\t ---------menu----------\n");
	printf("\t 1. Application Form \n");
	printf("\t 2. Give a number \n");
	printf("\t 3. Show the list \n");
	printf("\t 4. Moving \n");
	printf("\t 0. Exit\n");
	printf("\t Secim=...");
	scanf("%d",&a);
	return a;	
}
 
 int main()
 {
 	int choice; 
 	int telephonenumber;
 	tel.top=-1;
 	queue person;
 	person_t per;
 	person=initialize_q(person);
 	FILE*X=fopen("tel.txt","r");
 	while(feof(X)==0)
 	{
 		fscanf(X,"%d",&telephonenumber);
 		tel=push1(tel,telephonenumber);
	} 
 	do{
		choice=menu();
		switch(choice){	
			case 1:
				printf("---Application Form---\n");
				printf("Name:");
				scanf(" %[^\n]%*c",&per.name);
				printf("Address:");
				scanf(" %[^\n]%*c",&per.address);
				printf("Day.Mount.Year:");
				scanf("%s",per.date);
				person=insert(person,per);
			break;
			case 2:
				printf("---Give a number---\n");
				if (is_empty_q(person)) { 
 					printf("Error : Queue is empty!\n"); 
 				} 
				else
				{
					person=remove(person);
					tel=pop1(tel);
					printf("Telephone number is installed : %s\n",x[i].name);
					i++;
				}			
			break;
			case 3:
				printf("---Show the list---\n");
				int u;
				for(u=0;u<i;u++)
				{
					printf("Name: %s\n",x[u].name);
					printf("Address: %s\n",x[u].address);
					printf("Day Mount Year: %s\n",x[u].date);
					printf("Telephone %d \n",x[u].tel);
				}
			break;
			case 4:
				printf("---Moving---\n");
				printf("enter the name of the person to be moved: ");
				scanf(" %[^\n]%*c",temp);
				moving();
			break;
			case 0:
				printf("Exit!\n");
			break;
			default:
		    	printf("Wrong Choice !\n");
		    break;
		}	
	}while(choice!=0);
	fclose(X);			
	return 0;	 			
 }		
