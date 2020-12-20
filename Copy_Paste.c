/* system programming */

#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
   int  fd1,fd2,x,y;
   char str1[100];
   char str2[100];
   char Text[100];
   printf("Enter the filename to open for reading \n");
   scanf("%s",str1);
   printf("Enter the filename to open for writing... \n");
   scanf("%s",str2);   
   fd1=open(str1,O_RDONLY);                                                                                    
   if(fd1<0)
   {
        //printf("fd1=%d\n",fd1);
	perror(str1);
	exit(1);                                                                                                                                            perror(str1);                                                                              exit(1);
   }
   fd2=open(str2, O_CREAT || O_TRUNC || O_WRONLY || O_RDONLY);                                                                                       
   if(fd2<0)
   {
        //printf("fd2=%d\n",fd1);
	perror(str2);
	exit(1);                                                                                                                                               exit(1);
   } 
  y=lseek(fd1,0,SEEK_END); 
  lseek(fd1,0,SEEK_SET);   
  x=read(fd1,Text,y);
  write(fd2,Text,x);
  printf("Process successful");
}
