#include<iostream>
#include<pthread.h>
#include<semaphore.h>
using namespace std ;
sem_t sem1 , sem2 ;
pthread_t pth[1] ;
//mutex_t mutex ; 
class A{

 public :
 static void *worker1(void *arg);
};
class B{
 public :
 static void *worker2(void *arg);
};
class C{
 public : 
 static void *worker3(void *arg);
};

void *A::worker1(void *arg ){
 	int i = 0  ;
	while(i < 5 ) {
		i++;
		cout<<"A::worker1"<<endl;
		sem_post(&sem1);
	}
}
void *B::worker2(void *arg ){
	int j = 0 ;
	while(j < 5 ){
		j++;
		sem_wait(&sem1);
		cout<<"B::worker2"<<endl;
		sem_post(&sem1);
		sem_post(&sem2);
	}
}

void *C::worker3(void *arg ){
	int k = 0 ;
	while(k < 5 ){
		k++;
		sem_wait(&sem2);
		cout<<"C::worker3"<<endl;
	}
}

using namespace std ;

int main()
{
 int status = -1 ;
 sem_t sem1 , sem2 ;
 sem_init(&sem1,0,0); // 1 param sem id // 2 param is it sharable ---false for posix//3 param---of sem 
 sem_init(&sem2,0,0);
 status = pthread_create(&pth[0],NULL,A::worker1,NULL);
 if(status != 0 )
	cout<<"pthread create error "<<endl ;
 status = pthread_create(&pth[1],NULL,B::worker2,NULL);
 if(status != 0 )
	cout<<"pthread error "<<endl;
 status = pthread_create(&pth[2],NULL,C::worker3,NULL);	
 if(status != 0)
	cout<<"pthread error "<<endl;
  
 pthread_join(pth[0],NULL);
 pthread_join(pth[1],NULL);
 pthread_join(pth[2],NULL);
 sem_destroy(&sem1);
 sem_destroy(&sem2);
 return 0 ;
}

