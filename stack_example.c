#include<stdio.h>
#define SIZE 50 //YOU CAN CHANGE VALUE OF SIZE

typedef struct{
	int stack[SIZE];
	int top1;
	int top2;
}doublestack;

int item; 
doublestack initialize_s1(doublestack s)  
{ 
    s.top1 = -1; 
	return s; 
}

 doublestack initialize_s2(doublestack s)  
{ 
    s.top2 = SIZE;  
    return s;
}

int is_empty_s1(doublestack s)  
{   
if (s.top1==-1)  
    return 1;   
 
  return 0;  
}
int is_empty_s2(doublestack s)  
{
   
if (s.top2==SIZE)  
    return 1;   
 
  return 0;  
}   

int is_full_s1(doublestack s)  
{   
	if(s.top1+1 == s.top2)     
	return 1;  
 	return 0;  
 } 
 
 int is_full_s2(doublestack s)  
{   
	if(s.top2 == s.top1+1)     
	return 1;  
 	return 0;  
 } 
 
 
doublestack push1(doublestack s, int item)  
 {   
 
 	if (is_full_s1(s))
	 {
	 	printf("Error: Stack is full!\n"); 
	 	return s;
		  }     
 		   
   	else     
	{     
   		(s.top1)++;     
  		s.stack[s.top1] = item;  
		  return s;
  	}  
} 

doublestack push2(doublestack s, int item)  
 {   
 
 	if (is_full_s2(s))
	{
	 	printf("Error: Stack is full!\n"); 
	 	return s;
	}     
 		   
   	else     
	{     
   		(s.top2)--;     
  		s.stack[s.top2] = item;  
		  return s;
  	}  
  
} 

doublestack pop1(doublestack s)  
{    
	if (is_empty_s1(s))     
	{      
  	 item = 999;   
		return s;    
  	}    
	else    
   	{      
	   item = s.stack[s.top1];   
    	(s.top1)--;  
		return s;    
	}            
	
}

doublestack pop2(doublestack s)  
{      
	if (is_empty_s2(s))     
	{    
  	 item = 999;   
		return s;    
  	}    
	else    
   	{      
	   item = s.stack[s.top2];  
	      
    	(s.top2)++; 
	  
		return s;    
	}            
}

int menu()
{
	int a;
	printf("\n\n");
	printf("\t ---------menu----------\n");
	printf("\t 1. Stack1 push\n");
	printf("\t 2. Stack2 push\n");
	printf("\t 3. Stack1 pop\n");
	printf("\t 4. Stack2 pop\n");
	printf("\t 0. Exit\n");
	printf("\t choice=...");
	scanf("%d",&a);
	return a;	
}

int main()
{
	doublestack data;
	data=initialize_s1(data);
	data=initialize_s2(data);
	int number;
	int choice;
	do{
		choice=menu();
		switch(choice){	
			case 1:
				printf("---Stack1 push---\n");
				scanf("%d",&number);
				data=push1(data,number);
			break;
			case 2:
				printf("---Stack2 push---\n");
				scanf("%d",&number);
				data=push2(data,number);
			break;	
			case 3:
				printf("---Stack1 pop---\n");
				data=pop1(data);
				if(item==999)
					printf("stack1 empty");
				else
					printf("%d\n",item);
			break;	
			case 4:
				printf("---Stack2 pop---\n");
				data=pop2(data);
				if(item==999)
					printf("stack2 empty");
				else
					printf("%d\n",item);
			break;
			case 0:
				printf("EXIT !!!");
			break;
			default:
		    printf("WRONG CHOICE");
		    break;
		}	
	}while(choice!=0);

	return 0;
	
}
