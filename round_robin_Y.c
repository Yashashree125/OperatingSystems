	#include<stdio.h>
	int n,tq,time = 0;
	int queue[100]={0},front = 0, rear = 0, a[100];
	int i,j;

	void sort();
	void RoundRobin();
	int select(int t);
	void push(int q);
	int pop();
	
	struct data
	{
	  	int arrival_time , service_time, burst_time ,  wt ,  tat, completion_time; 
	}t;
	
	void sort( struct  data a[])
	{
	 	int i,j;
	 	for(i=0;i<n;i++)
	 {
	 	for(j=0;j<n-i-1;j++)
		 {
	  		if(a[j].arrival_time>a[j+1].arrival_time)
	 		 {
	  			 t=a[j];
	  			 a[j]=a[j+1];
	  			 a[j+1]=t;
	  		}
		 }
	 }
	}

	/*void sort_burstt_ime( struct  data a[])
	{
	 	int i,j;
	 	for(i=0;i<n;i++)
	 {
	 	for(j=0;j<n-i-1;j++)
		 {
	  		if(a[j].burst_time>a[j+1].burst_time)
	 		 {
	  			 t=a[j];
	  			 a[j]=a[j+1];
	  			 a[j+1]=t;
	  		}
		 }
	 }
	}*/

	int select(int j)
	{
	 	if(time == 0)
	 {
	      return j;
	 }
	 else
	 {
	    	j=pop();
	    	return j;
	 	}
	}
		int pop()
	{
		    int x;
		    x = queue[front++];
		    return x;
	}
	void push(int q)
	{
		  queue[rear++]=q;
	}
	
	
	
	
	void RoundRobin(struct data a[])
	
	{
	
		 int i=1,j=0,x;
	 	 x=n;
	 	while(x!=0)
	 {
	  		j=select(j);
	  		if( a[j].burst_time<=tq && a[j].burst_time>0)
	  	{
	   		time = time + a[j].burst_time;
	  		a[j].burst_time = 0;
	  }
	  		else if(a[j].burst_time > 0)
	  {
	   			a[j].burst_time = a[j].burst_time - tq;
	   			time = time + tq;  //timeline
	  }
		 while( a[i].arrival_time<=time && i<n )
		  {
			      push(i);
					//sort(a);
			       i++;
		  }
		 if(a[j].burst_time == 0)
	  {
		   	x--;
		   	a[j].completion_time = time;                
		   	a[j].wt = time - a[j].arrival_time - a[j].service_time;
		   	a[j].tat= a[j].wt+a[j].service_time;
	  }
		        else
		        {
		           	push(j);
					  // sort(a);
		        }
	 }
	}

	
	int main()
	{
	 	int i;
	 	float avg_WT=0,avg_TAT=0;
	 	printf("Enter the no of processes :   ");
	 	scanf("%d",&n);
	 	struct data P[n];
	 		for(i=0;i<n;i++)
		 {
			   printf("Enter the process p[%d]'s arival time and Burst time :  ",i+1);
			   scanf("%d%d",&P[i].arrival_time,&P[i].burst_time);
			   P[i].service_time=P[i].burst_time;
		 }
			 printf("Enter time_quantum :  ");
			 scanf("%d",&tq);
			 sort( P );
			 RoundRobin(P);

	printf("\n     ProcessID     ArrivalTime     BurstTime     WaitingTime     TurnAroundTime     Completion");
	for(i=0;i<n;i++)
	{
		 printf("\n|\tp[%d]\t|\t%d\t|\t%d \t|\t%d\t|\t%d\t|\t%d\t|",i+1,P[i].arrival_time,P[i].service_time,P[i].wt,P[i].tat,P[i].completion_time);
		avg_WT+=P[i].wt;
		avg_TAT+=P[i].tat;
	}
	printf("\n Average waiting_time:%f \n Average turn_around_time :%f",avg_WT/n,avg_TAT/n);
	
	return 0;
	}
	
