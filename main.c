#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
/*
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

int main()
{	
	int n;
	printf("Enter no. of elements: ");
	scanf("%d", &n);
    	
    	int arr[n] ;
	printf("Entr elements: ");
	
	for(int i=0;i<n;i++)
	{  scanf("%d",&arr[i]); }
	
	sort(arr, n);
	printf("\nBefor execve : \n");
	for(int i=0;i<n;i++)
	{  
	
	printf("%d ",arr[i]); }
		
	pid_t pid = fork();
	
	if (pid < 0){printf("Fork failed");}
	
	else if (pid == 0 ) {
	//child process
	char *args[n+2];
	args[0]="./reverse";
	
	//int to string
	for(int i=0 ; i<n+1 ; i++)
	{
		static char buffer[12];
		snprintf(buffer, sizeof(buffer), "%d",arr[i]);
		args[i + 1]=buffer;
	}
	args[n+1]=NULL;
		
	execve("./reverse",args,NULL); //imp
	
	}
	else{//parent
	    wait(NULL);
	    }
	
}
*/

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, n);

    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        char *args[n + 2];
        args[0] = "./reverse";  // The child executable name

        // Convert each integer to a string and assign to args
        for (int i = 0; i < n; i++) {
            static char buffer[12];
            snprintf(buffer, sizeof(buffer), "%d", arr[i]);
            args[i + 1] = buffer;
        }
        
        args[n + 1] = NULL;

        execve("./reverse", args, NULL);
        perror("execve failed");
        exit(1);
    } else if (pid > 0) {
        // Parent process waits for the child to complete
        wait(NULL);
    } else {
        perror("fork failed");
    }

    return 0;
}

