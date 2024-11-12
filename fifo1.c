#include <stdio.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
//IPC using FIFO pipe
//sender process
#define PIPE1 "pipe1"
#define PIPE2 "pipe2"
#define SIZE 100

int main()
{
	printf("\n---------------------First Process-------------------------\n"); 
	//create 2 fifo pipe files
	mkfifo(PIPE1, 0666);
	mkfifo(PIPE2, 0666);
	
	//Take input 
	char str1[SIZE], str2[SIZE];
	printf("Enter sentence : ");
	fgets(str1,SIZE,stdin);
	
	// write to  pipe1 file
	int fd1 = open(PIPE1, O_WRONLY);
	write(fd1, str1, strlen(str1)+1 );
	
	//Read from pipe2 file ( response from second process.)
	printf("\nRead from pipe2 file ( response from second process.)\n ");
	int fd2 = open(PIPE2, O_RDONLY);
	read(fd2, str2, SIZE );
	printf(" %s", str2);
	close(fd2);




return 0;
}

