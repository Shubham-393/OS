#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


void sort(int arr[], int n )
{
	for(int i= 0; i<n ; i++)
	{
	 	for(int j=0; j<n-i-1; j++)
	 	 	{
	 	 		if(arr[j]>arr[j+1])
	 	 		{int temp = arr[j];
	 	 		arr[j]= arr[j+1];
	 	 		arr[j+1]=temp;}
	 	 		
	 	 	}
	}  
}
/*
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, 
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
*/
int main()
{	
	int n;
	printf("Enter no. of elements: ");
	scanf("%d", &n);
    	
    	int arr[n] ;
	printf("Entr elements: ");
	
	for(int i=0;i<n;i++)
	{  scanf("%d",&arr[i]); }
	
	pid_t pid = fork();
	
	if (pid < 0){printf("Fork failed");}
	
	else if (pid == 0 ) {
	//child process
	printf("Child sorting....");
	sort(arr, n);
	for(int i=0;i<n;i++)
	{  printf("%d",arr[i]); }
	
	}
	else
	{
		//parent
		//child process
	printf("parent sorting....");
	sort(arr, n);
	for(int i=0;i<n;i++)
	{  printf("%d",arr[i]); }
	//sleep(5);
	
	wait(NULL);
	exit(0);
		
	}
	

}

