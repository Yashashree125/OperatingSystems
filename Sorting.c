/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t child_pid;
   
   int arr[] = {4, 2, 0, 7, 1}; 
   int  temp;
    child_pid=fork();
    if( child_pid ==0)
    {
        
         int length = sizeof(arr)/sizeof(arr[0]);    
        for (int i = 0; i < length; i++) 
    {     
        for (int j = i+1; j < length; j++) 
        {     
           if(arr[i] < arr[j]) 
           {    
               temp = arr[i];    
               arr[i] = arr[j];    
               arr[j] = temp;    
           }     
        }     
    }    
        
    printf("\nChild Process Elements :  Descending Order\n");   
     for (int i = 0; i < length; i++) 
     {     
        printf("%d ", arr[i]);    
    } 
    printf(" \n");
    printf(" \nChild Process ID  %d",getpid());
    printf(" \nParent Process ID  %d",getppid());
    printf(" \n");
    system("ps");
    
        
}

    else
    {
        sleep(1);
       
       int length = sizeof(arr)/sizeof(arr[0]);    
        for (int i = 0; i < length; i++) 
        {     
        for (int j = i+1; j < length; j++) 
        {     
           if(arr[i] > arr[j]) {    
               temp = arr[i];    
               arr[i] = arr[j];    
               arr[j] = temp;    
           }     
        }     
    } 
    printf("\nParent Process Elements :  Ascending Order \n");   
     for (int i = 0; i < length; i++) 
     {     
        printf("%d ", arr[i]);    
     }   
     printf(" \n");
        
      printf(" \nParent Process ID  %d",getpid());
      printf(" \nChild Process ID  %d",child_pid);
      printf(" \nParent Process ID  %d",getppid());
      printf(" \n");
      system("ps");
      
      

        
        
    }
    
    return 0;
}
