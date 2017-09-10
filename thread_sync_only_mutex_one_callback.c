#include <iostream>
#include<stdio.h>
#include <pthread.h>
using namespace std;

// Initiliazer variables ///
const int MAX_NUM=12;
const int THREADS=3;
//////////////////////////
int gCount=0;
pthread_mutex_t mt;

void *callback(void* ptr)
{
	int id = *((int*)(ptr));
	while(1)
	{
		if(gCount>MAX_NUM)
			break;
		pthread_mutex_lock (&mt);
		if(gCount<= MAX_NUM && gCount%THREADS == id)
		{
			cout<<"thread "<<id<<" - "<<gCount<<endl;
			gCount++;
		}
		pthread_mutex_unlock (&mt);
	}
	pthread_exit(NULL); 
}

int main()
{
	pthread_t T[THREADS];
	pthread_mutex_init(&mt, NULL);
	int arr[THREADS];
	for(int j=0; j<THREADS; j++) 
	{
		arr[j]=j;
		pthread_create(&T[j],NULL,callback,&arr[j]); // Passing the array address as the argument to the call back function 
	}
	for(int j=0; j<THREADS; j++) 
		pthread_join(T[j],NULL);
	pthread_exit(NULL);
	return 0;
}
