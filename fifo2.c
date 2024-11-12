#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

//IPC using FIFO pipe
//Reciever process
#define PIPE1 "pipe1"
#define PIPE2 "pipe2"
#define SIZE 100

int main()
{
	printf("\n---------------------Second Process-------------------------\n"); 	
	
	char str1[SIZE], str2[SIZE];
		
	// Read  from pipe1 file
	int fd1 = open(PIPE1, O_RDONLY);
	read(fd1, str1, SIZE );
	printf("Sentence is : %s", str1);
	close(fd1);
	
	//counting words, lines,charcters
	int i =0, l=0, w=1,c=0;
	while(str1[i] != '\0' )
	{
		if (str1[i]=='.' || str1[i]=='\n') l++;
		else if (str1[i]==' ') w++;
		else c++;
		i++;		
	}
	
	printf("Total lines: %d ; Total words: %d ; Total charctrs : %d \n",l,w,c);
	snprintf(str2,SIZE,"Total lines: %d ; Total words: %d ; Total charctrs : %d \n",l,w,c) ;
	
	//Write to pipe2
	int fd2 = open(PIPE2, O_WRONLY);
	write(fd2, str2, strlen(str2)+1);
	close(fd2);
	
	//save to txt file
	FILE *file = fopen("output.txt", "w");
        fprintf(file, "%s", str2);
        fclose(file);
        printf("String saved to output.txt\n");
	

return 0;
}

