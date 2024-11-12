#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

//writer process
int main(){

// key id for shard mem segment

key_t key =  ftok("shmfile", 64 );

// creating shared mem seg using key

int shmid = shmget(key, 1024, 0666 | IPC_CREAT );

//Attaching shared memory to process

char *str = shmat(shmid, NULL, 0);

//writing to shared memory
printf("[SERVER] Enter message : ");
gets(str);

//Detaching shared memory from current process
shmdt(str);

return 0;
}
