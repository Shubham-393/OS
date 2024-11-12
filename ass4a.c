#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
//Producer consumer problem
//counter accessed exclusively 

#define size 5
pthread_mutex_t mutex;
sem_t empty, full;
int counter=0 ;
int buffer[size] ;
int n1, n2;
void *producer(void *arg)
{
	int f=*((int *)arg);
	
	sem_wait(&empty); //wait for empty slots, if not
	pthread_mutex_lock(&mutex);
	
	buffer[counter] = rand()%10 ; //item produced
	printf("Producer %d produced item : %d \n",f, buffer[counter] );
	counter++;
	
	pthread_mutex_unlock(&mutex) ;
	sem_post(&full); //full ++
	pthread_exit(0);	
	return NULL;
}

void *consumer(void *arg)
{
	int f=*((int *)arg);
	sem_wait(&full); //wait for full slots, if not
	pthread_mutex_lock(&mutex);
	
	counter--;
	int item =buffer[counter]; //item consumed
	printf("Consumer %d consumed item : %d \n",f, item );
	sleep(5);
	
	pthread_mutex_unlock(&mutex) ;
	sem_post(&empty); //full ++
	pthread_exit(0);	
	return NULL;
}


int main(int argc ,char *argv[])
{

printf("Enter no. of Producers : ");
scanf("%d", &n1 );
printf("Enter no. of Consumers : ");
scanf("%d", &n2 );

pthread_t p[n1], c[n2];
int id1[n1],id2[n2];
sem_init(&empty, 0, size );
sem_init(&full, 0, 0 );
pthread_mutex_init(&mutex, NULL);

for(int i= 0; i<n1 ;i++)
{ id1[i]=i+1;
pthread_create(&p[i],NULL, producer, &id1[i]);  }
for(int i= 0; i<n2 ;i++)
{ id2[i]=i+1; pthread_create(&c[i],NULL, consumer, &id2[i]);  }
for(int i= 0; i<n1 ;i++)
{ pthread_join(p[i],NULL);  }
for(int i= 0; i<n2 ;i++)
{ pthread_join(c[i],NULL);  }
pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

return 0;	

} 
