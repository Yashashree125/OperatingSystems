#include <stdio.h>
#include <stdlib.h>
#define LOW 0
#define HIGH 199

int queue[100] , queue2[100], q_size, head, seek =0, diff, temp, sum, max, dloc;
float avg;



void getdata()
{
    printf("%s\n", "Enter the size of the queue");
    scanf("%d", &q_size);

    printf("%s\n", "Enter queue elements");
    for(int i=1; i<=q_size; i++)
    {
        scanf("%d",&queue[i]);
    }

    printf("%s\n","Enter initial head position");
    scanf("%d", &head);

}

void FCFS()
{
    queue[0]=head;
    //printf("\nFrom\t\tTo\n");
    for(int j=0; j<=q_size-1; j++)
    {
        diff = abs(queue[j]-queue[j+1]);
        seek += diff;
        
        //printf("\n%d\t\t%d\t\t\n",queue[j],queue[j+1]);
        printf("%d --> %d\n",queue[j],queue[j+1]);
  }

    printf("\nTotal seek time is %d\t",seek);
    avg = seek/(float)q_size;
    printf("\nAverage seek time is %f\t", avg);
    printf("\n");


}

void SSTF()
{
    for(int i=0; i<q_size; i++)
    {
        queue2[i] = abs(head-queue[i]);
    }

  
  for(int i=0; i<q_size; i++)
  {
      for(int j=i+1; j<q_size;j++)
      {

        if(queue2[i]>queue2[j])
        {
            temp = queue2[i];
            queue2[i]=queue[j];
            queue2[j]=temp;

            temp=queue[i];
            queue[i]=queue[j];
            queue[j]=temp;
        }
    }

  }

  for(int i=1; i<q_size; i++)
  {
    seek = seek+abs(head-queue[i]);
    head = queue[i];
  }

  printf("\nTotal seek time is %d\t",seek);
  avg = seek/(float)q_size;
  printf("\nAverage seek time is %f\t", avg);

}

void SCAN()
{
  
    queue[q_size] = head; //add RW head into queue
  q_size++;

  //sort the array
  for(int i=0; i<q_size;i++){
    for(int j=i; j<q_size; j++){
      if(queue[i]>queue[j]){
        temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
      }
    }
  }

  max = queue[q_size-1];

  //locate head in the queue
  for(int i=0; i<q_size; i++){
    if(head == queue[i]){
      dloc = i;
      break;
    }
  }

  if(abs(head-LOW) <= abs(head-HIGH))
  {

      for(int j=dloc; j>=0; j--)
      {
        printf("%d --> ",queue[j]);
      }
      for(int j=dloc+1; j<q_size; j++)
      {
        printf("%d --> ",queue[j]);
      }

      } else 
      {

      for(int j=dloc+1; j<q_size; j++)
      {
          printf("%d --> ",queue[j]);
      }
      for(int j=dloc; j>=0; j--){
          printf("%d --> ",queue[j]);
      }

  }




  //sum  = head + max;
  //printf("\nmovement of total cylinders %d", sum);

}

int main()
{
    int choice;
    while(1)
    {
        printf("\n1.Enter data\n2.FCFS\n3.SSTF\n4.SCAN\n5.Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                getdata();

            break;

            case 2:
                FCFS();

            break;

            case 3:
                SSTF();

            break;

            case 4:
                SCAN();

            break;

            case 5:
                exit(0);
          
            
        default:
                printf("Wrong Choice !!!");
            

        }
    }


    return 0;
}