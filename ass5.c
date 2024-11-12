//Bamkers Algo to avoid deadlock
#include <stdio.h>
#include <stdlib.h>

int n = 5, m = 3; // Number of processes and resources
int allocation[5][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
int max[5][3] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
int available[3] = {3, 3, 2};
int work[10], finish[10];
int  need[10][10];

void cal_need(){
//calculate need , need = max - allocation
for(int i =0; i<n ; i++)

{
    for(int j=0 ; j<m ; j++ )
	need[i][j] = max[i][j] - allocation[i][j];
}
}

int isSafe(){

int safe_seq[n];
for(int i=0; i<n ; i++) finish[i] =0 ;
for(int i=0; i<m ; i++) work[i] =available[i] ;
int count=0;
int found;
while(count<n)
   {	
   	found = 0;
	for(int i=0; i< n ;i++)
	{
		if(finish[i] == 0)  //check need>available
		{
		   int j;
		   for(j=0;j<m;j++)
		   {
		       if(need[i][j] > work[j]) break ;
		        
		   }
		   if (j== m)  //process found, do process
		   { 	
		   	safe_seq[count] = i ;
		   	found =1;
		   	count++;  
		   	finish[i]=1; 
		   	for(int k=0;k<m;k++) work[k] += allocation[i][k];//work = work + allocation
		   	   
		   }
		   
		}
	}

  // }
   
  if (found == 0) {
            printf("\nDeadlock detected, system is not safe!\n");
            return 0;
        }
    }
    
    printf("\nSafe sequence is: ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", safe_seq[i]);
    }
    printf("\n");
    
    return 1;
}   



int main() {
    printf("Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) printf("%d ", allocation[i][j]);
        printf("\n");
    }

    printf("\nMax Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) printf("%d ", max[i][j]);
        printf("\n");
    }

    printf("\nAvailable Resources:\n");
    for (int i = 0; i < m; i++) printf("%d ", available[i]);
    printf("\n");

    cal_need();
    isSafe();

    return 0;
}



  





