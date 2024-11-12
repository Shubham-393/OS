#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
//Reader writer problem
//counter accessed exclusively 

#define size 5
pthread_mutex_t mutex; //mutex for shared data,writer
pthread_mutex_t r_count; //for r_count
int readers=0,n1,n2 ;
int shared_data=25;
void *reader(void *arg)
{
	int f=*((int *)arg);
	
	pthread_mutex_lock(&r_count); //lock r
	
	readers++;
	
	if( readers==1)
	{pthread_mutex_lock(&mutex); }//lock for shared_data
	
	pthread_mutex_unlock(&r_count);
	
	printf("\nReader %d is in critical sectio\n",f );
	sleep(1);
	printf("Reader %d reading item : %d \n",f, shared_data );
	
	pthread_mutex_lock(&r_count);
	
	readers--;
	if( readers==0)
	{pthread_mutex_unlock(&mutex); }//unlock for shared_data
	
	pthread_mutex_unlock(&r_count);
	
	
	printf("Reader %dleft critical sectio\n\n",f );	
	
	sleep(1);
	pthread_exit(0);
	return NULL;
}

void *writer(void *arg)
{
	int f=*((int *)arg);
	
	pthread_mutex_lock(&mutex);
	sleep(1);
	shared_data += 5;
	printf("\nWriter %d is in criticl section \n",f);
	sleep(1);
	printf("Writer %d wrote item : %d \n",f, shared_data );
		
	pthread_mutex_unlock(&mutex) ;
	
	printf("Writer %d left criticl section \n\n",f);
	pthread_exit(0);
	
	//sleep(5);	
	return NULL;
}


int main(int argc ,char *argv[])
{

printf("Enter no. of Reader : ");
scanf("%d", &n1 );
printf("Enter no. of Writer : ");
scanf("%d", &n2 );

pthread_t p[n1], c[n2];    //1.All variables(global and local)
int id1[n1],id2[n2];

pthread_mutex_init(&mutex, NULL);   
pthread_mutex_init(&r_count, NULL);   //2.All initialization

for(int i= 0; i<n1 ;i++)	//3.Create All threads
{ id1[i]=i+1;
pthread_create(&p[i],NULL, reader, &id1[i]);  }
for(int i= 0; i<n2 ;i++)
{ id2[i]=i+1; pthread_create(&c[i],NULL, writer, &id2[i]);  }

for(int i= 0; i<n1 ;i++)
{ pthread_join(p[i],NULL);  }	//4.Wait 
for(int i= 0; i<n2 ;i++)
{ pthread_join(c[i],NULL);  }

pthread_mutex_destroy(&mutex); //optional
 pthread_mutex_destroy(&r_count);    

return 0;	

} 
