#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t chopstick[5];
pthread_t philosopher[5];
void *func(int n){
    printf("\n Philosopher %d hungry",n+1);
    pthread_mutex_lock(&chopstick[n]);
    pthread_mutex_lock(&chopstick[(n+1)%5]);

    printf("\n philosopher %d Eating",n+1);
    sleep(3);
    printf("\n philosopher %d thinking",n+1);
    pthread_mutex_unlock(&chopstick[n]);
    pthread_mutex_unlock(&chopstick[(n+1)%5]);
    return NULL;
}
void main(){
    for(int i=0;i<5;i++)
        printf("\n Philosopher %d thinking",i+1);

    for(int i=0;i<5;i++){
        pthread_mutex_init(&chopstick[i],NULL);

    }
    for(int i=0;i<5;i++){
        pthread_create(&philosopher[i],NULL,(void *)func,(void *)i);
    }
    for(int i=0;i<5;i++){
        pthread_join(philosopher[i],NULL);
    }
     for(int i=0;i<5;i++){
         pthread_mutex_destroy(&chopstick[i]);
     }


}