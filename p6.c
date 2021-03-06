#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

#include<sys/shm.h>
#include<sys/ipc.h>


void main(){
    
    key_t key=ftok("shmfile",65);
    int shmid= shmget(key,1024,0666|IPC_CREAT);
    char *str=(char *)shmat(shmid,(void *)0,0);
    int pid=fork();
    if(pid<0){
        printf("error");
    }
    else if(pid==0){
        execvp("./reader",NULL);
    }
    else{
        wait(NULL);
        printf("recieved: %s",str);
        shmdt(str);
        shmctl(shmid,IPC_RMID,NULL);

    }



}