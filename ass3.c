
#include <stdio.h>
#include <stdlib.h>


struct Process{
int at;
int bt;
};

void rr(Process p[], int n, int tq)
{
	int rt[n];
	int total_wt=0, total_tat=0, complete =0, time =0;
	
	//initialize remaining times
	for(int i=0 ; i<n ; i++ )
	{
		rt[i] = p[i].bt;
	}
	
	while(complete < n)   //Till All process completed
	{
		for(int i=0 ; i<n ;i++ )  //loop all process at each 'time'
		{
		    if(rt[i] > 0 && p[i].at <= time )   //process arrived ? and remaining time >0 
		     {	if( rt[i] > tq  )
			{
				//processing 
				time = time + tq ;
				rt[i] -= tq ;
			}
			else
			{
				//terminating that process
				time = time +rt[i];
				rt[i] = 0;
				
				int tat = time - p[i].at   ;      // tat= ct - at
				int wt = tat - p[i].bt;  //wt = tat -bt
				printf(" \n Process No : %d , TAT : %d , WT : %d \n ", i ,tat, wt);
				total_wt += wt;
				total_tat += tat;
				complete++;  //imp
				
			}
			
			
		     }
		
		}	
	}
	
	//Now all process completes
	printf("\n Avg TAT : %d ,\n Avg WT : %d \n", total_tat/3 , total_wt/3 );	
	

}


void sjf(Process p[], int n)
{
	int rt[n];
	float total_wt=0, total_tat=0;
	int complete =0, time =0;
	
	//initialize remaining times
	for(int i=0 ; i<n ; i++ )
	{
		rt[i] = p[i].bt;
	}
	
	while(complete < n)   //Till All process completed
	{
		int shortest=-1 ; //index  Shortest process
		int min_rt = 9999; //
		
		for(int i=0 ; i<n ;i++ )  //loop all process at each 'time'
		{
		    if(rt[i] > 0 && p[i].at <= time )   //process arrived ? and remaining time >0 
		     {	if( rt[i] < min_rt )          //Finding process of shortest remaining time
			{
				min_rt = rt[i];
				shortest = i;
			}			
		     }		     	
		}
		
		//We got shortest of all process
		//processingPremptive , so 1 sec
		time++;
		rt[shortest]--;
		
		//checking if process should be terminated
		if(rt[shortest] == 0 )
		{
			int tat = time - p[shortest].at   ;      // tat= ct - at
			int wt = tat - p[shortest].bt;  //wt = tat -bt
			printf(" \n Process No : %d , TAT : %d , WT : %d \n ", shortest ,tat, wt);
			total_wt += wt;
			total_tat += tat;
			complete++;  //imp
		}
			
	}
	
	//Now all process completes
	printf("\n Avg TAT : %f ,\n Avg WT : %f \n", total_tat/3 , total_wt/3 );	
	

}

int main()
{

Process p[] = {{0, 10 }, {1,5 } , {2, 8 } };

printf("\n -----------Round Robin------------\n ");

rr(p , 3 , 3 );
printf("\n -----------SJF------------\n ");

sjf(p,3);
return 0;

}



